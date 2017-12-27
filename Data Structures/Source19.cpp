#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

#define LEFT	0
#define RIGHT	1
using namespace std;

struct node {
	int info;
	node *right, *left;
};

void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int whereX() {
	CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
	return consoleinfo.dwCursorPosition.X;
}

int whereY() {
	CONSOLE_SCREEN_BUFFER_INFO consoleinfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &consoleinfo);
	return consoleinfo.dwCursorPosition.Y;
}

class CompleteBinaryTree {
public:
	node *root;
	bool debug;
	int level,bs;
	int totalNode;
	bool flag;
	CompleteBinaryTree(){
			bs=0;
			 root = NULL;
			 debug = true;
			 level = 0;
			 totalNode = 0;
			 flag = false;
	}

	node* getAncestor(node* tmp) {
		if (tmp == NULL) return NULL;
		else if (tmp->left) tmp = getAncestor(tmp->left);
		return tmp;
	}

	void log(string msg) {
		if (debug) cout << msg << endl;
	}

	void print(node *n, int x = 40, int y = 0, int isRight = -1) {
		int tmpY = whereY();

		if (y == 0) y = tmpY;

		if (n == NULL)  {
			gotoXY(x, y);
			cout << "Empty";
			return;
		}

		if (isRight == 1) {
			gotoXY(x + 2, y - 1);
			cout << "/";
		}

		if (isRight == 0) {
			gotoXY(x - 2, y - 1);
			cout << "\\";
		}

		gotoXY(x, y);
		cout << n->info << endl;
		getch();

		if (n->left != NULL) {
			print(n->left, x - 5, y + 2, 1);
		}

		if (n->right != NULL) {
			print(n->right, x + 5, y + 2, 0);
		}

		gotoXY(0, tmpY + maxDepth(this->root) + 4);
	}

	int maxDepth(node *root) {
		if (root == NULL) return 0;
		int left = maxDepth(root->left);
		int right = maxDepth(root->right);
		return (left > right) ? left + 1 : right + 1;
	}

	node* insert(node *tmp, int nodeLevel = 0) {
		if (tmp == NULL) {	
			log("tmp = NULL");
			if (nodeLevel <= level) {
				tmp = new node;
				cout << "Enter value: ";
				cin >> tmp->info;
				tmp->right = NULL;
				tmp->left = NULL;
				totalNode++;
				if (totalNode == (pow(2, level + 1) - 1)) {
					level++;
					log("Level increased.");
				}
				log("totalNode = " + to_string(totalNode));
				flag = true;
				return tmp;
			}

			return NULL;
		}
		else {
					
			if (!flag){
				tmp->left = insert(tmp->left, nodeLevel + 1);
				if(flag)
				{
				if(tmp->left->info<tmp->info)
					{
						bs=tmp->info;
						tmp->info=tmp->left->info;
						tmp->left->info=bs;
					}
				}
			}
			if (!flag){ 
				tmp->right = insert(tmp->right, nodeLevel + 1);
				if(flag)
				{
					if(tmp->right->info<tmp->info)
					{
						bs=tmp->info;
						tmp->info=tmp->right->info;
						tmp->right->info=bs;
					}
				}
			}
		}
		return tmp;
	}

	node* _insert(node *tmp) {
		flag = false;
		return insert(root);
	}
	void  options()
	{
	 cout<<"\n\n ************** Select Option *****************.\n";
	 cout<<"\n Enter any of choices.\n";
	 cout<<"\n 1 : Adding (inserting) node in BST.\n";
	 cout<<"\n 2 : Print the whole BST .\n";
	 cout<<"\n 3 : Quitting the Program.\n";
	}//--------------------------------------------------------------
};



int main() {
	system("cls");
  char ch;
  CompleteBinaryTree obj;
  obj.debug=false;
  while( 4 )
  {
    obj.options();
    ch=getch();
    switch(ch)
     {
       case '1':
		system("cls");
		cout<<"\n Enter number to add in a tree... \n";
		obj.flag=false;
		obj.root=obj.insert( obj.root);
		break;
	  case '2':
		system("cls");
		obj.print(obj.root);
		break;
       case '3':
		exit(0);
		break;
       default :
		exit(0);
		break;
     } // end of switch.
  } // end of while.


	return 0;
}