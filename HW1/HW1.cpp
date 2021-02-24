#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num, temp, carry = 0, length;
	int i, j, k;
	scanf("%d", &num);
	string str1[num], str2[num]; //參考honor code附上的第一個鏈接，使用string存儲輸入數字 
	string a, b;
	for(i = 0; i < num; i++)
	{
		cin >> a >> b;
		str1[i].insert(str1[i].length(), a); //關於string類型insert函數的使用我參考了honor code中附上的第二個鏈接 
		str2[i].insert(str2[i].length(), b);
	}
	
	//整體乘法思路我有參考honor code中附上的第一個鏈接，但詳細實踐都是自己構思 
	for(k = 0; k < num; k++)
	{
		int arr[str2[k].size() + str1[k].size()] = {0};
		for(i = str2[k].size() - 1; i >= 0; i--)
		{
			for(j = str1[k].size() - 1; j >= 0; j--)
			{
				temp = arr[str2[k].size() - 1 - i + str1[k].size() - 1 - j] + ((int(str2[k][i]) - 48) * (int(str1[k][j]) - 48) + carry);
				arr[str2[k].size() - 1 - i + str1[k].size() - 1 - j] = temp % 10;
				carry = temp / 10;
			}
			if(carry != 0 && j == -1)
			{
				arr[str2[k].size() - 1 - i + str1[k].size() - 1 + 1] = carry;
				carry = 0;
				length = str2[k].size() - 1 - i + str1[k].size() - 1 + 1;
			}
			else if(j == -1)
			{
				length = str2[k].size() - 1 - i + str1[k].size() - 1;
			}		
		}
	
		while(length >= 0)
		{
			cout << arr[length];
			length--;
		}
		cout << endl;
		
	} 

	
	return 0;
}
