#include <iostream>
using namespace std;
class ListArray
{
private:
	int *current,lengt,*fro,*rea,size;
public:
	ListArray()
	{
		fro=NULL;
		rea=NULL;
		size=0;
		lengt=10;
		current=new int[lengt];
		fro=current;
		rea=current+(lengt-1);
		for(int i=0;i<lengt;i++)
		{
		*(current+i)=0;
		}
		current--;
	}
	void insert()
	{
		if(size>=0&&size<lengt)
		{
			cout<<"Enter a value :"<<endl;
				cin>>*(++current);
				if(!(current>=fro&&current<=fro+size-1))
				size++;
		}
	}
	int get()
	{
		return *(current);
	}
	void update(int X)
	{
		if(current+1==fro)
		cout<<"Nothing in the Array..."<<endl;
		*current=X;
	}
	int length()
	{
		return size;
	}
	void start()
	{
		current=fro;
	}
	void end()
	{
		current=rea;
	}
	void next()
	{
		if((current>fro&&current<rea))
		{
			current++;
		}
		else
			cout<<"Out of Bounds/n";
	}
	void back()
	{
		if((current>fro&&current< rea))
		{
		current--;
		}
		else
			cout<<"Out of Bounds/n";
	}
	void remove()
	{
		int *p;
		p=current;
		while(p!=fro+(size-1))
		{
		 *p=*(p+1);
		 p++;
		}
		size--;
	}
	void add()
	{
		int *ptr;
		ptr=fro+size;
		//cout<<ptr<<endl<<current<<endl;
		while(current!=ptr)
		{
		 *ptr=*(ptr--);
		 ptr--;
		}
		cout<<"Enter a value :"<<endl;
		cin>>*(++current);
		size++;
	}
	void show()
	{
		int *p;
		p=fro;
		for(int i=0;i<size;i++)
		{
		cout<<*(p+i)<<endl;	
		}
	}
};
void main()
{
	ListArray obj;
	/*for(int i=0;i<5;i++)
	obj.insert();
	obj.show();*/
	obj.update(0);
	obj.show();
}
