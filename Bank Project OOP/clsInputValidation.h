#pragma once
#include<iostream>
#include<string>
using namespace std;

class clsInputValidation
{
public:
	static string ReadString()
	{
		string line;
		getline(cin >> ws, line);
		return line;
	}

	static bool IsNumberBetween(short Num, short Num1, short Num2)
	{
		if (Num2 > Num1)
		{
			if (Num <= Num2 && Num >= Num1)
				return true;
		}
		else if (Num1 > Num2)
		{
			if (Num <= Num1 && Num >= Num2)
				return true;
		}

		return false;
	}

	static bool IsNumberBetween(int Num, int Num1, int Num2)
	{
		if (Num2 > Num1)
		{
			if (Num <= Num2 && Num >= Num1)
				return true;
		}
		else if (Num1 > Num2)
		{
			if (Num <= Num1 && Num >= Num2)
				return true;
		}

		return false;
	}

	static bool IsNumberBetween(float Num, float Num1, float Num2)
	{
		if (Num2 > Num1)
		{
			if (Num <= Num2 && Num >= Num1)
				return true;
		}
		else if (Num1 > Num2)
		{
			if (Num <= Num1 && Num >= Num2)
				return true;
		}

		return false;
	}

	static bool IsNumberBetween(double Num, double Num1, double Num2)
	{
		if (Num2 > Num1)
		{
			if (Num <= Num2 && Num >= Num1)
				return true;
		}
		else if (Num1 > Num2)
		{
			if (Num <= Num1 && Num >= Num2)
				return true;
		}

		return false;
	}

	static int ReadIntNumbers()
	{
		int Number = 0;
		cin >> Number;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Worng Input, Please Try Again:\n";
			cin >> Number;
		}
		return Number;
	}

	static float ReadFloatNumbers()
	{
		float Num = 0;
		cin >> Num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Worng Input, Please Try Again:\n";
			cin >> Num;
		}

		return Num;
	}

	static double ReadDoubleNumbers()
	{
		double Num = 0;
		cin >> Num;
		while (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Worng Input, Please Try Again:\n";
			cin >> Num;
		}

		return Num;
	}

	static int ReadNumberBetween(int From, int To,string ErrorMessage)
	{
		int Number = 0;
		cin >> Number;
		while (cin.fail() || Number<From || Number>To)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout <<ErrorMessage;
			cin >> Number;
		}
		return Number;
	}
};