#include<iostream>
#include<conio.h>

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
		dummy->left=dummy;
		dummy->lth=child;
		dummy->rth=child;
		Root=NULL;
	}
	void insertion(node *,int );
	void fastInorder(node*);
	void options();
};

void ThreadBST:: insertion(node *temp,int num)
	{
		if(temp==NULL)
		{
			Root=new node;
			dummy->right=Root;
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
	if(p->lth == thread) 
		return(p->left); 
  else { 
	  p = p->left; 
    while(p->rth == child) 
      p = p->right; 
    return p; 
  } 
}
	void ThreadBST::fastInorder(node* p) 
{ 	
	while(  ( p=nextInorder(p) ) != dummy ) 	
		cout << p->info<<" ";
} 
	void ThreadBST :: options()
{
 cout<<"\n\n ************** Select Option *****************.\n";
 cout<<"\n Enter any of choices.\n";
 cout<<"\n 1 : Adding (inserting) node in BST.\n";
 cout<<"\n 2 : Print the whole BST .\n";
 cout<<"\n 3 : Quitting the Program.\n";
}//--------------------------------------------------------------

void main()
{
	int number;
  char ch;
  ThreadBST obj;
  while( 4 )
  {
    obj.options();
    ch=getch();
    switch(ch)
     {
       case '1':
		system("cls");
		cout<<"\n Enter number to add in a tree... \n";
		cin>>number;
		obj.insertion( obj.Root,number);
		break;
	  case '2':
		system("cls");
		obj.fastInorder(obj.dummy);
		break;
       case '3':
		exit(0);
		break;
       default :
		exit(0);
		break;
     } // end of switch.
  } // end of while.
}//-----------------------------------------------

