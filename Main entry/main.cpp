#include <Windows.h>
#include <iostream>
#include <string>
#include <conio.h>
#include "../Types of variables/TYPES.h"
#include "../public and terminal func/TERMINAL.h"
using namespace std;
#include "../Admin data/ADMIN_data.h"
#include "../Doctor data/DOCTOR_data.h"
#include "../User data/USER_data.h"
#include "../Employee data/EMPLOYEE_data.h"
#include "../File handling/FILE_handling.h"
#include "../public and terminal func/Public_functions.h"

int main()
{
	system("chcp 65001");
	system("cls");
	//to maxmize window
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
	ShowConsoleCursor(false);
	u8 loop1, loop2, temp = 136, Active = 0, Choice1, hour1, hour2, minute1, minute2;
	u16 counter, size, counter2;
	//printing flipped triangle
	for (loop1 = 0; loop1 <= number_of_hyphen_in_firstline; loop1 += 6)
	{
		for (loop2 = number_of_hyphen_in_firstline - loop1; loop2 < number_of_hyphen_in_firstline; loop2 += 2)
		{
			cout << ' ';
		}
		for (loop2 = loop1; loop2 < number_of_hyphen_in_firstline; loop2++)
		{
			temp ^= 4;
			Change_Color_FG(temp);
			cout << '-';
		}
		cout << '\n';
	}
	Move_Cursor(35, 37);
	Change_Color_FG(88);
	Select_Graphic_Rendition(RAPID_BLINK);
	Double_Height_Top();
	cout << "╔═══════════════════════════════════╗";
	Move_Cursor(35, 38);
	cout << "║";
	Change_Color_FG(52);
	Change_Color_BG(BRIGHT_WHITE);
	Select_Graphic_Rendition(NOT_BLINKING);
	Double_Height_Top();
	cout << "Welcome to Clinic management system";
	Select_Graphic_Rendition(RAPID_BLINK);
	Change_Color_FG(88);
	Change_Color_BG(BLACK);
	cout << "║";
	Move_Cursor(35, 39);
	cout << "║";
	Change_Color_FG(52);
	Change_Color_BG(BRIGHT_WHITE);
	Select_Graphic_Rendition(NOT_BLINKING);
	Double_Height_Bottom();
	cout << "Welcome to Clinic management system";
	Select_Graphic_Rendition(RAPID_BLINK);
	Change_Color_FG(88);
	Change_Color_BG(BLACK);
	cout << "║";
	Move_Cursor(35, 40);
	Double_Height_Bottom();
	cout << "╚═══════════════════════════════════╝";
	Select_Graphic_Rendition(NOT_BLINKING);
	Change_Color_FG(9);
	Move_Cursor(172, 34);
	cout << "Attention:";
	Move_Cursor(160, 35);
	cout << "If you close the program suddenly";
	Move_Cursor(164, 36);
	cout << "any changes will be lost.";
	Move_Cursor(1, 49);
	Change_Color_FG(14);
	system("pause");
	system("cls");
	Admin_C Admin;
	User_C User;
	Employee_C Employee;
	Doctor_C Doctor;
	Read_Data(User, Admin, Employee, Doctor);
	string temp_string1 = "";
	string temp_string2 = "";
	while (Active != ADMIN && Active != USER && Active != EMPLOYEE)
	{
		system("cls");
		if (Admin.Empty())
		{
			Sign_Up_Admin(User, Admin, Employee, Doctor);
		}
		system("cls");
		Change_Color_FG(MAGENTA);
		Move_Cursor(2, 1);
		cout << "╔════════════════════════════════╗";
		Move_Cursor(2, 2);
		cout << "║Please choose from the following║";
		Move_Cursor(2, 3);
		cout << "╠════════════════════════════════╝";
		Move_Cursor(2, 4);
		cout << "║  ╔═╦═══════╗";
		Move_Cursor(2, 5);
		cout << "╚══╣1╬Sign up║";
		Move_Cursor(2, 6);
		cout << "   ╠═╩═══════╝";
		Move_Cursor(5, 7);
		cout << "║  ╔═╦═══════╗";
		Move_Cursor(5, 8);
		cout << "╚══╣2╬Sign in║";
		Move_Cursor(5, 9);
		cout << "   ╠═╩═══════╝";
		Move_Cursor(8, 10);
		cout << "║  ╔═╦════╗";
		Move_Cursor(8, 11);
		cout << "╚══╣3╬Exit║";
		Move_Cursor(8, 12);
		cout << "   ╚═╩════╝";
		Choice1 = _getch();
		while (Choice1 != '1' && Choice1 != '2' && Choice1 != '3')
		{
			Move_Cursor(97, 1);
			cout << "╔══════════════╗";
			Move_Cursor(97, 2);
			cout << "║Invalid choice║\a";
			Move_Cursor(97, 3);
			cout << "╚══════════════╝";
			Choice1 = _getch();
		}
		system("cls");
		if (Choice1 == '3')
		{
			break;
		}
		switch (Choice1)
		{
		case'1':
			Sign_Up_User(User, Admin, Employee, Doctor);
			break;
		case'2':
			Move_Cursor(2, 1);
			cout << "╔══════════════╗";
			Move_Cursor(2, 2);
			cout << "║Please sign in║";
			Move_Cursor(2, 3);
			cout << "╠══════════════╝";
			Move_Cursor(2, 4);
			cout << "║  ╔══════════════════════════╗";
			Move_Cursor(2, 6);
			cout << "   ╠══════════════════════════╝";
			Move_Cursor(2, 5);
			cout << "╚══╣Please enter your username╠ ";
			Save_Cursor();
			Move_Cursor(5, 7);
			cout << "║  ╔══════════════════════════╗";
			Move_Cursor(5, 8);
			cout << "╚══╣Please enter your password╠ ";
			Move_Cursor(5, 9);
			cout << "   ╚══════════════════════════╝";
			Restore_Cursor();
			Read_Stream(&temp_string1);
			Move_Cursor(37, 8);
			Read_Stream(&temp_string2);
			if (!Admin.Empty() && Admin.GET_Username() == temp_string1 && Admin.GET_Password() == temp_string2)
			{
				Change_Color_FG(37);
				Active = ADMIN;
			}
			else if (!User.Empty() && !User.SEARCH_Node(temp_string1))
			{
				if (User.GET_Password() == temp_string2)
				{
					Change_Color_FG(39);
					Active = USER;
				}
			}
			else if (!Employee.Empty() && !Employee.SEARCH_Node(temp_string1))
			{
				if (Employee.GET_Password() == temp_string2)
				{
					Change_Color_FG(64);
					Active = EMPLOYEE;
				}
			}
			else
			{
				Active = 0;
			}
			while (Active == 0)
			{
				Restore_Cursor();
				Erase_After_Cursor();
				Move_Cursor(37, 8);
				Erase_After_Cursor();
				Move_Cursor(90, 1);
				cout << "╔════════════════════════════╗";
				Move_Cursor(90, 2);
				cout << "║Invalid Username or Password║\a";
				Move_Cursor(90, 3);
				cout << "╚════════════════════════════╝";
				Restore_Cursor();
				Read_Stream(&temp_string1);
				Move_Cursor(37, 8);
				Read_Stream(&temp_string2);
				if (!Admin.Empty() && Admin.GET_Username() == temp_string1 && Admin.GET_Password() == temp_string2)
				{
					Change_Color_FG(37);
					Active = ADMIN;
				}
				else if (!User.Empty() && !User.SEARCH_Node(temp_string1))
				{
					if (User.GET_Password() == temp_string2)
					{
						Change_Color_FG(39);
						Active = USER;
					}
				}
				else if (!Employee.Empty() && !Employee.SEARCH_Node(temp_string1))
				{
					if (Employee.GET_Password() == temp_string2)
					{
						Change_Color_FG(64);
						Active = EMPLOYEE;
					}
				}
				else
				{
					Active = 0;
				}
			}
			break;
		}
		system("cls");
		switch (Active)
		{
		case ADMIN:
			while (Choice1 != '0')
			{
				Print_Header(Admin);
				Change_Color_FG(37);
				Move_Cursor(2, 5);
				cout << "╔════════════════════════════════╗  ╔═╦════════╗";
				Move_Cursor(2, 6);
				cout << "║Please choose from the following╠══╣0╬Sign out║";
				Move_Cursor(2, 7);
				cout << "╠════════════════════════════════╝  ╚═╩════════╝";
				Move_Cursor(2, 8);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(2, 9);
				cout << "╚══╣1╬Change my Username║";
				Move_Cursor(2, 10);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(5, 11);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(5, 12);
				cout << "╚══╣2╬Change my Password║";
				Move_Cursor(5, 13);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(8, 14);
				cout << "║  ╔═╦══════════════════════╗";
				Move_Cursor(8, 15);
				cout << "╚══╣3╬Change my Phone number║";
				Move_Cursor(8, 16);
				cout << "   ╠═╩══════════════════════╝";
				Move_Cursor(11, 17);
				cout << "║  ╔═╦═══════════════╗";
				Move_Cursor(11, 18);
				cout << "╚══╣4╬Change my Email║";
				Move_Cursor(11, 19);
				cout << "   ╠═╩═══════════════╝";
				Move_Cursor(14, 20);
				cout << "║  ╔═╦═══════════════════╗";
				Move_Cursor(14, 21);
				cout << "╚══╣5╬Sign up an Employee║";
				Move_Cursor(14, 22);
				cout << "   ╠═╩═══════════════════╝";
				Move_Cursor(17, 23);
				cout << "║  ╔═╦════════════════╗";
				Move_Cursor(17, 24);
				cout << "╚══╣6╬Sign up a Doctor║";
				Move_Cursor(17, 25);
				cout << "   ╠═╩════════════════╝";
				Move_Cursor(20, 26);
				cout << "║  ╔═╦═══════════════╗";
				Move_Cursor(20, 27);
				cout << "╚══╣7╬Print full name║";
				Move_Cursor(20, 28);
				cout << "   ╠═╩═══════════════╝";
				Move_Cursor(23, 29);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(23, 30);
				cout << "╚══╣8╬Print Phone number║";
				Move_Cursor(23, 31);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(26, 32);
				cout << "║  ╔═╦═══════════╗";
				Move_Cursor(26, 33);
				cout << "╚══╣9╬Print Email║";
				Move_Cursor(26, 34);
				cout << "   ╚═╩═══════════╝";
				Move_Cursor(173, 45);
				cout << "╔════════════════════════════════════╗";
				Move_Cursor(173, 46);
				cout << "║ To delete a doctor account press q ║";
				Move_Cursor(173, 47);
				cout << "╠════════════════════════════════╦═══╝";
				Move_Cursor(173, 48);
				cout << "║ To delete your account press d ║";
				Move_Cursor(173, 49);
				cout << "╚════════════════════════════════╝";
				Choice1 = _getch();
				while ((Choice1 < '0' || Choice1 > '9') && Choice1 != 'd' && Choice1 != 'q')
				{
					Move_Cursor(97, 8);
					cout << "╔══════════════╗";
					Move_Cursor(97, 9);
					cout << "║Invalid choice║\a";
					Move_Cursor(97, 10);
					cout << "╚══════════════╝";
					Choice1 = _getch();
				}
				Move_Cursor(97, 8);
				Erase_After_Cursor();
				Move_Cursor(97, 9);
				Erase_After_Cursor();
				Move_Cursor(97, 10);
				Erase_After_Cursor();
				switch (Choice1)
				{
				case'1':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new username║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔═══════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Username can contain numbers, letters & underscore only║";
					Move_Cursor(77, 8);
					cout << "╚═══════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your username╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while ((User.Username_Repeat(temp_string1) || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || Admin.SET_Username(temp_string1))
					{
						Move_Cursor(150, 6);
						Erase_After_Cursor();
						Move_Cursor(150, 7);
						Erase_After_Cursor();
						Move_Cursor(150, 8);
						Erase_After_Cursor();
						if (Admin.SET_Username(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═══════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a correct username║\a";
							Move_Cursor(150, 8);
							cout << "╚═══════════════════════════════╝";
						}
						else if (User.Username_Repeat(temp_string1) || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═════════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a different username║\a";
							Move_Cursor(150, 8);
							cout << "╚═════════════════════════════════╝";
						}
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'2':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new password║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Password can contain letters, numbers & symbols only║";
					Move_Cursor(77, 8);
					cout << "╚════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your password╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while (Admin.SET_Password(temp_string1))
					{
						Move_Cursor(150, 6);
						cout << "╔═══════════════════════════════╗";
						Move_Cursor(150, 7);
						cout << "║Please enter a correct password║\a";
						Move_Cursor(150, 8);
						cout << "╚═══════════════════════════════╝";
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'3':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new phone number║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔═══════════════════════════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║phone number can contain 11 numbers only starting with 010, 011, 012 or 015║";
					Move_Cursor(77, 8);
					cout << "╚═══════════════════════════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your phone number╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while (Admin.SET_Phone_number(temp_string1))
					{
						Move_Cursor(170, 6);
						cout << "╔═══════════════════════════════════╗";
						Move_Cursor(170, 7);
						cout << "║Please enter a correct phone number║\a";
						Move_Cursor(170, 8);
						cout << "╚═══════════════════════════════════╝";
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'4':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Move_Cursor(2, 6);
					cout << "╔═══════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new email║";
					Move_Cursor(2, 8);
					cout << "╠═══════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔═══════════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚═══════════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔═════════════════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Please enter a correct email address example: someone@outlook.com║";
					Move_Cursor(77, 8);
					cout << "╚═════════════════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your email address╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while (Admin.SET_Email(temp_string1))
					{
						Move_Cursor(150, 6);
						cout << "╔════════════════════════════════════╗";
						Move_Cursor(150, 7);
						cout << "║Please enter a correct email address║\a";
						Move_Cursor(150, 8);
						cout << "╚════════════════════════════════════╝";
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'5':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Sign_Up_Employee(User, Admin, Employee, Doctor);
					system("cls");
					Change_Color_FG(37);
					break;
				case'6':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Sign_Up_Doctor(User, Admin, Employee, Doctor);
					system("cls");
					Change_Color_FG(37);
					break;
				case'7':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Admin.GET_Name();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 16)) / 2), 36);
					cout << "╔════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 16)) / 2), 38);
					cout << "╚════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 16)) / 2), 37);
					cout << "║ " << "Full name: " << temp_string1 + " ║";
					break;
				case'8':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Admin.GET_Phone_number();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 19)) / 2), 36);
					cout << "╔═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 19)) / 2), 38);
					cout << "╚═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 19)) / 2), 37);
					cout << "║ " << "Phone number: " << temp_string1 + " ║";
					break;
				case'9':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Admin.GET_Email();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 12)) / 2), 36);
					cout << "╔════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 12)) / 2), 38);
					cout << "╚════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 12)) / 2), 37);
					cout << "║ " << "Email: " << temp_string1 + " ║";
					break;
				case 'd':
					system("cls");
					Move_Cursor(1, 1);
					cout << "╔══════════════════════════════════════════════╗";
					Move_Cursor(1, 2);
					cout << "║ Are you sure you want to delete your account ║\a";
					Move_Cursor(1, 3);
					cout << "╠══════════════════════════════════════════════╝";
					Move_Cursor(1, 4);
					cout << "║";
					Move_Cursor(1, 5);
					cout << "╠═════════════════╗";
					Move_Cursor(1, 6);
					cout << "║ Press Y for yes ║";
					Move_Cursor(1, 7);
					cout << "╠═════════════════╝";
					Move_Cursor(1, 8);
					cout << "║";
					Move_Cursor(1, 9);
					cout << "╠════════════════╗";
					Move_Cursor(1, 10);
					cout << "║ Press N for no ║";
					Move_Cursor(1, 11);
					cout << "╚════════════════╝";
					Choice1 = _getch();
					while (Choice1 != 'Y' && Choice1 != 'y' && Choice1 != 'N' && Choice1 != 'n')
					{
						Move_Cursor(97, 1);
						cout << "╔══════════════╗";
						Move_Cursor(97, 2);
						cout << "║Invalid choice║\a";
						Move_Cursor(97, 3);
						cout << "╚══════════════╝";
						Choice1 = _getch();
					}
					if (Choice1 == 'Y' || Choice1 == 'y')
					{
						Admin.DELETE_Node();
						Active = 0;
						Choice1 = '0';
					}
					system("cls");
					break;
				case 'q':
					system("cls");
					Print_Header(Admin);
					Change_Color_FG(37);
					Move_Cursor(1, 5);
					cout << "╔═════════════════════════════════════════╗";
					Move_Cursor(1, 6);
					cout << "║ Please enter the username of the doctor ╠ ";
					Save_Cursor();
					Move_Cursor(1, 7);
					cout << "╚═════════════════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string1);
					if (!Doctor.SEARCH_Node_Username(temp_string1))
					{
						Move_Cursor(1, 7);
						cout << "╠";
						Move_Cursor(1, 8);
						cout << "║";
						Move_Cursor(1, 9);
						cout << "╠═══════════════════════════════════════════════╗";
						Move_Cursor(1, 10);
						cout << "║ Are you sure you want to delete doctor's data ║\a";
						Move_Cursor(1, 11);
						cout << "╠═══════════════════════════════════════════════╝";
						Move_Cursor(1, 12);
						cout << "║";
						Move_Cursor(1, 13);
						cout << "╠═════════════════╗";
						Move_Cursor(1, 14);
						cout << "║ Press Y for yes ║";
						Move_Cursor(1, 15);
						cout << "╠═════════════════╝";
						Move_Cursor(1, 16);
						cout << "║";
						Move_Cursor(1, 17);
						cout << "╠════════════════╗";
						Move_Cursor(1, 18);
						cout << "║ Press N for no ║";
						Move_Cursor(1, 19);
						cout << "╚════════════════╝";
						Choice1 = _getch();
						while (Choice1 != 'Y' && Choice1 != 'y' && Choice1 != 'N' && Choice1 != 'n')
						{
							Move_Cursor(97, 5);
							cout << "╔══════════════╗";
							Move_Cursor(97, 6);
							cout << "║Invalid choice║\a";
							Move_Cursor(97, 7);
							cout << "╚══════════════╝";
							Choice1 = _getch();
						}
						if (Choice1 == 'Y' || Choice1 == 'y')
						{
							Doctor.DELETE_Node();
						}
					}
					else
					{
						Move_Cursor(97, 5);
						cout << "╔═════════╗";
						Move_Cursor(97, 6);
						cout << "║Not found║\a";
						Move_Cursor(97, 7);
						cout << "╚═════════╝";
						system("pause>0");
					}
					system("cls");
					break;
				}
			}
			Active = '0';
			break;
		case EMPLOYEE:
			while (Choice1 != '0')
			{
				Print_Header(Employee);
				Change_Color_FG(64);
				Move_Cursor(2, 5);
				cout << "╔════════════════════════════════╗  ╔═╦════════╗";
				Move_Cursor(2, 6);
				cout << "║Please choose from the following╠══╣0╬Sign out║";
				Move_Cursor(2, 7);
				cout << "╠════════════════════════════════╝  ╚═╩════════╝";
				Move_Cursor(2, 8);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(2, 9);
				cout << "╚══╣1╬Change my Username║";
				Move_Cursor(2, 10);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(5, 11);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(5, 12);
				cout << "╚══╣2╬Change my Password║";
				Move_Cursor(5, 13);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(8, 14);
				cout << "║  ╔═╦═══════════════════╗";
				Move_Cursor(8, 15);
				cout << "╚══╣3╬Print doctor number║";
				Move_Cursor(8, 16);
				cout << "   ╠═╩═══════════════════╝";
				Move_Cursor(11, 17);
				cout << "║  ╔═╦═════════════════╗";
				Move_Cursor(11, 18);
				cout << "╚══╣4╬Print Doctor list║";
				Move_Cursor(11, 19);
				cout << "   ╠═╩═════════════════╝";
				Move_Cursor(14, 20);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(14, 21);
				cout << "╚══╣5╬Reserve for a user║";
				Move_Cursor(14, 22);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(17, 23);
				cout << "║  ╔═╦═══════════════════════════════╗";
				Move_Cursor(17, 24);
				cout << "╚══╣6╬Change doctor availability time║";
				Move_Cursor(17, 25);
				cout << "   ╠═╩═══════════════════════════════╝";
				Move_Cursor(20, 26);
				cout << "║  ╔═╦═══════════════╗";
				Move_Cursor(20, 27);
				cout << "╚══╣7╬Print full name║";
				Move_Cursor(20, 28);
				cout << "   ╠═╩═══════════════╝";
				Move_Cursor(23, 29);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(23, 30);
				cout << "╚══╣8╬Print Phone number║";
				Move_Cursor(23, 31);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(26, 32);
				cout << "║  ╔═╦═══════════╗";
				Move_Cursor(26, 33);
				cout << "╚══╣9╬Print Email║";
				Move_Cursor(26, 34);
				cout << "   ╚═╩═══════════╝";
				Move_Cursor(177, 47);
				cout << "╔════════════════════════════════╗";
				Move_Cursor(177, 48);
				cout << "║ To delete your account press d ║";
				Move_Cursor(177, 49);
				cout << "╚════════════════════════════════╝";
				Choice1 = _getch();
				while ((Choice1 < '0' || Choice1 > '9') && Choice1 != 'd')
				{
					Move_Cursor(97, 8);
					cout << "╔══════════════╗";
					Move_Cursor(97, 9);
					cout << "║Invalid choice║\a";
					Move_Cursor(97, 10);
					cout << "╚══════════════╝";
					Choice1 = _getch();
				}
				Move_Cursor(97, 8);
				Erase_After_Cursor();
				Move_Cursor(97, 9);
				Erase_After_Cursor();
				Move_Cursor(97, 10);
				Erase_After_Cursor();
				switch (Choice1)
				{
				case'1':
					system("cls");
					Print_Header(Employee);
					Change_Color_FG(64);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new username║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔═══════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Username can contain numbers, letters & underscore only║";
					Move_Cursor(77, 8);
					cout << "╚═══════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your username╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while ((User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || Employee.SET_Username(temp_string1))
					{
						Move_Cursor(150, 6);
						Erase_After_Cursor();
						Move_Cursor(150, 7);
						Erase_After_Cursor();
						Move_Cursor(150, 8);
						Erase_After_Cursor();
						if (Employee.SET_Username(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═══════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a correct username║\a";
							Move_Cursor(150, 8);
							cout << "╚═══════════════════════════════╝";
						}
						else if (User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═════════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a different username║\a";
							Move_Cursor(150, 8);
							cout << "╚═════════════════════════════════╝";
						}
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'2':
					system("cls");
					Print_Header(Employee);
					Change_Color_FG(64);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new password║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Password can contain letters, numbers & symbols only║";
					Move_Cursor(77, 8);
					cout << "╚════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your password╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while (Admin.SET_Password(temp_string1))
					{
						Move_Cursor(150, 6);
						cout << "╔═══════════════════════════════╗";
						Move_Cursor(150, 7);
						cout << "║Please enter a correct password║\a";
						Move_Cursor(150, 8);
						cout << "╚═══════════════════════════════╝";
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'3':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					Move_Cursor(8, 14);
					cout << "║  ╔══════════════════════════════╗";
					Move_Cursor(8, 15);
					cout << "╚══╣Please enter doctor's username╠ ";
					Save_Cursor();
					Move_Cursor(8, 16);
					cout << "   ╠══════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string2);
					Move_Cursor(8, 14);
					Erase_Line();
					Move_Cursor(8, 15);
					Erase_Line();
					Move_Cursor(8, 16);
					Erase_Line();
					Move_Cursor(8, 14);
					cout << "║  ╔═╦═══════════════════╗";
					Move_Cursor(8, 15);
					cout << "╚══╣3╬Print doctor number║";
					Move_Cursor(8, 16);
					cout << "   ╠═╩═══════════════════╝";
					if (Doctor.SEARCH_Node_Username(temp_string2))
					{
						temp_string1 = "Not found\a";
						size = temp_string1.length()-1;
					}
					else
					{
						temp_string1 = "Phone number: " + Doctor.GET_Phone_number();
						size = temp_string1.length();
					}
					Move_Cursor(((212 - size) / 2), 36);
					cout << "╔═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - size) / 2), 38);
					cout << "╚═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - size) / 2), 37);
					cout << "║ " << temp_string1 + " ║";
					break;
				case'4':
					system("cls");
					Print_Header(Employee);
					Change_Color_FG(64);
					Doctor.Reset_Holder();
					if (Doctor.Empty())
					{
						temp_string1 = "List is empty\a";
						size = temp_string1.length()-1;
						Move_Cursor(((212 - size) / 2), 6);
						cout << "╔═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╗";
						Move_Cursor(((212 - size) / 2), 8);
						cout << "╚═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╝";
						Move_Cursor(((212 - size) / 2), 7);
						cout << "║ " << temp_string1 + " ║";
					}
					else
					{
						for (counter2 = 6; ; counter2 += 4)
						{
							temp_string1 = Doctor.GET_Name() + " (" + specializes[Doctor.GET_Specialize()] + ')' + "   " + Doctor.GET_Username();
							size = temp_string1.length();
							Move_Cursor(((212 - (size + 4)) / 2), counter2);
							cout << "╔═";
							for (counter = 0; counter < size; counter++)
							{
								cout << "═";
							}
							cout << "═╗";
							Move_Cursor(((212 - (size + 4)) / 2), counter2 + 2);
							cout << "╚═";
							for (counter = 0; counter < size; counter++)
							{
								cout << "═";
							}
							cout << "═╝";
							Move_Cursor(((212 - (size + 4)) / 2), counter2 + 1);
							cout << "║ " << temp_string1 + " ║";
							if (!Doctor.Next_Node())
							{
								break;
							}
						}
					}
					system("pause>0");
					system("cls");
					break;
				case'5':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					Move_Cursor(14, 20);
					cout << "║  ╔════════════════════════════╗";
					Move_Cursor(14, 21);
					cout << "╚══╣Please enter user's username╠ ";
					Save_Cursor();
					Move_Cursor(14, 22);
					cout << "   ╠════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string2);
					if (User.SEARCH_Node(temp_string2))
					{
						temp_string1 = "Not found\a";
						size = temp_string1.length()-1;
					}
					else
					{
						Move_Cursor(14, 20);
						Erase_Line();
						cout << "║  ╔══════════════════════════════╗";
						Move_Cursor(14, 21);
						Erase_Line();
						cout << "╚══╣Please enter doctor's username╠ ";
						Save_Cursor();
						Move_Cursor(14, 22);
						cout << "   ╠══════════════════════════════╝";
						Restore_Cursor();
						Read_Stream(&temp_string2);
						if (Doctor.SEARCH_Node_Username(temp_string2))
						{
							temp_string1 = "Not found\a";
							size = temp_string1.length()-1;
						}
						else if(Doctor.DECREASE_Remainder())
						{
							temp_string1 = "Doctor is available From: " + Doctor.GET_Available_Start_Time() + " To: " + Doctor.GET_Available_End_Time();
							User.SET_reservation_Name(Doctor.GET_Name());
							Move_Cursor(14, 20);
							Erase_Line();
							cout << "║  ╔════════════════════════════════╗";
							Move_Cursor(14, 22);
							cout << "   ╠════════════════════════════════╝";
							Move_Cursor(14, 21);
							Erase_Line();
							cout << "╚══╣Please enter date of reservation╠ ";
							Save_Cursor();
							Read_Stream(&temp_string2);
							while (User.SET_reservation_Date(Doctor.GET_Available_Start_Time(), temp_string2))
							{
								Restore_Cursor();
								Erase_After_Cursor();
								Move_Cursor(92, 8);
								cout << "╔═════════════════════════╗";
								Move_Cursor(92, 9);
								cout << "║Invalid reservation Date ║\a";
								Move_Cursor(92, 10);
								cout << "╚═════════════════════════╝";
								Restore_Cursor();
								Read_Stream(&temp_string2);
							}
							Move_Cursor(92, 8);
							Erase_After_Cursor();
							Move_Cursor(92, 9);
							Erase_After_Cursor();
							Move_Cursor(92, 10);
							Erase_After_Cursor();
							Doctor.INC_Patient();
							User.ADD_cost(Doctor.GET_Cost());
							size = temp_string1.length();
						}
						else
						{
							temp_string1 = "No reservation time left\a";
							size = temp_string1.length()-1;
						}
					}
					Move_Cursor(((212 - size) / 2), 36);
					cout << "╔═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - size) / 2), 38);
					cout << "╚═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - size) / 2), 37);
					cout << "║ " << temp_string1 + " ║";
					Move_Cursor(14, 20);
					Erase_Line();
					Move_Cursor(14, 21);
					Erase_Line();
					Move_Cursor(14, 22);
					Erase_Line();
					Move_Cursor(14, 20);
					cout << "║  ╔═╦══════════════════╗";
					Move_Cursor(14, 21);
					cout << "╚══╣5╬Reserve for a user║";
					Move_Cursor(14, 22);
					cout << "   ╠═╩══════════════════╝";
					break;
				case'6':

					Move_Cursor(17, 23);
					Erase_Line();
					cout << "║  ╔═╦════════════════════════════╗";
					Move_Cursor(17, 24);
					Erase_Line();
					cout << "╚══╣Please enter doctor's username╠ ";
					Save_Cursor();
					Move_Cursor(17, 25);
					Erase_Line();
					cout << "   ╠═╩════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string1);
					if (Doctor.SEARCH_Node_Username(temp_string1))
					{
						Move_Cursor(17, 23);
						cout << "║  ╔═╦═══════════════════════════════╗";
						Move_Cursor(17, 24);
						Erase_Line();
						cout << "╚══╣6╬Change doctor availability time║";
						Move_Cursor(17, 25);
						cout << "   ╠═╩═══════════════════════════════╝";
						temp_string1 = "Not found\a";
						size = temp_string1.length()-1;
						Move_Cursor(((212 - size) / 2), 36);
						cout << "╔═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╗";
						Move_Cursor(((212 - size) / 2), 38);
						cout << "╚═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╝";
						Move_Cursor(((212 - size) / 2), 37);
						cout << "║ " << temp_string1 + " ║";
					}
					else
					{
						system("cls");
						Print_Header(Employee);
						Move_Cursor(2, 6);
						cout << "╔════════════════════════════════╗";
						Move_Cursor(2, 7);
						cout << "║Please enter your new start time║";
						Move_Cursor(2, 8);
						cout << "╠════════════════════════════════╝";
						Move_Cursor(2, 9);
						cout << "║  ╔═════════════════════════════════╗";
						Move_Cursor(2, 11);
						cout << "   ╚═════════════════════════════════╝";
						Move_Cursor(77, 6);
						cout << "╔════════════════════════════════════════════╗";
						Move_Cursor(77, 7);
						cout << "║Please enter a correct time example: 1:03 AM║";
						Move_Cursor(77, 8);
						cout << "╚════════════════════════════════════════════╝";
						Move_Cursor(2, 10);
						cout << "╚══╣Please enter your work start time╠ ";
						Save_Cursor();
						Read_Stream(&temp_string1);
						while (Doctor.SET_Available_Start_Time(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═════════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a correct start time║\a";
							Move_Cursor(150, 8);
							cout << "╚═════════════════════════════════╝";
							Restore_Cursor();
							Erase_After_Cursor();
							Read_Stream(&temp_string1);
						}
						system("cls");
						Print_Header(Employee);
						Move_Cursor(2, 6);
						cout << "╔══════════════════════════════╗";
						Move_Cursor(2, 7);
						cout << "║Please enter your new end time║";
						Move_Cursor(2, 8);
						cout << "╠══════════════════════════════╝";
						Move_Cursor(2, 9);
						cout << "║  ╔═══════════════════════════════╗";
						Move_Cursor(2, 11);
						cout << "   ╚═══════════════════════════════╝";
						Move_Cursor(77, 6);
						cout << "╔════════════════════════════════════════════╗";
						Move_Cursor(77, 7);
						cout << "║Please enter a correct time example: 1:03 AM║";
						Move_Cursor(77, 8);
						cout << "╚════════════════════════════════════════════╝";
						Move_Cursor(2, 10);
						cout << "╚══╣Please enter your work end time╠ ";
						Save_Cursor();
						Read_Stream(&temp_string1);
						while (Doctor.SET_Available_End_Time(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═══════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a correct end time║\a";
							Move_Cursor(150, 8);
							cout << "╚═══════════════════════════════╝";
							Restore_Cursor();
							Erase_After_Cursor();
							Read_Stream(&temp_string1);
						}
						system("cls");
					}
					break;
				case'7':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Employee.GET_Name();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 16)) / 2), 36);
					cout << "╔════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 16)) / 2), 38);
					cout << "╚════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 16)) / 2), 37);
					cout << "║ " << "Full name: " << temp_string1 + " ║";
					break;
				case'8':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Employee.GET_Phone_number();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 19)) / 2), 36);
					cout << "╔═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 19)) / 2), 38);
					cout << "╚═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 19)) / 2), 37);
					cout << "║ " << "Phone number: " << temp_string1 + " ║";
					break;
				case'9':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = Employee.GET_Email();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 12)) / 2), 36);
					cout << "╔════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 12)) / 2), 38);
					cout << "╚════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 12)) / 2), 37);
					cout << "║ " << "Email: " << temp_string1 + " ║";
					break;
				case 'd':
					system("cls");
					Move_Cursor(1, 1);
					cout << "╔══════════════════════════════════════════════╗";
					Move_Cursor(1, 2);
					cout << "║ Are you sure you want to delete your account ║\a";
					Move_Cursor(1, 3);
					cout << "╠══════════════════════════════════════════════╝";
					Move_Cursor(1, 4);
					cout << "║";
					Move_Cursor(1, 5);
					cout << "╠═════════════════╗";
					Move_Cursor(1, 6);
					cout << "║ Press Y for yes ║";
					Move_Cursor(1, 7);
					cout << "╠═════════════════╝";
					Move_Cursor(1, 8);
					cout << "║";
					Move_Cursor(1, 9);
					cout << "╠════════════════╗";
					Move_Cursor(1, 10);
					cout << "║ Press N for no ║";
					Move_Cursor(1, 11);
					cout << "╚════════════════╝";
					Choice1 = _getch();
					while (Choice1 != 'Y' && Choice1 != 'y' && Choice1 != 'N' && Choice1 != 'n')
					{
						Move_Cursor(97, 1);
						cout << "╔══════════════╗";
						Move_Cursor(97, 2);
						cout << "║Invalid choice║\a";
						Move_Cursor(97, 3);
						cout << "╚══════════════╝";
						Choice1 = _getch();
					}
					if (Choice1 == 'Y' || Choice1 == 'y')
					{
						Employee.DELETE_Node();
						Active = 0;
						Choice1 = '0';
					}
					system("cls");
				}
			}
			Active = 0;
			break;
		case USER:
			while (Choice1 != '0')
			{
				Print_Header(User);
				Change_Color_FG(39);
				Move_Cursor(2, 5);
				cout << "╔════════════════════════════════╗  ╔═╦════════╗";
				Move_Cursor(2, 6);
				cout << "║Please choose from the following╠══╣0╬Sign out║";
				Move_Cursor(2, 7);
				cout << "╠════════════════════════════════╝  ╚═╩════════╝";
				Move_Cursor(2, 8);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(2, 9);
				cout << "╚══╣1╬Change my Username║";
				Move_Cursor(2, 10);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(5, 11);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(5, 12);
				cout << "╚══╣2╬Change my Password║";
				Move_Cursor(5, 13);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(8, 14);
				cout << "║  ╔═╦═══════════════════╗";
				Move_Cursor(8, 15);
				cout << "╚══╣3╬Print doctor number║";
				Move_Cursor(8, 16);
				cout << "   ╠═╩═══════════════════╝";
				Move_Cursor(11, 17);
				cout << "║  ╔═╦═════════════════╗";
				Move_Cursor(11, 18);
				cout << "╚══╣4╬Print Doctor list║";
				Move_Cursor(11, 19);
				cout << "   ╠═╩═════════════════╝";
				Move_Cursor(14, 20);
				cout << "║  ╔═╦═════════════════════╗";
				Move_Cursor(14, 21);
				cout << "╚══╣5╬Reserve with a doctor║";
				Move_Cursor(14, 22);
				cout << "   ╠═╩═════════════════════╝";
				Move_Cursor(17, 23);
				cout << "║  ╔═╦════════════════╗";
				Move_Cursor(17, 24);
				cout << "╚══╣6╬Get money to pay║";
				Move_Cursor(17, 25);
				cout << "   ╠═╩════════════════╝";
				Move_Cursor(20, 26);
				cout << "║  ╔═╦═══════════════╗";
				Move_Cursor(20, 27);
				cout << "╚══╣7╬Print full name║";
				Move_Cursor(20, 28);
				cout << "   ╠═╩═══════════════╝";
				Move_Cursor(23, 29);
				cout << "║  ╔═╦══════════════════╗";
				Move_Cursor(23, 30);
				cout << "╚══╣8╬Print Phone number║";
				Move_Cursor(23, 31);
				cout << "   ╠═╩══════════════════╝";
				Move_Cursor(26, 32);
				cout << "║  ╔═╦═══════════════════════╗";
				Move_Cursor(26, 33);
				cout << "╚══╣9╬Get Reservation detials║";
				Move_Cursor(26, 34);
				cout << "   ╚═╩═══════════════════════╝";
				Move_Cursor(177, 47);
				cout << "╔════════════════════════════════╗";
				Move_Cursor(177, 48);
				cout << "║ To delete your account press d ║";
				Move_Cursor(177, 49);
				cout << "╚════════════════════════════════╝";
				Choice1 = _getch();
				while ((Choice1 < '0' || Choice1 > '9') && Choice1 != 'd')
				{
					Move_Cursor(97, 8);
					cout << "╔══════════════╗";
					Move_Cursor(97, 9);
					cout << "║Invalid choice║\a";
					Move_Cursor(97, 10);
					cout << "╚══════════════╝";
					Choice1 = _getch();
				}
				Move_Cursor(97, 8);
				Erase_After_Cursor();
				Move_Cursor(97, 9);
				Erase_After_Cursor();
				Move_Cursor(97, 10);
				Erase_After_Cursor();
				switch (Choice1)
				{
				case'1':
					system("cls");
					Print_Header(User);
					Change_Color_FG(39);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new username║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔═══════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Username can contain numbers, letters & underscore only║";
					Move_Cursor(77, 8);
					cout << "╚═══════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your username╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while ((User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || User.SET_Username(temp_string1))
					{
						Move_Cursor(150, 6);
						Erase_After_Cursor();
						Move_Cursor(150, 7);
						Erase_After_Cursor();
						Move_Cursor(150, 8);
						Erase_After_Cursor();
						if (User.SET_Username(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═══════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a correct username║\a";
							Move_Cursor(150, 8);
							cout << "╚═══════════════════════════════╝";
						}
						else if (User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
						{
							Move_Cursor(150, 6);
							cout << "╔═════════════════════════════════╗";
							Move_Cursor(150, 7);
							cout << "║Please enter a different username║\a";
							Move_Cursor(150, 8);
							cout << "╚═════════════════════════════════╝";
						}
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'2':
					system("cls");
					Print_Header(User);
					Change_Color_FG(39);
					Move_Cursor(2, 6);
					cout << "╔══════════════════════════════╗";
					Move_Cursor(2, 7);
					cout << "║Please enter your new password║";
					Move_Cursor(2, 8);
					cout << "╠══════════════════════════════╝";
					Move_Cursor(2, 9);
					cout << "║  ╔══════════════════════════╗";
					Move_Cursor(2, 11);
					cout << "   ╚══════════════════════════╝";
					Move_Cursor(77, 6);
					cout << "╔════════════════════════════════════════════════════╗";
					Move_Cursor(77, 7);
					cout << "║Password can contain letters, numbers & symbols only║";
					Move_Cursor(77, 8);
					cout << "╚════════════════════════════════════════════════════╝";
					Move_Cursor(2, 10);
					cout << "╚══╣Please enter your password╠ ";
					Save_Cursor();
					Read_Stream(&temp_string1);
					while (User.SET_Password(temp_string1))
					{
						Move_Cursor(150, 6);
						cout << "╔═══════════════════════════════╗";
						Move_Cursor(150, 7);
						cout << "║Please enter a correct password║\a";
						Move_Cursor(150, 8);
						cout << "╚═══════════════════════════════╝";
						Restore_Cursor();
						Erase_After_Cursor();
						Read_Stream(&temp_string1);
					}
					system("cls");
					break;
				case'3':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					Move_Cursor(8, 14);
					cout << "║  ╔══════════════════════════════╗";
					Move_Cursor(8, 15);
					cout << "╚══╣Please enter doctor's username╠ ";
					Save_Cursor();
					Move_Cursor(8, 16);
					cout << "   ╠══════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string2);
					Move_Cursor(8, 14);
					Erase_Line();
					Move_Cursor(8, 15);
					Erase_Line();
					Move_Cursor(8, 16);
					Erase_Line();
					Move_Cursor(8, 14);
					cout << "║  ╔═╦═══════════════════╗";
					Move_Cursor(8, 15);
					cout << "╚══╣3╬Print doctor number║";
					Move_Cursor(8, 16);
					cout << "   ╠═╩═══════════════════╝";
					if (Doctor.SEARCH_Node_Username(temp_string2))
					{
						temp_string1 = "Not found\a";
						size = temp_string1.length()-1;
					}
					else
					{
						temp_string1 = "Phone number: " + Doctor.GET_Phone_number();
						size = temp_string1.length();
					}
					Move_Cursor(((212 - size) / 2), 36);
					cout << "╔═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - size) / 2), 38);
					cout << "╚═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - size) / 2), 37);
					cout << "║ " << temp_string1 + " ║";
					break;
				case'4':
					system("cls");
					Print_Header(User);
					Change_Color_FG(39);
					Doctor.Reset_Holder();
					if (Doctor.Empty())
					{
						temp_string1 = "List is empty\a";
						size = temp_string1.length()-1;
						Move_Cursor(((212 - size) / 2), 6);
						cout << "╔═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╗";
						Move_Cursor(((212 - size) / 2), 8);
						cout << "╚═";
						for (counter = 0; counter < size; counter++)
						{
							cout << "═";
						}
						cout << "═╝";
						Move_Cursor(((212 - size) / 2), 7);
						cout << "║ " << temp_string1 + " ║";
					}
					else
					{
						for (counter2 = 6; ; counter2 += 4)
						{
							temp_string1 = Doctor.GET_Name() + " (" + specializes[Doctor.GET_Specialize()] + ')' + "   " + Doctor.GET_Username();
							size = temp_string1.length();
							Move_Cursor(((212 - (size + 4)) / 2), counter2);
							cout << "╔═";
							for (counter = 0; counter < size; counter++)
							{
								cout << "═";
							}
							cout << "═╗";
							Move_Cursor(((212 - (size + 4)) / 2), counter2 + 2);
							cout << "╚═";
							for (counter = 0; counter < size; counter++)
							{
								cout << "═";
							}
							cout << "═╝";
							Move_Cursor(((212 - (size + 4)) / 2), counter2 + 1);
							cout << "║ " << temp_string1 + " ║";
							if (!Doctor.Next_Node())
							{
								break;
							}
						}
					}
					system("pause>0");
					system("cls");
					break;
				case'5':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					Move_Cursor(14, 20);
					Erase_Line();
					cout << "║  ╔══════════════════════════════╗";
					Move_Cursor(14, 21);
					Erase_Line();
					cout << "╚══╣Please enter doctor's username╠ ";
					Save_Cursor();
					Move_Cursor(14, 22);
					cout << "   ╠══════════════════════════════╝";
					Restore_Cursor();
					Read_Stream(&temp_string2);
					if (Doctor.SEARCH_Node_Username(temp_string2))
					{
						temp_string1 = "Not found\a";
						size = temp_string1.length()-1;
					}
					else if (Doctor.DECREASE_Remainder())
					{
						temp_string1 = "Doctor is available From: " + Doctor.GET_Available_Start_Time() + " To: " + Doctor.GET_Available_End_Time();
						User.SET_reservation_Name(Doctor.GET_Name());
						Move_Cursor(14, 20);
						Erase_Line();
						cout << "║  ╔════════════════════════════════╗";
						Move_Cursor(14, 22);
						cout << "   ╠════════════════════════════════╝";
						Move_Cursor(14, 21);
						Erase_Line();
						cout << "╚══╣Please enter date of reservation╠ ";
						Save_Cursor();
						Read_Stream(&temp_string2);
						while (User.SET_reservation_Date(Doctor.GET_Available_Start_Time(), temp_string2))
						{
							Restore_Cursor();
							Erase_After_Cursor();
							Move_Cursor(92, 8);
							cout << "╔═════════════════════════╗";
							Move_Cursor(92, 9);
							cout << "║Invalid reservation Date ║\a";
							Move_Cursor(92, 10);
							cout << "╚═════════════════════════╝";
							Restore_Cursor();
							Read_Stream(&temp_string2);
						}
						Move_Cursor(92, 8);
						Erase_After_Cursor();
						Move_Cursor(92, 9);
						Erase_After_Cursor();
						Move_Cursor(92, 10);
						Erase_After_Cursor();
						Doctor.INC_Patient();
						User.ADD_cost(Doctor.GET_Cost());
						size = temp_string1.length();
					}
					else
					{
						temp_string1 = "No reservation time left\a";
						size = temp_string1.length()-1;
					}
					Move_Cursor(((212 - size) / 2), 36);
					cout << "╔═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - size) / 2), 38);
					cout << "╚═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - size) / 2), 37);
					cout << "║ " << temp_string1 + " ║";
					Move_Cursor(14, 20);
					Erase_Line();
					Move_Cursor(14, 21);
					Erase_Line();
					Move_Cursor(14, 22);
					Erase_Line();
					Move_Cursor(14, 20);
					cout << "║  ╔═╦═════════════════════╗";
					Move_Cursor(14, 21);
					cout << "╚══╣5╬Reserve with a doctor║";
					Move_Cursor(14, 22);
					cout << "   ╠═╩═════════════════════╝";
					break;
				case'6':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = to_string(User.GET_cost());
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 16)) / 2), 36);
					cout << "╔═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 16)) / 2), 38);
					cout << "╚═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 16)) / 2), 37);
					cout << "║ " << "Money to pay: " << temp_string1 + " ║";
					break;
				case'7':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = User.GET_Name();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 16)) / 2), 36);
					cout << "╔════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 16)) / 2), 38);
					cout << "╚════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 16)) / 2), 37);
					cout << "║ " << "Full name: " << temp_string1 + " ║";
					break;
				case'8':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					temp_string1 = User.GET_Phone_number();
					size = temp_string1.length();
					Move_Cursor(((212 - (size + 19)) / 2), 36);
					cout << "╔═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size + 19)) / 2), 38);
					cout << "╚═══════════════";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size + 19)) / 2), 37);
					cout << "║ " << "Phone number: " << temp_string1 + " ║";
					break;
				case'9':
					Move_Cursor(1, 36);
					Erase_Line();
					Move_Cursor(1, 37);
					Erase_Line();
					Move_Cursor(1, 38);
					Erase_Line();
					if (User.GET_reservation_Name() != "")
					{
						temp_string1 = "The name of the doctor is: " + User.GET_reservation_Name() + "    The time and date for reservation: " + User.GET_reservation_Date();
						size = temp_string1.length();
					}
					else
					{
						temp_string1 = "No reservations yet\a";
						size = temp_string1.length()-1;
					}
					Move_Cursor(((212 - (size+4)) / 2), 36);
					cout << "╔═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╗";
					Move_Cursor(((212 - (size+4)) / 2), 38);
					cout << "╚═";
					for (counter = 0; counter < size; counter++)
					{
						cout << "═";
					}
					cout << "═╝";
					Move_Cursor(((212 - (size+4)) / 2), 37);
					cout << "║ " << temp_string1 << " ║";
					break;
				case 'd':
					system("cls");
					Move_Cursor(1, 1);
					cout << "╔══════════════════════════════════════════════╗";
					Move_Cursor(1, 2);
					cout << "║ Are you sure you want to delete your account ║\a";
					Move_Cursor(1, 3);
					cout << "╠══════════════════════════════════════════════╝";
					Move_Cursor(1, 4);
					cout << "║";
					Move_Cursor(1, 5);
					cout << "╠═════════════════╗";
					Move_Cursor(1, 6);
					cout << "║ Press Y for yes ║";
					Move_Cursor(1, 7);
					cout << "╠═════════════════╝";
					Move_Cursor(1, 8);
					cout << "║";
					Move_Cursor(1, 9);
					cout << "╠════════════════╗";
					Move_Cursor(1, 10);
					cout << "║ Press N for no ║";
					Move_Cursor(1, 11);
					cout << "╚════════════════╝";
					Choice1 = _getch();
					while (Choice1 != 'Y' && Choice1 != 'y' && Choice1 != 'N' && Choice1 != 'n')
					{
						Move_Cursor(97, 1);
						cout << "╔══════════════╗";
						Move_Cursor(97, 2);
						cout << "║Invalid choice║\a";
						Move_Cursor(97, 3);
						cout << "╚══════════════╝";
						Choice1 = _getch();
					}
					if (Choice1 == 'Y' || Choice1 == 'y')
					{
						User.DELETE_Node();
						Active = 0;
						Choice1 = '0';
					}
					system("cls");
				}
			}
			Active = 0;
			break;
		}
		Save_Data(User, Admin, Employee, Doctor);
	}
	Delete_Dynamic_mem(User, Admin, Employee, Doctor);
}