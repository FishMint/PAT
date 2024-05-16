#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void heapSort(vector<int> &b , int end)
{
	int index = 1;
	int tmp;
	while(index * 2 <= end)
	{
		tmp = index * 2;
		if(tmp < end)
		{
			if(b[tmp] < b[tmp + 1])  tmp++;
		}
		//cout<<tmp<<endl;	
		if(b[index] < b[tmp])	swap(b[index] , b[tmp]);
		index = tmp;
	}
}


int main(void)
{
    int n;
    scanf("%d",&n);
    vector<int> a(n +1),b(n+1);

    //输入a[1] - a[n] b....
    for(int i =1; i <= n; i++)  scanf("%d",&a[i]);
    for(int i =1; i <= n; i++)  scanf("%d",&b[i]);

    int p = 2;
    while(p <= n && b[p-1] <= b[p]) p++;    //算出如果是插入排序的第一个下标
    int index = p;
    while(p <= n && a[p] == b[p])  p++;     //如果后面都是一样的话，p = n + 1

    if(p == n + 1)
    {
        cout<<"Insertion Sort"<<endl;
        sort(b.begin() + 1, b.begin() + 1 + index);
    }
    else    //堆排序
    {
        cout<<"Heap Sort"<<endl;
        //堆排序 前乱 后整齐 , 第一个是前面最大的 
        p = n;
		while(p > 2 && b[1] < b[p]) p--;
		swap(b[1],b[p]);	
		//cout<<p-1<<endl; 
		heapSort(b,p - 1); 
    }
    cout<<b[1];
    for(int i = 2; i <= n ;i++)
    {
    	cout<<" "<<b[i];
	}
	cout<<endl;
    return 0;
}

