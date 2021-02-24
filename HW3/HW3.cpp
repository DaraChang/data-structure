#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct node
{
	public:
		char data;		//Àx¦s¸ê®Æ 
		node* next;	
};

class list
{
	node* head = NULL, * tail = NULL, * temp = NULL;
	public:
		list(string str);
		void increase(int num);	
		void decrease(int num);
		void insert(string str);
		void del(int num);
};

list::list(string str)
{
	node* ptr;
	for(int i = 0; i < str.size(); i++)
	{
		ptr = new node;
		ptr -> data = str[i];
		ptr -> next = NULL;
		if(i != 0)
		{
			temp -> next = ptr;
		}
		else
		{
			head = ptr;
		}
		temp = ptr;
	}
	ptr = new node;
	ptr -> next = NULL;
	temp ->  next = ptr;
	tail = ptr;
	temp = head;
}

void list::increase(int num)
{
	
}

int main()
{
	string str, instr, input;
	bool again = 1;
	int num;
	cin >> str;
	list linkedlist(str);
	while(again)
	{
		cin >> instr >> input;
		if(instr == "INC")
		{
			cout << instr;
			printf("%s", input);
			num = atoi(input);
			printf("%d", num);
			//cout << int(input) - 48;
			
		}
		else if(instr == "DEC")
		{
			
		}
		else if(instr == "INS")
		{
			
		}
		else if(instr == "DEL")
		{
			
		}
		else if(instr == "END")
		{
			again = 0;
		}
	}
	return 0;
 } 
