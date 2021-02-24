#include <iostream>
using namespace std;
struct node
{
	int weight;
	int time_down;		//the moment get down the bridge
	node* next;	
};

//construct the queue with linked list based on chapter 4 ppt 
class queue
{
	node* head = NULL, * tail = NULL;
	public:
		void enqueue(int weight, int time_up, int cost);
		void dequeue(int time_up);
		bool broken(int weight_max);
};

int max(int a, int b)
{
	if(a >= b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

void queue::enqueue(int weight, int time_up, int cost)
{
	node* ptr = new node;
	if(head != NULL)
	{
		ptr->weight = weight;
		ptr->time_down = max(tail->time_down, time_up + cost);		//get the bigger value of the moment getting down the bridge between the new node and the previous one, based on the rule the later cannot overtake the former  
		ptr->next = NULL;
		tail->next = ptr;
		tail = ptr;
	}
	else
	{
		ptr->weight = weight;
		ptr->time_down = time_up + cost;
		ptr->next = NULL;
		head = ptr;
		tail = ptr;
	}
}

void queue::dequeue(int time_up)
{
	node* ptr;
	//when enqueueing a new node, check if there is any node can be dequeued 
	while(head->time_down <= time_up)
	{
		ptr = head;
		head = head->next;
		delete ptr;
	}
}

//after enqueueing and dequeueing, check the total weight of the people on the bridge
bool queue::broken(int weight_max)
{
	node* ptr;
	int sum = 0;
	ptr = head;
	while(ptr != NULL)
	{
		sum = sum + ptr->weight;
		ptr = ptr->next;
	}
	if(sum <= weight_max)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	int num, weight_max;
	int weight, time_up, cost;
	int time_broken = -1;
	queue bridge;
	cin >> num >> weight_max;
	for(int i = 1; i <= num; i++)
	{
		cin >> weight >> time_up >> cost;
		//if the beidge hasn't be broken
		if(time_broken == -1)
		{
			bridge.enqueue(weight, time_up, cost);
			bridge.dequeue(time_up);
			if(!bridge.broken(weight_max))
			{
				continue;
			}
			else
			{
				time_broken = i;	//save the time when the bridge is broken
			}
		}
	}
	if(time_broken != -1)
	{
		cout << time_broken << endl;
	}
	else
	{
		cout << "safe" << endl;
	}
 } 
