#include<iostream>
#include<algorithm>
using namespace std;

struct Mooncake{
	int tons;
	float price;
	float per_price;
};

int compare(struct Mooncake &a,struct Mooncake &b){
	return a.per_price <= b.per_price ? 0:1 ;
}

int main(void){
	int n,d;
	float result = 0;
	struct Mooncake m[100000];
	cin>>n>>d;
	for(int i = 0;i<n;i++)	cin>>m[i].tons;
	for(int i = 0;i<n;i++)	cin>>m[i].price;
	for(int i = 0;i<n;i++)	m[i].per_price = m[i].price/m[i].tons;
	sort(m,m + n,compare);

	int cnt_tons = 0,cur = 0;
	while(cnt_tons < d && cur < n){
		//现在的tons不够填满
		if(m[cur].tons < d - cnt_tons){
			cnt_tons += m[cur].tons;
			result += m[cur].price;
		}
		//可以填满了
		else{
			result += m[cur].per_price * (d - cnt_tons);
			cnt_tons =d;
		}
		cur++;
	}
	printf("%.2lf\n",result);

	return 0;
}
