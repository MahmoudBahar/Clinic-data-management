#ifndef EMPLOYEE_DATA_H
#define EMPLOYEE_DATA_H
#include "../Types of variables/BASE_data.h"

class Employee_C
{
private:
	Employee* Head_Ref;
	Employee* Holder;
public:
	Employee_C()
	{
		Head_Ref = NULL;
		Holder = NULL;
	}
	void PUSH_Node();
	void DELETE_Node();
	void Reset_Holder();
	bool Empty();
	bool Next_Node();
	bool SET_Salary(string Salary);
	bool SET_Gender(string Gender);
	bool SEARCH_Node(string Username);
	bool Username_Repeat(string Username);
	bool SET_Name(string Name);
	bool SET_Username(string Username);
	bool SET_Password(string Password);
	bool SET_Phone_number(string Phone_number);
	bool SET_Email(string Email);
	bool SET_Birth_Date(string Date_Of_Birth);
	bool SET_Work_Start(string Time);
	bool SET_Work_End(string Time);
	string GET_Name() const;
	string GET_Username() const;
	string GET_Password() const;
	string GET_Phone_number() const;
	string GET_Email() const;
	string GET_Birth_Date() const;
	string GET_Work_Start() const;
	string GET_Work_End() const;
	u16 GET_Age() const;
	u16 GET_Work_Time();
	f32 GET_Salary();
	u16 GET_Gender() const;
};

#endif