#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(void){
	string s_buy,s_need;
	unordered_map<char,long> map;
	int cnt = 0;
	cin>>s_buy;
	cin>>s_need;
	bool flag = true;
	
	for(char c : s_buy){
		map[c]++;
	}

	for(char c : s_need){
		map[c]--;
		if(map[c] < 0){
			flag =false;
			cnt++;
		}
	}

	if(flag == true) cout<<"Yes"<<" "<<s_buy.size() - s_need.size()<<endl;
	else	cout<<"No"<<" "<<cnt<<endl;
	
		
	return 0;
}
