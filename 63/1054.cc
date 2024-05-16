#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int compare(char &a, char &b){
	return a > b ? 1 : 0;
}

string beString(int val){
	string s;
	s.push_back('0' + val /1000);
	s.push_back('0' + (val % 1000) /100);
	s.push_back('0' + (val % 100) /10);
	s.push_back('0' + val % 10);
	return s;
}


int main(void){
	string pre = "", cur;
	int cur_num;
	cin>>cur_num;
	int a,b;
	cur = beString(cur_num);

	while(1){
		pre = cur;
		sort(cur.begin(),cur.end(),compare);
		a = stoi(cur);
		sort(cur.begin(),cur.end());
		b = stoi(cur);
		cur = beString(a-b);

		if(cur != pre){
			printf("%04d - %04d = ",a,b);
			cout<<cur;
		}else{
			break;
		}
		cout<<endl;
	}

	return 0;
}
