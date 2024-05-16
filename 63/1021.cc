#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(void){
	int n,tmp,m,k;
	vector<set<int>> v;

	cin>>n;
	for(int i =0;i < n;i++){
		set<int> s;
		cin>>m;
		for(int j = 1;j<=m;j++){
			cin>>tmp;
			s.insert(tmp);
		}
		v.push_back(s);
	}

	int a,b;
	double nc,nt;
	cin>>k; 
	for(int i = 0;i<k;i++){
		cin>>a>>b;
		nc = 0; nt = v[b -1].size();
		for(auto it = v[a-1].begin(); it != v[a-1].end();it++){
			if(v[b-1].find(*it) == v[b-1].end())	nt++;
			else nc++;
		}
		double ans = (nc/nt) * 100;
		printf("%.1f%%\n",ans);
	}
	return 0;
}
