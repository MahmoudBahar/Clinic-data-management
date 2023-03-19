#include <string>
#include <ctime>
using namespace std;
#include "../Types of variables/TYPES.h"
#include "../Types of variables/BASE_data.h"
#include "Employee_data.h"

extern const u8 months_days[12];

bool Employee_C::SET_Name(string Name)
{
	u8 size = Name.length();
	do
	{
		size--;
		if (Name[size] != ' ' && (Name[size] < 65 || Name[size] > 90) && (Name[size] < 97 || Name[size] > 122))
		{
			return true;
		}
	} while (size != 0);
	Holder->Name = Name;
	Holder->Name.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Username(string Username)
{
	u8 size = Username.length();
	do
	{
		size--;
		if (Username[size] != '_' && (Username[size] < 48 || Username[size] > 57) && (Username[size] < 65 || Username[size] > 90) && (Username[size] < 97 || Username[size] > 122))
		{
			return true;
		}
	} while (size != 0);
	Holder->Username = Username;
	Holder->Username.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Password(string Password)
{
	if (Password.length() > 50 || Password.length() < 8)
	{
		return true;
	}
	Head_Ref->Password = Password;
	Head_Ref->Password.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Phone_number(string Phone_number)
{
	u8 size = Phone_number.length();
	if (Phone_number[0] != '0' || Phone_number[1] != '1' || ((Phone_number[2] < '0' || Phone_number[2] > '2') && Phone_number[2] != '5') || size != 11)
	{
		return true;
	}
	do
	{
		size--;
		if (Phone_number[size] < 48 || Phone_number[size] > 57)
		{
			return true;
		}
	} while (size > 3);
	Holder->Phone_number = Phone_number;
	Holder->Phone_number.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Email(string Email)
{
	u8 size = Email.length(), counter, temp = 0, temp2 = 0;
	for (counter = 0; counter < size; counter++)
	{
		if (Email[counter] == '@')
		{
			break;
		}
		else if ((Email[counter] < 48 || Email[counter] > 57) && (Email[counter] < 65 || Email[counter] > 90) && (Email[counter] < 97 || Email[counter] > 122))
		{
			return true;
		}
	}
	if (counter + 1 >= size || counter == 0)
	{
		return true;
	}
	for (counter++; counter < size; counter++)
	{
		if (Email[counter] == '.')
		{
			temp = counter;
		}
		else if (Email[counter] != '-' && (Email[counter] < 48 || Email[counter] > 57) && (Email[counter] < 65 || Email[counter] > 90) && (Email[counter] < 97 || Email[counter] > 122))
		{
			return true;
		}
		if (temp == 0)
		{
			temp2++;
		}
	}
	if (temp == 0 || temp2 < 2)
	{
		return true;
	}
	for (counter = temp + 1; counter < size; counter++)
	{
		if ((Email[counter] < 65 || Email[counter] > 90) && (Email[counter] < 97 || Email[counter] > 122))
		{
			return true;
		}
	}
	if (temp > (size - 3))
	{
		return true;
	}
	Head_Ref->Email = Email;
	Head_Ref->Email.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Birth_Date(string Date_Of_Birth)
{
	u8 leap_year, day, month, counter, size = Date_Of_Birth.length(), temp1 = 0, temp2 = 0;
	u16 year;
	string temp = "";
	if (size > 10 || size < 8)
	{
		return true;
	}
	for (counter = 0; counter < size; counter++)
	{
		if (Date_Of_Birth[counter] != '/' && (Date_Of_Birth[counter] < 48 || Date_Of_Birth[counter] > 57))
		{
			return true;
		}
		if (Date_Of_Birth[counter] == '/' && temp1 == 0)
		{
			if (counter != 1 && counter != 2)
			{
				return true;
			}
			temp1 = counter;
		}
		else if (temp1 != 0 && Date_Of_Birth[counter] == '/')
		{
			if (counter != 3 && counter != 4 && counter != 5)
			{
				return true;
			}
			temp2 = counter;
		}
	}
	if (temp1 == 0 || temp2 == 0)
	{
		return true;
	}
	for (counter = 0; counter < temp1; counter++)
	{
		temp += Date_Of_Birth[counter];
	}
	day = stoi(temp);
	temp = "";
	for (counter = temp1 + 1; counter < temp2; counter++)
	{
		temp += Date_Of_Birth[counter];
	}
	month = stoi(temp);
	temp = "";
	for (counter = temp2 + 1; counter < size; counter++)
	{
		temp += Date_Of_Birth[counter];
	}
	year = stoi(temp);
	time_t time_now = time(0);
	#pragma warning(suppress : 4996)
	tm* Now_date = localtime(&time_now);
	if (year > (1900 + Now_date->tm_year) || year == (1900 + Now_date->tm_year) && month >= Now_date->tm_mon + 1 && day >= Now_date->tm_mday)
	{
		return true;
	}
	if (month < 13 && year > 1910 && month != 0 && day != 0)
	{
		if (month == 2)
		{
			leap_year = (year % 4 ? 0 : (year % 100 ? 1 : (year % 400 ? 0 : 1)));
			if (day > months_days[1] + leap_year)
			{
				return true;
			}
		}
		else
		{
			if (day > months_days[month - 1])
			{
				return true;
			}
		}

	}
	else
	{
		return true;
	}
	Holder->Date_Of_Birth = Date_Of_Birth;
	Holder->Date_Of_Birth.shrink_to_fit();
	Holder->Age = (1900 + Now_date->tm_year) - year + ((Now_date->tm_mon + 1) > month ? 0 : (((Now_date->tm_mon + 1) == month) ? (((Now_date->tm_mday) >= day) ? 0 : -1) : -1));
	return false;
}

bool Employee_C::SET_Work_Start(string Time)
{
	u8 size = Time.length(), counter, temp1, hour, minute;
	string temp = "";
	if (size != 8 && size != 7)
	{
		return true;
	}
	if (Time[size - 3] != ' ')
	{
		return true;
	}
	if ((Time[size - 2] != 'A' && Time[size - 2] != 'a' && Time[size - 2] != 'p' && Time[size - 2] != 'P') || (Time[size - 1] != 'm' && Time[size - 1] != 'M'))
	{
		return true;
	}
	for (counter = 0; counter < size - 3; counter++)
	{
		if (Time[counter] != ':' && (Time[counter] < 48 || Time[counter] > 57))
		{
			return true;
		}
		if (Time[counter] == ':')
		{
			if (counter != 1 && counter != 2)
			{
				return true;
			}
			temp1 = counter;
		}
	}
	for (counter = 0; counter < temp1; counter++)
	{
		temp += Time[counter];
	}
	hour = stoi(temp);
	temp = Time[temp1 + 1];
	temp += Time[temp1 + 2];
	minute = stoi(temp);
	if (hour > 12 || minute > 59)
	{
		return true;
	}
	Holder->Work_from = Time;
	Holder->Work_from.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Work_End(string Time)
{
	u8 size = Time.length(), counter, temp1, hour1, minute1, hour2, minute2;
	string temp = "";
	if (size != 8 && size != 7)
	{
		return true;
	}
	if (Time[size - 3] != ' ')
	{
		return true;
	}
	if ((Time[size - 2] != 'A' && Time[size - 2] != 'a' && Time[size - 2] != 'p' && Time[size - 2] != 'P') || (Time[size - 1] != 'm' && Time[size - 1] != 'M'))
	{
		return true;
	}
	for (counter = 0; counter < size - 3; counter++)
	{
		if (Time[counter] != ':' && (Time[counter] < 48 || Time[counter] > 57))
		{
			return true;
		}
		if (Time[counter] == ':')
		{
			if (counter != 1 && counter != 2)
			{
				return true;
			}
			temp1 = counter;
		}
	}
	for (counter = 0; counter < temp1; counter++)
	{
		temp += Time[counter];
	}
	hour2 = stoi(temp);
	temp = Time[temp1 + 1];
	temp += Time[temp1 + 2];
	minute2 = stoi(temp);
	if (hour2 > 12 || minute2 > 59)
	{
		return true;
	}
	temp = "";
	for (counter = 0; Holder->Work_from[counter] != ':'; counter++)
	{
		temp += Holder->Work_from[counter];
	}
	hour1 = stoi(temp);
	temp = "";
	for (++counter; Holder->Work_from[counter] != ' '; counter++)
	{
		temp += Holder->Work_from[counter];
	}
	minute1 = stoi(temp);
	if (Holder->Work_from[(Holder->Work_from.length()) - 2] == 'p' || Holder->Work_from[(Holder->Work_from.length()) - 2] == 'P')
	{
		hour1 += 12;
	}
	hour2 += (Time[size - 2] == 'P' || Time[size - 2] == 'p' ? 12 : 0);
	if (hour2 < hour1)
	{
		return true;
	}
	else if(hour2 == hour1)
	{
		if (minute2 <= minute1)
		{
			return true;
		}
	}
	Holder->Work_to = Time;
	Holder->Work_to.shrink_to_fit();
	return false;
}

bool Employee_C::SET_Gender(string Gender)
{
	u8 counter, size = Gender.length();
	for (counter = 0; counter < size; counter++)
	{
		if (Gender[counter] >= 97 && Gender[counter] <= 122)
		{
			Gender[counter] -= 32;
		}
		else if (Gender[counter] < 65 || Gender[counter] > 90)
		{
			return true;
		}
	}
	if (Gender == "MALE")
	{
		Holder->Gender = 0;
		return false;
	}
	else if (Gender == "FEMALE")
	{
		Holder->Gender = 1;
		return false;
	}
	else
	{
		return true;
	}
}

bool Employee_C::SET_Salary(string Salary)
{
	u8 size = Salary.length(), counter, temp = 0;
	if (size < 1)
	{
		return true;
	}
	for (counter = 0; counter < size; counter++)
	{
		if (Salary[counter] != '.' && (Salary[counter] < 48 || Salary[counter] > 57))
		{
			return true;
		}
		if (Salary[counter] == '.')
		{
			temp++;
			if (temp > 1)
			{
				return true;
			}
		}
	}
	Holder->Salary = stof(Salary);
	return false;
}

string Employee_C::GET_Name() const
{
	return Holder->Name;
}

string Employee_C::GET_Username() const
{
	return Holder->Username;
}

string Employee_C::GET_Password() const
{
	return Holder->Password;
}

string Employee_C::GET_Phone_number() const
{
	return Holder->Phone_number;
}

string Employee_C::GET_Email() const
{
	return Holder->Email;
}

string Employee_C::GET_Birth_Date() const
{
	return Holder->Date_Of_Birth;
}

string Employee_C::GET_Work_Start() const
{
	return Holder->Work_from;
}
string Employee_C::GET_Work_End() const
{
	return Holder->Work_to;
}

u16 Employee_C::GET_Age() const
{
	return Holder->Age;
}

u16 Employee_C::GET_Work_Time()
{
	u8 hour1, minute1, hour2, minute2, counter;
	string temp = "";
	for (counter = 0; Holder->Work_from[counter] != ':'; counter++)
	{
		temp += Holder->Work_from[counter];
	}
	hour1 = stoi(temp);
	temp = "";
	for (++counter; Holder->Work_from[counter] != ' '; counter++)
	{
		temp += Holder->Work_from[counter];
	}
	minute1 = stoi(temp);
	temp = "";
	for (counter = 0; Holder->Work_to[counter] != ':'; counter++)
	{
		temp += Holder->Work_to[counter];
	}
	hour2 = stoi(temp);
	temp = "";
	for (++counter; Holder->Work_to[counter] != ' '; counter++)
	{
		temp += Holder->Work_to[counter];
	}
	minute2 = stoi(temp);
	if (Holder->Work_from[(Holder->Work_from.length()) - 2] == 'p' || Holder->Work_from[(Holder->Work_from.length()) - 2] == 'P')
	{
		hour1 += 12;
	}
	if (Holder->Work_to[(Holder->Work_to.length()) - 2] == 'p' || Holder->Work_to[(Holder->Work_to.length()) - 2] == 'P')
	{
		hour2 += 12;
	}
	return ((hour2 - hour1) * 60) + (minute2 - minute1);
}

f32 Employee_C::GET_Salary()
{
	return Holder->Salary;
}

u16 Employee_C::GET_Gender() const
{
	return Holder->Gender;
}