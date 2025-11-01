#pragma once
#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidation.h"
using namespace std;
class clsUpdateUserScreen:protected clsScreen
{
private:
	static int _ReadPermissions()
	{
		char Answer = 'n';
		int Permission = 0;
		cout << "\nDo you want this user to have full permission? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			return -1;
		}


		cout << "\n Do you want this user to have permission to:\n\n";
		cout << "Show Clinet List? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pShowClientLinst;
		}

		cout << "Add New Clients? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pAddNewClient;
		}

		cout << "Delete Clients? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pDeleteClient;
		}


		cout << "Update Clients? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pUpdateClient;
		}

		cout << "Find Clients? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pFindClient;
		}

		cout << "Do Transactions? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pTransactions;
		}

		cout << "Manage Users? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pManageUsers;
		}

		cout << "Show Login Register? Y/N : ";
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			Permission += clsUser::enPermissions::pLoginRegister;
		}

		return Permission;
	}
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "Enter First Name: ";
		User.FirstName = clsInputValidation::ReadString();
		cout << "Enter Last Name: ";
		User.LastName = clsInputValidation::ReadString();
		cout << "Enter Email: ";
		User.Email = clsInputValidation::ReadString();
		cout << "Enter Phone Number: ";
		User.PhoneNumber = clsInputValidation::ReadString();
		cout << "Enter the Password: ";
		User.Password = clsInputValidation::ReadString();
		cout << "\nUser Permissions:\n";
		User.Permissions = _ReadPermissions();
	}
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
	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");
		cout << "Enter the Username: ";
		string UserName = clsInputValidation::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "Username does not exists, Try another one: ";
			UserName = clsInputValidation::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUser(User);

		char Answer = 'n';
		cout << "\nAre you sure you want to update this user? y/n : ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\n------------------------\n";
			cout << "Enter The User Info:";
			cout << "\n------------------------\n";
			_ReadUserInfo(User);
			clsUser::enSaveResult SaveResult;
			SaveResult = User.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResult::svSeccussed:
			{
				cout << "User is Updated...";
				_PrintUser(User);
				break;
			}
			case clsUser::enSaveResult::svFaildEmptyOpject:
			{
				cout << "User is not updated, Empty ..";
				break;
			}
			case clsUser::enSaveResult::svFaildUserExists:
			{
				cout << "User is not updated, User already exists..";
				break;
			}
			}
		}

	}

};

