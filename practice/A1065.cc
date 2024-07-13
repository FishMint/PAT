#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int t;
    ll a, b, c;

    cin>>t;
    for(int i = 0; i < t; i++) {
		cin>> a >> b >> c;

        //如果是异号
		if(a >> 63 != b >> 63) {
			cout<<"Case #"<< i + 1 <<": "
                << ((a + b) > c ? "true" : "false") <<endl;
		}
        //如果是同号
        else {
            if(a >> 63 == 0) {
                if(a + b < 0)
                    cout << "Case #" << i + 1 << ": true" << endl;
                else
                    cout << "Case #" << i + 1 << ": "
                         << ((a + b) > c ? "true" : "false") << endl;
            }
            else {
                //这里多个等于完全是因为负数比正数的多一个
                //正好可以到0
                if(a + b >= 0)
                    cout << "Case #" << i + 1 << ": false" << endl;
                else
                    cout << "Case #" << i + 1 << ": "
                         << ((a + b) > c ? "true" : "false") << endl;
            }
        }

    }

    return 0;
}
