#include<iostream>
#include<cmath>
#include<conio.h>

#define SIZE 50
using namespace std;

class ArrHeap
{
protected:
	int Lchild(int parent)
	{
		return parent*2+1;
	}
	int Rchild(int parent)
	{
		return parent*2+2;
	}
	int getparent(int child)
	{
		return int((child-1)/2);
	}
	void siftdown(int parent)
	{
		int tmp;
		int min;
		int LC= Lchild(parent);
		int RC=Rchild(parent);
	if (RC >= count) {
            if (LC >= count)
                  return;
            else
                  min = LC;
      } else {
		  if (MinHeap[LC] <= MinHeap[RC])
                  min = LC;
            else
                  min = RC;
      }
      if (MinHeap[parent] > MinHeap[min]) {
            tmp = MinHeap[min];
            MinHeap[min] = MinHeap[parent];
            MinHeap[parent] = tmp;
            siftdown(min);
      }	
	}

	void siftup(int child)
	{
		int tmp;
		int parent=getparent(child);
		if(child!=0)
		{
			if(MinHeap[parent]>MinHeap[child])
			{
				tmp = MinHeap[child];
				MinHeap[child] = MinHeap[parent];
				MinHeap[parent] = tmp;
				siftup(parent);
			}
		}
	}
private:
	int count;
public:
	int MinHeap[SIZE];

	ArrHeap()
	{
		count=0;
		for(int i=0;i<SIZE;i++)
			MinHeap[i]=-99;
	}
	void insert(int val)
	{
		if(count==SIZE)	
			return;							//Array is Full
		count++;
		MinHeap[count-1]=val;
		siftup(count-1);
	}

	void removmin()
	{
		if(count==0)
			return;						//Array is Empty
		MinHeap[0]=MinHeap[count-1];
		MinHeap[count-1]=-99;
		count--;
		if(count>0)
			siftdown(0);
	}
	void in_order(int temp)
	{
		if(MinHeap[(temp*2)+1]!=-99)		//if Left-child != NULL
		{
			in_order((temp*2)+1);
		}
		cout<<MinHeap[(temp)]<<"  ";		//cout<<temp->info
		if(MinHeap[(temp*2)+2]!=-99)		//if Right-child != NULL
		{
			in_order((temp*2)+2);
		}
	}
	void show()
	{
		for(int i=0;i<count;i++)
			cout<<MinHeap[i]<<"("<<i<<")"<<"   ";
	}
};

void main()
{
	ArrHeap obj;
	int n;
	for(int i=0;i<11;i++)
	{
		cin>>n;
		obj.insert(n);
	}
	obj.in_order(0);
	cout<<endl;
	obj.show();
	getch();
	system("cls");
	obj.removmin();
	obj.in_order(0);
	cout<<endl;
	obj.show();
}