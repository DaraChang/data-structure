#include <iostream>
#include <queue>
using namespace std;

int widthTree(BinNode* x)
{
	if(x == NULL)
	{
		return 0;
	}
	int width_max = 1;
	int width_temp = 1;
	BinNode* ptr;
	queue<BinNode*> tree;
	tree.push(x);
	while(!tree.empty())
	{
		for(int i = 0; i < width_temp; i++)
		{
			ptr = tree.front();
			tree.pop();
			if(ptr->leftchild != NULL)
			{
				tree.push(ptr->leftchild);
			} 
			if(ptr->rightchild != NULL)
			{
				tree.push(ptr->rightchild);
			}
		}
		width_temp = tree.size();
		width_max = width_max > width_temp ? width_max : width_temp;
	}
	return width_max;
}

