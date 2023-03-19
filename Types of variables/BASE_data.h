#ifndef BASE_DATA_H
#define BASE_DATA_H

#define ADMIN		3
#define USER		6
#define EMPLOYEE	11

#define NUMBER_OF_SPECIALIZES	15
#define NUMBER_OF_MONTHS	12

struct User {
	string Name;
	string Username;
	string Password;
	string Phone_number;
	string Email;
	string Date_Of_Birth;
	string reservation_with;
	string time_and_date_for_reservation;
	f32	To_pay;
	u8 Gender;
	u8	Age;
	User* ptr_to_next;
};

struct Employee {
	string Name;
	string Username;
	string Password;
	string Phone_number;
	string Email;
	string Date_Of_Birth;
	string Work_from;
	string Work_to;
	f32 Salary;
	u8 Gender;
	u8 Age;
	Employee* ptr_to_next;
};

struct Doctor {
	string Name;
	string Username;
	string Password;
	string Phone_number;
	string Email;
	string Date_Of_Birth;
	string available_from;
	string available_to;
	f32	Cost;
	f32 Salary;
	u16 Remainder;
	u8 specialize;
	u8 Time_for_patient;
	u8 Number_Of_Patient;
	u8 Gender;
	u8 Age;
	Doctor* ptr_to_next;
};

struct Admin {
	string Name;
	string Username;
	string Password;
	string Phone_number;
	string Email;
	string Date_Of_Birth;
	u8 Gender;
	u8 Age;
};

#endif