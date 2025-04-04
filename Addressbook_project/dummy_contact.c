/********************************
Name: M vijay chalam
ID = 24022_066
Descrp: contact addressBook project
		this file contains the data of contacts which are presented in .txt file
		and file is opened in read mode to add into addressBook file
**************************************/
#include "contact.h"

// Function to initialize the address book by reading from a file
void initialize(AddressBook *addressBook) {
    char ch;
	FILE *pf;

pf = fopen("Addressbook.txt", "r");
	if(pf == NULL){
		printf("failed to open file\n");
		return;
	}

	char name[100];
	int i = 0, j = 0;

	while(fgets(name,sizeof(name),pf) && i < MAX_CONTACTS){
		
		//remove new line character if present
		name[strcspn(name, "\n")] = 0;
		
		//tokenize the line by comma
		char *Name = strtok(name,",");
		char *phone = strtok(NULL,","); //marking in the same arr name
		char *email = strtok(NULL, ","); //marking the same arr email
	//logic to read data into addressBook from file
		if (Name && phone && email){
			
			strncpy(addressBook->contacts[i].name,name, sizeof(addressBook->contacts[i].name)-1);
			strncpy(addressBook->contacts[i].phone,phone, sizeof(addressBook->contacts[i].phone)-1);
			strncpy(addressBook->contacts[i].email,email, sizeof(addressBook->contacts[i].email)-1);
			i++;
		}
		
	}
	
	//printing the data saved in addressBook 
	addressBook->contactCount = i;
	
	printf("---------------------------------------------------------------------------------------\n");
    printf("| %-5s | %-25s | %-20s | %-25s |\n","S.No","NAME","PHONE NUM","EMAIL ID");
    printf("---------------------------------------------------------------------------------------\n");
		for(j=0; j<i; j++){
			printf("| %-5d | %-25s | %-20s | %-25s |\n",j+1,addressBook->contacts[j].name,
													addressBook->contacts[j].phone,
													addressBook->contacts[j].email);
		}
		
	printf("---------------------------------------------------------------------------------------\n");
	printf("\n");
	fclose(pf);
	//printf("Loaded %d contacts from file.\n", addressBook->contactCount);
    
}

