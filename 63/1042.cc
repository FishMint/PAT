#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> v;

int cur_weight = 0;


struct tree{
	int id;
	int weight;
	vector<int> child;
};


tree t[200];
int cmp(int a,int b){
	return t[a].weight > t[b].weight;
}

void dfs(tree * t,int k);

int main(void){
	int n,m,s;
	int cur_id,num,child_id;
	cin>>n>>m>>s;

	for(int i = 0;i<n;i++){
		cin>>t[i].weight;
		t[i].id = i;
	}

	for(int i = 0;i<m;i++){
		scanf("%d %d",&cur_id,&num);
		for(int j = 0;j < num; j++){
			scanf("%d",&child_id);
			t[cur_id].child.push_back(child_id);
		}
		//从大到小排序
		sort(t[cur_id].child.begin(),t[cur_id].child.end(),cmp);
	}
	dfs(&t[0],s);

	return 0;
}

void dfs(tree * tr,int k){
	//cout<< tr->id<<endl;
	v.push_back(tr->weight);
	cur_weight += tr->weight;

	//等于就输出
	if(cur_weight == k){
		//说明是叶子节点
		if(tr->child.size() == 0){
			cout<<v[0];
			for(int i =1;i < v.size();i++)
				cout<<" "<<v[i];
			cout<<endl;
		}
	}
	//小于继续递归
	else if(cur_weight < k){
		for(int i : tr->child){
			dfs(&t[i],k);
		}
	}

	//回溯
	cur_weight -= tr->weight;
	v.pop_back();
	return ;
}
