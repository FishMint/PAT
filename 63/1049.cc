#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

//这里可以想象成把和谁组合，放在前面的都会大的string放到最后面
int compare(string a, string b){
	return a + b < b + a;
}

int main(void){
	string s[10005];
	string ans="";
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];

	sort(s,s+n,compare);
	for(int i=0;i<n;i++)
		ans += s[i];

	while(ans[0] == '0')
		ans.erase(ans.begin());
	if(ans.size() == 0) cout<<"0"<<endl;
	else cout<<ans<<endl;

	return 0;
}

