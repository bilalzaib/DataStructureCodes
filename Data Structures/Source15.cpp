#include<iostream>

#define SIZE 10

using namespace std;

class Hashing
{
private:
	int size,hasharr[SIZE];
public:

	Hashing ()
	{
		size=0;
		for (int i=0;i<SIZE;i++)
			hasharr[i]=-1;
	}

	void insert(int num)
	{
		if(size==SIZE)
			return;
		int index=num%SIZE;
		int i=0;
		while(hasharr[index]!=-1 && i<SIZE)
		{
			++index%=SIZE;
			i++;
		}
		hasharr[index]=num;
	}

	bool search(int num)
	{
		if(size==0)
			return false;
		int index=num%SIZE;
		int i=0;
		while(hasharr[index]!=num && i<SIZE)
		{
			++index%=SIZE;
			i++;
		}
		if(hasharr[index]==num)
			return true;
		else
			return false;
	}

	void show()
	{
		for(int i=0;i<SIZE;i++)
			cout<<hasharr[i]<<"("<<i<<")"<<"  ";
	}
	
};

void main()
{
	Hashing obj;
	int n;
	for (int i=0;i<7;i++)
	{
		cin>>n;
		obj.insert(n);
	}

	obj.show();
}