#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"vector"
using namespace std;

class clsLoginRegisterScreen:protected clsScreen
{
private:

	static void _PrintLoginRegisterLine(clsUser::stLoginRegisterRecord Record)
	{
		cout << "| " << left << setw(25) << Record.DateTime;
		cout << "| " << left << setw(20) << Record.UserName;
		cout << "| " << left << setw(20) << Record.PassWord;
		cout << "| " << left << setw(20) << Record.Permisstion;
	}
public:
	static void ShowLoginRegisterScreen()
	{

		if (!CkeckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector<clsUser::stLoginRegisterRecord> vLoginRegisterRecords = clsUser::GetLoginRegisterList();
		string Title = "Login Register Screen";
		string SubTitle = "( " + to_string(vLoginRegisterRecords.size())+ " ) Registers";
		_DrawScreenHeader(Title, SubTitle);
		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		cout << "| " << left << setw(25) << "Date & Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(20) << "Permissions";
		cout << "\n----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
		if (vLoginRegisterRecords.size() == 0)
			cout << "\t\t\t\t NO RECORDS AVALIABLE IN THE SYSTEM!";
		else
			for (clsUser::stLoginRegisterRecord &Record : vLoginRegisterRecords)
			{
				_PrintLoginRegisterLine(Record);
				cout << endl;
			}
		cout << "----------------------------------------------------------------";
		cout << "-------------------------------------------\n";
	}
};

