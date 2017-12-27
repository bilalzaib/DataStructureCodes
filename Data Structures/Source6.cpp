#include <iostream>
#include<stdlib.h>
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
		int t=1;
		while(t!=11)
		{
			if (head == NULL)
			{
				head = new Node;
				head->info=t;
				head->next = head;
				tail=head;
			}
			else
			{
				temp = head;
				head = new Node;
				head->info=t;
				head->next = temp;
				tail->next=head;
			}
			t++;
		}
	}

	void Delete()
	{
		Node *temp2, *temp;
		temp = head;
		while (head->next!=head)
		{
			for(int i=0;i<rand()%5+3;i++)
			 temp = temp->next;
			head=temp;
				temp2 = temp->next;
				if(temp->next==tail)
				{
					 tail=temp;
				}
				temp->next = temp->next->next;
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
};
void main()
{
	LinkList obj;
	obj.insert();
	obj.Delete();
	cout<<"Head After deletion..."<<endl;
	obj.show();
	system("pause");
}

