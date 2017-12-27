#include<iostream>

using namespace std;
const int MAX=5;

class Queue
{
private:
	int rare, front,Array[MAX],size;
public:
	Queue()
	{
		front=rare=-1;
		size=0;
		for(int i=0;i<MAX;i++)
			Array[i]=0;
	}
	void Enqueue()
	{
		if(size==MAX)
		{
			cout<<"Stack is Full...\n";
			return;
		}
		rare=(++rare)%MAX;
		cin>>Array[rare];
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
	void show()
	{
		int temp;
		temp=front;
		for(int i=0;i<size;i++)
		{
			temp=(++temp)%MAX;
			cout<<Array[temp]<<"  ";
		}
	}
};
void main()
{
	Queue obj;
	for(int i=0;i<MAX;i++)
		obj.Enqueue();
	obj.show();
	cout<<endl;
	for(int i=0;i<4;i++)
		obj.Dequeue();
	cout<<"After del"<<endl;
	obj.show();
	for(int i=0;i<2;i++)
		obj.Enqueue();
	obj.show();
}s