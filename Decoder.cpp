#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Decode(string& data)
{
	unsigned size = data.length();
	for (int counter = 0; counter < size; counter++)
	{
		data[counter] ^= 1;
	}
}

int main()
{
	char choice;
	string temp;
	system("cls");
	cout <<"Please choose one of the files:\n";
	cout << "1- Admin_data\n";
	cout << "2- Doctor_data\n";
	cout << "3- Employee_data\n";
	cout << "4- User_data\n";
	cout << "-->";
	choice = getchar();
	switch (choice)
	{
	case '1' :
		temp = "saved data\\Admin_data.txt";
		break;
	case '2':
		temp = "saved data\\Doctor_data.txt";
		break;
	case '3':
		temp = "saved data\\Employee_data.txt";
		break;
	case '4':
		temp = "saved data\\User_data.txt";
		break;
	default:
		temp = "";
	}
	system("cls");
	ifstream file(temp, ios::in);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, temp);
			Decode(temp);
			cout << temp << endl;
		}
	}
	system("pause>0");
}