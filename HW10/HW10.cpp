#include <iostream>
#include <vector>
#include <queue> 
using namespace std;

struct Cor
{
	int x;
	int y;
	int step;
};

class point
{
	public:
		int y;		//cor y
		point* next = NULL;		//linkedlist pointer
		//initialize
		point(int a)
		{
			y = a;
		}
};

//tell if the point has been visited
bool find(point* linkedlist, int y)
{
	point* ptr = linkedlist;
	while (ptr != NULL)
	{
		if (ptr->y == y)
		{
			return true;
		}
		ptr = ptr->next;
	}
	return false;
}

//implement by using bfs based on the link attached to honor code
int shortpath(Cor* list, Cor final, int trap_num)
{
	//8 possible ways that horse can move in 
	int arr[8][2] = { {2, 1}, {2, -1}, {-2, -1}, {-2, 1}, {1, 2}, {1, -2}, {-1, -2}, {-1, 2} };
	point* table[201] = { NULL };		//create a table to store the points have been visited
	point* ptr;
	queue<Cor> q;
	Cor prev, curr;
	//set the base point as (0,0)
	prev.step = 0;
	prev.x = 0;
	prev.y = 0;
	table[100] = new point(100);
	//set the points which cannot be visited as visited points
	while (trap_num >= 0)
	{
		ptr = new point(list[trap_num - 1].y + 100);
		ptr->next = table[list[trap_num - 1].x + 100];
		table[list[trap_num - 1].x + 100] = ptr;
		trap_num--;
	}
	q.push(prev);
	while (!q.empty())
	{
		prev = q.front();
		q.pop();
		for (auto a : arr)
		{
			//out of the field
			if (prev.x + a[0] < -100 || prev.x + a[0] > 100 || prev.y + a[1] < -100 || prev.y + a[1] > 100)
			{
				continue;
			}
			//point has been visited
			if (find(table[prev.x + a[0] + 100], prev.y + a[1] + 100) == true)
			{
				continue;
			}
			if (prev.x + a[0] == final.x && prev.y + a[1] == final.y)
			{
				return prev.step + 1;
			}
			else
			{
				curr.x = prev.x + a[0];
				curr.y = prev.y + a[1];
				curr.step = prev.step + 1;
				//set the point as visited
				ptr = new point(curr.y + 100);
				ptr->next = table[curr.x + 100];
				table[curr.x + 100] = ptr;
				q.push(curr);
			}
		}
	}
	//fail to get to the final point
	return -1;
}

int main()
{
	Cor final;
	int trap_num, i;
	int result;
	cin >> final.x >> final.y;
	cin >> trap_num;
	Cor* list = new Cor[trap_num];
	for (i = 0; i < trap_num; i++)
	{
		cin >> list[i].x >> list[i].y;
	}
	result = shortpath(list, final, trap_num);
	if (result != -1)
	{
		cout << result << endl;
	}
	else
	{
		cout << "fail" << endl;
	}
	return 0;
}
