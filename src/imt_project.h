/*
 * imt_project.h
 *
 *  Created on: Dec 28, 2022
 *      Author: DINA ELESSAWY
 */

#ifndef IMT_PROJECT_H_
#define IMT_PROJECT_H_


enum Account_state{Active,Restricted,Closed};
struct User{
	char Name[100];
	char address[100];
	char National_ID[15];
	int age;
	char Bank_ID[11];
	char Guardian_Name[100];
	char Guardian_National_ID[15];
	int account_state;
	int balance;
	char password[9];
	struct User *next;
};


char * Rnadom_Password();
char * Rnadom_ID();
void  Create_New_Account();
void Admin_login(char* Admin_id , char* password);
void Open_Existing_Account();
void Make_Transaction( char * id) ;
void Change_Account_Status(char * id);
void Get_Cash(char *id);
void Deposit_in_Account(char *id);
void user_menu(char * id);
void user_login();
void Change_Account_Password(char *id);
void printList(void);

#endif /* IMT_PROJECT_H_ */
