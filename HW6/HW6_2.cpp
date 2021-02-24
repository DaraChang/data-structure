#include <iostream>
using namespace std;
//treenode
struct BSTNode
{
	int data;
	BSTNode* left;
	BSTNode* right;	
};

class tree
{
	public:
		BSTNode* root = NULL;
		void Insert(int data, BSTNode* &ptr);
		void Construct(int len);
		void Initialize();
};

//baesd on chapter 6 ppt using recursive
void tree::Insert(int data, BSTNode* &ptr)
{
	if(ptr == NULL)
	{
		ptr = new BSTNode;
		ptr->data = data;
		ptr->left = NULL;
		ptr->right = NULL;
	}
	else if(data > ptr->data)
	{
		Insert(data, ptr->right);
	}
	else if(data < ptr->data)
	{
		Insert(data, ptr->left);
	}
}

//based on the link attached to honor code using recursive 
bool Same(BSTNode* model, BSTNode* example)
{
	if(model == NULL && example == NULL)
	{
		return true;
	}
	else if((model == NULL && example != NULL) || (example == NULL && model != NULL) || (model->data != example->data))
	{
		return false;
	}
	return (Same(model->left, example->left) && Same(model->right, example->right));
}

//baesd on chapter 6 ppt constructing a new tree
void tree::Construct(int len)
{
	int data, i;
	for(i = 0; i < len; i++)
	{
		cin >> data;
		Insert(data, root);
	}
}

void tree::Initialize()
{
	root = NULL;
}

int main()
{
	int num, len, i;	//num:number of loops len:number of nodes in a tree
	cin >> len >> num;
	bool* arr = new bool[num];	//save the results of telling if the trees are the same
	tree model, example;
	model.Construct(len);
	for(i = 0; i < num; i++)
	{
		example.Initialize();
		example.Construct(len);
		arr[i] = Same(model.root, example.root);
	}
	for(i = 0; i < num; i++)
	{
		if(arr[i] == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
