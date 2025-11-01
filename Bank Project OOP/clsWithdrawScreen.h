#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include"clsInputValidation.h"

using namespace std;

class clsWithdrawScreen:protected clsScreen
{
private:
	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		AccountNumber = clsInputValidation::ReadString();
		return AccountNumber;
	}
	static void _PrintClient(clsBankClient Client)
	{
		cout << "--------------------------------------\n";
		cout << "\t\tClient Card\n";
		cout << "______________________________________\n";
		cout << "First Name      : " << Client.FirstName << endl;
		cout << "Last Name       : " << Client.LastName << endl;
		cout << "Full Name       : " << Client.FirstName << " " << Client.LastName << endl;
		cout << "Email           : " << Client.Email << endl;
		cout << "Phone Number    : " << Client.PhoneNumber << endl;
		cout << "Account Number  : " << Client.GetAccountNumber() << endl;
		cout << "Password        : " << Client.PIN << endl;
		cout << "Account Balance : " << Client.AccountBalance << endl;
		cout << "______________________________________\n";
	}
public:
	static void ShowWithdrawScreen()
	{
		system("cls");
		_DrawScreenHeader("Withdraw Screen");
		cout << "Please enter the Account Number: ";
		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with [ " << AccountNumber << " ] Does not exsist,try again: ";
			AccountNumber = _ReadAccountNumber();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "Please enter the Amount: ";
		Amount = clsInputValidation::ReadDoubleNumbers();
		char Answer = 'n';
		cout << "Are you sure  you want to withdraw [ " << Amount<<" ] Y/N: ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			if (Client.Withdraw(Amount))
			{
				cout << "Wothdraw Secceded...\n";
				cout << "New Balance is : " << Client.AccountBalance << endl;
			}
			else
			{
				cout << "Withdraw Failed...\n";
				cout << "The Wihdraw amount is: " << Amount << endl;
				cout << "The Acount Balance is: " << Client.AccountBalance << endl;
			}
		}

	}
};

