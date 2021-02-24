#include <iostream>
#include <stack>
using namespace std;
void reverseDisplay(int value)
{
	stack<int> s;
	int result = 0, a = 1;
	while(value != 0)
	{
		s.push(value%10);
		value = (value - value%10)/10;
	}
	while(!s.empty())
	{
		result = result + s.top() * a;
		a = a * 10;
		s.pop();
	}
	cout << result;
}

int main()
{
	int input;
	cin >> input;
	reverseDisplay(input);
	return 0;
}
