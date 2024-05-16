#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(void){
	int n;
	scanf("%d\n",&n);
	string ans;
	int lens;
	for(int i = 0;i < n;i++){
		string s;
		getline(cin,s);
		reverse(s.begin(),s.end());
		if(i == 0){
			ans = s;
		}
		else{
			lens = min((int)ans.length(),(int)s.length());
			if(ans.size() > s.size()) swap(ans,s);
			for(int j =0; j < lens;j++){
				if(ans[j] != s[j])	{
					ans = ans.substr(0,j);
					break;
				}
			}
		}
	}
	if(ans.length() == 0)	cout<<"nai"<<endl;
	else{
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}

	return 0;
}

