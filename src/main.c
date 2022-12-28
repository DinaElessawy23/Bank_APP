/*
 * main.c
 *
 *  Created on: Dec 28, 2022
 *      Author: DINA ELESSAWY
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "imt_project.h"


int main(void)
{    printList();
while(1)
{
	char* Admin_ID="12345";
	char* pass="123";
	int x;
	printf("1-Admin Window:\n");
	printf("2-Client Window:\n");
	scanf("%d",&x);
	if(x==1)
	{
		Admin_login(Admin_ID,pass);
	}
	else if(x==2)
	{
		user_login();
	}
	printList();
}
return 0;
}
