#include<iostream>
using namespace std;

class Check
{
	char* stack;
	int top;
	int capacity;
public:
	Check(int size)
	{
		stack = new char[size];
		top=size;
		capacity=size;
	}
	int checkbraket(char a[])
	{
		int i=0;
		int c=0;
		while(i<capacity)
		{
		if(a[i]=='(')
		{
			stack[top-1]='(';
			top--;
			c++;
		}
		else
		{
			top++;
			c--;

		}
		i++;
	}
		return c;
	}
};
int main()
{
	Check c(6);
	char s[6]={'(','(',')','(',')',')'};
	if(c.checkbraket(s)==0)
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
}
