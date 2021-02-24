#include <iostream>
#include <vector>
using namespace std;
struct node
{
	int data;
	node* next;	
};

//implement stack with linked list
class stack
{
	node* head = NULL, * ptr;
	public:
		void push(int x);
		void pop();
		bool empty();
		int top();	
};

//push a new element to stack
void stack::push(int x)
{
	ptr = new node;
	ptr->data = x;
	ptr->next = head;
	head = ptr;
}

//remove an element from the top of stack
void stack::pop()
{
	ptr = head;
	head = head->next;
	delete ptr;
}

bool stack::empty()
{
	if(head != NULL)
		return 0;
	else
		return 1;
}

int stack::top()
{
	return head->data; //return data of the top of stack 
}

//based on ppt of chapter 4
bool permutation(int* arr, int len)
{
	stack A;
    int i = 1;
    for(int j = 0; j < len; j++)
	{
        while(A.empty() || (arr[j] != A.top()))
        {
        	//arr[j] has been pushed to stack and can't be popped directly
        	if(i > len) 
			{
				return 0;
			}
			else
			{
				A.push(i);		//assume that arr[j] hasn't been pushed to stack
				i++;
			}
		}
		A.pop();	//find arr[j]
	} 
    return 1;  
}

int main()
{
	int num, len;
	int i, j;
	int* arr;
	bool* result;
	cin >> num >> len;
	arr = new int[len];
	result = new bool[num];
	for(i = 0; i < num; i++)
	{
		for(j = 0; j < len; j++)
		{
			cin >> arr[j];
		} 
		result[i] = permutation(arr, len);	//store the results of permutation
	}
	for(i = 0; i < num; i++)
	{
		if(result[i] == 1)
		{
			cout << "Yes" << endl;
		}
		else if(result[i] == 0)
		{
			cout << "No" << endl;
		}
	}
	delete arr;
	delete result;
	return 0;
}
