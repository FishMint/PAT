#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main(void){
	string s;
	//这里的dp[i][j] —— i到j有回文
	getline(cin,s);
	int dp[1005][1005], lenth = s.size(),ans = 1;

	memset(dp,0,sizeof(dp));
	//动归，初始化L =1, 2 
	for(int i=0;i<lenth;i++){
		dp[i][i] = 1;
		if(i < lenth -1 && s[i] == s[i+1]){
			dp[i][i+1] =1;
			ans =2;
		}
	}

	//遍历各种长度L，
	for(int L =3;L <= lenth;L++){
		for(int i = 0;i <lenth - L + 1;i++){
			if(s[i] == s[i+L-1] && dp[i+1][i+L-2] == 1){
				dp[i][i+L-1] = 1;
				ans = L;
			}
		}
	}

	cout<<ans<<endl;
	return 0;
}
