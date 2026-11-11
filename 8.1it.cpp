// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи зустрічається в даній послідовності група з трьох знаків оклику '!',які розташовані поспіль.
// 2.   Замінити кожну трійку сусідніх знаків оклику "!!!" парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

bool Contains(const char* str)
{
	if (strlen(str) < 3)
		return false;

	for (int i = 1; str[i + 1] != 0; i++)

		if (str[i - 1] == '!' && str[i] == '!' && str[i + 1] == '!')

			return true;

	return false;
}

char* Change(char* str)

{

	size_t len = strlen(str);

	char* tmp = new char[len + 1];
	char* t = tmp;

	tmp[0] = '\0';

	size_t i = 0;

	while (i + 2 < len)

	{
		if (str[i] == '!' && str[i + 1] == '!' && str[i + 2] == '!')

		{
			strcat(t, "**");
			t += 2;
			i += 3;
		}

		else

		{
			*t++ = str[i++];
			*t = '\0';
		}
	}
	while (i < len)

		*t++ = str[i++];
	*t = '\0';

	strcpy(str, tmp);

	return tmp;
}


int main()

{

	char str[101];

	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	if (Contains(str))
		cout << "String contains a group of three '!'" << endl;

	else
		cout << "String does not contain a group of three '!'" << endl;

	char* dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	delete[] dest;

	return 0;

}
