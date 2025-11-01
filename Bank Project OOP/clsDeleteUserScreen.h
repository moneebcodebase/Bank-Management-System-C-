#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidation.h"
using namespace std;

class clsDeleteUserScreen:protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\n------------------------\n";
		cout << "\tThe User";
		cout << "\n------------------------\n";
		cout << "UserName     : " << User.UserName << endl;
		cout << "First Name   : " << User.FirstName << endl;
		cout << "Last Name    : " << User.LastName << endl;
		cout << "Email        : " << User.Email << endl;
		cout << "Phone Number : " << User.PhoneNumber << endl;
		cout << "Pasword      : " << User.Password << endl;
		cout << "Permissions  : " << User.Permissions << endl;
		cout << "------------------------\n";
	}
public:
	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");
		cout << "Enter the User name: ";
		string UserName = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User name already exists, Try another one: ";
			UserName = clsInputValidation::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);
		char Answer = 'n';

		cout << "Are you sure you want to delete this user? y/n : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			if (User.Delete())
			{
				cout << "User Deleted Seccussfully...\n\n";
				_PrintUser(User);
			}
			else
			{
				cout << "Error User was not deleted....\n";
			}
		}

	}
};

