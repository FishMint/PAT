#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main(void){
	int start,n,tmp;
	int val[100001],next[100001],list[100001],remove_list[100001];
	int flag_val[10001];

	cin>>start>>n;

	for(int i =0;i < n;i++){
		cin>>tmp;
		cin>>val[tmp]>>next[tmp];
	}

	memset(flag_val,1,sizeof(flag_val));
	int l = start,l_cnt = 0,rl_cnt = 0;
	while(l != -1)
	{
		if(flag_val[abs(val[l])])
		{
			list[l_cnt++] = l;
			flag_val[abs(val[l])] =0;	//打标记
		}else
		{
			remove_list[rl_cnt++] = l;
		}
		l = next[l];
	}

	printf("%05d %d ",list[0],val[list[0]]);
	for(int i =1; i < l_cnt; i++)
	{
		printf("%05d\n",list[i]);
		printf("%05d %d ",list[i],val[list[i]]);
	}
	printf("-1\n");

	if(rl_cnt == 0) return 0;

	printf("%05d %d ",remove_list[0],val[remove_list[0]]);
	for(int i =1; i < rl_cnt; i++)
	{
		printf("%05d\n",remove_list[i]);
		printf("%05d %d ",remove_list[i],val[remove_list[i]]);
	}
	printf("-1\n");

	return 0;
}
