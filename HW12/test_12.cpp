#include <iostream>
#include <cmath>
#include <list>
#define MD 119997
#define MAX 400
using namespace std;

struct Cor
{
	int x;
	int y;
};

struct Hash
{
	int mid_x;
	int mid_y;
	int cnt;
};

Cor p[MAX];

list<Hash> hash[MD];

int res = 0;

void hashInsert(int sum, const Hash h, Cor* p, list<Hash>* hash)
{
	sum %= MD;
	list<Hash>::iterator s = hash[sum].begin(), e = hash[sum].end();
	for (; s != e; s++)
	{
		if (h.mid_x == s->mid_x && h.mid_y == s->mid_y)
		{
			res += s->cnt;
			s->cnt += 1;
			break;
		}
	}
	
	if (s == e)
	{
		hash[sum].push_back(h);
	}
	
	
}

int main()
{
	int test_num, sum, test_data;
	int* result;
	Hash temp;
	cin >> test_data;
	result = new int[test_data];
	for (int i = 0; i < test_data; i++)
	{
		res = 0;
		Cor p[MAX];
		list<Hash> hash[MD];

		cin >> test_num;
		for (int j = 0; j < test_num; j++)
		{
			scanf("%d %d", &p[j].x, &p[j].y);
		}
	
		for (int k = 0; k < test_num - 1; k++)
		{
			for (int l = k + 1; l < test_num; l++)
			{	
				temp.mid_x = p[k].x + p[l].x;
				temp.mid_y = p[k].y + p[l].y;
				temp.cnt = 1;
				sum = temp.mid_x + temp.mid_y;
				hashInsert((sum >= 0?sum:-sum), temp, p, hash);
			}
		}
	
		result[i] = res;
	}
	
	for (int i = 0; i < test_data; i++)
	{
		cout << result[i] << endl;
	}	
	return 0;
 } 
