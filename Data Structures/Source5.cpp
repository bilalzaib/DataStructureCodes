#include <iostream>
using namespace std;
struct Node
{
	int info;
	Node *next;
	Node *prev;
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
			head->prev=head;
			tail=head;
		}
		else
		{
			temp = head;
			head = new Node;
			temp->prev=head;
			cin >> head->info;
			head->next = temp;
			head->prev=tail;
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
				temp->next->prev=temp;
				temp->prev=search;
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
					temp->next->prev=temp;
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
		head->prev=tail;
		tail->next=head;
		if(temp2==temp2->next)
			head=NULL;
		delete temp2;
		}
	}
	void tell()
	{
	int d;
	cin>>d;
	Node *temp,*temp1;
	temp=head;
	temp1=tail;
	do
	{
	if(temp->info==d||temp1->info==d)
	{
		if(temp==temp1)
		{
		cout<<"equal..";
		break;
		}
	else if(temp->info==d)
		{
		cout<<"next..";
		break;
		}
	else if(temp1->info==d)
		{
		cout<<"prev..";
		break;
		}
	}
	temp=temp->next;
	temp1=temp1->prev;
	}while(temp!=head);
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
};
void main()
{
	LinkList obj;
	for (int i = 0; i < 5; i++)
	{
		obj.insert();
	}
	obj.show();
	obj.tell();
	system("pause");
}

