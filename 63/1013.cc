#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int n,prime;
bool pos[10001];

//检查是不是质数
bool isPrim(int p)
{
	if(p == 1)	return false;
	if(p == 2)	return true;
	for(int i = 2; i <= sqrt(p);i++)
	{
		if(p % i == 0)	return false;
	}
	return true;
}

void hash_fun(int val)
{
	for(int step = 0; step < n; step++)
	{
		int index = (step * step + val) % prime;
		if(pos[index] == false)	//说明没有冲突
		{
			pos[index] = true;
			cout<<index;
			return;
		}
	}
	cout<<"-";
}

int main(void)
{
	cin>>n>>prime;

	while(!isPrim(prime))	//prime 变成质数
		prime++;

	int tmp;
	for(int i =0; i < n;i++)
	{
		cin>>tmp;
		hash_fun(tmp);

		if(i != n -1) cout<<" ";	//输出空格
	}

	cout<<endl;
	return 0;
}
