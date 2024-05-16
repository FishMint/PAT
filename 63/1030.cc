#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(void){
	int n,tmp;
	vector<int> v;
	unordered_map<int,int> u_map;

	cin>>n;
	for(int i =0;i<n;i++){
		cin>>tmp;
		v.push_back(tmp);
		u_map[tmp]++;
	}

	for(auto it = v.begin();it != v.end();it++){
		if(u_map[*it] == 1){
			cout<<*it<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}
