#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsString.h"
#include"clsPerson.h"
#include"clsDate.h"
#include"clsUtil.h"
using namespace std;

class clsUser:public clsPerson
{
private:
	enum enMode { eEmptyMode = 0,eUpdateMode=1,eAddNewMode=2 };
	enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions;
	bool _MarkForDelete = false;

	string _PrepareLoginRecord(string Sparater = "#//#")
	{
		string LoginRecoed = "";
		LoginRecoed += clsDate::GetSystemDateTimeString() + Sparater;
		LoginRecoed += UserName + Sparater;
		LoginRecoed += clsUtil::Encryption(Password,6) + Sparater;
		LoginRecoed += to_string(_Permissions);
		return LoginRecoed;
	}

	static clsUser _CovertLineIntoUserObject(string Line, string Sperator = "#//#")
	{
		vector<string> vUser = clsString::SpliteString(Line, Sperator);

		return clsUser(enMode::eUpdateMode, vUser[0], vUser[1], vUser[2], vUser[3]
			, vUser[4], clsUtil::Decryption(vUser[5],6), stoi(vUser[6]));
	}

	static string _ConvertUserObjectIntoRecord(clsUser User, string Sperator = "#//#")
	{
		string RecordLine = "";
		RecordLine += User.FirstName + Sperator;
		RecordLine += User.LastName + Sperator;
		RecordLine += User.Email + Sperator;
		RecordLine += User.PhoneNumber + Sperator;
		RecordLine += User.UserName + Sperator;
		RecordLine += clsUtil::Encryption(User.Password,6) + Sperator;
		RecordLine += to_string(User.Permissions);
		return RecordLine;
	}

	struct stLoginRegisterRecord; //this is a declaration for the structur

	static stLoginRegisterRecord _ConvertLoginRgisterLinetoRecord(string Line,string Sparater="#//#")
	{
		stLoginRegisterRecord LoginRegisterRecord;
		vector<string> vString = clsString::SpliteString(Line, Sparater);

		LoginRegisterRecord.DateTime = vString[0];
		LoginRegisterRecord.UserName = vString[1];
		LoginRegisterRecord.PassWord = clsUtil::Decryption(vString[2],6);
		LoginRegisterRecord.Permisstion = stoi(vString[3]);

		return LoginRegisterRecord;

	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::eEmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser> _LoadUsersDataFromFile()
	{
		vector<clsUser> _Users;
		fstream File;
		File.open("Users.txt", ios::in);
		if (File.is_open())
		{
			string Line;
			while (getline(File, Line))
			{
				clsUser User = _CovertLineIntoUserObject(Line);
				_Users.push_back(User);
			}
			File.close();
		}
		return _Users;
	}

	static void _SaveUsersDataToFile(vector<clsUser> vUsers)
	{
		fstream File;
		File.open("Users.txt", ios::out);
		if (File.is_open())
		{
			string* Record = new string; //it's not neccary to use the memory managment because the variables is within the function scope
			for (clsUser& U : vUsers)
			{
				if (U._MarkForDelete == false)
				{
					*Record = _ConvertUserObjectIntoRecord(U);
					File << *Record << endl;
				}
			}
			delete Record;
			File.close();
		}
	}

	void _Update()
	{
		vector<clsUser> _vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : _vUsers)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
	}

	void _AddNewLinetoRecord(string Line)
	{
		fstream File;
		File.open("Users.txt", ios::out | ios::app);
		if (File.is_open())
		{
			File << Line << endl;
			File.close();
		}
	}

	void _AddNew()
	{
		_AddNewLinetoRecord(_ConvertUserObjectIntoRecord(*this));
	}

public:

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string PhoneNumber,
		string UserName, string Password, int Permissions) :clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	enum enPermissions{pAll=-1,pShowClientLinst=1,pAddNewClient=2,pDeleteClient=4,
	pUpdateClient=8,pFindClient=16,pTransactions=32,pManageUsers=64,pLoginRegister=128};

     struct stLoginRegisterRecord
	{
		string DateTime;
		string UserName;
		string PassWord;
		int Permisstion;
	};

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	string GetPassword()
	{
		return _Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	bool MarkForDelete()
	{
		return _MarkForDelete;
	}

	static bool IsUserExist(string UserName)
	{
		clsUser Client = Find(UserName);
		return (!Client.IsEmpty());
	}

	static clsUser Find(string UserName)
	{
		fstream File;
		File.open("Users.txt", ios::in);
		if (File.is_open())
		{
			string Line = "";
			while (getline(File, Line))
			{
				clsUser User = _CovertLineIntoUserObject(Line);
				if (User._UserName == UserName)
				{
					File.close();
					return User;
				}
			}
		}

		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName,string Password)
	{
		fstream File;
		File.open("Users.txt", ios::in);
		if (File.is_open())
		{
			string Line = "";
			while (getline(File, Line))
			{

				clsUser User = _CovertLineIntoUserObject(Line);

				if (User.UserName == UserName && User.Password == Password)
				{
					File.close();
					return User;
				}
			}
		}

		return _GetEmptyUserObject();
	}

	enum enSaveResult{svFaildEmptyOpject=0,svSeccussed,svFaildUserExists};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::eEmptyMode:
		{
			return enSaveResult::svFaildEmptyOpject;
			break;
		}
		case enMode::eUpdateMode:
		{
			_Update();
			return enSaveResult::svSeccussed;
			break;
		}
		case enMode::eAddNewMode:
		{
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResult::svFaildUserExists;
				break;
			}
			else
			{
				_AddNew();
				_Mode = enMode::eUpdateMode;
				return enSaveResult::svSeccussed;
				break;
			}
		}
		}
	}

	static clsUser GetAddNewUserObject(string UserName)
	{
		return clsUser(enMode::eAddNewMode, "", "", "", "", UserName, "", 0);
	}

	bool Delete()
	{
		vector<clsUser> _vUsers = _LoadUsersDataFromFile();
		for (clsUser& U : _vUsers)
		{
			if (U.UserName == UserName)
			{
				U._MarkForDelete = true;
				break;
			}
		}
		_SaveUsersDataToFile(_vUsers);
		*this = _GetEmptyUserObject();
		return true;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUsersDataFromFile();
	}

	bool CkeckAccessPermisions(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::pAll)
			return true;

		if ((Permission & this->Permissions) == Permission)
			return true;
		else
			return false;
	}

	void RegisterLogIn()
	{
		string RecordLine = _PrepareLoginRecord();
		fstream File;
		File.open("LoginRegister.txt", ios::out | ios::app);
		if (File.is_open())
		{
			File << RecordLine << endl;

			File.close();
		}
	}

	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord> vLoginRegisterRecord;

		fstream File;
		File.open("LoginRegister.txt", ios::in);
		if (File.is_open())
		{
			string Record;
			while (getline(File, Record))
			{
				stLoginRegisterRecord LoginRecord = _ConvertLoginRgisterLinetoRecord(Record);

				vLoginRegisterRecord.push_back(LoginRecord);
			}
			File.close();
		}
		return vLoginRegisterRecord;
	}
};

