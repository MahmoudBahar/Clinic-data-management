#include <fstream>
#include <string>
using namespace std;
#include "../Types of variables/TYPES.h"
#include "../Types of variables/BASE_data.h"
#include "../Admin data/ADMIN_data.h"
#include "../User data/USER_data.h"
#include "../Doctor data/DOCTOR_data.h"
#include "../Employee data/EMPLOYEE_data.h"
#include "FILE_handling.h"

void Encrypt(string* data);
void Decrypt(string* data);

extern const char* specializes[NUMBER_OF_SPECIALIZES];

void Save_Data(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	system("mkdir \"saved data\"");
	system("cls");
	string temp;
	ofstream	file_admin("saved data/Admin_data.txt",ios::out|ios::trunc);
	if (!Admin.Empty())
	{
		temp = Admin.GET_Name();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = Admin.GET_Username();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = Admin.GET_Password();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = Admin.GET_Phone_number();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = Admin.GET_Email();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = Admin.GET_Birth_Date();
		Encrypt(&temp);
		file_admin << temp << endl;
		temp = to_string(Admin.GET_Gender());
		Encrypt(&temp);
		file_admin << temp;
	}
	file_admin.close();
	ofstream	file_employee("saved data/Employee_data.txt", ios::out | ios::trunc);
	if (!Employee.Empty())
	{
		Employee.Reset_Holder();
		do
		{
			temp = Employee.GET_Name();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Username();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Password();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Phone_number();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Email();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Birth_Date();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = to_string(Employee.GET_Gender());
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Work_Start();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = Employee.GET_Work_End();
			Encrypt(&temp);
			file_employee << temp << endl;
			temp = to_string(Employee.GET_Salary());
			Encrypt(&temp);
			file_employee << temp << endl;
		} while (Employee.Next_Node());
	}
	file_employee.close();
	ofstream	file_doctor("saved data/Doctor_data.txt", ios::out | ios::trunc);
	if (!Doctor.Empty())
	{
		Doctor.Reset_Holder();
		do
		{
			temp = Doctor.GET_Name();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Username();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Password();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Phone_number();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Email();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Birth_Date();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Gender());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Available_Start_Time();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = Doctor.GET_Available_End_Time();
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Cost());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Salary());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Remainder());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Specialize());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Patient_Time());
			Encrypt(&temp);
			file_doctor << temp << endl;
			temp = to_string(Doctor.GET_Number_Of_Patient());
			Encrypt(&temp);
			file_doctor << temp << endl;
		} while (Doctor.Next_Node());
	}
	file_doctor.close();
	ofstream	file_user("saved data/User_data.txt", ios::out | ios::trunc);
	if (!User.Empty())
	{
		User.Reset_Holder();
		do
		{
			temp = User.GET_Name();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_Username();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_Password();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_Phone_number();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_Email();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_Birth_Date();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = to_string(User.GET_Gender());
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_reservation_Name();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = User.GET_reservation_Date();
			Encrypt(&temp);
			file_user << temp << endl;
			temp = to_string(User.GET_cost());
			Encrypt(&temp);
			file_user << temp << endl;
		} while (User.Next_Node());
	}
	file_user.close();
	file_user.close();
}

void Read_Data(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	string temp;
	ifstream	file_admin("saved data/Admin_data.txt", ios::in);
	if (file_admin.is_open())
	{
		if (file_admin.peek() != ifstream::traits_type::eof())
		{
			Admin.PUSH_Node();
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Name(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Username(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Password(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Phone_number(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Email(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Birth_Date(temp);
			getline(file_admin, temp);
			Decrypt(&temp);
			Admin.SET_Gender((temp == "0" ? "MALE" : "FEMALE"));
		}
	}
	file_admin.close();
	ifstream	file_employee("saved data/Employee_data.txt", ios::in);
	if (file_employee.is_open())
	{
		if (file_employee.peek() != ifstream::traits_type::eof())
		{
			do
			{
				Employee.PUSH_Node();
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Name(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Username(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Password(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Phone_number(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Email(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Birth_Date(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Gender((temp == "0" ? "MALE" : "FEMALE"));
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Work_Start(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Work_End(temp);
				getline(file_employee, temp);
				Decrypt(&temp);
				Employee.SET_Salary(temp);
			} while (!file_employee.eof() && file_employee.peek() != ifstream::traits_type::eof());
		}
	}
	file_employee.close();
	ifstream	file_doctor("saved data/Doctor_data.txt", ios::in);
	if (file_doctor.is_open())
	{
		if (file_doctor.peek() != ifstream::traits_type::eof())
		{
			do
			{
				Doctor.PUSH_Node();
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Name(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Username(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Password(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Phone_number(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Email(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Birth_Date(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Gender((temp == "0" ? "MALE" : "FEMALE"));
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Available_Start_Time(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Available_End_Time(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Cost(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Salary(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Remainder(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Specialize(specializes[stoi(temp)]);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Patient_Time(temp);
				getline(file_doctor, temp);
				Decrypt(&temp);
				Doctor.SET_Number_Of_Patient(temp);
			} while (!file_doctor.eof() && file_doctor.peek() != ifstream::traits_type::eof());
		}
	}
	file_doctor.close();
	ifstream	file_user("saved data/User_data.txt", ios::in);
	if (file_user.is_open())
	{
		if (file_user.peek() != ifstream::traits_type::eof())
		{
			do
			{
				User.PUSH_Node();
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Name(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Username(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Password(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Phone_number(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Email(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Birth_Date(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_Gender((temp == "0" ? "MALE" : "FEMALE"));
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_reservation_Name(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.SET_reservation_Date_Time(temp);
				getline(file_user, temp);
				Decrypt(&temp);
				User.ADD_cost(stof(temp));
			} while (!file_user.eof() && file_user.peek() != ifstream::traits_type::eof());
		}
	}
}

void Encrypt(string* data)
{
	u16 size = data->length();
	for (int counter = 0; counter < size; counter++)
	{
		(*data)[counter] ^= 1;
	}
}

void Decrypt(string* data)
{
	u16 size = data->length();
	for (int counter = 0; counter < size; counter++)
	{
		(*data)[counter] ^= 1;
	}
}