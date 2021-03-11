#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int CountB(char* str, int itr)
{
	if (strlen(str) < 1) {
		return 0;
	}
	if (str[itr] != 0) {
		if (str[itr] == 'B') {
			return 1 + CountB(str, itr + 1);
		}
		else {
			return CountB(str, itr + 1);
		}
	}
	else {
		return 0;
	}
}
int CountA(char* str, int itr)
{
	if (strlen(str) < 1) {
		return 0;
	}
	if (str[itr] != 0) {
		if (str[itr] == 'A') {
			return 1 + CountA(str, itr + 1);
		}
		else {
			return CountA(str, itr + 1);
		}
	}
	else {
		return 0;
	}
}
int CountS(char* str, int itr)
{
	if (strlen(str) < 1) {
		return 0;
	}
	if (str[itr] != 0) {
		if (str[itr] == 'S') {
			return 1 + CountS(str, itr + 1);
		}
		else {
			return CountS(str, itr + 1);
		}
	}
	else {
		return 0;
	}
}
int CountI(char* str, int itr)
{
	if (strlen(str) < 1) {
		return 0;
	}
	if (str[itr] != 0) {
		if (str[itr] == 'I') {
			return 1 + CountI(str, itr + 1);
		}
		else {
			return CountI(str, itr + 1);
		}
	}
	else {
		return 0;
	}
}
int CountC(char* str, int itr)
{
	if (strlen(str) < 1) {
		return 0;
	}
	if (str[itr] != 0) {
		if (str[itr] == 'C') {
			return 1 + CountC(str, itr + 1);
		}
		else {
			return CountC(str, itr + 1);
		}
	}
	else {
		return 0;
	}
}
char* Change(char* dest, const char* str, char* t, int i)
{
	if (str[i + 4] != 0)
	{
		if (str[i] == 'B' && str[i + 1] == 'A' && str[i + 2] == 'S' && str[i + 3] == 'I' && str[i + 4] == 'C')
		{
			strcat(t, "Delphi");
			return Change(dest, str, t + 6, i + 5);
		}
		else
		{
			*t++ = str[i++];
			*t = '\0';
			return Change(dest, str, t, i);
		}
	}
	else
	{
		*t++ = str[i++];
		*t++ = str[i++];
		*t++ = str[i++];
		*t++ = str[i++];
		*t = '\0';
		return dest;
	}
}
int main()
{
	char str[101];
	int itr = 0;
	int b = 0;
	int a = 0;
	int s = 0;
	int i = 0;
	int c = 0;
	cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << CountB(str, itr) << " B " << CountA(str, itr) << " A " << CountS(str, itr) << " S " << CountI(str, itr) << " I " << CountC(str, itr) << " C " << endl;
	char* dest1 = new char[151];
	dest1[0] = '\0';
	char* dest2;
	dest2 = Change(dest1, str, dest1, 0);
	cout << "Modified string (param) : " << dest1 << endl;
	cout << "Modified string (result): " << dest2 << endl;
	return 0;
}