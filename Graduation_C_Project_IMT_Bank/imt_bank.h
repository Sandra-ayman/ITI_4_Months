/*
 * imt_bank.h
 *
 *  Created on: Dec 25, 2022
 *      Author: 20109
 */

#ifndef IMT_BANK_H_
#define IMT_BANK_H_
/*----------New data types----------*/
typedef enum{Active,Restricted,Closed}accountStatus_t;
typedef enum{E_OK,E_NOK}errorStatus_t;
typedef struct
{
	uint8 Full_Name[100];
	uint8 Address[100];
	uint8 National_ID[15];
	uint32 Age;
	uint32 Bank_account_ID;
	uint8 Guardian[100];
	uint8 Guardian_ID[15];
	uint8 Status;
	uint32 Balance;
	uint16 password;
}clientData_t;
/*----------Linked List for Bank Account----------*/
struct bankAccount
{
	clientData_t client;
	struct bankAccount *PNextClient;
};
/*----------APIs----------*/
/*
 * function description: create new bank account (Admin only)
 * return: nothing
 * parameters: take nothing
 */
void create_account(void);
/*
 * function description: make a transaction ( Admin and client can use it)
 * return: nothing
 * parameters: take the bank account id
 */
void make_transaction(uint32 ID);
/*
 * function description: change the account status (Admin only)
 * return: nothing
 * parameters: take the bank account id
 */
void change_account_status(uint32 ID);
/*
 * function description: get cash from account ( Admin and client can use it)
 * return: nothing
 * parameters: take the bank account id
 */
void get_cash(uint32 ID);
/*
 * function description: deposit account ( Admin and client can use it)
 * return: nothing
 * parameters: take the bank account id
 */
void deposit_in_account(uint32 ID);
/*
 * function description: change the account password (client only)
 * return: nothing
 * parameters: take the bank account id
 */
void change_account_password(uint32 ID);
/*
 * function description: view bank account states (for checking the progress)
 * return: nothing
 * parameters: take nothing
 */
void view_bank_accounts(void);
/*
 * function description: check the client id
 * return: the id is correct or not
 * parameters: take the id number
 */
errorStatus_t check_id(uint32 ID);
/*
 * function description: check the client id
 * return: the password is correct or not
 * parameters: take the id number
 */
errorStatus_t check_password(uint32 ID);
#endif /* IMT_BANK_H_ */
