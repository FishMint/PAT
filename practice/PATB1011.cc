#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int n;
    ll a, b, c;

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a>>b>>c;
        if(a + b > c) cout<<"Case #"<<i<<": true"<<endl;
        else cout<<"Case #"<<i<<": false"<<endl;
    }


    return 0;
}