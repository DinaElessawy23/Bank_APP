/*
 ============================================================================
 Name        : imt_project.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "imt_project.h"

struct User *head = NULL;
struct User *current = NULL;

void insertAtLast(struct User newUser)
{
   //create a new node
   struct User *link = (struct User*) malloc(sizeof(struct User));

   //store data in the node
   strcpy(link->Name,newUser.Name);
   strcpy(link->address,newUser.address);
   strcpy(link->Bank_ID,newUser.Bank_ID);
   strcpy(link->Guardian_Name,newUser.Guardian_Name);
   strcpy(link->password,newUser.password);
   strcpy(link->National_ID,newUser.National_ID);
   strcpy(link->Guardian_National_ID,newUser.Guardian_National_ID);
   link->account_state = newUser.account_state;
   link->balance = newUser.balance;


   //point the next pointer to the old head node
   link->next = NULL;
   // If head is empty, create new list
   if(head==NULL)
   {
      head = link;
      return;
   }

   current = head;

   // loop until reach the last node in the old list
   while(current->next != NULL)
   {
	   current = current->next;
   }

   // Make the last node in the old list point to new node
   current->next = link;
}



void  Create_New_Account()
{
	struct User newAcc;
	printf("- Full Name: \n");
	getchar();
	scanf("%s",newAcc.Name);
	getchar();
	printf("- Full Address: \n");
	getchar();//before scanf srting only
	scanf("%s",newAcc.address);
	getchar();
	printf("- Age: \n");
	scanf("%d",&(newAcc.age));
	do
	{
		printf("- National ID: \n");
		fflush(stdout);
		scanf("%s",newAcc.National_ID);
	}while(strlen(newAcc.National_ID)!=14);

	if((newAcc.age)<21)
	{
		printf("- Guardian Full Name: ");
		getchar();
		scanf("%s",newAcc.Guardian_Name);
		getchar();
		printf("- Guardian National ID: ");
		getchar();
		scanf("%s",newAcc.Guardian_National_ID);
	}

	printf("- Balance: ");
	getchar();
	scanf("%d",&newAcc.balance);
	strcpy(newAcc.Bank_ID,Rnadom_ID());
	strcpy(newAcc.password,Rnadom_Password());
	printf("id:%s\n",newAcc.Bank_ID);
	printf("password:%s\n",newAcc.password);
	newAcc.account_state=Active;
	insertAtLast(newAcc);

}
void Make_Transaction( char  id[]) {
	char  id2[11];
    int money;
    printf("enter the Bank Account ID you want to transfer money to: ");
     scanf("%s",id2);
    printf("enter amount of money to transfer it to the this account: ");
	 scanf("%d",&money);
	if (head == NULL) {
		printf("Linked List is empty");
		return;
	}

	// start checking from the first node
	current = head;
	while (current != NULL)
	{
		if (strcmp(current->Bank_ID, id) == 0)
		{
			if (current->account_state == Active)
			{
				if (money > current->balance)
					printf("Insufficient Funds | Balance Avaliable %d",
							current->balance);

				else {
					current->balance -= money;
					printf("Account balance has been updated : %d",
							current->balance);
				}
			}
			return;
		}
		else if (strcmp(current->Bank_ID, id2) == 0)
		{
			if (current->account_state == Active)
			{
				current->balance += money;
				printf("Account balance has been updated : %d",
						current->balance);
			}

		}
		current = current->next;
	}
	// item not found in the list
	printf("%s does not exist\n", id);

}
void Change_Account_Status(char id[])
{ char status[100];
	printf("enter the Bank Account Status");
    scanf("%s",status);
	  if(head==NULL)
	   {
	      printf("Linked List is empty");
	      return;
	   }

	   // start checking from the first node
	   current = head;
	   while(current != NULL)
	   {
	      if(strcmp(current->Bank_ID, id) == 0)
	      {
	    	  current->account_state = status;

	         return;
	      }
	      current = current->next;

	   }
	   // item not found in the list
		printf("%s does not exist\n", id);
}
void Get_Cash(char id[])
{
	int money;
	printf("Enter the cash amount you want:");
	scanf("%d",&money);
	  if(head==NULL)
	   {
	      printf("Linked List is empty");
	      return;
	   }

	   // start checking from the first node
	   current = head;
	   while(current != NULL)
	   {
	      if(strcmp(current->Bank_ID, id) == 0)
	      {
			if (money > current->balance)
				printf("Insufficient Funds | Balance Avaliable %d",	current->balance);

			else {
				current->balance -= money;
				printf("Account balance has been updated : %d",current->balance);
			}
	         return;
	      }
	      current = current->next;

	   }
	   // item not found in the list
		printf("%s does not exist\n", id);
}
void Deposit_in_Account(char id[])
{
	int money;
	printf("Enter the cash amount you want to add:");
	scanf("%d",&money);
	  if(head==NULL)
	   {
	      printf("Linked List is empty");
	      return;
	   }

	   // start checking from the first node
	   current = head;
	   while(current != NULL)
	   {
	      if(strcmp(current->Bank_ID, id) == 0)
	      {
	    	  current->balance += money;
	    	  printf("Account balance has been updated : %d",current->balance);
	         return;
	      }
	      current = current->next;

	   }
	   // item not found in the list
		printf("%s does not exist\n", id);
}
void Admin_menu()
{
	int x;
	printf("choose between the following features:\n");
	printf("1: Create New Account\n");
	printf("2: Open Existing Account\n");
	printf("3: Exit System\n");
	scanf("%d", &x);
	switch (x)
	{
	case 1:
		Create_New_Account();
		break;
	case 2:
		Open_Existing_Account();
		break;
	default:
		break;
	}
}
void Admin_login(char Admin_id[] , char password[])
{
	char id[5];
	char pass[5];
	printf("Bank Account ID:");
	scanf("%s",id);
	printf("Password:");
	scanf("%s",pass);

	  if((strcmp(Admin_id, id) )== 0)
	    {
	    	  if(strcmp(password, pass) == 0)
	    	  {
	    		  Admin_menu();
	    	  }
	    	  else
	    	  {
	    	 printf("uncorrect password\n");
	    	 return;
	    	  }


	      }
	   else
	      {
		printf("%s does not exist\n", id);
	      }

}
void Open_Existing_Account()
{
	char  id[11];
	int x;
	printf("Enter Client Bank Account ID: ");
	scanf("%s",id);
	printf("choose between the following features:\n");
	printf("1: Make Transaction\n");
	printf("2: Change Account Status\n");
	printf("3: Get Cash\n");
	printf("4: Deposit in Account\n");
	printf("5: Return to main menu\n");
	scanf("%d",&x);
	switch(x)
	{
	case 1:
	         Make_Transaction(id);
		     break;
	case 2:  Change_Account_Status( id);
             break;
	case 3:  Get_Cash(id);
		     break;
	case 4:  Deposit_in_Account(id);
		     break;
	case 5: Open_Existing_Account();
		    break;
	default:  break;


	}
}
char * Rnadom_Password()
{
	  int length=8;

	static  char password[9] ;

	  char *digits = "0123456789";
	  int digits_length = strlen(digits);

	  char *lowers = "abcdefghijklmnopqrstuwxyz";
	  int lowers_length = strlen(lowers);

	  char *uppers = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	  int uppers_length = strlen(uppers);

	  char *symbols = "!@#$%^&*()";
	  int symbols_length = strlen(symbols);

	  srand(time(NULL) * getpid());

	  for (int i = 0; i < length; i++)
	  {

	    int char_type = rand() % 4;

	    if (char_type == 0)
	      password[i] = digits[rand() % digits_length];
	    else if (char_type == 1)
	      password[i] = lowers[rand() % lowers_length];
	    else if (char_type == 2)
	      password[i] = uppers[rand() % uppers_length];
	    else
	      password[i] = symbols[rand() % symbols_length];

	  }

	  password[length] = '\0';

	  return password;

}
char * Rnadom_ID()
{
	  int length=10;

	 static char ID[11] ;

	  char *digits = "0123456789";
	  int digits_length = strlen(digits);

	  srand(time(NULL) * getpid());

	  for (int i = 0; i < length; i++)
	  {

	      ID[i] = digits[rand() % digits_length];

	  }

	  ID[length] = '\0';

	  return ID;

}
void user_menu(char  id[])
{
	int x;
	printf("choose between the following features:\n");
	printf("1: Make Transaction\n");
	printf("2: Change Account Password\n");
	printf("3: Get Cash\n");
	printf("4: Deposit in Account\n");
	printf("5: Return to main menu\n");
	scanf("%d", &x);
	switch (x) {
	case 1:
		Make_Transaction(id);
		break;
	case 2:
		Change_Account_Password(id);
		break;
	case 3:
		Get_Cash(id);
		break;
	case 4:
		Deposit_in_Account(id);
		break;
	case 5:
		user_menu(id);
		break;
	default:
		break;}

}
void user_login()
{
	char id[11]=" ";
	char pass[9]=" ";
	printf("Bank Account ID:");
	scanf("%s",id);
	printf("Password:");
	scanf("%s",pass);

	  if(head==NULL)
	   {
	      printf("Linked List is empty");
	      return;
	   }

	   // start checking from the first node
	   current = head;
	   while(current != NULL)
	   {
	      if(strcmp(current->Bank_ID, id) == 0)
	      {
	    	  if(strcmp(current->password, pass) == 0)
	    	  {
	    		  user_menu(id);
	    	  }
	    	  else
	    	  {
	 	    	 printf("uncorrect password\n");
	    	  }
	      }
	      current = current->next;

	   }
	   // item not found in the list
		printf("%s does not exist\n", id);

}
void Change_Account_Password(char id[])
{
	  if(head==NULL)
	   {
	      printf("Linked List is empty");
	      return;
	   }

	   // start checking from the first node
	   current = head;
	   while(current != NULL)
	   {
	      if(strcmp(current->Bank_ID, id) == 0)
	      {
	    		strcpy(current->password,Rnadom_Password());
		    	printf("Account password has been changed : %s",current->password);


	         return;
	      }
	      current = current->next;

	   }
	   // item not found in the list
		printf("%s does not exist\n", id);
}
void printList(void)
{
   struct User *ptr = head;

   printf("[head] =>");

   //start looping from the head until the last node
   while(ptr != NULL)
   {
      printf(" %s =>",ptr->Bank_ID);
      ptr = ptr->next;
   }

   printf(" [null]\n");
}

