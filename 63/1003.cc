#include<iostream>
#include<string>
#include<vector>

struct tree
{
	int id;
	std::vector<int> childs;
};

struct tree t[100001];
std::vector<int> v[100001];

void bfs(int id, int level){
	v[level].push_back(id);	//添加每一层的节点个数
	for(int i : t[id].childs)
		bfs(i,level+1);
}

int main(void){
	int n;
	double p,r;
	int s[100001], root = 0;

	std::cin>>n>>p>>r;
	r = r/100 + 1.00;
	for(int i =0;i < n; i++)
	{
		t[i].id = i;
		std::cin>>s[i];		//输入供应商，父亲节点
		if(s[i] == -1)
		{
			root = i; 
			continue;
		}
		t[s[i]].childs.push_back(i);	//添加孩子
	}
	bfs(root,0);

	int i;
	for(i = 0;v[i].size() != 0;i++);
	i -= 1;

	for(int j = 1; j <= i;j++)
		p *= r;
	printf("%.2f %d\n",p,(int)v[i].size());

	return 0;
}
