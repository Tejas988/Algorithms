#include <bits/stdc++.h>
using namespace std;




class Base{
public:
	Base()
	{
		cout<<"constructing base"<<endl;
	}
	static void Greet()
	{
		cout<<"HELLO FROM BASE"<<endl;
	}
	void GoodBye()
	{
		cout<<"GoodBye from base"<<endl;
	}
	~Base()
	{
		cout<<"destructing base"<<endl;
	}

};

class Child:public Base{

	int x,y;
public:
	Child(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	Child()
	{		
		cout<<"constructing child"<<endl;
		x=0;
		y=0;
	}
	void SetValues(int x,int y)
	{
		this->x=x;
		this->y=y;
	}
	static void Greet()
	{
		cout<<"HEllo from child"<<endl;
	}
	void GetValues()
	{
		cout<<x<<" "<<y<<endl;		
	}		
	void GoodBye()
	{
		cout<<"GoodBye from child"<<endl;
	}
	~Child()
	{
		cout<<"destructing child"<<endl;
	}
};



// class Your;
class My{
public:
	static int a;
	static void f1();
	

};
int My::a;
class My1:private My{

public:
	My1()
	{
		a=10;
	}
	My1(int x)
	{
		a=x;
	}
	void f1()
	{
		cout<<"A is"<<a<<endl;
	}
};
void My::f1()
{
	cout<<a<<endl;
}	
int main()
{		
	My1 m;
	// m.f1();
	My1 m2(10);
	m2.f1();
	// cout<<m2.a;
	return 0;
}