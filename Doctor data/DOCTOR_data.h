#ifndef DOCTOR_DATA_H
#define DOCTOR_DATA_H
#include "../Types of variables/BASE_data.h"

class Doctor_C
{
private:
	Doctor* Head_Ref;
	Doctor* Holder;
public:
	Doctor_C()
	{
		Head_Ref = NULL;
		Holder = NULL;
	}
	void PUSH_Node();
	void DELETE_Node();
	void Reset_Holder();
	void INC_Patient();
	void SET_Salary(string salary);
	void SET_Remainder(string remainder);
	void SET_Number_Of_Patient(string number);
	bool Empty();
	bool Next_Node();
	bool SET_Gender(string Gender);
	bool SET_Cost(string Cost);
	bool SEARCH_Node_Username(string Username);
	bool Username_Repeat(string Username);
	bool SET_Name(string Name);
	bool SET_Username(string Username);
	bool SET_Password(string Password);
	bool SET_Phone_number(string Phone_number);
	bool SET_Email(string Email);
	bool SET_Birth_Date(string Date_Of_Birth);
	bool SET_Available_Start_Time(string Time);
	bool SET_Available_End_Time(string Time);
	bool SET_Specialize(string Specialize);
	bool SET_Patient_Time(string minute);
	bool DECREASE_Remainder();
	string GET_Name() const;
	string GET_Username() const;
	string GET_Password() const;
	string GET_Phone_number() const;
	string GET_Email() const;
	string GET_Birth_Date() const;
	string GET_Available_Start_Time() const;
	string GET_Available_End_Time() const;
	u16 GET_Specialize() const;
	f32 GET_Cost() const;
	f32 GET_Salary() const;
	u16 GET_Age() const;
	u16 GET_Patient_Time() const;
	u16 GET_Gender() const;
	u16 GET_Remainder() const;
	u16 GET_Number_Of_Patient() const;
};

#endif