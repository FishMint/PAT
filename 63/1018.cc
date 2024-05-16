#include<iostream>
#include<string>
using namespace std;

int main(void) {
	string a,b,tmp;
	int a1,a2,a3,b1,b2,b3;
	cin>>a>>b;

	//记录a的 1，2个 '.'的位置
	int p1 = 0,p2 = 0;
	for(int i =0;i<a.size();i++){
		if(a[i] == '.'){
			if(p1 == 0) p1 = i;
			else{
				p2 = i;
				break;
			}
		}
	}
	//a的各个位的数字
	a1 = stoi(a.substr(0,p1));
	a2 = stoi(a.substr(p1+1,p2));
	a3 = stoi(a.substr(p2 + 1));

	//记录b的 1，2个 '.'的位置
	p1 =0; p2 = 0;
	for(int i =0;i<b.size();i++){
		if(b[i] == '.'){
			if(p1 == 0) p1 = i;
			else{
				p2 = i;
				break;
			}
		}
	}
	//b的各个位的数字
	b1 = stoi(b.substr(0,p1));
	b2 = stoi(b.substr(p1+1,p2));
	b3 = stoi(b.substr(p2 + 1));


	//答案的各个位的数字
	int ans1 = a1 + b1,
		ans2 = a2 + b2,
		ans3 = a3 + b3;

	if(ans3 >= 29){ans3 %= 29; ans2++;}
	if(ans2 >= 17){ans2 %= 17; ans1++;}
	cout<<ans1<<'.'<<ans2<<'.'<<ans3<<endl;
	return 0;
}
