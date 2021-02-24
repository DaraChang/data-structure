#include <iostream>
#include <queue>
using namespace std;
struct node
{
	int num;
	node* next;
};

struct x
{
	int degree = 0;		//indegree
	node* ptr = NULL;	
};

struct N
{
	int phy = 0;
	int mag = 0;
	int ori = 0;	
};

//return the maximum value between mag, phy, ori and max
int func(N a, int max)
{
	if(a.mag >= a.phy && a.mag >= a.ori && a.mag >= max)
	{
		return a.mag;
	}
	else if(a.phy >= a.mag && a.phy >= a.ori && a.phy >= max)
	{
		return a.phy; 
	}
	else if(a.ori >= a.mag && a.ori >= a.phy && a.ori >= max)
	{
		return a.ori;
	}
	else
	{
		return max;
	}
}

int findmax(x* &table, N* list, int n)
{
	queue<int> q;
	int a, max = 0, phy_temp, mag_temp;
	N* temp = new N[n];
	//find the first node
	for(int i = 0; i < n; i++)
	{
		if(table[i].degree == 0)
		{
			temp[i] = list[i];
			max = func(temp[i], max);
			q.push(i);
		}
	}
	node* ptr;
	//based on the code attached to chapter 11 ppt
	while(!q.empty())
	{
		a = q.front();
		ptr = table[a].ptr;
		while(ptr != NULL)
		{
			phy_temp = temp[a].phy + list[ptr->num].phy;
			mag_temp = temp[a].mag + list[ptr->num].mag;
			//update the physics value of node ptr->num
			if((temp[a].ori + list[ptr->num].phy) > phy_temp && (temp[a].ori + list[ptr->num].phy) > temp[ptr->num].phy)
			{
				temp[ptr->num].phy = temp[a].ori + list[ptr->num].phy;
			}
			else if(phy_temp > temp[ptr->num].phy)
			{
				temp[ptr->num].phy = phy_temp;
			}
			//update the magic value of node ptr->num
			if((temp[a].ori + list[ptr->num].mag) > mag_temp && (temp[a].ori + list[ptr->num].mag) > temp[ptr->num].mag)
			{
				temp[ptr->num].mag = temp[a].ori + list[ptr->num].mag;
			}
			else if(mag_temp > temp[ptr->num].mag)
			{
				temp[ptr->num].mag = mag_temp;
			}
			//update the original value of node ptr->num
			if((temp[a].ori + list[ptr->num].ori) > temp[ptr->num].ori)
			{
				temp[ptr->num].ori = temp[a].ori + list[ptr->num].ori;
			}
			table[ptr->num].degree--;
			//node ptr->num has been fully updated and the maximum sum of attack value till node ptr->num has been saved
			if(table[ptr->num].degree ==  0)
			{
				q.push(ptr->num);
			}
			ptr = ptr->next;
		}
		max = func(temp[a], max);		//record the current maximum value
		q.pop();
	}
	return max;
}
int main()
{
	int n, i, j;
	int attack;
	bool connect, prop;
	cin >> n;
	x* table = new x[n];
	N* list = new N[n];
	node* ptr;
	//adjacency list
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
		{
			cin >> connect;
			if(connect)
			{
				ptr = new node;
				ptr->num = j;
				ptr->next = table[i].ptr;
				table[i].ptr = ptr;
				table[j].degree++;
			}
		}
	}
	for(i = 0; i < n; i++)
	{
		cin >> attack >> prop;
		list[i].ori = attack;
		if(prop)
		{
			list[i].mag = attack * 2;
			list[i].phy = 0;
		}
		else
		{
			list[i].phy = attack * 2;
			list[i].mag = 0;			
		}
	}
	cout << findmax(table, list, n) << endl;
	return 0;
}
