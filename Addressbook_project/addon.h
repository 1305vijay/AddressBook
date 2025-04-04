#ifndef ADDON_H
#define ADDON_H

#include"C:\Users\maluv\Desktop\vijayAddress\contact.h"
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int  Valid_with_nospaces(char *);
void deleteNow(AddressBook *addressBook);
void searching(AddressBook *addressBook, int , char *, int *);
void trimWhitespace(char*);
void clearInputBuffer();
int display(char *);
void findings(AddressBook * addressBook, int );
int SearchAndDisplay(AddressBook *addressBook, char *, int);
int  withoutspace(char *);
void addingNewContact(AddressBook *addressBook, int );

#endif
