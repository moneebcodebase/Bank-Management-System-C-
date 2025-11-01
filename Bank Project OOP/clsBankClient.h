#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"clsPerson.h"
#include"clsString.h"
using namespace std;

class clsBankClient :public clsPerson
{
private:
	enum enMode { EmptyMode = 0, UpdateMode = 1 ,AddNewMode=2};
	enMode _Mode;
	string _AccountNumber;
	string _PINCode;
	float _AccountBalance;
	bool _MarkforDelete = false;

	struct stTransferLog;

	static stTransferLog _ConvertTransferLogLineToRecord(string Line,string Sparater="#//#")
	{
		stTransferLog Record;
		vector<string> vString = clsString::SpliteString(Line,Sparater);
		Record.Date_Time = vString[0];
		Record.FromAccount = vString[1];
		Record.ToAccount = vString[2];
		Record.Amount = stod(vString[3]);
		Record.s_Balance = stod(vString[4]);
		Record.d_Balance = stod(vString[5]);
		Record.User = vString[6];
		return Record;
	}

	string _PrepareTransferRecord(double Amount, clsBankClient& DestinationClient,string Sprater="#//#")
	{
		string Record = "";
		Record += clsDate::GetSystemDateTimeString() + Sprater;
		Record += GetAccountNumber() + Sprater;
		Record += DestinationClient.GetAccountNumber() + Sprater;
		Record += to_string(Amount) + Sprater;
		Record += to_string(AccountBalance) + Sprater;
		Record += to_string(DestinationClient.AccountBalance) + Sprater;
		Record += CurrentUser.UserName;
		return Record;
	}

	void _TransferLogFile(double Amount, clsBankClient& DestinationClient)
	{
		string Recoed = _PrepareTransferRecord(Amount, DestinationClient);
		fstream File;
		File.open("TransferLogFile.txt", ios::out | ios::app);
		if (File.is_open())
		{
			File << Recoed << endl;
			File.close();
		}
	}

	static clsBankClient _ConvertLineIntoClientObject(string Line, string Sparater = "#//#")
	{
		vector<string> vClient = clsString::SpliteString(Line, Sparater);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2]
			, vClient[3], vClient[4], vClient[5], stod(vClient[6]));
	}

	static string _ConvertClientObjecttoRecored(clsBankClient Client, string Sparater = "#//#")
	{
		string RecordLine = "";
		RecordLine += Client.FirstName + Sparater;
		RecordLine += Client.LastName + Sparater;
		RecordLine += Client.Email + Sparater;
		RecordLine += Client.PhoneNumber + Sparater;
		RecordLine += Client.GetAccountNumber() + Sparater;
		RecordLine += Client.PIN + Sparater;
		RecordLine += to_string(Client.AccountBalance);

		return RecordLine;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient> _LoadClientDataFromFile()
	{
		vector<clsBankClient> vClients;

		fstream File;
		File.open("Client.txt", ios::in);
		if (File.is_open())
		{
			string line = "";
			while (getline(File, line))
			{
				clsBankClient Client = _ConvertLineIntoClientObject(line);
				vClients.push_back(Client);
			}
			File.close();
		}
		return vClients;
	}

	static void _SaveClientsDatatoFile(vector<clsBankClient> vClients)
	{
		fstream File;
		File.open("Client.txt", ios::out);
		if (File.is_open())
		{
			string * Record = new string;//it's not neccary to use the memory managment because the variables is within the function scope
			for (clsBankClient& C : vClients)
			{
				if (C._MarkforDelete == false)
				{
					*Record = _ConvertClientObjecttoRecored(C);
					File << *Record << endl;
				}
			}
			delete Record;
			File.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C = *this;
				break;
			}
			
		}
		_SaveClientsDatatoFile(_vClients);
	}

	void _AddNewLinetoRecord(string Line)
	{
		fstream File;
		File.open("Client.txt", ios::out | ios::app);
		if (File.is_open())
		{
			File << Line << endl;
			File.close();
		}
	}

	void _AddNew()
	{
		_AddNewLinetoRecord(_ConvertClientObjecttoRecored(*this));
	}

public:
	clsBankClient(enMode Mode,string FirstName, string LastName, string Email, string PhoneNumber
		, string AccountNumber, string PINCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, PhoneNumber)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool MarkforDelete()
	{
		return _MarkforDelete;
	}

	string GetAccountNumber()
	{
		return _AccountNumber;
	}

	void SetPINCode(string PIN)
	{
		_PINCode = PIN;
	}
	string GetPINCode()
	{
		return _PINCode;
	}
	__declspec(property(get = GetPINCode, put = SetPINCode)) string PIN;

	void SetAccountBalance(float Balance)
	{
		_AccountBalance = Balance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	
	static clsBankClient Find(string AccountNumber)
	{
		fstream File;
		File.open("Client.txt", ios::in);
		if (File.is_open())
		{
			string Line = "";
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineIntoClientObject(Line);
				if (AccountNumber == Client.GetAccountNumber())
				{
					File.close();
					return Client;
				}
			}
			File.close();
		}

		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PIN)
	{
		vector<clsBankClient> vClients;
		fstream File;
		File.open("Client.txt", ios::in);
		if (File.is_open())
		{
			string Line = "";
			while (getline(File, Line))
			{
				clsBankClient Client = _ConvertLineIntoClientObject(Line);
				if (Client.GetAccountNumber() == AccountNumber && Client.PIN == PIN)
				{
					return Client;
					File.close();
				}
				vClients.push_back(Client);
			}
			File.close();
		}
		return _GetEmptyClientObject();
	}

	enum enSaveResults{svFaildEmptyObject=0,svSecceesed=1,svFaildAccountNumberExists=3};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:
			{
			return enSaveResults::svFaildEmptyObject;
			break;
			}
		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSecceesed;
			break;
		} 
		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSecceesed;

				break;
			}
		}

		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._MarkforDelete = true;
				break;
			}
		}
		_SaveClientsDatatoFile(_vClients);
		*this = _GetEmptyClientObject();
		return true;
	}

	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	}

	static float GetTotalBalance()
	{
		float Total = 0;
		vector<clsBankClient> _vClients;
		_vClients = _LoadClientDataFromFile();
		for (clsBankClient& C : _vClients)
		{
			Total += C.AccountBalance;
		}
		return Total;
	}

	void Deposite(double Amount)
	{
		AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > AccountBalance)
			return false;
		else
		{
			AccountBalance -= Amount;
			Save();
			return true;
		}
	}
	bool Transfer(double Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
			return false;
		else
		{
			Withdraw(Amount);
			DestinationClient.Deposite(Amount);
			_TransferLogFile(Amount, DestinationClient);
			return true;
		}
	}
	
	struct stTransferLog
	{
		string Date_Time;
		string FromAccount;
		string ToAccount;
		double Amount;
		double s_Balance;
		double d_Balance;
		string User;
	};

	static vector<stTransferLog> GetTransferLogList()
	{
		vector<stTransferLog> vTransferLogRecords;

		fstream File;
		File.open("TransferLogFile.txt", ios::in);
		if (File.is_open())
		{
			string Line = "";
			stTransferLog Record;
			while (getline(File, Line))
			{
				Record = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecords.push_back(Record);
			}
			File.close();
		}

		return vTransferLogRecords;
	}
};