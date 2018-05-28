#include <iostream>
#include <string>

using namespace std;

int Factorial(int num)
{
	if (num == 0)
		return 1;
	return num * Factorial(num - 1);
}

int CombinationNK(int n, int k)
{
	return Factorial(n) / (Factorial(n - k) * Factorial(k));
}

int CheckExit(string str)
{
	if (str == "exit")
		return 1;
	return 0;
}

int TranslateStringInNumber(string str)
{
	int num = 0;
	for (int i = 0; i < (int)str.size(); i++) {
		if ((int)str[i] < 48 || (int)str[i] > 57)
			return -1;

		num = num * 10 + str[i] - 48;   
	}
	return num;
}

int main()
{
	string str1;
	string str2;
	int flag1 = 0;
	int flag2 = 0;
	int n;
	int k;

	while (1) {
		cout << "Input n(or 'exit' for end program): ";
		cin >> str1;
		if (CheckExit(str1))
			return 0;

		cout << "Input k(or 'exit' for end program): ";
		cin >> str2;
		if (CheckExit(str2))
			return 0;

		if ((n = TranslateStringInNumber(str1)) == -1)
			flag1 = 1;
		if ((k = TranslateStringInNumber(str2)) == -1)
			flag2 = 1;

		if (flag1 == 0 && flag2 == 0 && n >= k) {
			cout << "C(n, k) = " << CombinationNK(n, k) << "\n\n";
		} else {
			cout << "Error, input number" << "\n\n";
		}

		flag1 = 0;
		flag2 = 0;
	}

	return 0;
}