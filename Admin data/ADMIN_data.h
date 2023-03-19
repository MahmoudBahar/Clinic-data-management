#ifndef ADMIN_DATA_H
#define	ADMIN_DATA_H
#include "../Types of variables/BASE_data.h"

class Admin_C
{
private:
	Admin* Head_Ref;
public:
	Admin_C()
	{
		Head_Ref = NULL;
	}
	void PUSH_Node();
	void DELETE_Node();
	void Reset_Holder();
	bool Empty();
	bool Next_Node();
	bool SET_Gender(string Gender);
	bool Username_Repeat(string Username);
	bool SET_Name(string Name);
	bool SET_Username(string Username);
	bool SET_Password(string Password);
	bool SET_Phone_number(string Phone_number);
	bool SET_Email(string Email);
	bool SET_Birth_Date(string Date_Of_Birth);
	string GET_Name() const;
	string GET_Username() const;
	string GET_Password() const;
	string GET_Phone_number() const;
	string GET_Email() const;
	string GET_Birth_Date() const;
	u16 GET_Age() const;
	u16 GET_Gender() const;
};

#endif