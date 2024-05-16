#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

map<string,int> m_stoi;
map<int,string> m_itos;
int numId =1;
int g[1005][1005],weight[1005];

//把string转换成int,自己编号
int stoiFunc(string s){
	if(m_stoi[s] == 0){
		m_stoi[s] = numId;
		m_itos[numId] = s;
		return numId++;
	}
	return m_stoi[s];
}

bool flag[1005];
map <string,int> ans;

void dfs(int cur,int &head,int &number,int &total_weight){
	flag[cur] = true;
	number++;
	if(weight[cur] > weight[head]) head =cur;
	for(int i=1; i < numId;i++){
		//说明联通
		if(g[cur][i] > 0){
			total_weight += g[cur][i];
			g[cur][i] = g[i][cur] = 0;	//这条边要断开
			//说明没有走过,这个点
			if(flag[i] == false){
				dfs(i,head,number,total_weight);
			}
		}
		
	}
}

//通过dfs来查看满足条件的gang
void dfsTrave(int k){
	for(int i =1;i<numId;i++){
		//说明没有遍历过，属于不同的gang
		if(flag[i] == false){
			int head = i,number = 0,total_weight = 0;
			dfs(i,head,number,total_weight);
			if(number > 2 && total_weight > k)
				ans[m_itos[head]] = number;
		}
	}

}


int main(void){
	int n,k;
	cin>>n>>k;
	
	string a,b;
	int w;
	for(int i=0;i<n;i++){
		cin>>a>>b>>w;
		int id1 = stoiFunc(a);
		int id2 = stoiFunc(b);
		weight[id1] += w;
		weight[id2] += w;
		g[id1][id2] += w;
		g[id2][id1] += w;
	}
	cout<<g[0][0]<<endl;
	dfsTrave(k);

	cout<<ans.size()<<endl;
	for(auto it = ans.begin();it != ans.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;
}
