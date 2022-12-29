/*
 * main.c
 *
 *  Created on: Dec 25, 2022
 *      Author: 20109
 */
#include "stdtypes.h"
#include "imt_bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
typedef enum{IDENTICAL,NOTIDENTICAL}strCmp_t;
strCmp_t string_compare(uint8 st[])
{
	uint8 name[11]="Sandra2020";
	uint8 i=0,x;
	uint8 err_st= NOTIDENTICAL;
	while(name[i]!=0)
	{
		if(st[i]==name[i])
		{
			x=IDENTICAL;
		}
		else
		{
			x=NOTIDENTICAL;
			break;
		}
		i++;
	}
	if(x==IDENTICAL)
	{
		err_st= IDENTICAL;
	}
	else if(x==NOTIDENTICAL)
	{
		err_st= NOTIDENTICAL;
	}
	return err_st;
}
int main()
{
	uint8 choice[20],userName[20];
	uint32 password,clientID;
	uint8 exit2=0;
	printf("----------Welcome to IMT Bank----------\n");
	while(1)
	{
		printf("For Admin press 1\n");
		printf("For User press 2\n");
		printf("Enter Your choice: ");
		scanf("%s",&choice);
		Sleep(1000);
		system("cls");
		switch(atoi(choice))
		{
		case 1:
			while ((getchar()) != '\n');
			printf("Enter your user name:");
			fgets(userName,50,stdin);
			printf("Enter your password:");
			scanf("%d",&password);
			Sleep(1000);
			system("cls");
			if( string_compare(userName)==IDENTICAL && password == 1234)
			{
				while(exit2==0)
				{
					printf("Create New Account press 1\n");
					printf("Open Existing Account press 2\n");
					printf("To show the list of accounts press 3\n");
					printf("Exit the system press 4\n");
					printf("Enter Your choice: ");
					scanf("%s",&choice);
					Sleep(1000);
					system("cls");
					switch(atoi(choice))
					{
					case 1:
						create_account();
						Sleep(1000);
					    system("cls");
						break;
					case 2:
						printf("Enter the Client Bank Account ID: ");
						scanf("%d",&clientID);
						Sleep(1000);
						system("cls");
						if(check_id(clientID)==E_OK)
						{
							printf("Make transaction press 1\n");
							printf("Change account status press 2\n");
							printf("Get cash press 3\n");
							printf("Deposit in account press 4\n");
							printf("Return to main menu press 5\n");
							printf("Enter Your choice: ");
							scanf("%s",&choice);
							Sleep(1000);
							system("cls");
							switch(atoi(choice))
							{
							case 1:
								make_transaction(clientID);
								Sleep(1000);
								system("cls");
								exit2=1;
								break;
							case 2:
								change_account_status(clientID);
								Sleep(1000);
								system("cls");
								exit2=1;
								break;
							case 3:
								get_cash(clientID);
								Sleep(1000);
								system("cls");
								exit2=1;
								break;
							case 4:
								deposit_in_account(clientID);
								Sleep(1000);
								system("cls");
								exit2=1;
								break;
							case 5:
								break;
							default:
								printf("You enter a wrong choice\n");
							}
						}
						else
						{
							printf("The Client Bank Account ID is not correct\n");
						}
						break;
					case 3:
						view_bank_accounts();
						break;
					case 4:
						printf("\n\n\n\n\n\n\n\n\n----------Bye Bye:)----------\n");
						exit2=1;
						break;
					default:
						printf("You enter a wrong choice\n");
					}
				}
				exit2=0;
			}
			else
			{
				printf("Your user name or password is not correct\n");
			}
			break;
		case 2:
			printf("Enter the Client Bank Account ID: ");
			scanf("%d",&clientID);
			Sleep(1000);
			system("cls");
			if(check_password(clientID) == E_OK)
			{
				printf("Make transaction press 1\n");
				printf("Change account password press 2\n");
				printf("Get cash press 3\n");
				printf("Deposit in account press 4\n");
				printf("Return to main menu press 5\n");
				printf("Enter Your choice: ");
				scanf("%s",&choice);
				Sleep(1000);
				system("cls");
				switch(atoi(choice))
				{
				case 1:
					make_transaction(clientID);
					Sleep(1000);
					system("cls");
					break;
				case 2:
					change_account_password(clientID);
					Sleep(1000);
					system("cls");
					break;
				case 3:
					get_cash(clientID);
					Sleep(1000);
					system("cls");
					break;
				case 4:
					deposit_in_account(clientID);
					Sleep(1000);
					system("cls");
					break;
				case 5:
					printf("\n\n\n\n\n\n\n\n\n----------Bye Bye:)----------\n");
					break;
				default:
					printf("You enter a wrong choice\n");
				}
			}
			else
			{
				printf("The Client Bank Account ID or Password is not correct\n");
			}
			break;
		default:
			printf("You enter a wrong choice\n");
			break;
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}

