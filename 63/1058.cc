#include <algorithm>
#include<cctype>
#include<string>
#include <iostream>
#include<unordered_map>
using namespace std;

int main(void) {
	string s1,s2;
	cin>>s1>>s2;
	unordered_map<char,int> u_map;
	for(char c : s1)
		u_map[toupper(c)] = 1;
	for(char c : s2)
		u_map[toupper(c)]++;

	char tmp;
	for(char c : s1){
		tmp = toupper(c);
		if(u_map[tmp] == 1){
			cout<<tmp;
			u_map[tmp] = 0;
		}
	}
	cout<<endl;

	return 0;
}
