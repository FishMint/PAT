#include <bits/stdc++.h>
using namespace std;

void Liu_func (string s) {
	long long countT = 0, countP = 0, total = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == 'T') countT++;
	}

	for(int i = 0; i < s.size(); i++){
		if(s[i] == 'P') countP++;
		if(s[i] == 'T') countT--;
		if(s[i] == 'A')
			total = (total + (countP % 1000000007) * (countT % 1000000007)) % 1000000007;
	}

	cout<<total<<endl;
}
void Book_func () {
	//答案的方法就是本质是和柳神的方法一样
	//但是 他是用一个数组 
	//leftP[1-n] 记录每一个index左边的p的数量
	//rightT[1-n]记录每一个index右边的t的数量
	//选到a 就是 leftP[index] * rightA[index]
}

int main(void) {
    string s;
    cin>>s;
	Liu_func(s);

    return 0;
}
