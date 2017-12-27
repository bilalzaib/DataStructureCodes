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

class CBT
{
protected:
private:
	int count,level;
public:
	int number;
	bool check;
	node* Root;
	CBT()
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
int CBT :: heightp(int h)
	{
		int temp=1;
		for(int i=0;i<h;i++)
			temp*=2;
		return temp;
	}
void CBT :: insert(node*& temp,int val)
	{
		if(temp==NULL)
		{
			temp=new node;
			temp->info=val;
			temp->left=NULL;
			temp->right=NULL;
			count++;
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
			temp->right->info=val;
			temp->right->left=NULL;
			temp->right->right=NULL;
			count++;
			check=true;
			temp->right->id=count;
			return;
		}
	}
			if(temp->left!=NULL)
			insert(temp->left,val);
			if(temp->right!=NULL&&(!check))
			insert(temp->right,val);

	}
void CBT:: in_ord(node *temp)
	{
	   if(temp==NULL)
		 {    cout<<" Tree is empty.\n";       return;    }
	   if( temp->left!=NULL )
    			 in_ord(temp->left);
	   cout<<temp->info<<" ";
	   if( temp->right!=NULL )
    			 in_ord(temp->right);
	}
void CBT:: options()
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
  CBT obj;
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


     
