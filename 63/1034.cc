#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main(void){
	int n,k;
	int num;
	int tmp;
	string name;
	map<int,vector<string>> map1;
	cin>>n>>k;

	for(int i =0;i < n;i++){
		cin>>name;
		cin>>num;
		for(int j = 0;j < num;j++){
			cin>>tmp;
			map1[tmp].push_back(name);
		}
	}

	for(auto it = map1.begin();it != map1.end();it++){
		//按着名字排序
		sort((it->second).begin(),(it->second).end());
		cout<<it->first<<" "<<it->second.size()<<endl;

		for(auto vit = it->second.begin();vit != it->second.end();vit++){
			cout<<*vit<<endl;
		}
	}


	return 0;
}


