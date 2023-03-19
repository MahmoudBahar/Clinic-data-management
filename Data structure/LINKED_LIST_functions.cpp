#include <string>
#include <cstdlib>
using namespace std;
#include "../Types of variables/TYPES.h"
#include "../Types of variables/BASE_data.h"
#include "../User data/USER_data.h"
#include "../Employee data/EMPLOYEE_data.h"
#include "../Doctor data/DOCTOR_data.h"
#include "../Admin data/ADMIN_data.h"

/*Admin_C class functions*/
void Admin_C::PUSH_Node()
{
	if (Head_Ref == NULL)
	{
		Head_Ref = new Admin;
	}
}

void Admin_C::DELETE_Node()
{
	delete Head_Ref;
	Head_Ref = NULL;
}

bool Admin_C::Username_Repeat(string Username)
{
	return Head_Ref->Username == Username ? true : false;
}

bool Admin_C::Empty()
{
	return Head_Ref == NULL ? true : false;
}
/*Doctor_C class functions*/
void Doctor_C::PUSH_Node()
{
	Holder = new Doctor;
	Holder->Number_Of_Patient = 0;
	Holder->Salary = 0;
	Holder->ptr_to_next = Head_Ref;
	Head_Ref = Holder;
}

bool Doctor_C::SEARCH_Node_Username(string Username)
{
	if (Head_Ref == NULL)
	{
		return true;
	}
	Holder = Head_Ref;
	while (Holder->Username != Username)
	{
		if (Holder->ptr_to_next == NULL)
		{
			return true;
		}
		Holder = Holder->ptr_to_next;
	}
	return false;
}

void Doctor_C::DELETE_Node()
{
	Doctor* Helper = Head_Ref;
	if (Head_Ref == NULL)
	{
		return;
	}
	if (Head_Ref->ptr_to_next == NULL)
	{
		delete Head_Ref;
		Head_Ref = NULL;
		Holder = NULL;
	}
	else if (Head_Ref == Holder)
	{
		Head_Ref = Head_Ref->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
	else if (Holder->ptr_to_next == NULL)
	{
		delete Holder;
		Holder = NULL;
	}
	else
	{
		while (Helper->ptr_to_next != Holder)
		{
			Helper = Helper->ptr_to_next;
		}
		Helper->ptr_to_next = Holder->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
}

bool Doctor_C::Username_Repeat(string Username)
{
	Doctor* Temp = Head_Ref;
	if (Holder == NULL)
	{
		return false;
	}
	while (Temp->Username != Username)
	{
		if (Temp->ptr_to_next == NULL)
		{
			return false;
		}
		Temp = Temp->ptr_to_next;
	}
	return true;
}

void Doctor_C::Reset_Holder()
{
	Holder = Head_Ref;
}

bool Doctor_C::Next_Node()
{
	if (Holder->ptr_to_next == NULL)
	{
		return false;
	}
	Holder = Holder->ptr_to_next;
	return true;
}

bool Doctor_C::Empty()
{
	return Head_Ref == NULL ? true : false;
}

/*Employee_C class functions*/
void Employee_C::PUSH_Node()
{
	Holder = new Employee;
	Holder->ptr_to_next = Head_Ref;
	Head_Ref = Holder;
}

bool Employee_C::SEARCH_Node(string Username)
{
	if (Head_Ref == NULL)
	{
		return true;
	}
	Holder = Head_Ref;
	while (Holder->Username != Username)
	{
		if (Holder->ptr_to_next == NULL)
		{
			return true;
		}
		Holder = Holder->ptr_to_next;
	}
	return false;
}
void Employee_C::DELETE_Node()
{
	Employee* Helper = Head_Ref;
	if (Head_Ref == NULL)
	{
		return;
	}
	if (Head_Ref->ptr_to_next == NULL)
	{
		delete Head_Ref;
		Head_Ref = NULL;
		Holder = NULL;
	}
	else if (Head_Ref == Holder)
	{
		Head_Ref = Head_Ref->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
	else if (Holder->ptr_to_next == NULL)
	{
		delete Holder;
		Holder = NULL;
	}
	else
	{
		while (Helper->ptr_to_next != Holder)
		{
			Helper = Helper->ptr_to_next;
		}
		Helper->ptr_to_next = Holder->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
}

bool Employee_C::Username_Repeat(string Username)
{
	Employee* Temp = Head_Ref;
	if (Holder == NULL)
	{
		return false;
	}
	while (Temp->Username != Username)
	{
		if (Temp->ptr_to_next == NULL)
		{
			return false;
		}
		Temp = Temp->ptr_to_next;
	}
	return true;
}

bool Employee_C::Empty()
{
	return Head_Ref == NULL ? true : false;
}

void Employee_C::Reset_Holder()
{
	Holder = Head_Ref;
}

bool Employee_C::Next_Node()
{
	if (Holder->ptr_to_next == NULL)
	{
		return false;
	}
	Holder = Holder->ptr_to_next;
	return true;
}

/*User_C class functions*/
void User_C::PUSH_Node()
{
	Holder = new User;
	Holder->reservation_with = "";	
	Holder->reservation_with.shrink_to_fit();
	Holder->time_and_date_for_reservation = "";
	Holder->time_and_date_for_reservation.shrink_to_fit();
	Holder->To_pay = 0;
	Holder->ptr_to_next = Head_Ref;
	Head_Ref = Holder;
}

bool User_C::SEARCH_Node(string Username)
{
	if (Head_Ref == NULL)
	{
		return true;
	}
	Holder = Head_Ref;
	while (Holder->Username != Username)
	{
		if (Holder->ptr_to_next == NULL)
		{
			return true;
		}
		Holder = Holder->ptr_to_next;
	}
	return false;
}
void User_C::DELETE_Node()
{
	User* Helper = Head_Ref;
	if (Head_Ref == NULL)
	{
		return;
	}
	if(Head_Ref->ptr_to_next == NULL)
	{
		delete Head_Ref;
		Head_Ref = NULL;
		Holder = NULL;
	}
	else if (Head_Ref == Holder)
	{
		Head_Ref = Head_Ref->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
	else if (Holder->ptr_to_next == NULL)
	{
		delete Holder;
		Holder = NULL;
	}
	else
	{
		while (Helper->ptr_to_next != Holder)
		{
			Helper = Helper->ptr_to_next;
		}
		Helper->ptr_to_next = Holder->ptr_to_next;
		delete Holder;
		Holder = NULL;
	}
}

bool User_C::Username_Repeat(string Username)
{
	User* Temp = Head_Ref;
	if (Holder == NULL)
	{
		return false;
	}
	while (Temp->Username != Username)
	{
		if (Temp->ptr_to_next == NULL)
		{
			return false;
		}
		Temp = Temp->ptr_to_next;
	}
	return true;
}

bool User_C::Empty()
{
	return Head_Ref == NULL ? true : false;
}

void User_C::Reset_Holder()
{
	Holder = Head_Ref;
}

bool User_C::Next_Node()
{
	if (Holder->ptr_to_next == NULL)
	{
		return false;
	}
	Holder = Holder->ptr_to_next;
	return true;
}