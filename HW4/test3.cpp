#include <iostream>
using namespace std;
int func(int input)
{
	if(input == 1)
	{
		return 0;
	}	
	else
	{
		if(input%2 == 0)
		{
			return func(input/2) + 1;
		}
		else
		{
			return func(input * 3 + 1) + 1;
		}
	}
}
int main()
{
	int input;
	cin >> input;
	cout << func(input);
	return 0;
}
