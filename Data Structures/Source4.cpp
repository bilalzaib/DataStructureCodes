#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *next;	
};

class LinkList
{
private:
	Node *head,*tail;
public:
	LinkList()
	{
		head = NULL;
		tail = NULL;
	}
	void insert()
	{
		Node *temp;
		if (head == NULL)
		{
			head = new Node;
			cin >> head->info;
			head->next = head;
			tail=head;
		}
		else
		{
			temp = head;
			head = new Node;
			cin >> head->info;
			head->next = temp;
			tail->next=head;
		}
	}
	void insert1()
	{
		int key;
		Node *temp, *search;
		if (head == NULL)
		{
			head = new Node;
			cin >> head->info;
			head->next = NULL;
		}

		cout << "Enter key :";
		cin >> key;
		search = head;
		do
		{
			if (search->info == key)
			{
				temp = new Node;
				cin >> temp->info;
				temp->next = search->next;
				search->next = temp;
				if(search==tail)
					tail=temp;
			}
			search = search->next;
		}
		while (search != head);
	}
	void Delete()
	{
		Node *temp2, *temp;
		int key;
		cout << "Enter key :";
		cin >> key;
		temp = head;
		while (temp!= tail)
		{
				if ( temp->next->info == key)
				{
					temp2 = temp->next;
					if(temp->next==tail)
					{
					 tail=temp;
					}
					temp->next = temp->next->next;
					delete temp2;
				}
				else
				{
					temp = temp->next;
				}
		}
		if(head->info==key)
		{
		temp2=head;
		head=head->next;
		tail->next=head;
		if(temp2==temp2->next)
			head=NULL;
		delete temp2;
		}
	}
	void show()
	{
		Node *temp;
		temp=head;
		if(head!=NULL)
		{
			do
		{
			cout << temp->info << endl;
			temp = temp->next;
		}
		while (temp != head);
		}
		}
		void sorting ()
{
Node * temphead = head;
Node * tempnode = NULL;
int a,counter = 0;
do
{
temphead = temphead->next;
counter++;
}
while (temphead!=head);
cout<<"NODES..."<<counter<<endl;
temphead=head;
for (int i=0; i<counter; i++)
{
	temphead=head;
for (int j=0; j<counter-i; j++)
{
	if ((temphead->info> temphead->next->info))
{
	a = temphead->info;
	temphead->info = temphead->next->info;
	temphead->next->info =a;
	temphead=temphead->next;
}
	else
		temphead=temphead->next;
}
}
}
};
void main()
{
	LinkList obj;
	for (int i = 0; i < 5; i++)
	
		obj.insert();
	
	//obj.insert1();
	obj.show();
	obj.Delete();
	obj.show();
	system("pause");
}
