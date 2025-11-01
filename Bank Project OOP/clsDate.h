#pragma warning(disable:4996)
#pragma once
#include<iostream>
#include<ctime>
#include<string>
#include"clsString.h"
using namespace std;

class clsDate
{
private:
	short _Year = 1900;
	short _Month = 1;
	short _Day = 1;
public:
	//Constructors
	clsDate()
	{
		time_t t = time(0);
		tm* TimeNow = localtime(&t);
		_Year += TimeNow->tm_year;
		_Month += TimeNow->tm_mon;
		_Day = TimeNow->tm_mday;
	}
	clsDate(string Date, string Seprator)
	{
		vector<string> vString = clsString::SpliteString(Date, Seprator);
		_Day = stoi(vString[0]);
		_Month = stoi(vString[1]);
		_Year = stoi(vString[2]);
	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(int NumberofDays, short Year)
	{
		int RemainingDays = NumberofDays;
		int MonthDays = 0;
		_Year = Year;
		_Month = 1;
		while (true)
		{
			MonthDays = NumberofDaysInaMonth(*this);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				_Month++;
			}
			else
			{
				_Day = RemainingDays;
				break;
			}

		}
	}

	//Properties
	void SetDay(short Day)
	{
		_Day = Day;
	}
	short GetDay()
	{
		return _Day;
	}
	__declspec(property(get = GetDay, put = SetDay)) short Day;

	void SetMonth(short Month)
	{
		_Month = Month;
	}
	short GetMonth()
	{
		return _Month;
	}
	__declspec(property(get = GetMonth, put = SetMonth)) short Month;

	void SetYear(short Year)
	{
		_Year = Year;
	}
	short GetYear()
	{
		return _Year;
	}
	__declspec(property(get = GetYear, put = SetYear)) short Year;


	//Functions
	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* TimeNow = localtime(&t);

		short Year, Month, Day, Hour, Minutes, Seconds;
		Year = TimeNow->tm_year + 1900;
		Month = TimeNow->tm_mon + 1;
		Day = TimeNow->tm_mday;
		Hour = TimeNow->tm_hour;
		Minutes = TimeNow->tm_min;
		Seconds = TimeNow->tm_sec;

