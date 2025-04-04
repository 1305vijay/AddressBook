/**********************************
Name: m vijay chalam
ID = 24022_066
Descrp: contact addressBook project
		 this file contains savecontactstoFile() which used to save file into txt file which will be saved 
permanantly
***************************************/

#include"contact.h"


void saveContactsToFile(AddressBook *addressBook){
	//file pointer to access address of file
	FILE *pf;
	pf = fopen("Addressbook.txt", "w"); //calling file in write mode
	
	//checking file is opened or not
	if(pf == NULL)
		printf("failed to open file\n");
	else{
		//file opened then writing all the data of addressBook to the file
		int i;
		
		for(i=0; i<addressBook->contactCount; i++){
		
		if(fprintf(pf,"%s,%s,%s\n",addressBook->contacts[i].name 
								,addressBook->contacts[i].phone
								,addressBook->contacts[i].email) < 0)
			{
				perror("Failed to write to file");
				fclose(pf);
				return;
			
			}
		}
	 fclose(pf);
	 puts("Contact Saved Successfully\n");
	}
}
