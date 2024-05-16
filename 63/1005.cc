#include<iostream>
#include<vector>
#include<string.h>

struct Node{
	int id;
	std::vector<int> child;
};

Node tree[101];
int cnt[101];

void bfs(int id,int level){
	cnt[level]++;
	for(int cild : tree[id].child)
	{
		bfs(cild,level+1);
	}
}

int main(void){
	int n,m,fmly[101],tmp_id,c_num,c_id,root_id = 0;
	std::cin>>n>>m;
	for(int i =0;i < 101;i++)
	{
		tree[i].id = i;
		fmly[i] = 0;
	}

	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&tmp_id,&c_num);
		//放孩子
		for(int j = 0;j < c_num;j++)
		{
			scanf("%d",&c_id);
			fmly[c_id] = 1;	//打标记
			tree[tmp_id].child.push_back(c_id);
		}
	}

	for(int i =1; i <= n;i++)
	{
		if(fmly[i] == 0)	{root_id = i; break;}
	}

	bfs(root_id,1);

	int ans = 1;
	for(int i = 1;i <= m;i++)
	{
		if(cnt[ans] < cnt[i])	ans = i;
	}
	std::cout<<cnt[ans]<<" "<<ans<<std::endl;

	return 0;
}
