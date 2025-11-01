#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidation.h"

class clsTransferScreen: protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "______________________________\n";
		cout << "\tClient Card.\n";
		cout << "------------------------------\n";
		cout << "Full Name  : " << Client.GetFullName() << endl;
		cout << "Acc.Number : " << Client.GetAccountNumber() << endl;
		cout << "Balance    : " << Client.AccountBalance << endl;
		cout << "______________________________\n";

	}

public:
	static void ShowTransferScreen()
	{
		string AccountNumber = "";
		_DrawScreenHeader("Transfer Screen");
		
		cout << "Please enter the Account Number to Transfer From: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client Does not Exists, Please enter another Account Number: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient FromClient = clsBankClient::Find(AccountNumber);
		_PrintClient(FromClient);

		cout << "\nPlease enter the Account Number to Transfer To: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client Does not Exists, Please enter another Account Number: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient ToClient = clsBankClient::Find(AccountNumber);
		_PrintClient(ToClient);

		double Amount = 0;
		cout << "Please enter the Amount: ";
		Amount = clsInputValidation::ReadDoubleNumbers();
		

		char Answer = 'n';
		cout << "\nAre you sure you want to do this Transfer? Y/N: ";
		cin >> Answer;
		
		if (Answer == 'Y' || Answer == 'y')
		{
			if (FromClient.Transfer(Amount, ToClient))
			{
				cout << "\nTransfer Done Seccessfully...\n";
			}
			else
			{
				cout << "\nTransfer Faild...\n";
			}
		}
		_PrintClient(FromClient);
		_PrintClient(ToClient);
	}
};

