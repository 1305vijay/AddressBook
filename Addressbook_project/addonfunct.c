/***********************************
Name: M vijay chalam
ID = 24022_066
Descrp: contact addressBook project
		this file contains all the functions which were used in opeation function as inbuilt functions
***********************************/

#include"addon.h"

/*******  Function to check that given i/p has no only spaces  *******************/ 
int  Valid_with_nospaces(char *opt){
	//logic to check if str contains space at first 
	if(opt == NULL || *opt == 32)
		return 1; //invalid
	
	//logic to check if str contains only spaces	
	while(*opt){
		if(*opt != 32)
			return 0; //valid str
		opt++;
	}
	return 1; //invalid
	
}
/****************** function to delete the specified data when user selected the serial num*********************************/
void deleteNow(AddressBook *addressBook){
	int serNum;
	printf("Select the Serial number of data which you want to delete: \n");
	scanf("%d",&serNum);
	
	//logic to delete the given serial num data
	int i;
	for(i=serNum-1; i < addressBook->contactCount; i++){
		strcpy(addressBook->contacts[i].name,addressBook->contacts[i+1].name);
		strcpy(addressBook->contacts[i].phone,addressBook->contacts[i+1].phone);
		strcpy(addressBook->contacts[i].email,addressBook->contacts[i+1].email);
	}
		(addressBook->contactCount)--;
	printf("\n");
	printf("Selected data is deleted succussfully from list\n");
	printf("\n");
}
/************** Searching() to search and print the data**************************/
void searching(AddressBook *addressBook, int num, char *opt, int *check){
	int i, found_match = 0;
//	if(check)
//	printf("---------------------------------------------------------------------------------------\n");
//	printf("| %-5s | %-25s | %-20s | %-25s |\n","S.No","NAME","PHONE NUM","EMAIL ID");
  //  printf("---------------------------------------------------------------------------------------\n");
	for(i=0; i<addressBook->contactCount; i++)
	{
	if((num == 1) && (strstr(addressBook->contacts[i].name,opt)) ||
		(num == 2) && (strstr(addressBook->contacts[i].phone,opt))||
		(num == 3) && (strstr(addressBook->contacts[i].email,opt))
		){
			findings(addressBook,i);
			found_match = 1;
		}
	
	}
	
//printf("---------------------------------------------------------------------------------------\n");
	if(!found_match){
	printf("no match found\n");
	*check = 1; //raising flag to alert about this error in master funct
	}

}
/******************this funct used to trim any white spaces as tail end or starting of i/p str*************************/
void trimWhitespace(char* str) {
    int i, j;

    // Remove leading whitespaces
    i = 0;
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
        i++;
    }

    // Shift all characters to the left
    for (j = 0; str[i + j] != '\0'; j++) {
        str[j] = str[i + j];
    }
    str[j] = '\0';  // Null-terminate the string
}
/**************function used to clear input buffer which are more than one char********************/
void clearInputBuffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}
/****************function to display the menu of criteria which will be shown after selection of specific operaion********************/
int display(char opt[]){
	int num;
	printf("#__MENU__# \n"
	"1.Name\n"
	"2.Phone Number\n"
	"3.Emaid ID\n"
	"Please select your criteria you'd like to use for this operation :\n");
	if(scanf("%d",&num) != 1)
	{
		printf("Choose options (1-3) only\n");
		clearInputBuffer();
		return -1;
	}
	getchar();
	
	if(num >=1 && num <=3)
	{
		//continuing to ask user i/p 
switch(num){
		case 1:
			printf("Enter name to search into the list :\n");
			scanf("%[^\n]",opt);
			getchar();
			break;
		case 2:
			printf("Enter phone to search into the list :\n");
			scanf("%[^\n]",opt);
			getchar(); 
			break;
		case 3:
			printf("Enter Email ID to search into the list :\n");
			scanf("%[^\n]",opt);
			getchar();
			break;
			
	}
	return num;

}
else{

	printf("Choose options (1-3) only\n");
	num = 0;
	return -1;
	}

}
/*************function used find the data which was found *********************/
void findings(AddressBook * addressBook, int n){
	printf("| %-5d | %-25s | %-20s | %-25s |\n",n+1,addressBook->contacts[n].name,
													addressBook->contacts[n].phone,
													addressBook->contacts[n].email);

													
}
/****************used to call findings funct and also checks whether data was found or not*******************/
int SearchAndDisplay(AddressBook *addressBook, char opt[], int num){
		int i, found = 0;
		
		for(i = 0; i < addressBook->contactCount; i++){
			
		char tempOpt[100];
		strcpy(tempOpt,opt);
		trimWhitespace(tempOpt);
		if(num == 1)
		{
				if((strcmp(addressBook->contacts[i].name,opt)) == 0)
			{
				
				found = 1;
				if(found){
						printf("---------------------------------------------------------------------------------------\n");
    					printf("| %-5s | %-25s | %-20s | %-25s |\n","S.No","NAME","PHONE NUM","EMAIL ID");
    					printf("---------------------------------------------------------------------------------------\n");
    					findings(addressBook, i);
    					printf("---------------------------------------------------------------------------------------\n");
				}
				break;
			}
				
		}
		else if(num == 2)
		{
			//res = (strcmp(addressBook->contacts[i].phone,opt));
			if((strcmp(addressBook->contacts[i].phone,opt)) == 0)
			{
				findings(addressBook, i);
				found = 1;
				break;
			}
			
		}
				
		else if(num == 3)
		{
			//res = (strcmp(addressBook->contacts[i].email,opt));
				if((strcmp(addressBook->contacts[i].email,opt)) == 0)
			{
				findings(addressBook, i);
				found = 1;
				break;
			}
			
		}
		else {
			printf("invalid option\n");
			return -1;
		}

	
	}

	if (!found ){
		printf("Data not found\n");
		return -1;
	}
	else 
		return i;


}
/************************-----------------------*********************/
//same as nospaces()
int  withoutspace(char *opt){
	//logic to check if str contains space at first 
	if(opt == NULL || *opt == 32)
		return 1; //invalid
	
	//logic to check if str contains only spaces	
	while(*opt){
		if(*opt != 32)
			return 0; //valid str
		opt++;
	}
	return 1; //invalid
	
}
/****************---------------------************************/

