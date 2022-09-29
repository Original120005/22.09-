#pragma once
#include <iostream>
using namespace std;

class MyString {
private:
	char* str;
	int lenght;

public:
	MyString();
	MyString(int answer);
	MyString(const char* ch);
	~MyString();

	MyString& operator=(const MyString& obj2);
	char operator[](int index);
	operator int() const;

	MyString(MyString&& obj);
	MyString& operator=(MyString&& obj);

	void MyStrcpy(MyString& obj);
	bool MyStrStr(char* str);
	int  MyChr(char c);
	int MyStrLen(const char* str);
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
	int GetString() const;
	char* GetrString() const;


	MyString(initializer_list<char> s) {
		cout << "Size: " << s.size() << endl;
		lenght = s.size();
		str = new char[lenght];
		for (auto x = s.begin(); x != s.end(); x++) {
			*str = *x;
			str++;
		}
		str -= lenght;
	}



	void Input();
	void Print() const;
};
