/******************************
Name: M vijay chalam
ID = 24022_066
Descrp: contact addressBook project
		 contact.c contains all the function calls need to do specific operation based on user i/p
***********************************/
#include "contact.h"

//CreateContact(): funct when user wants to add new contact in addressbook
//**************************************************************************
void createContact(AddressBook *addressBook){
	int n= addressBook->contactCount; //storing no of contacts into var to send as arguement to nxt funct
	addingNewContact(addressBook,n); //calling inbuilt funct to add new contact (can find in addfunct.c file)

}

//searchContact(): funct used to search contact in addressbook and it checks whether i/p has valid data to search or not
//**************************************************************************
void searchContact(AddressBook *addressBook) {
	//declaring str var for each criteria to store the user i/p data for search operation
	char nameSearch[50], phoneSearch[20], mailSearch[50], opt[60], *data;
	
	int num, i=0, check=0;
	
	printf("You selected the Search operation:\n");
	num = display(opt);//calling display function to show the menu of criteria based on selected operation
	
	
	//checking for i/p with only spaces or NULL (can find in addonfunct.c file)
	if(Valid_with_nospaces(opt)){
		printf("Input contains only spaces. Please try again!\n");
		return;
	}
	
	//if selected user op is valid  search operation will start here
	searching(addressBook, num, opt, &check);
	
}

//editContact() : funct used to edit existing data but with new and unique data 
//*****************************************************
void editContact(AddressBook *addressBook) 
{
	

	int num, index; char opt[60];
	printf("You selected the Edit option \n");
	
	//asking user to input the criteria option based on which the operation should call
	num = display(opt);
	
	//checking for i/p with only spaces or NULL (can find in addonfunct.c file)	
	if(Valid_with_nospaces(opt)){
		puts("Input contains only spaces. Please try again!\n");
		return;
	}
	
	//stops the operationif selected criteria option is not present 
	if(num == -1)
	 	return;
	else 	
		index = SearchAndDisplay(addressBook, opt, num); //calling function to search and display if any data is found
		

//calling to edit data in place of found data 
	if(index != -1 ){
		
		addingNewContact(addressBook,index);
		(addressBook->contactCount)--;
	}
		else return ;
		
}

//deletecontact(): used to delete contact based on serial number we given to it
//***********************************************************************
void deleteContact(AddressBook *addressBook) 
{
	char opt[60];
	int num, check = 0;
	printf("You selected the Delete operation \n");
	num=display(opt);
	if(Valid_with_nospaces(opt)){
		printf("Input contains only spaces. Please try again!\n");
		return;
	}
	
	searching(addressBook, num, opt, &check); //searching the list to delete the required data
	
	if(!check) //if  check  raised to 1 it is error otherwise runs the nxt funct
		deleteNow(addressBook); //calling function to delete the data from list
	else 
		puts("Try again next time\n");
		//printf("No data found to delete\n");
		

}

//Listcontacts(): shows contact list 
//*******************************************************************
void listContacts(AddressBook *addressBook) 
{
    int i ,n = addressBook->contactCount;
    
    printf("---------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-25s | %-20s | %-25s |\n","S.No","NAME","PHONE NUM","EMAIL ID");
    printf("---------------------------------------------------------------------------------------\n");
    for(i=0; i<n; i++){
    	printf("| %-5d | %-25s | %-20s | %-25s |\n",i+1,addressBook->contacts[i].name,
													addressBook->contacts[i].phone,
													addressBook->contacts[i].email);
	}
	 printf("---------------------------------------------------------------------------------------\n");
	 printf("\n");
}
