#include "Header.h"
#include <iostream>
using namespace std;


MyString::MyString() {
	str = new char[80];
	str = nullptr;
	lenght = 0;
}

MyString::MyString(int answer) {
	this->lenght = answer;
	str = new char[lenght + 1];
}

MyString::MyString(const char* ch) {
	str = new char[strlen(ch) + 1];
	strcpy_s(str, strlen(ch) + 1, ch);

	lenght = 0;
}

MyString::~MyString() {
	delete[]str;
}


MyString& MyString::operator=(const MyString& obj2) {
	if (str != nullptr) {
		delete[]str;
	}

	str = new char[obj2.lenght];
	lenght = obj2.lenght;

	for (int i = 0; i < lenght; i++) {
		str[i] = obj2.str[i];
	}

	return *this;
}

char MyString::operator[](int index) {
	if (index >= 0 && index < strlen(str)) {
		return str[index];
	}
	return '\0';
}

MyString::operator int() const {
	return lenght;
}


MyString::MyString(MyString&& obj) {
	str = obj.str;
	obj.str = nullptr;

	lenght = obj.lenght;
	obj.lenght = 0;
}

MyString& MyString::operator=(MyString&& obj) {
	if (str != nullptr) {
		delete[] str;
	}
	cout << " Move " << endl;
	str = obj.str;
	obj.str = nullptr;

	lenght = obj.lenght;

	return *this;
}


void MyString::MyStrcpy(MyString& obj) {
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
}

bool MyString::MyStrStr(char* str) {
	bool ans = 0;
	if (MyStrLen(str) > lenght) {
		return ans;
	}

	cout << "Enter part of string: ";
	cin.getline(str, 100);
	this->str = new char[strlen(str) + 1];
	strcpy_s(this->str, strlen(str) + 1, str);

	for (int i = 0; i < lenght; i++) {
		ans = 1;
		for (int j = 0; j < MyStrLen(str); j++) {
			if (this->str[j + i] != str[j])
				ans = 0;
		}
		break;
	}
}

int MyString::MyChr(char c) {
	for (int i = 0; i < lenght; i++) {
		if (str[i] == c) {
			cout << "Index: " << i << endl;
		}
	}
	return 0;
}

int MyString::MyStrLen(const char* str) {
	lenght = 0;
	while (str[lenght] != '\0') {
		lenght++;
	}
	return lenght;
}

void MyString::MyStrCat(MyString& b) {
	char* ob = new char[lenght + b.lenght + 1];
	for (int i = 0; i < lenght; i++) {
		ob[i] = str[i];
	}
	for (int i = 0; i < b.lenght; i++) {
		ob[i + lenght] = b.str[i];
	}
	lenght += b.lenght;
	ob[lenght] = '\0';
	delete[] str;
	str = ob;
}

void MyString::MyDelChr(char c) {
	bool check = 0;
	for (int i = 0; i < lenght; i++)
	{
		if (str[i] == c)
		{
			check = 1;
			for (int j = i; j < lenght - 1; j++)
				str[j] = str[j + 1];
			str[lenght] = '\0';
			i--;
			lenght--;
		}
	}
	if (check)
	{
		char* temp = new char[lenght + 1];
		for (int i = 0; i < lenght; i++)
			temp[i] = str[i];
		temp[lenght] = '\0';
		delete[] str;
		str = temp;
	}
}

int MyString::MyStrCmp(MyString& b) {
	char* ob = new char[lenght + b.lenght + 1];
	for (int i = 0; i < lenght; i++)
	{
		ob[i] = str[i];
	}
	for (int i = 0; i < b.lenght; i++)
	{
		ob[i + lenght] = b.str[i];
	}
	lenght += b.lenght;
	ob[lenght] = '\0';
	delete[] str;
	str = ob;

	return 0;
}

int MyString::GetString() const {
	return lenght;
}

char* MyString::GetrString() const {
	return str;
}


void MyString::Input() {
	char s[100];

	cout << "Enter string: ";
	cin.getline(s, 100);

	str = new char[strlen(s) + 1];
	strcpy_s(str, strlen(s) + 1, s);
}

void MyString::Print() const {
	cout << str << endl;
}