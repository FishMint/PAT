#include<iostream>
#include<string>
using namespace std;

int main(void){
	string s;
	cin>>s;
	int n1,n2,n = s.size();
	n1 = (n + 2) /3;
	n2 = n1 + (n + 2)%3;

	int i;
	for(i = 0;i < n1 -1;i++){
		cout<<s[i];
		for(int j = 1;j<=n2 -2;j++)	cout<<" ";
		cout<<s[n -1 -i];
		cout<<endl;
	}
	
	for(;i< n1 + n2 -1;i++)
		cout<<s[i];

	cout<<endl;

	return 0;
}
