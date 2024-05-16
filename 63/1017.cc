#include<iostream>
#include<string>
#include<vector>
using namespace std;

#define STACK_SIZE 100001

vector<int> v;
int top = 0;
int n;
int stack[STACK_SIZE];

void Pop();
void Push(int val);
void PeekMedian();

int main(void)
{
	int val;
	string opt;
	cin>>n;

	for(int k = 0;k < n;k++)
	{
		cin>>opt;
		if(opt == "Pop")
		{
			Pop();
		}
		else if(opt == "Push")
		{
			cin>>val;
			Push(val);

		}else if(opt == "PeekMedian")
		{
			PeekMedian();
		}
	}

	return 0;
}

void Pop()
{
	if(top == 0) { cout<<"Invalid"<<endl;	return; }
	top--;
	cout<<stack[top]<<endl;
}

void Push(int val)
{
	stack[top++] = val;
}

void PeekMedian()
{
	if(top == 0) { cout<<"Invalid"<<endl;	return;  }
	int s_min = stack[0];
	for(int i =1; i < (n+1) / 2 -1 && i < top;i++)
	{
		if(s_min > stack[i])	
			s_min = stack[i];
	}
	cout<<s_min<<endl;
}
