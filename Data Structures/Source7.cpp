#include<iostream>
using namespace std;
#define leng 10
class
	linklist_stack
{
private:
	int *top,size,*head;
public:
	linklist_stack()
	{
		top=new int[leng];
		head=top;
		size=0;
		for(int i=0;i<leng;i++)
		{
		*(top+i)=0;
		}
	}
	void push()
	{
		if(size<leng)
		{
			size++;
			cin>>*top++;
		}
		else
		{
			cout<<"Stack is over flow.."<<endl;
			exit(1);
		}
	}
		void pop()
	{
		if(size!=0)
		{
			*top--=0;
			size--;
		}
		else
		{
			cout<<"Stack is under flow.."<<endl;
			exit(1);
		}
	}
	void show()
	{
		for(int i=0;i<leng;i++)
			cout<<*(head+i)<<endl;
	}
};
void main()
{
int a,b,c,s=0,n;
cin>>a>>b>>c>>n;
cout<<a<<" , "<<b<<" , "<<c<<" , ";
for(int i=0;i<n-3;i++)
{
s=a+b+c;
a=b;
b=c;
c=s;
cout<<s<<" , ";
s=0;
}
}