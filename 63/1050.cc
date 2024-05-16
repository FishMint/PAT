#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
#include<vector>
using namespace std;

int main(void){
	int n,k;
	cin>>n>>k;
	int cors_num,stu_num;
	string name;
	unordered_map<string,vector<int>> u_map;

	for(int i = 1;i<=k;i++){
		cin>>cors_num>>stu_num;
		for(int j = 0;j < stu_num;j++){
			cin>>name;
			//把课程加入学生hash表
			u_map[name].push_back(cors_num);
		}
	}

	for(int i = 0;i<n;i++){
		cin>>name;
		if(u_map[name].empty())	cout<<name<<" 0"<<endl;
		else{
			cout<<name;
			//先排序
			sort(u_map[name].begin(),u_map[name].end());
			cout<<" "<<u_map[name].size();
			for(auto it = u_map[name].begin();it != u_map[name].end();it++){
				cout<<" "<<*it;
			}
			cout<<endl;
		}

	}

	return 0;
}
