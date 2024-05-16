#include<iostream>
#include<string>
using namespace std;

int main(void){
	int head1,head2,n;
	cin>>head1>>head2>>n;

	char c[100001];
	int next[100001];
	int num1= 0,num2 = 0,tmp;

	for(int i =0;i<n;i++){
		cin>>tmp;
		cin>>c[tmp]>>next[tmp];
	}

	int p = head1;
	while(p != -1){
		p = next[p];
		num1++;
	}

	p = head2;
	while(p != -1){
		p = next[p];
		num2++;
	}

	if(num1 > num2){
		for(int i=1;i<= num1 - num2;i++)
			head1 = next[head1];
	}else{
		for(int i=1;i<= num2 - num1;i++)
			head2 = next[head2];
	}

	while(head1 != -1 && head1 != head2 ){
		head1 = next[head1];
		head2 = next[head2];
	}

	if(head1 != -1)
		printf("%5d\n",head1);
	else
		cout<<-1<<endl;
	return 0;
}
