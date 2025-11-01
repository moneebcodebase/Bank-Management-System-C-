#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidation.h"
using namespace std;
class clsFindUserScreen:protected clsScreen
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

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");
		cout << "Enter the username: ";
		string UserName = clsInputValidation::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "User does not exists, Try another one: ";
			UserName = clsInputValidation::ReadString();
		}

		clsUser User = clsUser::Find(UserName);

		if (!User.IsEmpty())
		{
			cout << "\nUser Found (:-\n";
		}
		else if(User.IsEmpty())
		{
			cout << "\nUser not Found ):-\n";
		}
		_PrintUser(User);
	}

};

