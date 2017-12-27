#include<iostream>
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

class Tree
{
private:
public:
	int check;
	Leaf *Root;
	int num;
	Tree()
	{
		check=0;
		Root=NULL;
	}
void insert(Leaf *&temp, int value) {
	if (temp==NULL) {
		cout<<"Root \n";
			temp = new Leaf;
            temp->info = value;
            temp->left_child = temp->right_child = NULL;
        }
	else if(temp->left_child==NULL){
		cout<<"Left \n";
		temp->left_child = new Leaf;
		temp->left_child->info = value;
		temp->left_child ->left_child= temp->left_child->right_child = NULL;
        }
	else if(temp->right_child==NULL){
		cout<<"Right \n";
		temp->right_child = new Leaf;
		temp->right_child->info = value;
          temp->right_child ->left_child= temp->right_child->right_child = NULL;
        }
		else{
			if(!check%2)
			{
				check++;
			insert (temp->left_child,value);
			}
			else
			{
				check++;
			insert (temp->right_child,value);
			}
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
	for (int i=0;i<5;i++)
	{
		cin>>obj.num;
		obj.insert(obj.Root,obj.num);
	}
	obj.print(obj.Root);
}
