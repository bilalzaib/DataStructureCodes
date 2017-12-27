#include<iostream>
#include<conio.h>
#include <windows.h>    // SetConsoleCursorPosition()

using namespace std;

void gotoXY(int x, int y) {
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct Leaf
{
	int info;
	Leaf *left_child,*right_child;
};
const int MAX=10;

class Queue
{
private:
	int rare, front,size;
	Leaf Array[MAX];
public:
	Queue()
	{
		front=rare=-1;
		size=0;
	}
	bool isEmpty()
	{
		if (size==0)
			return true;
		else 
			return false;
	}
	void Enqueue(Leaf *temp)
	{
		if(size==MAX)
		{
			cout<<"Stack is Full...\n";
			return;
		}
		rare=(++rare)%MAX;
		Array[rare]=*temp;
		size++;
	}
	void Dequeue()
	{
		if(size==0)
		{
			cout<<"Stack is Empty...\n";
			return;
		}
		front=(++front)%MAX;
		size--;
	}
	Leaf getfornt()
	{
		return Array[front+1];
	}
};
class Tree:public Queue
{
private:
public:
	int count;
	Leaf *Root;
	int num;
	Tree()
	{
		count=0;
		Root=NULL;
	}
	void pap(Leaf *&temp, int value)
	{
		 if (!temp) {
			temp = new Leaf;
            temp->info = value;
            temp->left_child = temp->right_child = NULL;
			return;
        }
		 
		 if (temp->right_child==NULL)
		 {
            pap(temp->right_child, value);
		 return;
		 }
		 if (temp->left_child==NULL)
		 {
            pap(temp->left_child, value);
		 return;
		 }
		 pap(temp->right_child,value);
	}
void insert(Leaf *&temp, int value) {
        if (!temp) {
			temp = new Leaf;
            temp->info = value;
            temp->left_child = temp->right_child = NULL;
        }
		else if (value < temp->info)
            insert(temp->left_child, value);
        else if (value > temp->info)
            insert(temp->right_child, value);
		else if(value == temp->info)
		{
			cout<<"Number is already present\n";
			return;
		}
    }
void remove(Leaf *&parent, int &num ){
	
	Leaf *temp, *root; 
	
	temp=parent;
	
	if (parent==NULL) {
		cout << "Nothing to delete";
	}
	else if (parent->info == num){
	 if (parent->right_child==NULL&&parent->left_child==NULL){
	 temp = parent;
	 parent = NULL;
	 delete temp;
	 }
	 else if(parent->right_child==NULL){
	 temp = parent;
	 parent = parent->left_child;
	 delete temp;
	 
	 }
	 else if(parent->left_child==NULL){
	 temp = parent;
	 parent = parent->right_child;
	 delete temp;
	 }
	 else if(parent->right_child!=NULL&&parent->left_child!=NULL)
	 {
		
		 root=temp=parent->right_child;
		 while(temp->left_child!=NULL){
			 root=temp;
			 temp=temp->left_child;
		 }
		 if(parent->right_child==temp)
		 {
			 parent->info=temp->info;
			 if(temp->right_child==NULL)
				 parent->right_child=NULL;
			 else
				 parent->right_child=temp->right_child;
			 delete temp;
		 }
		 else if(temp->right_child==NULL&&temp->left_child==NULL)
		 {
			 parent->info=temp->info;
			 root->left_child=NULL;
			 delete temp;
		 }
		 else if(temp->right_child!=NULL)
		 {
			 parent->info=temp->info;
			 root->left_child=temp->right_child;
			 delete temp;
		 }
	 }
	}
	 else if (num < parent->info) {
	 remove(parent->left_child, num);
	 }
	 else {
		 remove(parent->right_child, num);
	 }	
	
}

void  in_order(Leaf *temp)
{
  if(Root==NULL)
    {
	cout<<" Tree is empty.\n";
	return;
    }
  if(temp->info%2==0)
	  count++;
      if( temp->left_child!=NULL )
    		 in_order(temp->left_child);
      if( temp->right_child!=NULL )
		 in_order(temp->right_child);
  return;
}   
bool search(Leaf *temp)
{
	 if(!temp)
		return false;
	else if(temp->info==num)
		return true;
	else if(temp->info>num)
		search(temp->left_child);
	else if(temp->info<num)
		search(temp->right_child);
}
int hight(Leaf *temp)
{
	int lh,rh;
	if(temp==NULL)
	{
	return 0;
	}
	 lh=hight(temp->left_child);
	 rh=hight(temp->right_child);
	if(lh>rh)
		return lh+1;
	else
		return rh+1;
}
void levlorder(Leaf *temp)
{
	Enqueue(temp);
	while(!isEmpty())
	{
		Leaf *v;
		v=&getfornt();
		if(v->left_child==NULL&&v->right_child==NULL){
			cout<<"Closest Leaf to Root is :";
		cout<<v->info<<endl;
		}
		if(v->left_child!=NULL)
			Enqueue(v->left_child);
		if(v->right_child!=NULL)
			Enqueue(v->right_child);
		Dequeue();	
	}
}
void print(Leaf *n, int x = 40, int y = 0, int isRight = -1) {

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
		cout << n->info << endl;

		if (n->left_child != NULL) {
			print(n->left_child, x-5, y+2, 1);
		}
		
		if (n->right_child != NULL) {
			print(n->right_child, x+5, y+2, 0);
		}

	}
};
void main()
{	
	Tree obj;
	cout<<"Enter numbers for tree\n";
	for(int i=1;i<10;i++)
	{
		obj.pap(obj.Root,i);
	}
	system("cls");
	obj.print(obj.Root);
}
