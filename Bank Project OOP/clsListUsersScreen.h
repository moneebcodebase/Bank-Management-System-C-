#pragma once
#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"
using namespace std;

class clsListUsersScreen:protected clsScreen
{
private:
	static void _PrintUserRecordLine(clsUser User)
	{
		cout << "| " << left << setw(15) << User.UserName;
		cout << "| " << left << setw(20) << User.GetFullName();
		cout << "| " << left << setw(20) << User.PhoneNumber;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(14) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions;

	}
public:

	static void ShowUsersListScreen()
	{

		
		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "Users List Screen";
		string SubTitle = "(" + to_string(vUsers.size()) + ") Users(s).";

		_DrawScreenHeader(Title, SubTitle);
		cout << "\n----------------------------------------------------------------";
		cout << "------------------------------------------------\n";
		cout << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(20) << "Phone Number";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(14) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << "\n----------------------------------------------------------------";
		cout << "------------------------------------------------\n";
		if (vUsers.size() == 0)
			cout << "\t\t\t\t NO Users AVALIABLE IN THE SYSTEM!";
		else
			for (clsUser& C : vUsers)
			{
				_PrintUserRecordLine(C);
				cout << endl;
			}
		cout << "\n----------------------------------------------------------------";
		cout << "------------------------------------------------\n";
	}
};

