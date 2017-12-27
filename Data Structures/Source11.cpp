#include<iostream>
#include<conio.h>
#include<windows.h>

using namespace std;

void gotoXY(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

struct Node
{
int info;

Node *right,*left;
int height;
};
class AVL_Tree
{
protected:
	int hight(Node *temp)
	{
		if(temp==NULL)
			return 0;
		else
		return (temp->height);
	}

	int MAX(int m,int n)
	{
		return ((m>n)?m:n);
	}

	void rr(Node *&temp)
	{
		Node *tem=temp;
		temp=temp->left;
		tem->left=temp->right;
		temp->right=tem;
		tem->height=MAX(hight(tem->left),hight(tem->right))+1;
		temp->height=MAX(hight(temp->left),hight(temp->right))+1;
	}

	void ll(Node *&temp)
	{
		Node *tem=temp;
		temp=temp->right;
		tem->right=temp->left;
		temp->left=tem;	
		tem->height=MAX(hight(tem->left),hight(tem->right))+1;
		temp->height=MAX(hight(temp->left),hight(temp->right))+1;
	}
public:
	int num;
	Node *Root;
	AVL_Tree()
	{
		num=0;
		Root=NULL;
	}

	void insert(Node *&root,int x)
	{
		if (root == NULL)
		{
			root = new Node;
			root->info = x;
			root->left=NULL;
			root->right = NULL;
			root->height=1;
		}
	else
	{
		if (x<root->info)
		{
			insert(root->left,x);
			if ((hight(root->left) - hight(root->right))==2)
			{
				if (x < root->left->info)
				{
					rr(root);
				}
				else
				{
					 ll(root->left);
					 rr(root);
				}
			}
		}
		else if (x>root->info)
		{
			insert(root->right,x);
			if ((hight(root->left) - hight(root->right))==-2)
			{
				if (x > root->right->info)
				{
					ll(root);
				}
				else
				{
					rr(root->right);
					ll(root);
				}
			}
		}
		else
		{
			cout<<"Element Exists\n"<<endl;
		}
	}
root->height=MAX(hight(root->left),hight(root->right))+1;
	}

	void remove(Node *&parent, int &num ){
	
	Node*temp, *root; 
	
	if (parent==NULL) {
		cout << "Nothing to delete";
	}
	else if (parent->info == num)
	{
		 if (parent->right==NULL&&parent->left==NULL){
			 temp = parent;
			 parent = NULL;
			 delete temp;
		 }
		 else if(parent->right==NULL){
			 temp = parent;
			 parent = parent->left;
			 delete temp;
	 
		 }
		 else if(parent->left==NULL){
			 temp = parent;
			 parent = parent->right;
			 delete temp;
		 }
		 else if(parent->right!=NULL&&parent->left!=NULL)
		 {
		
			 root=temp=parent->right;
			 while(temp->left!=NULL){
					 root=temp;
					 temp=temp->left;
			 }
			 if(parent->right==temp)
			 {
				 parent->info=temp->info;
				 if(temp->right==NULL)
					 parent->right=NULL;
				 else
					 parent->right=temp->right;
				 delete temp;
			 }
			 else if(temp->right==NULL&&temp->left==NULL)
			 {
				 parent->info=temp->info;
				 root->left=NULL;
				 delete temp;
			 }
			 else if(temp->right!=NULL)
			 {
				 parent->info=temp->info;
				 root->left=temp->right;
				 delete temp;
			 }
		 }
	}
	 else if (num < parent->info) 
	 {
		remove(parent->left, num);
	 }
	 else 
	 {
		 remove(parent->right, num);
	 }
	 if(parent==NULL)
	 return;
	 else
	 {
	 parent->height=MAX(hight(parent->left),hight(parent->right))+1;
	  if (((hight(parent->left) - hight(parent->right))>=2))
			{
				if ((hight(parent->left->left) - hight(parent->left->right))>=0)
				{
					rr(parent);
				}
				else
				{
					 ll(parent->left);
					 rr(parent);
				}
			}
	  else   if ((hight(parent->left) - hight(parent->right))<=-2)
			{
				if ((hight(parent->right->left) - hight(parent->right->right))<=0)
				{
					ll(parent);
				}
				else
				{
					rr(parent->right);
					ll(parent);
				}
			}
	 }
}

	void print(Node *n, int x = 40, int y = 0, int isRight = -1) {

		if (n == NULL)  {
			gotoXY(x, y);
			cout << "Empty";
			return;
		}

		if (isRight == 1) {
			gotoXY(x + 2, y-1);
			cout << "/";
		}

		if (isRight == 0) {
			gotoXY(x - 2, y-1);
			cout << "\\";
		}
		
		gotoXY(x, y);
		cout << n->info <<"("<<n->height<<")"<< endl;

		if (n->left != NULL) {
			print(n->left, x-5, y+2, 1);
		}
		
		if (n->right != NULL) {
			print(n->right, x+5, y+2, 0);
		}

	}

};
void main()
{
	AVL_Tree obj;
	cout<<"Enter numbers for avl tree :\n";
	for(int i=0;i<9;i++)
	{
		cin>>obj.num;
		obj.insert(obj.Root,obj.num);
	}
	system("cls");
	obj.print(obj.Root);
	for(int i=0;i<13;i++)
	{
		cin>>obj.num;
	obj.remove(obj.Root,obj.num);
	getch();
	system("cls");
	obj.print(obj.Root);
	}
	gotoXY(0,19);
}