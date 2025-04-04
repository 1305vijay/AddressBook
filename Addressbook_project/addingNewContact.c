/*
Name: M vijay chalam
ID = 24022_066
Descrp: contact addressBook project
**************
this file contains functions named "void addingNewContact()" & " int withoutspace()" 
withoutspace(): this function ensures the given i/p is not NULL or contains only spaces
addingNewContact(): based on user i/p this funct creates new contact details such as name,phone,Email
					also checks that they are unique and valid data
*****************************/

#include "contact.h"

//funt to add new contact details	
void addingNewContact(AddressBook *addressBook, int num ){
	//declaring var of diff datatypes
	int n = num;
	char tempName[50], tempPhone[15], tempEmail[30];
	int status=0, val=1;
	
//loop to continue again until valid details are given in this function
	while(val)
	{
		
		 //int nameIsValid = 0, phoneExists = 1, phoneIsValid = -1, emailIsValid = 1, emailIsUnique = 1;
		 //int phoneIsValid ;
//***************chekcing Num now********************

//asking and storing name str to temporary str	
	printf("enter name to do this operation: \n");
	scanf("%[^\n]",tempName);
	getchar();  //clears stdin buffer
	
	//checking the str should not empty
	if(withoutspace(tempName) == 1){
		printf("ERROR: It's Empty (or) given space first\nPlease try again\n");
		continue;
	}
		
	// declaring var of int datatype to use them as flags
	int i, nameExists , nameIsUnique = 1, nameIsValid = 0, size = addressBook->contactCount;
	
	//logic to check if name is present in the conact list
	for(i=0; i<size;i++)
	{	
		//comparing entered name with contact list  
		nameExists = strcmp(tempName,addressBook->contacts[i].name);
	
		if (nameExists == 0)  //logic of if name is found in list
		{
			printf("ERROR: Name matched in list please try again\n");
			tempName[0] = '\0'; //making user i/p str empty
			nameIsUnique = 0; //flag down
			break;			
		}	
	}
	printf("exists : %d\n",nameExists);
	
	//if flag is raised
	if (nameIsUnique){
	
	//logic to check user i/p  name is valid
	for(i=0; i < strlen(tempName); i++){
		if((tempName[i] == 32 || (tempName[i] >='a' && tempName[i] <='z' ) || (tempName[i] >= 'A' && tempName[i] <= 'Z' ))
			 && strcmp(tempName,addressBook->contacts[i].name))
		{ 	
			nameIsValid=1;
		} 
		else 
		{
			printf("%-6s \n","ERROR: Invalid Name Try again");
			tempName[0]='\0';
			nameIsValid = 0;
			break;
			
		}
	}
}

//************checking phone num now ***********************
//declaring var as falgs
int phoneIsUnique, phoneExists, phoneIsValid = 0;

printf("valid name: %d\n",nameIsValid);


	//asking num to user
	if(nameIsValid){ //value transfered from validName of previous funct
	
	//asking and storing data into tempPhone str
		printf("enter phone to do this operation \n");
		scanf("%[^\n]",tempPhone);
		getchar(); 
		
		//calling function to check phone num should not contain empty or space
		if(withoutspace(tempPhone) == 1){
			printf("ERROR: It's Empty (or) given space first\nPlease try again\n");
			continue;
		}
		

	//logic to check uniqueness of num
	for(i=0; i<size; i++){
		phoneExists = strcmp(tempPhone,addressBook->contacts[i].phone);
		if(phoneExists == 0 )
		{
			printf("ERROR: num found in list\n");
			phoneIsUnique = 0;
			tempName[0]='\0';
			break;

		}
		else 
			phoneIsUnique = 1; //raising flag for valid contact
			
   }
//}
   //int phoneIsValid = 0;
	//checking num with numericals and length is 10
	if(phoneIsUnique == 1){
		
	
	for (i=0; i < strlen(tempPhone); i++){
		if(((tempPhone[i] >= 48 && tempPhone[i] <= 57) && strlen(tempPhone) == 10 ) 
			&& strcmp(tempPhone,addressBook->contacts[i].phone)){	
				phoneIsValid = 1;
				printf("I entered into \n");
			}
		else
			{	
				printf("ERROR: Wrong number going to 1st step\n");
				printf("\n");
				tempName[0]= '\0';
				phoneIsValid = 0;
				break;
			}
		}	
	}
}


//**************checking email now********************
printf("valid Num : %d\n",phoneIsValid);
	//declaring var as flags
	int emailexists, emailIsUnique = 1;
if(phoneIsValid == 1){ //value transfered from validNum of previous funct
	
	printf("Enter email address to do this operation: \n");
	scanf("%[^\n]",tempEmail);
	getchar();
	
	//checking email not starting with space or empty
	if(withoutspace(tempPhone) == 1){
			printf("ERROR: It's Empty (or) given space first\nPlease try again\n");
			continue;
		}
	

	
	//int uniqEmail;
	//checking Email is not present in addressBook contact list
	for (i=0; i<size; i++){
		emailexists= strcmp(tempEmail,addressBook->contacts[i].email);
		
		if(emailexists == 0){
		
			printf("ERROR: Entered email is in list pls try again\n");
			emailIsUnique=0; //flag down if email present in addressBook
			tempName[0]='\0';
			break;
		}
	}
	//decalring var for checking  Email validity
	int dotcom=0, symbolcount= 0, isInvalidPattern = 0;
	
	//checking that user i/p email contains ".com" & "@" in it
	char *strdomain = (strstr(tempEmail,".com"));
	char *symbol = (strchr(tempEmail,'@'));
	
	//checking more than on '@' in email
	for (i = 0; tempEmail[i] != '\0'; i++) {
		
    if (tempEmail[i] == '@') {
        symbolcount++;
    	}
	}
	//logic to if @ is more than one gives error
	int emailIsValid = 1;
	printf("OKOKOK\n");
	if (symbolcount > 1) {
    	printf("ERROR: Email cannot contain more than one '@' symbol. Please try again.\n");
    	emailIsValid = 0;
	} 
	else if(emailIsUnique)
	{
		//checking that there is one @ and its not at start or last char
		if(symbol == NULL || symbol == tempEmail || *(symbol + 1) == '\0'){
			printf("ERROR: Email must contain a valid @ symobol Try again \n");
			emailIsValid = 0;
			val = 1;
		}
		//checking that email should not have immediately .(dot) after '@'
		else if(*(symbol + 1) == 46 || *(symbol + 1) == '\0'){
			printf("ERROR: Email must have valid name after @. Try again\n");
			emailIsValid = 0;
		}
		//else{
			//now checking for .com only after '@' symbol
			else if(strdomain == NULL || *(strdomain + 4) != '\0'){
				printf("ERROR: Email must end with '.com' \n");
				emailIsValid = 0;
				val = 1;
			}
			else{
				//continue checking character before '@'
				for(i = 0; i< (symbol - tempEmail); i++){
					if(!((tempEmail[i] >= '0' && tempEmail[i] <= '9' )||
			 		(tempEmail[i] >= 'a' && tempEmail[i] <= 'z') || 
			  		(tempEmail[i] >= 'A' && tempEmail[i] <= 'Z' )))
				  {
			  		printf("ERROR: Invalid charcter in email before '@' \n");
			  		emailIsValid = 0;
			  		val = 1;
			  		break;
				  }
				}
			}
		}
		//logic to raise flag to add user i/p details to addressBook
		if (emailIsValid) {
                status = 1; // Mark as valid to add contact
                val = 0;
            } else {
                printf("ERROR: Email is not valid. Please try again.\n");
                status = 0;
            }
            printf("emailIsValid : %d\n",emailIsValid);
		
		}	


  		printf("\n");
  		
}

//finally if valid data given proceeding to add contact to data list
if(status){
	
		strcpy(addressBook->contacts[n].name,tempName);
		strcpy(addressBook->contacts[n].phone,tempPhone);
		strcpy(addressBook->contacts[n].email,tempEmail);
		(addressBook->contactCount)++;
		printf("%-15s\n","Contact added Successfully Thank You");
		printf("\n");
	
		  }
		
}


