#include <iostream>
#include <cmath>
#define MD 119997
using namespace std;
struct Cor
{
	int x, y;
};

struct MidPoint
{
	float slope;
	MidPoint* link = NULL;
};

struct Hash
{
	MidPoint* head = NULL;
	MidPoint* rear = NULL;
	int x, y;
};

int searching(Hash* hash, int key)
{
	int num = 0;
	MidPoint* m1 = hash[key].head;
	while(m1 != hash[key].rear)
	{
		if(m1->slope != hash[key].rear->slope)
			num += 1;
		m1 = m1->link;
	}
	return num;
}

int hashing(Cor* list, Hash* &hash, int i, int j)
{
	int key, num = 0;
	key = (((list[i].x + list[j].x) * 1000 + (list[i].y + list[j].y) * 1234) % MD + MD) % MD;
	MidPoint* mid = new MidPoint;
	mid->slope = float(list[i].x - list[j].x) / (list[i].y - list[j].y);
	while(hash[key].head != NULL && ((hash[key].x != list[i].x + list[j].x) || (hash[key].y != list[i].y + list[j].y))) {
		key = (key + 1) % MD;
	}
	if(hash[key].head == NULL)
	{
		hash[key].head = mid;
		hash[key].rear = mid;
		hash[key].x = list[i].x + list[j].x;
		hash[key].y = list[i].y + list[j].y;
	}
	else
	{
		hash[key].rear->link = mid;
		hash[key].rear = mid;
		num = searching(hash, key);
	}
	return num;
}

int findpara(Cor* list, int point_num)
{
	int sum = 0;
	Hash* hash = new Hash[MD];
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
