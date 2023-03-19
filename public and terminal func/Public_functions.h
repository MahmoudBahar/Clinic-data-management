#ifndef PUBLIC_FUNCTIONS_H
#define PUBLIC_FUNCTIONS_H

#define number_of_hyphen_in_firstline 211

extern const char* specializes[NUMBER_OF_SPECIALIZES];

void Read_Stream(string* Input)
{
	ShowConsoleCursor(true);
	getline(cin, *Input);
	cin.clear();
	ShowConsoleCursor(false);
}

string GET_Until(string& name, char character)
{
	u8 counter, size = name.length();
	string temp = "";
	for (counter = 0; counter < size; counter++)
	{
		if (name[counter] == character)
		{
			break;
		}
		temp += name[counter];
	}
	return temp;
}

int Digits(int Number)
{
	int counter;
	if (Number == 0)
	{
		return 1;
	}
	for (counter = 0; Number != 0; counter++)
	{
		Number /= 10;
	}
	return counter;
}

template <typename T>
void Print_Header(T& Class)
{
	Change_Color_FG(52);
	Select_Graphic_Rendition(BOLD);
	Select_Graphic_Rendition(ITALIC);
	u8 temp, counter, size;
	string temp_string1 = "";
	temp_string1 = Class.GET_Name();
	temp_string1 = GET_Until(temp_string1, ' ');
	size = temp_string1.length();
	Move_Cursor(((212 - (size + 14)) / 2), 1);
	cout << "╔══════════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╗";
	Move_Cursor(((212 - (size + 14)) / 2), 3);
	cout << "╚══════════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╝";
	Move_Cursor(((212 - (size + 14)) / 2), 2);
	cout << "║"; Select_Graphic_Rendition(INVERT); Change_Color_BG(225); cout << " Welcome: " << temp_string1 << " "; Change_Color_BG(0); Select_Graphic_Rendition(NOT_REVERSED); cout << "║";
	temp_string1 = (Class.GET_Gender() == 0 ? "Male" : "Female");
	size = temp_string1.length();
	Move_Cursor(1, 1);
	cout << "╔═════════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╗";
	Move_Cursor(1, 3);
	cout << "╚═════════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╝";
	Move_Cursor(1, 2);
	cout << "║"; Select_Graphic_Rendition(INVERT); Change_Color_BG(225); cout << " Gender: " << temp_string1 << " "; Change_Color_BG(0); Select_Graphic_Rendition(NOT_REVERSED); cout << "║";
	temp = Class.GET_Age();
	size = Digits(temp);
	Move_Cursor((212 - size - 9), 1);
	cout << "╔══════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╗";
	Move_Cursor((212 - size - 9), 3);
	cout << "╚══════";
	for (counter = 0; counter < size; counter++)
	{
		cout << "═";
	}
	cout << "═╝";
	Move_Cursor((212 - size - 9), 2);
	cout << "║"; Select_Graphic_Rendition(INVERT); Change_Color_BG(225); cout << " Age: " << (u16)temp << " "; Change_Color_BG(0); Select_Graphic_Rendition(NOT_REVERSED); cout << "║";
	Select_Graphic_Rendition(NORMAL_INTENSITY);
	Select_Graphic_Rendition(NOT_ITALIC_BLACKLETTER);
}

