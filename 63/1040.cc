#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;

/*
 * 反着塞进去，弹出来也是123.。n
*/

int main(void){
	int m,n,k;
	int v[1005][1005];
	cin>>m>>n>>k;

	//输入
	for(int i = 0;i < k;i++)
		for(int j =0; j < n;j++)
			cin>>v[i][j];

	int flag = 1,target = n;
	for(int i = 0;i < k;i++){
		flag = 1;
		target = n;
		stack<int> s;
		for(int j = n -1; j >= 0;j--){
			s.push(v[i][j]);

			//如果栈满了，就是不符合
			if(s.size() > m){
				flag = 0;
				break;
			}

			while(s.size() > 0 && s.top() == target){
				s.pop();
				target--;
			}

		}
		if(s.empty()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
