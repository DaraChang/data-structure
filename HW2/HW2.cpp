#include <iostream>
using namespace std;

//struct和class的定義有參考honor code中附上的影片鏈接 
struct node
{
	public:
		int data;		//儲存資料 
		node* next;	
};

class list
{
	node* temp = NULL, * current = NULL;
	public:
		node* head =  NULL;		//head設為public，是為了可以在main裡呼叫 
		list(int n);
		void remove(int num);	
};

list::list(int n)
{
	//創建一個循環式的linked list 
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
	current = head;		//最後current指向head，temp指向最後一個node 
}

//remove函數也有稍微參考honor code中附上的影片鏈接，但大致上都是自己設計的 
void list::remove(int num)
{
	//尋找欲刪除的節點 
	while(num != 1)
	{
		temp = temp -> next;
		current = current -> next;
		num--;
	}
	
	//ptr指向刪除節點 
	node* ptr;
	ptr = current;
	temp -> next = current -> next;
	current = current -> next; 
	
	//避免head丟失 
	if(ptr == head)
	{
		head = head -> next;
	}
	
	//刪除 
	delete ptr;
}


int main()
{
	int size, num;
	scanf("%d %d", &size, &num);	//題目要求輸入 
	list linkedlist(size);
	
	//刪到剩一個node停止 
	while(size != 1)
	{
		linkedlist.remove(num);
		size--;
	}
	
	printf("%d\n", linkedlist.head -> data);	//印出最後一個node的data 
	
	return 0;
 } 
