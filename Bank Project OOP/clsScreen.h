#pragma once
#include<iostream>
#include"clsUser.h"
#include"Global.h"
#include"clsDate.h"
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << setw(40) << left << " " << "--------------------------------------------\n";
		cout << setw(55) << left << " " << Title << endl;
		if(SubTitle!="")
			cout << setw(55) << left << " " << SubTitle << endl;
		cout << setw(40) << left << " " << "--------------------------------------------\n";
		cout << setw(40) << left << " " << "User: " << CurrentUser.UserName << endl;
		cout << setw(40) << left << " " << "Date: " << clsDate::DateToString(clsDate()) << endl;
		cout << setw(40) << left << " " << "--------------------------------------------\n";
	}
	static bool CkeckAccessRights(clsUser::enPermissions Permiossion)
	{
		if (!CurrentUser.CkeckAccessPermisions(Permiossion))
		{
			cout << "\t\t\t------------------------------------------------------\n";
			cout << "\t\t\t\tAccess Denied, Please Contact your Admin....\n";
			cout << "\t\t\t------------------------------------------------------\n";
			return false;
		}
		else
			return true;
	}
};

