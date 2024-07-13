#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int e, x;
	int new_e, new_x;
	bool first = true;

    while (cin>> e >> x) {
		if(e == 0 || x == 0)	continue;
		
		//计算导数
		new_e = e * x;
		new_x = x - 1;

		if(first) {
			cout<< new_e << " "<<new_x;
			first = false;
		} 
		else {
			cout<< " " << new_e << " "<< new_x;
		}
    }

	if(first) cout<<"0 0";
	cout<<endl;

    return 0;
}