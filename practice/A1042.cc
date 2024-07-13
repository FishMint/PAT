#include <bits/stdc++.h>
using namespace std;


int main(void) {
	const int n = 54;
	int k;
	char map[5] = {'S', 'H', 'C', 'D', 'J'};
	int next[54];
	int begin[54], end[54];
	cin>>k;
	
    for(int i = 0; i < n; i++) {
		cin>>next[i];
		begin[i] = i;
	}

	for(int j = 0; j < k; j++) {
		for(int i = 0; i < n; i++) {
			end[next[i] - 1] = begin[i];
		}
		swap(begin, end);	//交换一下，让end永远是结果
	}
	swap(begin, end);	//交换一下，让end永远是结果

	for(int i = 0; i < n - 1; i++) {
		cout<<map[end[i] / 13]<<(end[i] % 13) + 1<<" ";
	}
	cout<<map[end[53] / 13]<<(end[53] % 13) + 1<<endl;
    
	return 0;
}
