#pragma once
#include<iostream>
#include<cstdlib>
#include"clsDate.h"
using namespace std;

class clsUtil
{
public:

	enum enCharacterType { Cabtel = 1, Small, Digit, Sympol, Mix };

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	static int RandomNumbers(int From, int To)
	{
		return rand() % (To - From + 1) + From;
	}

	static string Encryption(string Line)
	{
		string EncryptedLine = "";
		for (int i = 0; i < Line.length(); i++)
		{
			EncryptedLine += char(int(Line[i]) + 2);
		}
		return EncryptedLine;
	}
	static string Decryption(string Line)
	{
		string DecryptedLine = "";
		for (int i = 0; i < Line.length(); i++)
		{
			DecryptedLine += char(int(Line[i]) - 2);
		}
		return DecryptedLine;
	}

	static string Encryption(string Line, int EncryptionCode)
	{
		
		for (int i = 0; i < Line.length(); i++)
		{
			Line[i] = char(int(Line[i]) + EncryptionCode);
		}
		return Line;
	}
	static string Decryption(string Line, int DecryptionCode)
	{
		for ( int i = 0; i < Line.length();i++)
		{
			Line[i] = char(int(Line[i]) - DecryptionCode);
		}
		return Line;
	}

	static char RandomCharacter(enCharacterType Character)
	{
		if (Character == enCharacterType::Mix)
		{
			Character = (enCharacterType)RandomNumbers(1, 4);
		}
		switch (Character)
		{
		case enCharacterType::Cabtel:
		{
			return char(RandomNumbers(65, 90));
			break;
		}
		case enCharacterType::Small:
		{
			return char(RandomNumbers(97, 122));
			break;
		}
		case enCharacterType::Digit:
		{
			return char(RandomNumbers(48, 57));
			break;
		}
		case enCharacterType::Sympol:
		{
			return char(RandomNumbers(33, 47));
			break;
		}
		}
	}

	static string GenarateWord(enCharacterType Type, short NumberofLetters)
	{
		string Word = "";

		for (short i = 1; i <= NumberofLetters; i++)
		{
			Word += RandomCharacter(Type);
		}
		return  Word;
	}
	static string GenarateOneKey(enCharacterType Type, short NumberofLetters, short NumberofWords)
	{
		string Key = "";

		for (short i = 1; i <= NumberofWords; i++)
		{
			if (i == NumberofWords)
				Key += GenarateWord(Type, NumberofLetters);
			else
				Key += GenarateWord(Type, NumberofLetters) + " ";
		}
		return Key;
	}
	static void GenarateKeys(enCharacterType Type, short NumberofKeys, short NumberofLetters, short NumberofWords)
	{
		for (short i = 1; i <= NumberofKeys; i++)
		{
			cout << "Key [" << i << "] : " << GenarateOneKey(Type, NumberofLetters, NumberofWords) << endl;
		}
	}

	static void FillArrayWithRandomNumbers(int Arr[100], short Length, short From, short To)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = RandomNumbers(From, To);
		}
	}
	static void FillArrayWithRandomWords(string Arr[100], short Length, enCharacterType Type, short NumberofLetters)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = GenarateWord(Type, NumberofLetters);
		}
	}
	static void FillArrayWithRandomKeys(string Arr[100], short Length, enCharacterType Type, short NumberofLetters, short NumberofWords)
	{
		for (short i = 0; i < Length; i++)
		{
			Arr[i] = GenarateOneKey(Type, NumberofLetters, NumberofWords);
		}
	}
	static void ShuffleArray(int Arr[100], short Length)
	{
		for (int i = 0; i < Length; i++)
		{
			Swap(Arr[RandomNumbers(1, Length) - 1], Arr[RandomNumbers(1, Length) - 1]);
		}

	}

	static void Swap(int& A, int& B)
	{
		int* P = new int;
		*P = B;
		B = A;
		A = *P;
		delete P;
	}
	static void Swap(float& A, float& B)
	{
		float* P = new float;
		*P = B;
		B = A;
		A = *P;
		delete P;
	}
	static void Swap(double& A, double& B)
	{
		double* P = new double;
		*P = B;
		B = A;
		A = *P;
		delete P;
	}
	static void Swap(string& A, string& B)
	{
		string* P = new string;
		*P = B;
		B = A;
		A = *P;
		delete P;
	}
	static void Swap(char& A, char& B)
	{
		char* P = new char;
		*P = B;
		B = A;
		A = *P;
		delete P;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
			return "Zero";

		if (Number >= 1 && Number <= 19)
		{
			string Arr[]{ "","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twoelve",
			"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Ninteen" };
			for (int i = 0; i < 19; i++)
			{
				if (i == Number)
					return Arr[i];
			}
		}

		if (Number >= 20 && Number <= 99)
		{
			string Arr2[]{ "","","Twenty","Therty","Fourty","Fifty","Sixty","Seventy","Eighty","Ninty" };
			for (short i = 0; i < 9; i++)
			{
				if (i == (Number / 10))
					return Arr2[i] + " " + NumberToText(Number % 10);
			}
		}

		if (Number >= 100 && Number <= 199)
			return "One Hundred " + NumberToText(Number % 100);

		if (Number >= 200 && Number <= 999)
			return NumberToText(Number / 100) + " Hundred " + NumberToText(Number % 100);

		if (Number >= 1000 && Number <= 1999)
			return "One Thousend " + NumberToText(Number % 1000);

		if (Number >= 2000 && Number <= 999999)
			return NumberToText(Number / 1000) + " Thousend " + NumberToText(Number % 1000);

		return "";
	}

	static string Taps(short NumberofTaps)
	{
		for (short i = 1; i <= NumberofTaps; i++)
		{
			cout << "\t";
		}
	}
};