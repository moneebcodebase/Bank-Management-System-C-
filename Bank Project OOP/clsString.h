#pragma once
#include<iostream>
#include<cctype>
#include<vector>
using namespace std;



class clsString
{
private:
	string _Value;
public:
	//Constructer
	clsString(string Value)
	{
		_Value = Value;
	}
	clsString()
	{
		_Value = "";
	}

	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}
	__declspec(property(get = GetValue, put = SetValue)) string Value;



	static short CountCharacter(string Line)
	{
		return Line.length();
	}
	short CountCharacter()
	{
		return CountCharacter(_Value);
	}

	static short CountLetters(string Line)
	{
		short Counter = 0;
		for (char& Letter : Line)
		{
			if (!(isdigit(Letter) || ispunct(Letter)))
			{
				if (Letter != ' ')
					Counter++;
			}
		}
		return Counter;
	}
	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static short CountNumbers(string Line)
	{
		short Counter = 0;
		for (char& Letter : Line)
		{
			if (isdigit(Letter))
				Counter++;
		}
		return Counter;
	}
	short CountNumbers()
	{
		return CountNumbers(_Value);
	}

	static short CountVowels(string Line)
	{
		short Counter = 0;
		for (char& Car : Line)
		{
			if (toupper(Car) == toupper('a') || toupper(Car) == toupper('e') || toupper(Car) == toupper('u')
				|| toupper(Car) == toupper('i') || toupper(Car) == toupper('o'))
			{
				Counter++;
			}
		}
		return Counter;
	}
	short CountVowels()
	{
		return CountVowels(_Value);
	}

	static short CountPunctutions(string Line)
	{
		short Counter = 0;
		for (char& Letter : Line)
		{
			if (ispunct(Letter))
				Counter++;
		}
		return Counter;
	}
	short Countpunctutions()
	{
		return CountPunctutions(_Value);
	}

	enum enMatchcase { Cabital = 1, Small, All };
	static short CountSpecificLetter(string Line, char Letter, enMatchcase Matchcase = enMatchcase::All)
	{
		short Counter = 0;
		if (Matchcase == enMatchcase::All)
		{
			for (char& L : Line)
			{
				if (L == toupper(Letter))
					Counter++;

			}
			return Counter;
		}
		else if (Matchcase == enMatchcase::Small)
		{
			for (char& L : Line)
			{
				if (L == tolower(Letter))
					Counter++;

			}
			return Counter;

		}
		else
		{
			for (char& L : Line)
			{
				if (L == toupper(Letter))
					Counter++;

			}
			return Counter;

		}

	}
	short CountSpecificLetter(char Letter, enMatchcase Matchcase = enMatchcase::All)
	{
		return CountSpecificLetter(_Value, Letter, Matchcase);
	}

	static short CountCabitaleLetters(string Line)
	{
		short Counter = 0;
		for (char& Letter : Line)
		{
			if (isupper(Letter))
				Counter++;
		}
		return Counter;
	}
	short CountCabitaleLetters()
	{
		return CountCabitaleLetters(_Value);
	}

	static short CountSmallLetters(string Line)
	{
		short Counter = 0;
		for (char& Letter : Line)
		{
			if (islower(Letter))
				Counter++;
		}
		return Counter;
	}
	short CountSmallLetters()
	{
		return CountSmallLetters(_Value);
	}

	static short CountWords(string Line, string Dilem = " ")
	{
		string OneWord = "";
		short pos = 0;
		short Counter = 0;
		while ((pos = Line.find(Dilem)) != std::string::npos)
		{
			OneWord = Line.substr(0, pos);
			if (OneWord != "")
			{
				Counter++;
			}
			Line.erase(0, pos + Dilem.length());
		}
		if (Line != "")
		{
			Counter++;
		}
		return Counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static vector<string> SpliteString(string Line, string Dilem = " ")
	{
		vector<string> vString;
		short pos = 0;
		string OneWord = "";
		while ((pos = Line.find(Dilem)) != std::string::npos)
		{
			OneWord = Line.substr(0, pos);
			if (OneWord != "")
			{
				vString.push_back(OneWord);
			}
			Line.erase(0, pos + Dilem.length());
		}
		if (Line != "")
		{
			vString.push_back(Line);
		}
		return vString;
	}
	vector<string> SpliteString()
	{
		return SpliteString(_Value);
	}

	static string JoinString(vector<string> vString, string Dilem = " ")
	{
		string Line = "";
		for (string& Word : vString)
		{
			Line += (Word + Dilem);
		}
		Line.erase(Line.length() - Dilem.length(), Line.length());

		return Line;
	}

	static string CapitalizeString(string Line)
	{
		string Cap = "";
		for (char& Letter : Line)
		{
			Cap += toupper(Letter);
		}
		return Cap;
	}
	void CapitalizeString()
	{
		_Value = CapitalizeString(_Value);
	}

	static string CapitalizeFirstLetter(string Line, string Dilem = " ")
	{
		vector<string> vString = SpliteString(Line);
		for (string& Word : vString)
		{
			Word[0] = toupper(Word[0]);
		}
		return JoinString(vString);
	}
	void CapitalizeFirstLetter()
	{
		_Value = CapitalizeFirstLetter(_Value);
	}

	static string LowercaseString(string Line)
	{
		string Lower = "";
		for (char& Letter : Line)
		{
			Lower += tolower(Letter);
		}
		return Lower;
	}
	void LowercaseString()
	{
		_Value = LowercaseString(_Value);
	}

	static string LowercaseFirstLetter(string Line, string Dilem = "")
	{
		vector<string> vString = SpliteString(Line);
		for (string& Word : vString)
		{
			Word[0] = tolower(Word[0]);
		}
		return JoinString(vString);
	}
	void LowercaseFirstLetter()
	{
		_Value = LowercaseFirstLetter(_Value);
	}

	static string ConvertCabitalandsmallLetters(string Line)
	{
		string ConvertedLine = "";

		for (char& L : Line)
		{
			if (isupper(L))
			{
				ConvertedLine += tolower(L);
			}
			else if (islower(L))
			{
				ConvertedLine += toupper(L);
			}
			else
			{
				ConvertedLine += L;
			}

		}
		return ConvertedLine;
	}
	void ConvertCabitalandsmallLetters()
	{
		_Value = ConvertCabitalandsmallLetters(_Value);

	}

	static string RemovePunctuations(string Line)
	{
		string RemovedLine = "";
		for (char& Car : Line)
		{
			if (!ispunct(Car))
			{
				RemovedLine += Car;
			}
		}
		return RemovedLine;
	}
	void RemovePunctuations()
	{
		_Value = RemovePunctuations(_Value);
	}

	static string ReverseString(string Line, string Delim = " ")
	{
		vector < string > vString = SpliteString(Line);
		string ReversedLine = "";
		for (short i = vString.size() - 1; i >= 0; i--)
		{
			ReversedLine += vString.at(i) + Delim;
		}
		ReversedLine.erase(ReversedLine.length() - Delim.length(), ReversedLine.length());

		return ReversedLine;
	}
	void ReverseString(string Delim = " ")
	{
		_Value = ReverseString(_Value, Delim);
	}

	static string ReplaceWords(string Line, string whattoReplace, string ReplaceTo)
	{
		vector<string> vString = SpliteString(Line);
		for (string& Word : vString)
		{
			if (CapitalizeString(Word) == CapitalizeString(whattoReplace))
			{
				Word = ReplaceTo;
			}
		}
		return JoinString(vString);
	}
	void ReplaceWords(string WhattoReplace, string ReplaceTo)
	{
		_Value = ReplaceWords(_Value, WhattoReplace, ReplaceTo);
	}

	static string TrimLeft(string Line, char Separator)
	{
		string NewLine;
		for (short i = 0; i <= Line.length(); i++)
		{
			if (Line[i] != Separator)
			{
				NewLine = Line.substr(i, Line.length());
				return NewLine;
			}
		}

	}
	void TrimLeft(char Seprator)
	{
		_Value = TrimLeft(_Value, Seprator);
	}

	static string TrimRight(string Line, char Separator)
	{
		string NewLine;
		for (short i = Line.length() - 1; i >= 0; i--)
		{
			if (Line[i] != Separator)
			{
				NewLine = Line.substr(0, i + 1);
				return NewLine;
			}
		}
	}
	void TrimRight(char Separator)
	{
		_Value = TrimRight(_Value, Separator);
	}
};