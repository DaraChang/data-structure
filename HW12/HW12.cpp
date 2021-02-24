#include <iostream>
#include <cmath>
#define MD 200
using namespace std;
struct Cor
{
	int x, y;
};

struct Point
{
	int num1, num2;
	Point* next;
};

int searching(Cor* list, Point** hash, int i, int j, int key)
{
	Point* ptr = hash[key];
	int count = 10;
	float slope1, slope2;
	int num = 0;
	while(ptr != NULL)
	{
		if((list[ptr->num1].x + list[ptr->num2].x) == (list[i].x + list[j].x) && (list[ptr->num1].y + list[ptr->num2].y) == (list[i].y + list[j].y))
		{
			if((list[ptr->num1].x == list[ptr->num2].x && list[ptr->num1].y == list[ptr->num2].y) || (list[i].x == list[j].x && list[i].y == list[j].y))
			{
				continue;
			}
			else
			{
				slope1 = abs(float(list[i].y - list[j].y)/float(list[i].x - list[j].x));
				slope2 = abs(float(list[ptr->num1].y - list[ptr->num2].y)/float(list[ptr->num1].x - list[ptr->num2].x));
 				if(slope1 != slope2)
				{
					num++;
				}							
			}
	    }
		ptr = ptr->next;	
	}
	return num;
}

int hashing(Cor* list, Point** &hash, int i, int j)
{
	int key, num;
	key = (((list[i].x + list[j].x) * 1000 + (list[i].y + list[j].y) * 1234) % MD + MD) % MD;
	num = searching(list, hash, i, j, key);
	Point* ptr = new Point;
	ptr->num1 = i;
	ptr->num2 = j;
	ptr->next = hash[key];
	hash[key] = ptr;
	return num;
}

int findpara(Cor* list, int point_num)
{
	int sum = 0, key;
	Point** hash = new Point* [MD];
	*hash = {NULL};
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