void Sign_Up_Admin(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	Change_Color_FG(RED);
	string temp_string1 = "";
	Admin.PUSH_Node();
	Move_Cursor(2, 1);
	cout << "╔═══════════════════════════╗";
	Move_Cursor(2, 2);
	cout << "║Please sign up for an admin║";
	Move_Cursor(2, 3);
	cout << "╠═══════════════════════════╝";
	Move_Cursor(2, 4);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(2, 6);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═══════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Username can contain numbers, letters & underscore only║";
	Move_Cursor(77, 3);
	cout << "╚═══════════════════════════════════════════════════════╝";
	Move_Cursor(2, 5);
	cout << "╚══╣Please enter your username╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while ((User.Username_Repeat(temp_string1) || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || Admin.SET_Username(temp_string1))
	{
		Move_Cursor(150, 1);
		Erase_After_Cursor();
		Move_Cursor(150, 2);
		Erase_After_Cursor();
		Move_Cursor(150, 3);
		Erase_After_Cursor();
		if (Admin.SET_Username(temp_string1))
		{
			Move_Cursor(150, 1);
			cout << "╔═══════════════════════════════╗";
			Move_Cursor(150, 2);
			cout << "║Please enter a correct username║\a";
			Move_Cursor(150, 3);
			cout << "╚═══════════════════════════════╝";
		}
		else if (User.Username_Repeat(temp_string1) || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
		{
			Move_Cursor(150, 1);
			cout << "╔═════════════════════════════════╗";
			Move_Cursor(150, 2);
			cout << "║Please enter a different username║\a";
			Move_Cursor(150, 3);
			cout << "╚═════════════════════════════════╝";
		}
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(5, 6);
	cout << "╠";
	Move_Cursor(5, 7);
	cout << "║  ╔══════════════════════╗";
	Move_Cursor(5, 9);
	cout << "   ╚══════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔══════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Name can contain letters & spaces only║";
	Move_Cursor(77, 3);
	cout << "╚══════════════════════════════════════╝";
	Move_Cursor(5, 8);
	cout << "╚══╣Please enter your name╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Name(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═══════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct name║\a";
		Move_Cursor(150, 3);
		cout << "╚═══════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(8, 9);
	cout << "╠";
	Move_Cursor(8, 10);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(8, 12);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Password can contain letters, numbers & symbols only║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════════════╝";
	Move_Cursor(8, 11);
	cout << "╚══╣Please enter your password╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Password(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct password║\a";
		Move_Cursor(150, 3);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(11, 12);
	cout << "╠";
	Move_Cursor(11, 13);
	cout << "║  ╔══════════════════════════════╗";
	Move_Cursor(11, 15);
	cout << "   ╚══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═══════════════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║phone number can contain 11 numbers only starting with 010, 011, 012 or 015║";
	Move_Cursor(77, 3);
	cout << "╚═══════════════════════════════════════════════════════════════════════════╝";
	Move_Cursor(11, 14);
	cout << "╚══╣Please enter your phone number╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Phone_number(temp_string1))
	{
		Move_Cursor(170, 1);
		cout << "╔═══════════════════════════════════╗";
		Move_Cursor(170, 2);
		cout << "║Please enter a correct phone number║\a";
		Move_Cursor(170, 3);
		cout << "╚═══════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(14, 15);
	cout << "╠";
	Move_Cursor(14, 16);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(14, 18);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct email address example: someone@outlook.com║";
	Move_Cursor(77, 3);
	cout << "╚═════════════════════════════════════════════════════════════════╝";
	Move_Cursor(14, 17);
	cout << "╚══╣Please enter your email address╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Email(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct email address║\a";
		Move_Cursor(150, 3);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(17, 18);
	cout << "╠";
	Move_Cursor(17, 19);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(17, 21);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct date of birth in that form 23/12/2001║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════════════════════╝";
	Move_Cursor(17, 20);
	cout << "╚══╣Please enter your date of birth╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Birth_Date(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct date of birth║\a";
		Move_Cursor(150, 3);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(20, 21);
	cout << "╠";
	Move_Cursor(20, 22);
	cout << "║  ╔════════════════════════╗";
	Move_Cursor(20, 24);
	cout << "   ╚════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct gender Male or Female║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(20, 23);
	cout << "╚══╣Please enter your gender╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Admin.SET_Gender(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct gender║\a";
		Move_Cursor(150, 3);
		cout << "╚═════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Save_Data(User, Admin, Employee, Doctor);
}

void Sign_Up_User(User_C& User, Admin_C &Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	Change_Color_FG(202);
	string temp_string1 = "";
	User.PUSH_Node();
	Move_Cursor(2, 1);
	cout << "╔═════════════════════════╗";
	Move_Cursor(2, 2);
	cout << "║Please sign up for a user║";
	Move_Cursor(2, 3);
	cout << "╠═════════════════════════╝";
	Move_Cursor(2, 4);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(2, 6);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═══════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Username can contain numbers, letters & underscore only║";
	Move_Cursor(77, 3);
	cout << "╚═══════════════════════════════════════════════════════╝";
	Move_Cursor(2, 5);
	cout << "╚══╣Please enter your username╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while ((User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || User.SET_Username(temp_string1))
	{
		Move_Cursor(150, 1);
		Erase_After_Cursor();
		Move_Cursor(150, 2);
		Erase_After_Cursor();
		Move_Cursor(150, 3);
		Erase_After_Cursor();
		if (User.SET_Username(temp_string1))
		{
			Move_Cursor(150, 1);
			cout << "╔═══════════════════════════════╗";
			Move_Cursor(150, 2);
			cout << "║Please enter a correct username║\a";
			Move_Cursor(150, 3);
			cout << "╚═══════════════════════════════╝";
		}
		else if (User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
		{
			Move_Cursor(150, 1);
			cout << "╔═════════════════════════════════╗";
			Move_Cursor(150, 2);
			cout << "║Please enter a different username║\a";
			Move_Cursor(150, 3);
			cout << "╚═════════════════════════════════╝";
		}
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(5, 6);
	cout << "╠";
	Move_Cursor(5, 7);
	cout << "║  ╔══════════════════════╗";
	Move_Cursor(5, 9);
	cout << "   ╚══════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔══════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Name can contain letters & spaces only║";
	Move_Cursor(77, 3);
	cout << "╚══════════════════════════════════════╝";
	Move_Cursor(5, 8);
	cout << "╚══╣Please enter your name╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Name(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═══════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct name║\a";
		Move_Cursor(150, 3);
		cout << "╚═══════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(8, 9);
	cout << "╠";
	Move_Cursor(8, 10);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(8, 12);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Password can contain letters, numbers & symbols only║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════════════╝";
	Move_Cursor(8, 11);
	cout << "╚══╣Please enter your password╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Password(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct password║\a";
		Move_Cursor(150, 3);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(11, 12);
	cout << "╠";
	Move_Cursor(11, 13);
	cout << "║  ╔══════════════════════════════╗";
	Move_Cursor(11, 15);
	cout << "   ╚══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═══════════════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║phone number can contain 11 numbers only starting with 010, 011, 012 or 015║";
	Move_Cursor(77, 3);
	cout << "╚═══════════════════════════════════════════════════════════════════════════╝";
	Move_Cursor(11, 14);
	cout << "╚══╣Please enter your phone number╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Phone_number(temp_string1))
	{
		Move_Cursor(170, 1);
		cout << "╔═══════════════════════════════════╗";
		Move_Cursor(170, 2);
		cout << "║Please enter a correct phone number║\a";
		Move_Cursor(170, 3);
		cout << "╚═══════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(14, 15);
	cout << "╠";
	Move_Cursor(14, 16);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(14, 18);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔═════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct email address example: someone@outlook.com║";
	Move_Cursor(77, 3);
	cout << "╚═════════════════════════════════════════════════════════════════╝";
	Move_Cursor(14, 17);
	cout << "╚══╣Please enter your email address╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Email(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct email address║\a";
		Move_Cursor(150, 3);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(17, 18);
	cout << "╠";
	Move_Cursor(17, 19);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(17, 21);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct date of birth in that form 23/12/2001║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════════════════════╝";
	Move_Cursor(17, 20);
	cout << "╚══╣Please enter your date of birth╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Birth_Date(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct date of birth║\a";
		Move_Cursor(150, 3);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 1);
	Erase_After_Cursor();
	Move_Cursor(77, 2);
	Erase_After_Cursor();
	Move_Cursor(77, 3);
	Erase_After_Cursor();
	Move_Cursor(20, 21);
	cout << "╠";
	Move_Cursor(20, 22);
	cout << "║  ╔════════════════════════╗";
	Move_Cursor(20, 24);
	cout << "   ╚════════════════════════╝";
	Move_Cursor(77, 1);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 2);
	cout << "║Please enter a correct gender Male or Female║";
	Move_Cursor(77, 3);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(20, 23);
	cout << "╚══╣Please enter your gender╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (User.SET_Gender(temp_string1))
	{
		Move_Cursor(150, 1);
		cout << "╔═════════════════════════════╗";
		Move_Cursor(150, 2);
		cout << "║Please enter a correct gender║\a";
		Move_Cursor(150, 3);
		cout << "╚═════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Save_Data(User, Admin, Employee, Doctor);
}

void Sign_Up_Employee(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	Change_Color_FG(94);
	string temp_string1 = "";
	Employee.PUSH_Node();
	Move_Cursor(2, 5);
	cout << "╔══════════════════════════════╗";
	Move_Cursor(2, 6);
	cout << "║Please sign up for an employee║";
	Move_Cursor(2, 7);
	cout << "╠══════════════════════════════╝";
	Move_Cursor(2, 8);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(2, 10);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Username can contain numbers, letters & underscore only║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════════════════╝";
	Move_Cursor(2, 9);
	cout << "╚══╣Please enter your username╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while ((User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || Employee.SET_Username(temp_string1))
	{
		Move_Cursor(150, 5);
		Erase_After_Cursor();
		Move_Cursor(150, 6);
		Erase_After_Cursor();
		Move_Cursor(150, 7);
		Erase_After_Cursor();
		if (Employee.SET_Username(temp_string1))
		{
			Move_Cursor(150, 5);
			cout << "╔═══════════════════════════════╗";
			Move_Cursor(150, 6);
			cout << "║Please enter a correct username║\a";
			Move_Cursor(150, 7);
			cout << "╚═══════════════════════════════╝";
		}
		else if (User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
		{
			Move_Cursor(150, 5);
			cout << "╔═════════════════════════════════╗";
			Move_Cursor(150, 6);
			cout << "║Please enter a different username║\a";
			Move_Cursor(150, 7);
			cout << "╚═════════════════════════════════╝";
		}
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(5, 10);
	cout << "╠";
	Move_Cursor(5, 11);
	cout << "║  ╔══════════════════════╗";
	Move_Cursor(5, 13);
	cout << "   ╚══════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔══════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Name can contain letters & spaces only║";
	Move_Cursor(77, 7);
	cout << "╚══════════════════════════════════════╝";
	Move_Cursor(5, 12);
	cout << "╚══╣Please enter your name╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Name(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct name║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(8, 13);
	cout << "╠";
	Move_Cursor(8, 14);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(8, 16);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Password can contain letters, numbers & symbols only║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════════════╝";
	Move_Cursor(8, 15);
	cout << "╚══╣Please enter your password╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Password(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct password║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(11, 16);
	cout << "╠";
	Move_Cursor(11, 17);
	cout << "║  ╔══════════════════════════════╗";
	Move_Cursor(11, 19);
	cout << "   ╚══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║phone number can contain 11 numbers only starting with 010, 011, 012 or 015║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════════════════════════════════════╝";
	Move_Cursor(11, 18);
	cout << "╚══╣Please enter your phone number╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Phone_number(temp_string1))
	{
		Move_Cursor(170, 5);
		cout << "╔═══════════════════════════════════╗";
		Move_Cursor(170, 6);
		cout << "║Please enter a correct phone number║\a";
		Move_Cursor(170, 7);
		cout << "╚═══════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(14, 19);
	cout << "╠";
	Move_Cursor(14, 20);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(14, 22);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct email address example: someone@outlook.com║";
	Move_Cursor(77, 7);
	cout << "╚═════════════════════════════════════════════════════════════════╝";
	Move_Cursor(14, 21);
	cout << "╚══╣Please enter your email address╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Email(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct email address║\a";
		Move_Cursor(150, 7);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(17, 22);
	cout << "╠";
	Move_Cursor(17, 23);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(17, 25);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct date of birth in that form 23/12/2001║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════════════════════╝";
	Move_Cursor(17, 24);
	cout << "╚══╣Please enter your date of birth╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Birth_Date(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct date of birth║\a";
		Move_Cursor(150, 7);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(20, 25);
	cout << "╠";
	Move_Cursor(20, 26);
	cout << "║  ╔════════════════════════╗";
	Move_Cursor(20, 28);
	cout << "   ╚════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct gender Male or Female║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(20, 27);
	cout << "╚══╣Please enter your gender╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Gender(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct gender║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(23, 28);
	cout << "╠";
	Move_Cursor(23, 29);
	cout << "║  ╔═════════════════════════════════╗";
	Move_Cursor(23, 31);
	cout << "   ╚═════════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct time example: 1:03 AM║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(23, 30);
	cout << "╚══╣Please enter your work start time╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Work_Start(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct start time║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(26, 31);
	cout << "╠";
	Move_Cursor(26, 32);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(26, 34);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct time example: 1:03 AM║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(26, 33);
	cout << "╚══╣Please enter your work end time╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Work_End(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct end time║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(29, 34);
	cout << "╠";
	Move_Cursor(29, 35);
	cout << "║  ╔════════════════════════╗";
	Move_Cursor(29, 37);
	cout << "   ╚════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct salary example: 1000.5║";
	Move_Cursor(77, 7);
	cout << "╚═════════════════════════════════════════════╝";
	Move_Cursor(29, 36);
	cout << "╚══╣Please enter your salary╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Employee.SET_Salary(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct salary║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Save_Data(User, Admin, Employee, Doctor);
}

void Sign_Up_Doctor(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	Change_Color_FG(217);
	string temp_string1 = "";
	Doctor.PUSH_Node();
	Move_Cursor(2, 5);
	cout << "╔═══════════════════════════╗";
	Move_Cursor(2, 6);
	cout << "║Please sign up for a doctor║";
	Move_Cursor(2, 7);
	cout << "╠═══════════════════════════╝";
	Move_Cursor(2, 8);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(2, 10);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Username can contain numbers, letters & underscore only║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════════════════╝";
	Move_Cursor(2, 9);
	cout << "╚══╣Please enter your username╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while ((User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1)) || Doctor.SET_Username(temp_string1))
	{
		Move_Cursor(150, 5);
		Erase_After_Cursor();
		Move_Cursor(150, 6);
		Erase_After_Cursor();
		Move_Cursor(150, 7);
		Erase_After_Cursor();
		if (Doctor.SET_Username(temp_string1))
		{
			Move_Cursor(150, 5);
			cout << "╔═══════════════════════════════╗";
			Move_Cursor(150, 6);
			cout << "║Please enter a correct username║\a";
			Move_Cursor(150, 7);
			cout << "╚═══════════════════════════════╝";
		}
		else if (User.Username_Repeat(temp_string1) || Admin.GET_Username() == temp_string1 || Employee.Username_Repeat(temp_string1) || Doctor.Username_Repeat(temp_string1))
		{
			Move_Cursor(150, 5);
			cout << "╔═════════════════════════════════╗";
			Move_Cursor(150, 6);
			cout << "║Please enter a different username║\a";
			Move_Cursor(150, 7);
			cout << "╚═════════════════════════════════╝";
		}
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(5, 10);
	cout << "╠";
	Move_Cursor(5, 11);
	cout << "║  ╔══════════════════════╗";
	Move_Cursor(5, 13);
	cout << "   ╚══════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔══════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Name can contain letters & spaces only║";
	Move_Cursor(77, 7);
	cout << "╚══════════════════════════════════════╝";
	Move_Cursor(5, 12);
	cout << "╚══╣Please enter your name╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Name(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct name║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(8, 13);
	cout << "╠";
	Move_Cursor(8, 14);
	cout << "║  ╔══════════════════════════╗";
	Move_Cursor(8, 16);
	cout << "   ╚══════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Password can contain letters, numbers & symbols only║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════════════╝";
	Move_Cursor(8, 15);
	cout << "╚══╣Please enter your password╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Password(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct password║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(11, 16);
	cout << "╠";
	Move_Cursor(11, 17);
	cout << "║  ╔══════════════════════════════╗";
	Move_Cursor(11, 19);
	cout << "   ╚══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║phone number can contain 11 numbers only starting with 010, 011, 012 or 015║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════════════════════════════════════╝";
	Move_Cursor(11, 18);
	cout << "╚══╣Please enter your phone number╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Phone_number(temp_string1))
	{
		Move_Cursor(170, 5);
		cout << "╔═══════════════════════════════════╗";
		Move_Cursor(170, 6);
		cout << "║Please enter a correct phone number║\a";
		Move_Cursor(170, 7);
		cout << "╚═══════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(14, 19);
	cout << "╠";
	Move_Cursor(14, 20);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(14, 22);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═════════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct email address example: someone@outlook.com║";
	Move_Cursor(77, 7);
	cout << "╚═════════════════════════════════════════════════════════════════╝";
	Move_Cursor(14, 21);
	cout << "╚══╣Please enter your email address╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Email(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct email address║\a";
		Move_Cursor(150, 7);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(17, 22);
	cout << "╠";
	Move_Cursor(17, 23);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(17, 25);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct date of birth in that form 23/12/2001║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════════════════════╝";
	Move_Cursor(17, 24);
	cout << "╚══╣Please enter your date of birth╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Birth_Date(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔════════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct date of birth║\a";
		Move_Cursor(150, 7);
		cout << "╚════════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(20, 25);
	cout << "╠";
	Move_Cursor(20, 26);
	cout << "║  ╔════════════════════════╗";
	Move_Cursor(20, 28);
	cout << "   ╚════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct gender Male or Female║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(20, 27);
	cout << "╚══╣Please enter your gender╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Gender(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct gender║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(23, 28);
	cout << "╠";
	Move_Cursor(23, 29);
	cout << "║  ╔═════════════════════════════════╗";
	Move_Cursor(23, 31);
	cout << "   ╚═════════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct time example: 1:03 AM║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(23, 30);
	cout << "╚══╣Please enter your work start time╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Available_Start_Time(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct start time║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(26, 31);
	cout << "╠";
	Move_Cursor(26, 32);
	cout << "║  ╔═══════════════════════════════╗";
	Move_Cursor(26, 34);
	cout << "   ╚═══════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct time example: 1:03 AM║";
	Move_Cursor(77, 7);
	cout << "╚════════════════════════════════════════════╝";
	Move_Cursor(26, 33);
	cout << "╚══╣Please enter your work end time╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Available_End_Time(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct end time║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(29, 34);
	cout << "╠";
	Move_Cursor(29, 35);
	cout << "║  ╔════════════════════════════════════╗";
	Move_Cursor(29, 37);
	cout << "   ╚════════════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct cost example: 1000.5║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════╝";
	Move_Cursor(29, 36);
	cout << "╚══╣Please enter your patient check cost╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Cost(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═══════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct cost║\a";
		Move_Cursor(150, 7);
		cout << "╚═══════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(32, 37);
	cout << "╠";
	Move_Cursor(32, 38);
	cout << "║  ╔════════════════════════════════════╗";
	Move_Cursor(32, 40);
	cout << "   ╚════════════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter a correct time for patient in minute║";
	Move_Cursor(77, 7);
	cout << "╚═════════════════════════════════════════════════╝";
	Move_Cursor(32, 39);
	cout << "╚══╣Please enter your patient check time╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Patient_Time(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct check time║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Move_Cursor(77, 5);
	Erase_After_Cursor();
	Move_Cursor(77, 6);
	Erase_After_Cursor();
	Move_Cursor(77, 7);
	Erase_After_Cursor();
	Move_Cursor(35, 40);
	cout << "╠";
	Move_Cursor(35, 41);
	cout << "║  ╔════════════════════════════════════════╗";
	Move_Cursor(35, 43);
	cout << "   ╚════════════════════════════════════════╝";
	Move_Cursor(77, 5);
	cout << "╔═══════════════════════════════════════════════════════════╗";
	Move_Cursor(77, 6);
	cout << "║Please enter choose a correct specialize from the following║";
	Move_Cursor(77, 7);
	cout << "╚═══════════════════════════════════════════════════════════╝";
	for (int counter2 = 10,counter=0; counter < NUMBER_OF_SPECIALIZES; counter2+=2,counter++)
	{
		Move_Cursor(170, counter2);
		cout << specializes[counter] ;
	}
	Move_Cursor(35, 42);
	cout << "╚══╣Please enter the name of your specialize╠ ";
	Save_Cursor();
	Read_Stream(&temp_string1);
	while (Doctor.SET_Specialize(temp_string1))
	{
		Move_Cursor(150, 5);
		cout << "╔═════════════════════════════════╗";
		Move_Cursor(150, 6);
		cout << "║Please enter a correct specialize║\a";
		Move_Cursor(150, 7);
		cout << "╚═════════════════════════════════╝";
		Restore_Cursor();
		Erase_After_Cursor();
		Read_Stream(&temp_string1);
	}
	Save_Data(User, Admin, Employee, Doctor);
}

void Delete_Dynamic_mem(User_C& User, Admin_C& Admin, Employee_C& Employee, Doctor_C& Doctor)
{
	Save_Data(User, Admin, Employee, Doctor);
	if (!Admin.Empty())
	{
		Admin.DELETE_Node();
	}
	while (!User.Empty())
	{
		User.Reset_Holder();
		User.DELETE_Node();
	}
	while (!Employee.Empty())
	{
		Employee.Reset_Holder();
		Employee.DELETE_Node();
	}
	while (!Doctor.Empty())
	{
		Doctor.Reset_Holder();
		Doctor.DELETE_Node();
	}
}

#endif