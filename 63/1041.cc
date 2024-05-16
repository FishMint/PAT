#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;


int main(void){
	map<int ,int> u_map;
	int n, start,tmp,cnt = 0;
	int val[100001],next[100001];
	cin>>n>>start;
	for(int i=0;i < n;i++){
		cin>>tmp;
		cin>>val[tmp]>>next[tmp];
	}

	int p = start;
	while(p != -1){
		u_map[val[p]]  = p;
		p = next[p];
		cnt++;
	}

	cout<<cnt<<" ";
	for(auto it = u_map.begin();it != u_map.end();it++){
		printf("%05d\n",it->second);
		printf("%05d %d ",it->second,it->first);
	}
	printf("-1\n");

	return 0;
}
