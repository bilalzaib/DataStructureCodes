//Double link list in c++
#include <iostream>

using namespace std;

struct node
{
	int info;
	node *next;
	node *prev;
};

class dbllink
{
private:
	node *head;
public:
	dbllink()
	{
		head=NULL;
	}
	void insert()
	{
		node *temp;
		if(head==NULL)
		{
			head=new node;
			cin>>head->info;
			head->prev=NULL;
			head->next=NULL;
			return;
		}
		head->prev=new node;
		temp=head->prev;
		cin>>temp->info;
		temp->next=head;
		head=temp;
		head->prev=NULL;
		return;
	}
	void isert(int key)
	{
		if(head==NULL)
		{
			return;
		}
		node *temp;
		temp=head;
		while(temp!=NULL)
		{
			if(temp->info==key&&temp->next==NULL)
			{
				temp->next=new node;
				cin>>temp->next->info;
				temp->next->prev=temp;
				temp->next->next=NULL;
			}
			else if(temp->info==key)
			{
				temp->next->prev=new node;
				cin>>temp->next->prev->info;
				temp->next->prev->next=temp->next;
				temp->next=temp->next->prev;
				temp->next->prev=temp;
			}
			temp=temp->next;
		}
	}
	void show()
	{
		node *show;
		show=head;
		while(show!=NULL)
		{
			cout<<show->info<<endl;
			show=show->next;
		}
	}
	void del(int key)
	{
		node *temp,*temp1;
		temp=head;
		while(temp!=NULL)
		{
			if(head->info==key)
			{
				temp1=head;
				head=head->next;
				temp=head;
				if(head!=NULL)
				head->prev=NULL;
				delete temp1;
			}
			else if(temp->info==key)
			{
				temp1=temp;
				temp=temp->prev;
				temp->next=temp1->next;
				if(temp1->next!=NULL)
				temp->next->prev=temp;
				delete temp1;
			}
			else 
			{
				temp=temp->next;
			}
		}
	}
};

void main()
{
	//dbllink obj;int key;
	//for(int i=0;i<5;i++)
	//	obj.insert();

	//cout<<"Enter key :";
	//cin>>key;
	////obj.isert(key);

	//obj.del(key);
	//	obj.show();
	//	obj.insert();
	//	obj.show();
	int a;
	cin>>a;
	if(!a)
		cout<<"zero";
	else 
		cout<<"not zero";
}