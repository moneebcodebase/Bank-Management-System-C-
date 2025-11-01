#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsUser.h"
#include"Global.h"

using namespace std;
class clsShowClientListScreen:protected clsScreen
{
private:
	
	static void _PrintClientRecordLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.GetAccountNumber();
		cout << "| " << left << setw(20) << Client.GetFullName();
		cout << "| " << left << setw(12) << Client.PhoneNumber;
		cout << "| " << left << setw(20) << Client.Email;
		cout << "| " << left << setw(10) << Client.PIN;
		cout << "| " << left << setw(12) << Client.AccountBalance;

	}
public:
	static void ShowClientsList()
	{
		if (!CkeckAccessRights(clsUser::enPermissions::pShowClientLinst))
		{
			return;
		}

		vector<clsBankClient> vClients = clsBankClient::GetClientsList();

		string Title = "Client List Screen";
		string SubTitle = "(" + to_string(vClients.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);
		cout <<"\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout  << "| " << left << setw(20) << "Client Name";
		cout  << "| " << left << setw(12) << "Phone Number";
		cout  << "| " << left << setw(20) << "Email";
		cout  << "| " << left << setw(10) << "PIN";
		cout  << "| " << left << setw(12) << "Balance";
		cout  << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		if (vClients.size() == 0)
			cout << "\t\t\t\t NO CLIENTS AVALIABLE IN THE SYSTEM!";
		else
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordLine(C);
				cout << endl;
			}
		cout << "----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
	}
};

