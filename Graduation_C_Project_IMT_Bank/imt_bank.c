/*
 * imt_bank.c
 *
 *  Created on: Dec 25, 2022
 *      Author: 20109
 */

#include "stdtypes.h"
#include "imt_bank.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct bankAccount *PFirstClient=NULL;
sint32 myRand ()
{
	static int next = 3251 ;
	next = ((next * next) / 100 ) % 10000 ;
	return next ;
}

sint32 random_numbers ( sint32 min, sint32 max )
{
	return myRand() % (max+1-min) + min ;
}
uint8 check_spaces(uint8 str[])
{
	uint32 count=0,i=0;
	while(str[i]!=0)
	{
		if(str[i]== ' ')
		{
			count++;
		}
		i++;
	}
	return count;
}
uint8 No_digits(uint8 str[])
{
	uint32 i=0;
	while(str[i]!=0)
	{
		i++;
	}
	return i;
}
void view_bank_accounts(void)
{
	struct bankAccount *PCurrentClient = PFirstClient;
	if(PFirstClient == NULL)
	{
		printf("Empty list\n");
	}
	else
	{
		while(PCurrentClient)
		{
			printf("Full Name: %s\n",PCurrentClient->client.Full_Name);
			printf("Address: %s\n",PCurrentClient->client.Address);
			printf("National ID: %s\n",PCurrentClient->client.National_ID);
			printf("Age: %d\n",PCurrentClient->client.Age);
			printf("Bank Account ID: %d\n",PCurrentClient->client.Bank_account_ID);
			printf("Guardian Name: %s\n",PCurrentClient->client.Guardian);
			printf("Guardian ID: %s\n",PCurrentClient->client.Guardian_ID);
			printf("Status: %d\n",PCurrentClient->client.Status);
			printf("Balance: %d\n",PCurrentClient->client.Balance);
			printf("Password: %d\n",PCurrentClient->client.password);
			printf("-----------------------------------------------\n");
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	return;
}
void create_account(void)
{
	struct bankAccount *PNewClient;
	struct bankAccount *PLastClient;
	static uint32 bankAccount= 1000000000;
	uint8 Name[100];
	/*check the list is empty*/
	if(PFirstClient == NULL)
	{
		/*create a new bank account*/
		PNewClient = (struct bankAccount*)malloc(sizeof(struct bankAccount));
		PFirstClient = PNewClient;
		PNewClient->client.Bank_account_ID = bankAccount;
	}
	else
	{
		PLastClient = PFirstClient;
		/*navigate until reach to the last bank account*/
		while(PLastClient->PNextClient)
		{
			PLastClient = PLastClient->PNextClient;
		}
		/*create a new bank account*/
		PNewClient = (struct bankAccount*)malloc(sizeof(struct bankAccount));
		PLastClient->PNextClient = PNewClient;
		bankAccount++;
		PNewClient->client.Bank_account_ID = bankAccount;
	}
	/*fill the bank account information*/
	while ((getchar()) != '\n');
	printf("Enter Your Full Name(at least 4 names): ");
	fgets(Name,100,stdin);
	/*Check the has 3 spaces which means that he enter four names*/
	if(check_spaces(Name)>=3)
	{
		strcpy(PNewClient->client.Full_Name,Name);
		printf("Enter Your Address: ");
		fgets(PNewClient->client.Address,100,stdin);
		printf("Enter Your National ID: ");
		fgets(PNewClient->client.National_ID,15,stdin);
		/*check if the owner enter 14 digit of client's national id*/
		while(No_digits(PNewClient->client.National_ID)!=14)
		{
			printf("you write a wrong National ID(National ID must contains 14 digits)\n");
			printf("Enter Your National ID: ");
			fgets(PNewClient->client.National_ID,15,stdin);
		}
		printf("Enter Your Age: ");
		scanf("%d",&PNewClient->client.Age);
		/*check if the age of the client is less than 21 so it need a guardian*/
		if(PNewClient->client.Age <21)
		{
			while ((getchar()) != '\n');
			printf("Enter Your Guardian ID: ");
			fgets(PNewClient->client.Guardian_ID,15,stdin);
			/*check if the owner enter 14 digit of guardian's national id*/
			while(No_digits(PNewClient->client.Guardian_ID)!=14)
			{
				printf("you write a wrong Guardian ID(Guardian ID must contains 14 digits)\n");
				printf("Enter Your Guardian ID: ");
				fgets(PNewClient->client.Guardian_ID,15,stdin);
			}
			while ((getchar()) != '\n');
			printf("Enter Your Guardian Name: ");
			fgets(PNewClient->client.Guardian,100,stdin);
		}
		else/*the client's age is bigger than 21*/
		{
			PNewClient->client.Guardian[0]= '\0';
			PNewClient->client.Guardian_ID[0]='\0';
		}
		printf("Enter Your Balance: ");
		scanf("%d",&PNewClient->client.Balance);
		PNewClient->client.password = random_numbers(1000,9999);
		PNewClient->client.Status = Active;
		printf("The account has been created successfully\n");
		PNewClient->PNextClient = NULL;
	}
	else
	{
		PFirstClient = NULL;
		printf("You enter a wrong name\n");
	}
	return;
}
void make_transaction(uint32 ID)
{
	uint32 transactionID,money;
	struct bankAccount *PCurrentClient=PFirstClient;
	struct bankAccount *PtransactionClient=PFirstClient;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				/*check the client id is active or not*/
				if(PCurrentClient->client.Status==Active)
				{
					printf("Enter the Bank Account ID you want to transfer money to: ");
					scanf("%d",&transactionID);
					while(PtransactionClient)
					{
						if(PtransactionClient->client.Bank_account_ID == transactionID)
						{
							/*check the transaction account id is active or not*/
							if(PtransactionClient->client.Status==Active)
							{
								printf("Enter amount of money to transfer it to this account: ");
								scanf("%d",&money);
								/*check the client balance has the amount of money*/
								if(PCurrentClient->client.Balance>=money)
								{
									PtransactionClient->client.Balance +=money;
									PCurrentClient->client.Balance -=money;
									printf("The transaction has been done successfully\n");
								}
								else
								{
									printf("This amount is bigger than the account has\n");
								}
							}
							else
							{
								printf("Can't make this transaction\n");
							}
						}
						PtransactionClient = PtransactionClient->PNextClient;
					}
				}
				else
				{
					printf("Can't make this transaction\n");
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return;
}
void change_account_status(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	accountStatus_t state;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				printf("Set Account to Active State press 1\n");
				printf("Set Account to Restricted State press 2\n");
				printf("Set Account to Closed press 3\n");
				printf("Enter your choice: ");
				scanf("%d",&state);
				switch(state)
				{
				case 1:
					PCurrentClient->client.Status = Active;
					break;
				case 2:
					PCurrentClient->client.Status = Restricted;
					break;
				case 3:
					PCurrentClient->client.Status = Closed;
					break;
				default:
					printf("You enter a wrong choice\n");
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return;
}
void get_cash(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	uint32 money;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				/*check the client id is active or not*/
				if(PCurrentClient->client.Status==Active)
				{
					printf("Enter amount of money you want from this account: ");
					scanf("%d",&money);
					/*check the client balance has the amount of money*/
					if(PCurrentClient->client.Balance>=money)
					{
						PCurrentClient->client.Balance -=money;
						printf("The operation has been done successfully\n");
					}
					else
					{
						printf("This amount is bigger than the account has\n");
					}
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return;
}
void deposit_in_account(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	uint32 money;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				/*check the client id is active or not*/
				if(PCurrentClient->client.Status==Active)
				{
					printf("Enter amount of money you want to add to this account: ");
					scanf("%d",&money);
					PCurrentClient->client.Balance +=money;
					printf("The operation has been done successfully\n");
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return;
}
void change_account_password(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	uint32 old_password,new_password;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				/*check the client id is active or not*/
				if(PCurrentClient->client.Status==Active)
				{
					printf("Enter your old password: ");
					scanf("%d",&old_password);
					/*check the client password is correct or not*/
					if(PCurrentClient->client.password == old_password)
					{
						printf("Enter your new password: ");
						scanf("%d",&new_password);
						PCurrentClient->client.password = new_password;
						printf("The password has been changed successfully\n");
					}
					else
					{
						printf("You enter a wrong password\n");
					}
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return;
}
errorStatus_t check_id(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	errorStatus_t es=E_NOK;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				es=E_OK;
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return es;
}
errorStatus_t check_password(uint32 ID)
{
	struct bankAccount *PCurrentClient=PFirstClient;
	uint32 password;
	errorStatus_t es=E_NOK;
	/*check the list is not empty*/
	if(PFirstClient)
	{
		while(PCurrentClient)
		{
			if(PCurrentClient->client.Bank_account_ID == ID)
			{
				printf("Enter the Client Account password: ");
				scanf("%d",&password);
				if(PCurrentClient->client.password == password)
				{
					es=E_OK;
				}
			}
			PCurrentClient = PCurrentClient->PNextClient;
		}
	}
	else
	{
		printf("The list is empty\n");
	}
	return es;
}
