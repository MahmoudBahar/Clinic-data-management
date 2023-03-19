#include <string>
#include <ctime>
using namespace std;
#include "../Types of variables/TYPES.h"
#include "../Types of variables/BASE_data.h"
#include "USER_data.h"

extern const u8 months_days[NUMBER_OF_MONTHS] = {
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

bool User_C::SET_Name(string Name)
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

bool User_C::SET_Username(string Username)
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

bool User_C::SET_Password(string Password)
{
	if (Password.length() > 50 || Password.length() < 8)
	{
		return true;
	}
	Head_Ref->Password = Password;
	Head_Ref->Password.shrink_to_fit();
	return false;
}

bool User_C::SET_Phone_number(string Phone_number)
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

bool User_C::SET_Email(string Email)
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

bool User_C::SET_Birth_Date(string Date_Of_Birth)
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

bool User_C::SET_reservation_Name(string Doctor_Name)
{
	Holder->reservation_with = Doctor_Name;
	Holder->reservation_with.shrink_to_fit();
	return false;
}

void User_C::SET_reservation_Date_Time(string input)
{
	Holder->time_and_date_for_reservation = input;
}

bool User_C::SET_reservation_Date(string Time, string date)
{
	u8 leap_year, day, month, counter, size = date.length(), temp1 = 0, temp2 = 0;
	u16 year;
	string temp = "";
	if (size > 10 || size < 8)
	{
		return true;
	}
	for (counter = 0; counter < size; counter++)
	{
		if (date[counter] != '/' && (date[counter] < 48 || date[counter] > 57))
		{
			return true;
		}
		if (date[counter] == '/' && temp1 == 0)
		{
			if (counter != 1 && counter != 2)
			{
				return true;
			}
			temp1 = counter;
		}
		else if (temp1 != 0 && date[counter] == '/')
		{
			if (counter != 3 && counter != 4 && counter != 5)
			{
				return true;
			}
			temp2 = counter;
		}
	}
	for (counter = 0; counter < temp1; counter++)
	{
		temp += date[counter];
	}
	day = stoi(temp);
	temp = "";
	for (counter = temp1 + 1; counter < temp2; counter++)
	{
		temp += date[counter];
	}
	month = stoi(temp);
	temp = "";
	for (counter = temp2 + 1; counter < size; counter++)
	{
		temp += date[counter];
	}
	year = stoi(temp);
	time_t time_now = time(0);
	#pragma warning(suppress : 4996)
	tm* Now_date = localtime(&time_now);
	if (year != (1900 + Now_date->tm_year) || year == (1900 + Now_date->tm_year) && month < Now_date->tm_mon + 1 && day < Now_date->tm_mday)
	{
		return true;
	}
	if (month < 13 && month != 0 && day != 0)
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
	Holder->time_and_date_for_reservation = Time + "  " + date;
	Holder->time_and_date_for_reservation.shrink_to_fit();
	return false;
}

bool User_C::SET_Gender(string Gender)
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

string User_C::GET_Name() const
{
	return Holder->Name;
}

string User_C::GET_Username() const
{
	return Holder->Username;
}

string User_C::GET_Password() const
{
	return Holder->Password;
}

string User_C::GET_Phone_number() const
{
	return Holder->Phone_number;
}

string User_C::GET_Email() const
{
	return Holder->Email;
}

string User_C::GET_Birth_Date() const
{
	return Holder->Date_Of_Birth;
}

u16 User_C::GET_Age() const
{
	return Holder->Age;
}

string User_C::GET_reservation_Name() const
{
	return Holder->reservation_with;
}
string User_C::GET_reservation_Date() const
{
	return Holder->time_and_date_for_reservation;
}

void User_C::ADD_cost(f32 ADDER)
{
	Holder->To_pay += ADDER;
	if (Holder->To_pay < 0)
	{
		Holder->To_pay = 0;
	}
}

void User_C::RESET_cost()
{
	Holder->To_pay = 0;
}

f32 User_C::GET_cost() const
{
	return Holder->To_pay;
}

u16 User_C::GET_Gender() const
{
	return Holder->Gender;
}