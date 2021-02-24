#include <iostream>
using namespace std;
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;
};

class tree
{
	BSTNode* root = NULL;
	public:
		void Insert(int data, BSTNode* &ptr);
		void Construct(int len);
		int Ancestor(int input1, int unput2);
};

//recursive
void tree::Insert(int data, BSTNode* &ptr)
{
	if(ptr == NULL)
	{
		ptr = new BSTNode;
		ptr->data = data;
		ptr->right = NULL;
		ptr->left = NULL;
	}
	else if(data > ptr->data)
	{
		Insert(data, ptr->right);
	}
	else
	{
		Insert(data, ptr->left);
	}
}

//construct a new tree by inserting new data based on HW6
void tree::Construct(int len)
{
	int input;
	while(len > 0)
	{
		cin >> input;
		Insert(input, root);
		len--;
	}
}

//finding common ancestor
int tree::Ancestor(int input1, int input2)
{
	BSTNode* ptr = root;
	while(ptr->data != input1 || ptr->data != input2)
	{
		if(input1 > ptr->data && input2 > ptr->data)
		{
			ptr = ptr->right;
		}
		else if(input1 < ptr->data && input2 < ptr->data)
		{
			ptr = ptr->left;
		}
		else
		{
			break;
		}
	}
	return ptr->data;
}

int main()
{
	int len, num, i;
	int input1, input2;
	cin >> len >> num;
	int* arr = new int[num];
	tree x;
	x.Construct(len);
	for(i = 0; i < num; i++)
	{
		cin >> input1 >> input2;
		arr[i] = x.Ancestor(input1, input2);	//save the results in array
	}
	for(i = 0; i < num; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
 } 
