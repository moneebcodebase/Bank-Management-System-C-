#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidation.h"
using namespace std;


class clsDepositeScreen:protected clsScreen
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

	static void ShowDepositeScreen()
	{
		system("cls");
		_DrawScreenHeader("Deposite Screen");
		cout << "Enter the Account Number: ";
		string AccountNumber = _ReadAccountNumber();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Client with [ " << AccountNumber << " ] does not exist, Try another one: ";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
		
		double Amount = 0;
		cout << "Please enter the Deposite Amount: ";
		Amount = clsInputValidation::ReadDoubleNumbers();
		char Answer = 'n';
		cout << "\nAre sure you wan tto Deposite this Amount [" << Amount << "] ? Y/N : ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposite(Amount);
			cout << "\nAmount Deposited Seccessfuly...\n";
			cout << "New Balance is: " << Client.AccountBalance << endl;
		}
		else
		{
			cout << "Deposite is Canceled....\n";
		}



	}
	
};

