#include <iostream>
using namespace std;
struct node
{
	long long data;
	node* lchild;
	node* rchild;	
};

class tree
{
	public:
		node* head = NULL;
		void insert(long long data);
		int compare(long long data, tree model);
};

void tree::insert(long long data)
{
	node* ptr = NULL, * temp = NULL, * current = NULL;
	ptr = new node;
	ptr->data = data;
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	current = head;
	if(current == NULL)
	{
		head =  ptr;
	}
	else
	{
		while(current != NULL)
		{
			temp = current;
			if(data > current->data)
			{
				current = current->rchild;
			} 
			else
			{
				current = current->lchild;
			}
		}	
		if(data > temp->data)
		{
			temp->rchild = ptr;
		}
		else
		{
			temp->lchild = ptr;
		}			
	}
}

int tree::compare(long long data, tree model)
{
	node* ptr = NULL, * temp = NULL, *current = NULL, *ptr2 = NULL;
	ptr = new node;
	ptr->data = data;
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	current = head;
	ptr2 = model.head;
	if(current == NULL)
	{
		if(ptr2 == NULL)
		{
			return 0;
		}
		else if(data == ptr2->data)
		{
			head =  ptr;
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		while(current != NULL)
		{
			temp = current;
			if(data > current->data)
			{
				current = current->rchild;
				ptr2 = ptr2->rchild;
			} 
			else
			{
				current = current->lchild;
				ptr2 = ptr2->lchild;
			}
		}
		if(ptr2 == NULL)
		{
			return 0;
		}
		else if(data == ptr2->data)
		{
			if(data > temp->data)
			{
				temp->rchild = ptr;
			}
			else
			{
				temp->lchild = ptr;
			}
			return 1;						
		}
		else
		{
			return 0;
		}				
	}
}

int main()
{
	long long num, len, i, j, input;
	cin >> len >> num;
	long long* arr = new long long[num];
	for(i = 0; i < num; i++)
	{
		arr[i] = 1;
	}
	int same = 1;
	tree model;
	for(i = 0; i < len; i++)
	{
		cin >> input;
		model.insert(input);
	}
	
	for(j = 0; j < num; j++)
	{
		tree example;
		for(i = 0; i < len; i++)
		{
			cin >> input;
			same = example.compare(input, model);
			if(!same)
			{
				arr[j] = 0;
				break;
			}
			arr[j] = 1;
		}
	}
	
	for(i = 0; i < num; i++)
	{
		if(arr[i])
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
