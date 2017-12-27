#include <iostream>
using namespace std;

#define MAX_SIZE 5
struct Node
{
	int info;
	Node *next;	
};

class Queue
{
private:
	Node *head,*tail;
	int size;
public:
	Queue()
	{
		size=0;
		head = NULL;
		tail = NULL;
	}
	void Enqueue()
	{
		if(size==MAX_SIZE)
		{
			cout<<"Queue is Full...\n";
			return;
		}
		if (head == NULL)
		{
			head = new Node;
			cin >> head->info;
			head->next = NULL;
			tail=head;
			size++;
		}
		else
		{
			tail->next = new Node;
			tail=tail->next;
			cin >> tail->info;
			tail->next=NULL;
			size++;
		}
	}
	void Dequeue()
	{
		if(head==NULL)
		{
			cout<<"Queue is Empty...\n";
			return;
		}
		Node *temp;
		temp=head;
		head=head->next;
		delete temp;
		size--;
	}
	void show()
	{
		Node *temp;
		temp=head;
		while (temp != NULL)
		{
			cout << temp->info <<"  ";
			temp = temp->next;
		}
	}
};
void main()
{
	Queue obj;
	for (int i = 0; i < MAX_SIZE ;i++)
		obj.Enqueue();
	obj.show();
	cout<<endl;
	for(int j=0;j<6;j++)
		obj.Dequeue();
		obj.show();
		cout<<endl;
		for(int j=0;j<4;j++)
		obj.Enqueue();
		obj.show();
		cout<<endl;
}
