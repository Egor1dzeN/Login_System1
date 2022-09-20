#include <iostream>
#include <locale.h>
#include<fstream>
#include<string>
#include<stdio.h>
#include <cstdlib>
#include<Windows.h>

HWND myConsole = GetConsoleWindow();
bool checkingForSimilarity(std::string str1) {
	using namespace std;
	ifstream file("C:\\dataBase.txt");
	string str2,str3;
	while (getline(file, str2)) {
		int i = 0;
		for (i; str2[i] != ' '; i++) {
			str3 = str3 + str2[i];
		}
		
		if (str1 == str3) {
			return true;
			break;
		}
		str3 = ""; str2 = "";
	}
	return false;
}
bool IsLoggedIN() {
	using namespace std;
	string username, password, phoneNumber, un, pw, ph, nameOfFile,fullstr;
	int firstprobel;
	printf("Введите имя:  "); cin >> username;
	printf("Введите пароль:  "); cin >> password;
	nameOfFile = "C:\\dataBase.txt";
	ifstream read(nameOfFile);
	while (getline(read, fullstr)) {
		un = ""; pw = ""; firstprobel = 0;
		for (int i = 0; fullstr[i] != ' '; i++) {
			un = un + fullstr[i];
			firstprobel = i;
		}
		firstprobel += 2;
		for (int i = firstprobel; fullstr[i] != ' '; i++) {
			pw = pw + fullstr[i];
		}

		if (un == username && pw == password) {
			return true;
		}
	}	return false;
}
bool checkingPhoneNumber(std::string phoneNumber) {
	using namespace std;
	for (int i = 0; i < phoneNumber.length(); i++)
	{
		if (int(phoneNumber[i]) <= 47 || int(phoneNumber[i]) >= 59)
		{
			return false;
		}
	}
	return true;
}
bool registration() {
	std::string username1, password1,phoneNumber1;
	printf("Введите ваш логин: ");
	std::cin >> username1;
	printf("Введите ваш пароль: ");
	std::cin >> password1;
	printf("Введите ваш телефон: ");
	std::cin >> phoneNumber1;
	if (checkingForSimilarity(username1) == false) {
		if (checkingPhoneNumber(phoneNumber1) == true) {
			std::ofstream out("C:\\dataBase.txt", std::ios::app);
			if (out.is_open()) {
				printf("\n");
				out << username1 + " " + password1 + " " + phoneNumber1 << std::endl;
			}
			out.close();
			return true;
		}
		else
		{
			printf("Вы ввели неправильный номер телефона");
			return false;
		}
	}
	else 
	{
		printf("Такой пользователь уже зарегестрирован");
		return false;
	}
	return true;
}
int main()
{
	ShowWindow(myConsole, 1);
	using namespace std;
	int choise;
	string username,password,str;
    setlocale(LC_ALL, "");
	printf("Выберите,что хотите сделать\n 1. Войти в личный кабинет.\n 2. Зарегестрироваться.\n 3. Выход из программы.\n");
	cin >> choise;
	switch (choise) {
	case 1: 
		if (IsLoggedIN() == true) {
			printf("Вы зашли в личный кабинет");
		}
		else
		{
			printf("Неправильный логин или пароль");
		}
		break;
	case 2:
		if (registration() == true) {
			printf("Успешно зарегестрированы");
		}
		break;
	case 3: 
		ShowWindow(myConsole, 0); 
		break;
	default:
		printf("Введите коректное число...\n");
		main(); break;
	}
	
}
