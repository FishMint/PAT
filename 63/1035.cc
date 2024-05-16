#include<iostream>
#include<vector>
using namespace std;

int main(void){
	int n,dis[100005],m;
	int sum =0;
	vector<int> v;
	cin>>n;

	for(int i =1; i <= n;i++){
		cin>>dis[i];
		sum += dis[i];
	}

	cin>>m;
	int tmp1;
	int n1,n2;
	for(int i =0;i<m;i++){
		tmp1 = 0;
		cin>>n1>>n2;
		if(n1 > n2) swap(n1,n2);	//保证n1 < n2

		//正向
		for(int j = n1; j < n2;j++)
			tmp1 += dis[j];

		//输入答案
		v.push_back(min(tmp1,sum - tmp1));
	}
	for(int a : v){
		cout<<a<<endl;
	}

	return 0;
}