		return to_string(Year) + "/" + to_string(Month) + "/" + to_string(Day) + " - " + to_string(Hour) + ":" +
			to_string(Minutes) + ":" + to_string(Seconds);
	}
	static string DateToString(clsDate Date)
	{
		return to_string(Date._Day) + "/" + to_string(Date._Month) + "/" + to_string(Date._Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}
	void PrintDate()
	{
		cout << DateToString() << endl;
	}
	static bool IsOdd(short Number)
	{
		return (Number % 2 == 0) ? false : true;
	}
	bool IsValide(clsDate Date)
	{
		if (Date.Month > 12 || Date.Month < 1)
			return false;
		if (Date.Day < 1 || Date.Day>31)
			return false;
		if (IsLeapYear(Date) && Date._Month == 2 && Date._Month > 29)
			return false;
		if (!IsLeapYear(Date) && Date._Month == 2 && Date._Month > 28)
			return false;
		if (!IsOdd(Date._Month) && Date._Day == 31)
			return false;

		return true;
	}

	static bool IsLeapYear(clsDate Date)
	{
		return (Date._Year % 4 == 0 && Date._Year % 100 != 0) || (Date._Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(*this);
	}

	static short NumberofDaysInaYear(clsDate Date)
	{
		return (IsLeapYear(Date)) ? 366 : 365;
	}
	short NumberofDaysInaYear()
	{
		return NumberofDaysInaYear(*this);
	}

	static int NumberofHoursInaYear(clsDate Date)
	{
		return NumberofDaysInaYear(Date) * 24;
	}
	int NumberofHoursInaYear()
	{
		return NumberofHoursInaYear(*this);
	}

	static int NumberOfMiuntesInaYear(clsDate Date)
	{
		return NumberofHoursInaYear(Date) * 60;
	}
	int NumberOfMiuntesInaYear()
	{
		return NumberOfMiuntesInaYear(*this);
	}

	static int NumberOfSecondsInaYear(clsDate Date)
	{
		return NumberOfMiuntesInaYear(Date) * 60;
	}
	int NumberOfSecondsInaYear()
	{
		return NumberOfSecondsInaYear(*this);
	}

	static short NumberofDaysInaMonth(clsDate Date)
	{
		if (Date._Month < 1 || Date._Month>12)
			return 0;
		if (Date._Month == 2)
			return (IsLeapYear(Date)) ? 29 : 28;
		if (IsOdd(Date._Month))
			return 31;

		return 30;
	}
	short NumberofDaysInaMonth()
	{
		return NumberofDaysInaMonth(*this);
	}

	static int NumberofHoursInaMonth(clsDate Date)
	{
		return NumberofDaysInaMonth(Date) * 24;
	}
	int NumberofhoursInaMonth()
	{
		return NumberofHoursInaMonth(*this);
	}

	static int NumberofMinutesInaMonth(clsDate Date)
	{
		return NumberofHoursInaMonth(Date) * 60;
	}
	int NumberofMinutesInaMonth()
	{
		return NumberofMinutesInaMonth(*this);
	}

	static int NumberofSecondsInaMonth(clsDate Date)
	{
		return NumberofMinutesInaMonth(Date) * 60;
	}
	int NumberofSecondsInaMonth()
	{
		return NumberofSecondsInaMonth(*this);
	}

	static short DayOrder(clsDate Date)
	{
		int a = (14 - Date._Month) / 12;
		int y = Date._Year - a;
		int m = Date._Month - (12 * a) - 2;
		return (Date._Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short DayOrder()
	{
		return DayOrder(*this);
	}

	static string GetDayShortName(clsDate Date)
	{
		short TheDay = DayOrder(Date);
		string Arr[] = { "Sun","Mon","Tue","Wen","Thu","Fri","Sat" };
		return Arr[TheDay];
	}
	string GetDayShortName()
	{
		return GetDayShortName(*this);
	}

	static string GetMonthShortName(clsDate Date)
	{
		string Arr[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		return Arr[Date._Month - 1];
	}
	string GetMonthShortName()
	{
		return GetMonthShortName(*this);
	}

	static void PrintMonthCalender(clsDate Date)
	{
		int* P = new int;
		*P = Date._Day;
		Date._Day = 1; //This for the Calender to start from day 1 then we will return it into the acual day at the end
		short Current = DayOrder(Date);
		int NumberofDays = NumberofDaysInaMonth(Date);

		cout << "-------------" << GetMonthShortName(Date) << "-------------" << endl;
		cout << " Sun Mon Tue Wen Thu Fri Sat " << endl;
		int i;
		for (i = 0; i < Current; i++)
		{
			cout << "    ";
		}
		for (int j = 1; j <= NumberofDays; j++)
		{
			printf("%4d", j);
			if (++i == 7)
			{
				i = 0;
				cout << "\n";
			}
		}

		cout << "\n-----------------------------" << endl; \

			Date._Day = *P;
		delete P;

	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(*this);

	}

	static void PrintYearCalender(clsDate Date)
	{
		cout << "-----------------------------" << endl;
		cout << "         Year Calender" << endl;
		cout << "-----------------------------" << endl;

		int* P = new int;
		*P = Date._Month;
		for (int i = 1; i <= 12; i++)
		{
			Date._Month = i;
			PrintMonthCalender(Date);
			cout << endl;
		}
		Date._Month = *P;
		delete P;
	}
	void PrintYearCalender()
	{
		PrintYearCalender(*this);
	}

	static short NumberofDaysFromTheBeginingofTheYear(clsDate Date)
	{
		int* P = new int; //this pointer to represent the Monthes
		*P = Date._Month;
		int TotalDays = 0;
		for (int i = 1; i <= *P - 1; i++)
		{
			Date._Month = i;
			TotalDays += NumberofDaysInaMonth(Date);
		}
		TotalDays += Date._Day;

		Date._Month = *P;
		delete P;
		return TotalDays;
	}
	short NumberofDaysFromTheBeginingofTheYear()
	{
		return NumberofDaysFromTheBeginingofTheYear(*this);
	}

	static bool IsDate1BeforDate2(clsDate Date1, clsDate Date2)
	{
		if (Date1._Year < Date2._Year)
			return true;
		else if (Date1._Year == Date2._Year)
		{
			if (Date1._Month < Date2._Month)
				return true;
			else if (Date1._Month == Date2._Month)
			{
				if (Date1._Day < Date2._Day)
					return true;
			}
		}
		return false;
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		return IsDate1BeforDate2(*this, Date2);
	}

	static bool IsDate1EqualtoDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year && Date1._Month == Date2._Month && Date1._Day == Date2._Day);
	}
	bool IsDate1EqualtoDate2(clsDate Date2)
	{
		return IsDate1EqualtoDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforDate2(Date1, Date2) && !IsDate1EqualtoDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static short DatesComparing(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforDate2(Date1, Date2))
			return -1;
		else if (IsDate1EqualtoDate2(Date1, Date2))
			return 0;
		else
			return 1;
	}
	short DatesComparing(clsDate Date2)
	{
		return DatesComparing(*this, Date2);
	}

	static short DiffrenceBetweenTwoDates(clsDate Date1, clsDate Date2, bool EncludeEndDay = false)
	{
		short Diff = NumberofDaysFromTheBeginingofTheYear(Date1)
			- NumberofDaysFromTheBeginingofTheYear(Date2);

		if (EncludeEndDay)
			return Diff;

		return Diff;
	}
	short DiffrenceBetweenTwoDates(clsDate Date2, bool EncludeEndDay = false)
	{
		return DiffrenceBetweenTwoDates(*this, Date2, EncludeEndDay);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberofDaysInaMonth(Date)) ? true : false;
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInaYear(clsDate Date)
	{
		return (Date._Month == 12) ? true : false;
	}
	bool IsLastMonthInaYear()
	{
		return IsLastMonthInaYear(*this);
	}

	static void IncreasDateByOneDay(clsDate& Date)
	{
		if (!IsLastDayInMonth(Date))
			Date._Day++;
		else if (IsLastDayInMonth(Date) && !IsLastMonthInaYear(Date))
		{
			Date._Day = 1;
			Date._Month++;
		}
		else if (IsLastDayInMonth(Date) && IsLastMonthInaYear(Date))
		{
			Date._Day = 1;
			Date._Month = 1;
			Date._Year++;
		}
	}
	void IncreasDateByOneDay()
	{
		IncreasDateByOneDay(*this);
	}

	static void IncreasDateByXDay(clsDate& Date, short ExtraDays)
	{
		for (int i = 1; i <= ExtraDays; i++)
		{
		IncreasDateByOneDay(Date);
		}
	}
	void IncreasDateByXDay(short ExtraDays)
	{
		IncreasDateByXDay(*this, ExtraDays);
	}

	static void IncreasDateByOneWeek(clsDate& Date)
	{
		IncreasDateByXDay(Date, 7);
	}
	void IncreasDateByOneWeek()
	{
		IncreasDateByOneWeek(*this);
	}

	static void IncreasDateByXWeeks(clsDate& Date, short Weeks)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			IncreasDateByOneWeek(Date);
		}
	}
	void IncreasDateByXWeeks(short Weeks)
	{
		IncreasDateByXWeeks(*this, Weeks);
	}

	static void IncreasDateByOneMonth(clsDate& Date)
	{
		short MonthDays = NumberofDaysInaMonth(Date);
		short CurrentMonthDays = Date._Day;
		Date._Day = 0;
		IncreasDateByXDay(Date, MonthDays + CurrentMonthDays);
	}
	void IncreasDateByOneMonth()
	{
		IncreasDateByOneMonth(*this);
	}

	static void IncreasDateByXMonths(clsDate& Date, short Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			IncreasDateByOneMonth(Date);
		}
	}
	void IncreasDateByXMonths(short Months)
	{
		IncreasDateByXMonths(*this, Months);
	}

	static void IncreasDateByOneYear(clsDate& Date)
	{
		IncreasDateByXMonths(Date, 12);
	}
	void IncreasDateByOneYear()
	{
		IncreasDateByOneYear(*this);
	}

	static void IncreasDateByXYears(clsDate& Date, short Years)
	{
		for (int i = 1; i <= Years; i++)
		{
			IncreasDateByOneYear(Date);
		}
	}
	void IncreasDateByXYears(short Years)
	{
		IncreasDateByXYears(*this, Years);
	}

	static void IncreasDateByOneDecade(clsDate& Date)
	{
		IncreasDateByXYears(Date, 10);
	}
	void IncreasDateByOneDecade()
	{
		IncreasDateByOneDecade(*this);
	}

	static void IncreasDateByXDecade(clsDate& Date, short Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			IncreasDateByOneDecade(Date);
		}
	}
	void IncreasDateByXDecade(short Decades)
	{
		IncreasDateByXDecade(*this, Decades);
	}

	static void IncreasDateByOneCentury(clsDate& Date)
	{
		IncreasDateByXDecade(Date, 10);
	}
	void IncreasDateByOneCentury()
	{
		IncreasDateByOneCentury(*this);
	}

	static void IncreasDateByXCentury(clsDate& Date, short Centurys)
	{
		for (int i = 1; i <= Centurys; i++)
		{
			IncreasDateByOneCentury(Date);
		}
	}
	void IncreasDateByXCentury(short Centurys)
	{
		IncreasDateByXCentury(*this, Centurys);
	}

	static void IncreasDateByOneMillennium(clsDate& Date)
	{
		IncreasDateByXCentury(Date, 10);
	}
	void IncreasDateByOneMillennium()
	{
		IncreasDateByOneMillennium(*this);
	}

	static void DecreasDateByOneDate(clsDate& Date)
	{
		if (Date._Day > 1)
		{
			Date._Day--;
		}
		else if (Date._Day == 1 && Date._Month > 1)
		{
			Date._Month--;
			Date._Day = NumberofDaysInaMonth(Date);
		}
		else if (Date._Day == 1 && Date._Month == 1)
		{
			Date._Year--;
			Date._Month = 12;
			Date._Day = NumberofDaysInaMonth(Date);
		}

	}
	void DecreasDateByOneDate()
	{
		DecreasDateByOneDate(*this);
	}

	static void DecreasDateByXDate(clsDate& Date, short Days)
	{
		for (int i = 1; i <= Days; i++)
		{
			DecreasDateByOneDate(Date);
		}
	}
	void DecreasDateByXDate(short Days)
	{
		DecreasDateByXDate(*this, Days);
	}

	static void DecreasDaetByOneWeek(clsDate& Date)
	{
		DecreasDateByXDate(Date, 7);
	}
	void DecreasDaetByOneWeek()
	{
		DecreasDaetByOneWeek(*this);
	}

	static void DecreasDateByXWeek(clsDate& Date, short Weeks)
	{
		for (int i = 1; i <= Weeks; i++)
		{
			DecreasDaetByOneWeek(Date);
		}
	}
	void DecreasDateByXWeek(short Weeks)
	{
		DecreasDateByXWeek(*this, Weeks);
	}

	static void DecreasDateByOneMonth(clsDate& Date)
	{

		if (Date._Month > 1)
		{
			Date.Month--;
			short CurrentDays = Date._Day;
			short MonthDays = NumberofDaysInaMonth(Date);
			if (CurrentDays > MonthDays)
				Date._Day = MonthDays;
		}
		else if (Date._Month == 1)
		{
			Date.Year--;
			Date.Month = 12;
			short CurrentDays = Date.Day;
			short MonthDays = NumberofDaysInaMonth(Date);
			if (CurrentDays > MonthDays)
				Date._Day = MonthDays;
		}

	}
	void DecreasDateByOneMonth()
	{
		DecreasDateByOneMonth(*this);
	}

	static void DecreasDateByXMonths(clsDate& Date, short Months)
	{
		for (int i = 1; i <= Months; i++)
		{
			DecreasDateByOneMonth(Date);
		}
	}
	void DecreasDateByXMonths(short Months)
	{
		DecreasDateByXMonths(*this, Months);
	}

	static void DecreasDateByOneyear(clsDate& Date)
	{
		Date._Year -= 1;
	}
	void DecreasDateByOneyear()
	{
		DecreasDateByOneyear(*this);
	}

	static void DecreasDaetByXYear(clsDate& Date, short Years)
	{
		Date._Year -= Years;
	}
	void DecreasDaetByXYear(short Years)
	{
		DecreasDaetByXYear(*this, Years);
	}

	static void DecreasDateByDecade(clsDate& Date)
	{
		Date._Year -= 10;
	}
	void DecreasDateByDecade()
	{
		DecreasDateByDecade(*this);
	}


	static void DecreasDateByXDecade(clsDate& Date, short Decades)
	{
		for (int i = 1; i <= Decades; i++)
		{
			DecreasDateByDecade(Date);
		}
	}
	void DecreasDateByXDecade(short Decades)
	{
		DecreasDateByXDecade(*this, Decades);
	}

	static void DecreasDaetByOneCentury(clsDate& Date)
	{
		Date._Year -= 100;
	}
	void DecreasDaetByOneCentury()
	{
		DecreasDaetByOneCentury(*this);
	}

	static void DecreasDateByMillennium(clsDate& Date)
	{
		Date._Year -= 1000;
	}
	void DecreasDateByMillennium()
	{
		DecreasDateByMillennium(*this);
	}

	static clsDate GetTheSystemDate(clsDate& Date)
	{

		time_t t = time(0);
		tm* TimeNow = localtime(&t);
		Date._Year = TimeNow->tm_year + 1900;
		Date._Month = TimeNow->tm_mon + 1;
		Date._Day = TimeNow->tm_mday;
		return Date;
	}
	void GetTheSystemDate()
	{
		GetTheSystemDate(*this);
	}

	static bool IsEndOffWeek(clsDate Date)
	{
		return DayOrder(Date) == 6;
	}
	bool IsEndOffWeek()
	{
		return IsEndOffWeek(*this);
	}

	static bool IsWeekEnd(clsDate Date)
	{
		return DayOrder(Date) == 5 || DayOrder(Date) == 6;
	}
	bool IsWeekEnd()
	{
		return IsWeekEnd(*this);
	}

	static bool IsBesinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBesinessDay()
	{
		return IsBesinessDay(*this);
	}

	static short DaysUntilEndofWeek(clsDate Date)
	{
		short CuurentDayIndex = DayOrder(Date);
		short DaysLeft = 0;
		for (int i = CuurentDayIndex; i < 6; i++)
		{
			DaysLeft++;
		}
		return DaysLeft;
	}
	short DaysUntilEndofWeek()
	{
		return DaysUntilEndofWeek(*this);
	}

	static short DaysUntilEndofMonth(clsDate Date)
	{
		short CurrentMonthDays = NumberofDaysInaMonth(Date);
		return CurrentMonthDays - Date._Day;
	}
	short DaysUntilEndofMonth()
	{
		return DaysUntilEndofMonth(*this);
	}

	static short DaysUntilEndofYear(clsDate Date)
	{
		if (IsLeapYear(Date))
			return 366 - NumberofDaysFromTheBeginingofTheYear(Date);
		else
			return 365 - NumberofDaysFromTheBeginingofTheYear(Date);
	}
	short DaysUntilEndofYear()
	{
		return DaysUntilEndofYear(*this);
	}

	static void GetDateDetails(clsDate& Date)
	{
		GetTheSystemDate(Date);
		cout << "*Today is " << GetDayShortName(Date) << " ";
		Date.PrintDate();
		//End of Week
		cout << "\n*Is it end of week? \n";
		if (IsEndOffWeek(Date))
			cout << "Yes, it's End of Week.\n";
		else
			cout << "No, it's not end of Week.\n";

		//Weekend
		cout << "\n*Is it Weekend?\n";
		if (IsWeekEnd(Date))
			cout << "Yes, it's a Weekend.\n";
		else
			cout << "No, it's not a WeekEnd.\n";

		//is Bussiness Day
		cout << "\n*Is it Busniess Day? \n";
		if (IsBesinessDay(Date))
			cout << "Yes it's a Business Day.\n\n";
		else
			cout << "NO it's not a Business Day.\n";

		//Days until end of Week
		cout << "*Days until End of Week  : " << DaysUntilEndofWeek(Date) << endl;
		//Days umtil End of Month
		cout << "*Days until End of Month : " << DaysUntilEndofMonth(Date) << endl;
		//Days until End of Month
		cout << "*Days until End of Year  : " << DaysUntilEndofYear(Date);
		system("pause>0");
	}
	void GetDateDetails()
	{
		GetDateDetails(*this);
	}

	static short CalculateVecationDays(clsDate Date1, clsDate Date2)
	{
		short Days = 0;
		while (IsDate1BeforDate2(Date1, Date2))
		{
			if (!IsWeekEnd(Date1))
				Days++;

			IncreasDateByOneDay(Date1);
		}
		return Days;
	}
	short CalculateVecationDays(clsDate Date2)
	{
		return CalculateVecationDays(*this, Date2);
	}

	static clsDate ClculateVecationReturnDate(clsDate Date1, short VecationDays)
	{
		clsDate Date2 = Date1;

		while (VecationDays != 0)
		{

			if (!IsWeekEnd(Date2))
				VecationDays--;
			IncreasDateByOneDay(Date2);
		}
		return Date2;
	}


};
