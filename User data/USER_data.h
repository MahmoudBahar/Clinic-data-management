#ifndef USER_DATA_H
#define USER_DATA_H
#include "../Types of variables/BASE_data.h"

class User_C
{
private:
	User* Head_Ref;
	User* Holder;
public:
	User_C()
	{
		Head_Ref = NULL;
		Holder = NULL;
	}
	void PUSH_Node();
	void DELETE_Node();
	void RESET_cost();
	void Reset_Holder();
	void ADD_cost(f32 ADDER);
	void SET_reservation_Date_Time(string input);
	bool Empty();
	bool Next_Node();
	bool SET_Gender(string Gender);
	bool SEARCH_Node(string Username);
	bool Username_Repeat(string Username);
	bool SET_Name(string Name);
	bool SET_Username(string Username);
	bool SET_Password(string Password);
	bool SET_Phone_number(string Phone_number);
	bool SET_Email(string Email);
	bool SET_Birth_Date(string Date_Of_Birth);
	bool SET_reservation_Name(string Doctor_Name);
	bool SET_reservation_Date(string Time, string date);
	string GET_Name() const;
	string GET_Username() const;
	string GET_Password() const;
	string GET_Phone_number() const;
	string GET_Email() const;
	string GET_Birth_Date() const;
	string GET_reservation_Name() const;
	string GET_reservation_Date() const;
	f32 GET_cost() const;
	u16 GET_Age() const;
	u16 GET_Gender() const;
};

#endif