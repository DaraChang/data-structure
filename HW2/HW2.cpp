#include <iostream>
using namespace std;

//struct�Mclass���w�q���Ѧ�honor code�����W���v���챵 
struct node
{
	public:
		int data;		//�x�s��� 
		node* next;	
};

class list
{
	node* temp = NULL, * current = NULL;
	public:
		node* head =  NULL;		//head�]��public�A�O���F�i�H�bmain�̩I�s 
		list(int n);
		void remove(int num);	
};

list::list(int n)
{
	//�Ыؤ@�Ӵ`������linked list 
	for(int i = 1; i <= n; i++)
	{
		current = new node;
		current -> data = i;
		if(i != 1 && i != n)
		{
			temp -> next = current;
		}
		else if(i == 1)
		{
			head = current;
		}
		else
		{
			temp -> next = current;
			current -> next = head;
		}
		temp = current;
	}
	current = head;		//�̫�current���Vhead�Atemp���V�̫�@��node 
}

//remove��Ƥ]���y�L�Ѧ�honor code�����W���v���챵�A���j�P�W���O�ۤv�]�p�� 
void list::remove(int num)
{
	//�M����R�����`�I 
	while(num != 1)
	{
		temp = temp -> next;
		current = current -> next;
		num--;
	}
	
	//ptr���V�R���`�I 
	node* ptr;
	ptr = current;
	temp -> next = current -> next;
	current = current -> next; 
	
	//�קKhead�ᥢ 
	if(ptr == head)
	{
		head = head -> next;
	}
	
	//�R�� 
	delete ptr;
}


int main()
{
	int size, num;
	scanf("%d %d", &size, &num);	//�D�حn�D��J 
	list linkedlist(size);
	
	//�R��Ѥ@��node���� 
	while(size != 1)
	{
		linkedlist.remove(num);
		size--;
	}
	
	printf("%d\n", linkedlist.head -> data);	//�L�X�̫�@��node��data 
	
	return 0;
 } 
