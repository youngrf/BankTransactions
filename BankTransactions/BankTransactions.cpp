// BankTransactions.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;


#define MAX_ENTRIES 100

//Function declarations
void getBeginningBalance(float *begBalance);
void getDeposit(float *deposit);
void getWithdrawal(float *withdrawal);
void getTotalcheck(float *check);

void initialize_arrays(float *withdrawal, float *deposit, float *check);

void totalWithdrawals(float *totalWithdrawal, float *withdrawal);
void totalDeposits(float *totalDeposit, float *deposit);
void totalChecks(float *totalCheck, float *deposit);

int main(int argc, char *argv[])
{
	//Variable declarations
	float		beginning_balance = 0;
	float		ending_balance = 0;

	float		withdrawal[MAX_ENTRIES];
	float		deposit[MAX_ENTRIES];
	float		check[MAX_ENTRIES];

	int			withdrawal_index = 0;
	int			deposit_index = 0;
	int			check_index = 0;

	float		total_withdrawals = 0;
	float		total_deposit = 0;
	float		total_checks = 0;

	char		inputChar = ' ';
	int			i;

	initialize_arrays(&withdrawal[0], &deposit[0], &check[0]);


	getBeginningBalance(&beginning_balance); //Calls beginning balance function
	cout << "Beginning balance is: " << beginning_balance << endl << endl;


	cout << endl << "Enter transactions:" << endl;
	cout << "------------------" << endl;
	while (inputChar != 'Q' && inputChar != 'q') //Loop for user transaction inputs

	{
		cout << "(W)ithdrawal (D)eposit (C)heck (Q)uit : ";
		cin >> inputChar;

		//Force user to input certain chars
		if (inputChar != 'C' && inputChar != 'c' && inputChar != 'Q' && inputChar != 'q' &&
			inputChar != 'D' && inputChar != 'd' && inputChar != 'W' && inputChar != 'w')
		{
			//cout << "Must enter valid response:" << endl;
			cout << "Invalid option.  Please try again..." << endl;
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
			continue;
		}

		//if(isalpha('W') && (isalpha('Q') && (isalpha('D') && (isalpha('C') 
		//&& (isalpha('w') && (isalpha('q') && (isalpha('d') && (isalpha('c')))))))))

		//if (!((inputChar >= 'a' && inputChar <= 'z') || (inputChar >= 'A' && inputChar <= 'Z')))
		//cout << "error" << endl;

		if (inputChar == 'D' || inputChar == 'd') //Calls deposit function
		{
			getDeposit(&deposit[deposit_index]);
			//total_deposit = total_deposit + deposit[deposit_index];
			deposit_index++;
		}

		else if (inputChar == 'W' || inputChar == 'w') //Calls withdrawal function
		{
			getWithdrawal(&withdrawal[withdrawal_index]);
			//total_withdrawals = total_withdrawals + withdrawal[withdrawal_index];
			withdrawal_index++;
		}

		else if (inputChar == 'C' || inputChar == 'c') //Calls check function
		{
			getTotalcheck(&check[check_index]);
			//total_checks = total_checks + check[check_index];
			check_index++;
		}

	}


	//Calculations

	cout << endl << "Transaction Summary:" << endl;
	cout << "-------------------" << endl;
	cout << "    " << "Beginning Balance: " << beginning_balance << endl << endl;

	totalDeposits(&total_deposit, &deposit[0]);
	totalWithdrawals(&total_withdrawals, &withdrawal[0]);
	totalChecks(&total_checks, &check[0]);

	cout << endl;
	ending_balance = beginning_balance + total_deposit + total_checks - total_withdrawals;

	cout << "-------------------" << endl;
	cout << "    " << "Ending Balance:    " << ending_balance << endl;

}

//Function definitions -- passes user input by pointer reference
void initialize_arrays(float *withdrawal, float *deposit, float *check)
{
	int			i;

	for (i = 0; i<MAX_ENTRIES; i++)		// initialize all to -1
	{
		*withdrawal = -1;
		withdrawal++;

		*deposit = -1;
		deposit++;

		*check = -1;
		check++;
	}

} // END: initialize_arrays()

void getDeposit(float *deposit)
{
	float y;
	cout << "Please enter amount for deposit: ";

	while (!(cin >> y)) //Error check user input
	{
		cout << "Must enter a number:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}

	*deposit = y;
}


void getBeginningBalance(float *begBalance)
{
	float y;
	cout << "Please enter account balance: ";

	while (!(cin >> y)) //Error check user input
	{
		cout << "Must enter a number:";
		cin.clear();
		cin.ignore(100, '\n');
	}

	*begBalance = y;
}


void getWithdrawal(float *withdrawal)
{
	float y;
	cout << "Please enter withdrawals: ";

	while (!(cin >> y)) //Error check user input
	{
		cout << "Must enter a number:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}

	*withdrawal = y;
}

void getTotalcheck(float *check)
{
	float y;
	cout << "Please enter check: ";
	while (!(cin >> y)) //Error check user input
	{
		cout << "Must enter a number:" << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}

	*check = y;
}

void totalWithdrawals(float *totalWithdrawal, float *withdrawal)
{
	*totalWithdrawal = 0;

	cout << "* Withdrawals:" << endl;
	while (*withdrawal != -1)
	{
		cout << "                         " << *withdrawal << endl;
		*totalWithdrawal = *totalWithdrawal + *withdrawal;
		withdrawal++;
	}
	cout << "                ________ " << endl;
	cout << "                " << *totalWithdrawal << endl;
}

void totalDeposits(float *totalDeposit, float *deposit)
{
	*totalDeposit = 0;

	cout << "* Deposits:" << endl;
	while (*deposit != -1)
	{
		cout << "                         " << *deposit << endl;
		*totalDeposit = *totalDeposit + *deposit;
		deposit++;
	}
	cout << "                ________ " << endl;
	cout << "                " << *totalDeposit << endl;
}


void totalChecks(float *totalChecks, float *check)
{
	*totalChecks = 0;

	cout << "* Checks:" << endl;
	while (*check != -1)
	{
		cout << "                            " << *check << endl;
		*totalChecks = *totalChecks + *check;
		check++;
	}
	cout << "                 ________" << endl;
	cout << "                 " << *totalChecks << endl;
}