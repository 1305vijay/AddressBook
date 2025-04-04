/*****************************
Name: M vijay chalam
ID = 24022_066
Descrp: contact addressBook project
****************************/
#include "contact.h"

int main()
{
    //all function calls should be inside the main 
    //declaring var of tyoe AddressBook struct
    AddressBook addressBook;
    
    //calling init funct before starting any other funct
    initialize(&addressBook);
    //now all emergency contacts will be saved to out addressBook var
	// along with count of those contacts
	
	int n = addressBook.contactCount;
	
	int i, status;
	status = 1;
	//setting always true until we select to exit the prog
	while(status){
		int opt;
		printf("Select your Operation to do from list:\n");
		printf("1. Add contact \n"
		"2. Search contact\n"
		"3. Edit contact\n"
		"4. Delete contact\n"
		"5. List contact\n"
		"6. Save the contacts to file\n"
		"7. Exit:\nEnter option : ");
		if(scanf("%d",&opt) != 1){
			printf("Choose between (1 - 7) options\n");
			clearInputBuffer();
			continue;
		}
		getchar();
		switch(opt){
			case 1:
				createContact(&addressBook);
				break;
			case 2:
				searchContact(&addressBook);
				break;
			case 3:
				editContact(&addressBook);
				break;
			case 4:
				deleteContact(&addressBook);
				break;
			case 5:
				listContacts(&addressBook);
				break;
			case 6:
				saveContactsToFile(&addressBook);
				break;
			case 7:
				printf("------->Exiting from operation<-----------\n");
				return;
			default:
				printf("Choose between (1 - 7) options\n");
				break; //ontinue to show the menu again until opt to exit
 		}
 		
	}
	
}

