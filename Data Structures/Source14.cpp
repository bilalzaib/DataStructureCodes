#include<iostream>
#include <cmath>
#include<conio.h>

using namespace std;

struct node
{
	int info;
	int id;
	node* left;
	node* right;
};

class MinHeap
{
protected:
private:
	int count,level;
public:
	int number;
	bool check;
	node* Root;
	MinHeap()
	{
		Root=NULL;
		count=0;
		level=1;
	}
	int heightp(int h);
	void insert(node*& temp,int val);
	void in_ord(node *temp);
	void options();
};
int MinHeap:: heightp(int h)
	{
		int temp=1;
		for(int i=0;i<h;i++)
			temp*=2;
		return temp;
	}
void MinHeap:: insert(node*& temp,int val)
	{
		if(temp==NULL)
		{
			temp=new node;
			temp->info=val;
			temp->left=NULL;
			temp->right=NULL;
			count++;
			check=true;
			temp->id=count;
			return;
		}
		if(count==(heightp(level)-1))
			level++;
	int t=log(temp->id)/log(2);
	if(t<level-1)
	{
		if(temp->left==NULL)
		{
			temp->left=new node;
			if(val<temp->info)
			{
				temp->left->info=temp->info;
				temp->info=val;
			}
			else
				temp->left->info=val;
			temp->left->left=NULL;
			temp->left->right=NULL;
			count++;
			check=true;
			temp->left->id=count;
			return;
		}
		else if(temp->right==NULL)
		{
			temp->right=new node;
			if(val<temp->info)
			{
				temp->right->info=temp->info;
				temp->info=val;
			}
			else
				temp->right->info=val;
			temp->right->left=NULL;
			temp->right->right=NULL;
			count++;
			check=true;
			temp->right->id=count;
			return;
		}
	}
	//Logic for heap will implement there
	int f;
	if(temp->left!=NULL)
	{
		insert(temp->left,val);
		if(check)
		{
			if(temp->left->info<temp->info)
			{
				f=temp->info;
				temp->info=temp->left->info;
				temp->left->info=f;
			}
		}
	}
	if(temp->right!=NULL&&(!check))
	{
		insert(temp->right,val);
		if(check)
		{
			if(temp->right->info<temp->info)
			{
				f=temp->info;
				temp->info=temp->right->info;
				temp->right->info=f;
			}
		}
	}

}
void MinHeap:: in_ord(node *temp)
	{
	   if(temp==NULL)
		 {    cout<<" Tree is empty.\n";       return;    }
	   if( temp->left!=NULL )
    			 in_ord(temp->left);
	   cout<<temp->info<<" ";
	   if( temp->right!=NULL )
    			 in_ord(temp->right);
	}
void MinHeap:: options()
	{
	 cout<<"\n\n ************** Select Option *****************.\n";
	 cout<<"\n Enter any of choices.\n";
	 cout<<"\n 1 : Adding (inserting) node in BST.\n";
	 cout<<"\n 2 : Print the whole BST .\n";
	 cout<<"\n 3 : Quitting the Program.\n";
	}//--------------------------------------------------------------

void main()
{
system("cls");
  char ch;
  MinHeap obj;
  while( 4 )
  {
    obj.options();
    ch=getch();
    switch(ch)
     {
       case '1':
		system("cls");
		cout<<"\n Enter number to add in a tree... \n";
		cin>>obj.number;
		obj.check=false;
		obj.insert( obj.Root,obj.number );
		break;
	  case '2':
		system("cls");
		obj.in_ord(obj.Root);
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


     
