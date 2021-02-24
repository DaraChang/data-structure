#include <iostream>
#include <cmath>
#define MD 119997
using namespace std;
struct Cor
{
	int x, y;
};

struct Point
{
	int num1 = -1, num2 = -1;
	int cnt = 0;
};

int searching(Cor* list, Point* hash, int i, int j, int key)
{
	float slope1, slope2;
	int num = 0, k = key;
	int cnt = hash[key].cnt;	//the number of pairs of points having the same hash key
	while(cnt != 0)
	{
		if((((list[hash[key].num1].x + list[hash[key].num2].x) * 1000 + (list[hash[key].num1].y + list[hash[key].num2].y) * 1234) % MD + MD) % MD == k)
		{
			cnt--;
			if(((list[hash[key].num1].x + list[hash[key].num2].x) == (list[i].x + list[j].x)) && ((list[hash[key].num1].y + list[hash[key].num2].y) == (list[i].y + list[j].y)))	//make sure the two pairs of points having the same midpoint
			{
				if(((list[hash[key].num1].x == list[hash[key].num2].x) && (list[hash[key].num1].y == list[hash[key].num2].y)) || ((list[i].x == list[j].x) && (list[i].y == list[j].y)))	//two pairs of points having the same coordinates
				{
					key = (key + 1) % MD;
					continue;
				}
				else
				{
					//have asked TA to calculate the slopes by multiplication instead of division 
					slope1 = float(list[i].y - list[j].y)*float(list[hash[key].num1].x - list[hash[key].num2].x);
					slope2 = float(list[hash[key].num1].y - list[hash[key].num2].y)*float(list[i].x - list[j].x);
	 				if(slope1 != slope2)
					{
						num++;
					}							
				}
		    }			
		}
		key = (key + 1) % MD;	
	}
	return num;
}

int hashing(Cor* list, Point* &hash, int i, int j)
{
	int key, num;
	key = (((list[i].x + list[j].x) * 1000 + (list[i].y + list[j].y) * 1234) % MD + MD) % MD;	//hash key
	num = searching(list, hash, i, j, key);		//searching for other two points to form a parallelogram
	hash[key].cnt++;
	//finding space to store the new element
	while(hash[key].num1 != -1)
	{
		key = (key + 1) % MD;
	}
	hash[key].num1 = i;
	hash[key].num2 = j;
	return num;
}

int findpara(Cor* list, int point_num)
{
	int sum = 0;	//result
	Point* hash = new Point[MD];
	for(int i = 0; i < point_num - 1; i++)
	{
		for(int j = i + 1; j < point_num; j++)
		{
			sum = sum + hashing(list, hash, i, j);
		}
	}
	delete hash;
	return sum;
}

int main()
{
	int test_num, point_num;
	cin >> test_num;
	int* result = new int[test_num];
	Cor* list;
	for(int i = 0; i < test_num; i++)
	{
		cin >> point_num;
		list = new Cor[point_num]; 
		for(int j = 0; j < point_num; j++)
		{
			cin >> list[j].x >> list[j].y;
		}
		result[i] = findpara(list, point_num);
		delete list;
	}
	for(int i = 0; i < test_num; i++)
	{
		cout << result[i] << endl;
	}
	return 0;
 } 
