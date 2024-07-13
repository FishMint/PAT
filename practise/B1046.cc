#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int a1, a2, b1, b2;
    int n;
    int cnt_a = 0, cnt_b = 0;

    cin>>n;

    for(int i =0; i < n; i++) {
        cin>>a1>>a2>>b1>>b2;
        int t = a1 + b1;
        if(t == a2 && t != b2) { cnt_b++; continue; };
        if(t != a2 && t == b2) { cnt_a++; continue; };
    }

    cout<<cnt_a<<" "<<cnt_b<<endl;

    return 0;
}
