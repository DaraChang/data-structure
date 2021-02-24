#include <iostream>
using namespace std;

int find_max(BSTNode* root, BSTNode* current)
{
	BSTNode* ptr = root;
	int max = INT_MIN;
	while(ptr != NULL)
	{
		if(ptr->data >= current->data)
		{
			ptr = ptr->left;
		}
		else
		{
			max = ptr->data;
			ptr = ptr->right;
		}
		
	}
	return max;
}

int main()
{
	return 0;
}
