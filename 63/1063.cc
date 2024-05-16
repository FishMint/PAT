#include<iostream>
#include<string>
#include<unordered_map>
#include<limits.h>
using namespace std;

int main(void){
	long long cnt = 0;
	string s;
	cin>>s;
	long long count_t = 0,count_p=0;

	//记录T的个数
	for(char c : s) {
		if(c == 'T')	count_t++;
	}

	//就是遇到T就减去T，前遇到A ， 把前面P的数量 * 后面T的数量
	for(int i = 0;i<s.size(); i++) {
		if(s[i] == 'P') count_p++;
		if(s[i] == 'T') count_t--;
		if(s[i] == 'A') cnt = cnt + (count_p * count_t);
	}

	cout<<cnt % 1000000007<<endl;
	return 0;
}
