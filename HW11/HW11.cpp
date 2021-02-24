#include <iostream>
#include <queue>
using namespace std;
struct point
{
	public:
		int num = -1;
		point* nxt = NULL;
};

struct Ver
{
	public:
		int indegree = 0;
		int order = -1;
		point* ptr = NULL;
};

//based on the code attached to lesson 11 ppt
bool topology(Ver* table, int ver_num)
{
	queue<int> q;		//bfs
	int n = 0;
	point* ptr;
	for (int i = 0; i < ver_num; i++)
	{
		if (table[i].indegree == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		ptr = table[q.front()].ptr;
		while (ptr != NULL)
		{
			if (--table[ptr->num].indegree == 0)
			{
				q.push(ptr->num);
			}
			ptr = ptr->nxt;
		}
		table[q.front()].order = n;		//orrder of bfs
		q.pop();
		n++;
	}
	//each point has been visited
	if (n == ver_num)
	{
		return 0;		//no loop
	}
	return 1;
}

int func(int a, int b, Ver* table)
{
	queue<int> q;
	point* ptr;
	if (a == b)
	{
		return 0;
	}
	if (table[a].order < table[b].order)
	{
		//a may be b's ancestor
		q.push(a);
	}
	else
	{
		//b may be a's ancestor
		q.push(b);
	}
	//bfs the children of a or b
	while (!q.empty())
	{
		if (table[a].order < table[b].order && q.front() == b)
		{
			//a is b's ancestor
			return 1;
		}
		else if(table[a].order > table[b].order && q.front() == a)
		{
			//b is a's ancestor
			return -1;
		}
		ptr = table[q.front()].ptr;
		while (ptr != NULL)
		{
			q.push(ptr->num);
			ptr = ptr->nxt;
		}
		q.pop();
	}
	//neither a is b's ancestor nor b is a's ancestor
	return 0;
}

int main()
{
	int ver_num, edge_num, test_num, i;
	int a, b;
	bool loop;
	cin >> ver_num >> edge_num >> test_num;
	Ver* table = new Ver[ver_num];
	int* res = new int[test_num];
	for (i = 0; i < edge_num; i++)
	{
		cin >> a >> b;
		point* ptr = new point;
		ptr->num = b;
		ptr->nxt = table[a].ptr;
		table[a].ptr = ptr;
		table[b].indegree++;
	}
	
	loop = topology(table, ver_num);		//tell if there's a loop in the graph
	
	for(i = 0; i < test_num; i++)
	{
		cin >> a >> b;
		if(!loop)
		{
			res[i] = func(a, b, table);		//save the results of each test
		}
	}
	if(!loop)
	{
		for(i = 0; i < test_num; i++)
		{
			cout << res[i] << endl;
		}
	}
	else
	{
		cout << "-1" << endl;
	}
	
	return 0;
}
