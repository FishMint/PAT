#include<iostream>
#include<cmath>
using namespace std;

int main(void){
	int n;
	cin>>n;
	int first = 0,len = 0,loop_szie = sqrt(n),max_len = 0,tmp;

	for(int i =2;i <= loop_szie;i++){
		len = 0;
		tmp =1;
		for(int j = i;j <= loop_szie;j++){
			tmp*=j;
			if(n % tmp != 0) break;	//如果连乘之后的结果不是n的质数就退出
			len++;
			if(len > max_len){
				first = i;
				max_len =len;
			}
		}
	}

	if(first == 0){
		cout<<1<<endl<<n<<endl;
	}else{
		cout<<max_len<<endl;
		cout<<first;
		for(int i = 1;i < max_len;i++){
			cout<<"*"<<first+i;
		}
	}


	return 0;
}
