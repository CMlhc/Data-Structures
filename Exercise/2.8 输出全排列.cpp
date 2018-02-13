#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string str;
	int n = 0;
	cin >> n;
	switch (n)
	{
	case 1:
		str = "1";
		break;
	case 2:
		str = "12";
		break;
	case 3:
		str = "123";
		break;
	case 4:
		str = "1234";
		break;
	case 5:
		str = "12345";
		break;
	case 6:
		str = "123456";
		break;
	case 7:
		str = "1234567";
		break;
	case 8:
		str = "12345678";
		break;
	case 9:
		str = "123456789";
		break;
	default:
		break;
	}
	sort(str.begin(), str.end());
	cout << str << endl;
	while (next_permutation(str.begin(), str.end()))
	{
		cout << str << endl;
	}

	return 0;
}
