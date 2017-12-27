#include<iostream>

#define thread 1
#define child 0

using namespace std;

struct node
{
	int info;
	node *left,*right;
	bool lth,rth;
};

class ThreadBST
{
private:
	node* nextInorder(node*);
public:
	node* Root,*dummy;
	ThreadBST()
	{
		dummy=new node;
		dummy->right=dummy;
		dummy->lth=child;
		dummy->rth=child;
		Root=NULL;
	}
	void insertion(node *,int );
	void fastInorder(node*); 
};

void ThreadBST:: insertion(node *temp,int num)
	{
		if(temp==NULL)
		{
			Root=new node;
			dummy->left=Root;
			Root->info=num;
			Root->left=dummy;
			Root->right=dummy;
			Root->lth=thread;
			Root->rth=thread;
		}
		else if(num<temp->info)
		{
			if(temp->lth==child)
				insertion(temp->left,num);
			else
			{
				node *temp1=temp->left;
				temp->left=new node;
				temp->lth=child;
				temp->left->info=num;
				temp->left->left=temp1;
				temp->left->right=temp;
				temp->left->lth=thread;
				temp->left->rth=thread;
			}
		}
		else if(num>temp->info)
		{
			if(temp->rth==child)
				insertion(temp->right,num);
			else
			{
				node *temp1=temp->right;
				temp->right=new node;
				temp->rth=child;
				temp->right->info=num;
				temp->right->right=temp1;
				temp->right->left=temp;
				temp->right->lth=thread;
				temp->right->rth=thread;
			}
		}
		else
		{
			cout<<"Number is already exit in Tree!!!\n";
		}
	}
	node* ThreadBST::nextInorder(node* p)
{ 
	if(p->rth == thread) 
		return(p->right); 
  else { 
	  p = p->right; 
    while(p->lth == child) 
      p = p->left; 
    return p; 
  } 
}
	void ThreadBST::fastInorder(node* p) 
{ 	
	while(  ( p=nextInorder(p) ) != dummy ) 	
		cout << p->info<<" ";
} 

void main()
{
	ThreadBST obj;
	int num;
	for(int i=0;i<15;i++)
	{
		cin>>num;
		obj.insertion(obj.Root,num);
	}
	cout<<"Data of Threaded Binary Tree...\n";
	obj.fastInorder(obj.dummy);
}
