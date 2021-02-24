#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Vertex
{
	public:
		char data = 48;		//0 ASCII code 
		bool status = 0;	//intialize status as 0(not visited)
};

struct Cor
{
	public:
		int x;
		int y;
};

int max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//change the recursion funtion with while loop function to avoid runtime error after asking others
void func(vector<vector<Vertex>>& matrix, int w, int l, int& area, stack<Cor>& list)
{
	Cor a;
	int x, y;
	while (!list.empty())
	{
		x = list.top().x;
		y = list.top().y;
		//push the bottom vertex to the stack if it exists and is not zero had nor been visted
		if ((x + 1) >= 0 && (x + 1) < w && y >= 0 && y < l && matrix[x + 1][y].data != 48 && matrix[x + 1][y].status != 1)
		{
			a.x = x + 1;
			a.y = y;
			list.push(a);
			matrix[x + 1][y].status = 1;
		}
		//push the right vertex to the stack if it exists and is not zero had nor been visted
		if (x >= 0 && x < w && (y + 1) >= 0 && (y + 1) < l && matrix[x][y + 1].data != 48 && matrix[x][y + 1].status != 1)
		{
			a.x = x;
			a.y = y + 1;
			list.push(a);
			matrix[x][y + 1].status = 1;
		}
		//push the top vertex to the stack if it exists and is not zero had nor been visted
		if ((x - 1) >= 0 && (x - 1) < w && y >= 0 && y < l && matrix[x - 1][y].data != 48 && matrix[x - 1][y].status != 1)
		{
			a.x = x - 1;
			a.y = y;
			list.push(a);
			matrix[x - 1][y].status = 1;
		}
		//push the left vertex to the stack if it exists and is not zero had nor been visted
		if (x >= 0 && x < w && (y - 1) >= 0 && (y - 1) < l && matrix[x][y - 1].data != 48 && matrix[x][y - 1].status != 1)
		{
			a.x = x;
			a.y = y - 1;
			list.push(a);
			matrix[x][y - 1].status = 1;
		}
		//start to backtrack
		if(list.top().x == x && list.top().y == y)
		{
			area++;
			list.pop();
		}
	}
}

//based on the link attached to honor code
int MaxArea(vector<vector<Vertex>> &matrix, int w, int l)
{
	int result = 0, area;
	stack<Cor> list;		//implement DFS of graph
	Cor a;
	if (w == 0 || l == 0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < w; i++)
		{
			for (int j = 0; j < l; j++)
			{
				//if data of the vertex is zero or the vertex had been visited
				if (matrix[i][j].data == 48 || matrix[i][j].status == 1)
				{
					continue;
				}
				else
				{
					area = 0;
					a.x = i;
					a.y = j;
					list.push(a);
					matrix[i][j].status = 1;
					func(matrix, w, l, area, list);
					result = max(result, area);		//save the biggest area as result
				}
			}
		}
	}
	return result;
}

int main()
{
	int w, l, i, j;
	char input;
	cin >> w >> l;
	vector<vector<Vertex>> matrix(w, vector<Vertex>(l));		//create a matrix of size w*l
	for (i = 0; i < w; i++)
	{
		for (j = 0; j < l; j++)
		{
			cin >> input;
			matrix[i][j].data = input;
		}
	}
	cout << MaxArea(matrix, w, l) << endl;
	return 0;
}
