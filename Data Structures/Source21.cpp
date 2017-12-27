#include<iostream>
#include<conio.h>
#include <windows.h>    // SetConsoleCursorPosition()

using namespace std;
class Tree;
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
	Leaf *Array[MAX];
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
		Array[rare]=temp;
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
	Leaf* getfornt()
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

void insert(Leaf *&temp, int value) {
        if (!temp) {
			temp = new Leaf;
            temp->info = value;
            temp->left_child = temp->right_child = NULL;
			Enqueue(temp);
			return;
        }
		Leaf *v=getfornt();
		if (v->left_child==NULL)
			insert(v->left_child,value);
		else if (v->right_child==NULL)
		{
			cout<<"It's Right...\n";
			insert(v->right_child,value);
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
	for(int i=0;i<13;i++)
	{
		obj.insert(obj.Root,i);
	}
	system("cls");
	obj.print(obj.Root);
	gotoXY(0,21);
}
