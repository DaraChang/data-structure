#include <iostream>
using namespace std;
void reverseDisplay(int value)
{
	if(value%10 == 0)
	{
		return;
	}
	else
	{
		cout << value%10;	
		reverseDisplay((value - value%10)/10);	
	}
}
int main()
{
	int input;
	cin >> input;
	reverseDisplay(input);
	return 0;
}
