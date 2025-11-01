#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
class clsFindClientScreen: protected clsScreen
{
private:
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
	static void ShowFindClientScreen()
	{
		if (!CkeckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
		_DrawScreenHeader("Find Client Screen");
		string AccountNumber = "";
		cout << "Please enter the Account Number: ";
		AccountNumber = clsInputValidation::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account number not found, Please enter another one: ";
			AccountNumber = clsInputValidation::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (!Client.IsEmpty())
			cout << "\nClient is found (:-\n\n";
		else
			cout << "\nClient not found ):-\n\n";

		_PrintClient(Client);
	}

};

