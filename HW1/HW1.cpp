#include <iostream>
#include <string>
using namespace std;
int main()
{
	int num, temp, carry = 0, length;
	int i, j, k;
	scanf("%d", &num);
	string str1[num], str2[num]; //�Ѧ�honor code���W���Ĥ@���챵�A�ϥ�string�s�x��J�Ʀr 
	string a, b;
	for(i = 0; i < num; i++)
	{
		cin >> a >> b;
		str1[i].insert(str1[i].length(), a); //����string����insert��ƪ��ϥΧڰѦҤFhonor code�����W���ĤG���챵 
		str2[i].insert(str2[i].length(), b);
	}
	
	//���魼�k����ڦ��Ѧ�honor code�����W���Ĥ@���챵�A���Բӹ��O�ۤv�c�� 
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
