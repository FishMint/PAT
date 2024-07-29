#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//特别注意
//一定要b != 0
ll gcd(ll a, ll b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


int main(void) {
    int n;
    long long m1 = 0, d1 = 1, m2 ,d2;

    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%lld/%lld", &m2, &d2);
        long long m3, d3, c;

        c = gcd(abs(m2), d2);
        m2 /= c;
        d2 /= c;

        d3 = d1 * d2;
        m3 = d2 * m1 + d1 * m2;

        c = gcd(abs(m3), abs(d3));
        m1 = m3 / c;
        d1 = d3 / c;
    }

    // if(m1 / d1 != 0) {
    //     cout<< m1 / d1;
    //     if(m1 % d1 != 0)
    //         cout<<" "<<abs(m1) % d1 <<"/"<<d1<<endl;
    // }
    // else {
    //     cout<<m1 <<"/"<<d1<<endl;
    // }

    // if(m1 == 0) cout<<0<<endl;

    int integer = m1 / d1;
    m1 -= integer * d1;

    if(integer != 0){
        cout<<integer;
        if(m1 != 0) cout<<" ";
    }
    if(m1 != 0) cout<<m1<<"/"<<d1<<endl;
    if(integer == 0 && m1 == 0) cout<<0<<endl;

    return 0;
}
