#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;

class clsAddNewClientScreen:protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "Enter First Name: ";
		Client.FirstName = clsInputValidation::ReadString();
		cout << "Enter Last Name: ";
		Client.LastName = clsInputValidation::ReadString();
		cout << "Enter Email: ";
		Client.Email = clsInputValidation::ReadString();
		cout << "Enter Phone Number: ";
		Client.PhoneNumber = clsInputValidation::ReadString();
		cout << "Enter PIN code: ";
		Client.PIN = clsInputValidation::ReadString();
		cout << "Enter Balance: ";
		Client.AccountBalance = clsInputValidation::ReadFloatNumbers();
		cout << "______________________________________\n";
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
	static void ShowAddNewClientScreen()
	{
		if (!CkeckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("Add New Client Screen");
		string AccountNumber = "";
		cout << "Please enter the account number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account number is in use, Try another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSecceesed:
		{
			cout << "\n\nClient Added Seccessfuly ....\n\n";
			_PrintClient(NewClient);
			break;
		}

		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "Erorr Clinet is not Saved Because it's Empty !!\n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "Fails, because the account is already in use.";
			break;
		}

		}

	}

};

