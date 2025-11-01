#pragma once
#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidation.h"
#include"clsUser.h"
using namespace std;
class clsDeleteClientScreen:protected clsScreen
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
	static void ShowDeleteClientScreen()
	{
		if (!CkeckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}
		_DrawScreenHeader("Delete Client Screen");

			string AccountNumber = "";
			cout << "Please enter the account number: ";
			AccountNumber = clsInputValidation::ReadString();
			while (!clsBankClient::IsClientExist(AccountNumber))
			{
				cout << "Account number not found, Try another one: ";
				AccountNumber = clsInputValidation::ReadString();
			}
			clsBankClient Client = clsBankClient::Find(AccountNumber);
			_PrintClient(Client);
			char Answer = 'n';
			cout << "Are you sure you want to delete this client? Y/N : ";
			cin >> Answer;
			if (Answer == 'Y' || Answer == 'y')
			{
				if (Client.Delete())
				{
					cout << "Client is Deleted....\n";
					_PrintClient(Client);
				}
				else
				{
					cout << "Client was not deleted....\n";
				}
			}
	}
};

