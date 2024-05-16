#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);

	unordered_map<char,int> u_map1,u_map2;	// map <（字符） ， （字符数量）>

	for(char c :s1){
		u_map1[c]++;
	}
	//拷贝一下
	u_map2 = u_map1;

	//
	for(char c : s2){
		u_map2[c]--;
	}
	
	//比较一下数量，字符数量不一样就不打印
	for(char c : s1){
		if(u_map1[c] == u_map2[c])
			cout<<c;
	}
	cout<<endl;
	return 0;
}
