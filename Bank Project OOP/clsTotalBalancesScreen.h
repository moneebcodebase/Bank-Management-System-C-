#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include "clsBankClient.h"
#include"clsUtil.h"
using namespace std;
class clsTotalBalancesScreen:protected clsScreen
{
private:
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << "| " << left << setw(15) << Client.GetAccountNumber();
		cout << "| " << left << setw(20) << Client.GetFullName();
		cout << "| " << left << setw(12) << Client.AccountBalance;
	}
public:
	static void ShowTotalBalancesScreen()
	{
		vector<clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "Total Balances Screen";
		string SubTitle = "( " + to_string(vClients.size()) + " ) Client's";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		cout << "| " << left << setw(15) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		float TotalBalance = clsBankClient::GetTotalBalance();

		if (vClients.size() == 0)
			cout << "\t\t\t\t NO CLIENTS AVALIABLE IN THE SYSTEM!";
		else
			for (clsBankClient& C : vClients)
			{
				_PrintClientRecordBalanceLine(C);
				cout << endl;
			}
		cout << "----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		cout << "\t\t\t\t\t   Total Balance: " << TotalBalance << endl;
		cout << "\t\t\t\t\t   (" << clsUtil::NumberToText(int(TotalBalance)) << ")" << endl;
	}
};

