#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

void func(ll m, ll d){
    //新增
    if(d == 0){
        cout<<"Inf";
        return;
    }
    //新增

    int c = gcd(abs(m), d);
    m /= c;
    d /= c;

    int integer = m / d;
    m -= integer * d;

    if(integer < 0 || m <0 || d < 0) cout<<"(-";

    if(integer != 0) {
        if(m != 0)  printf("%lld %lld/%lld", abs(integer), abs(m), abs(d));
        else printf("%lld", abs(integer));
    }else{
        if(m != 0)  printf("%lld/%lld", abs(m), abs(d));
        else cout<<0;
    }

    if(integer < 0 || m <0 || d < 0) cout<<")";
}

int main(void) {
    ll m1, d1, m2, d2;
    scanf("%lld/%lld %lld/%lld", &m1, &d1, &m2, &d2);

    int c = gcd(abs(m1), d1);
    m1 /= c; d1 /= c;
    c = gcd(abs(m2), d2);
    m2 /= c; d2 /= c;

    func(m1, d1);cout<<" + ";func(m2, d2);cout<<" = ";func(m1*d2 + m2*d1, d2 * d1);cout<<endl;
    func(m1, d1);cout<<" - ";func(m2, d2);cout<<" = ";func(m1*d2 - m2*d1, d2 * d1);cout<<endl;
    func(m1, d1);cout<<" * ";func(m2, d2);cout<<" = ";func(m1*m2, d1 * d2);cout<<endl;
    func(m1, d1);cout<<" / ";func(m2, d2);cout<<" = ";func(m1*d2, d1*m2);cout<<endl;
    // if(m2 == 0)  cout<<"Inf";
    // else func(m1*d2, d1 * m2);
    // cout<<endl;

    return 0;
}
