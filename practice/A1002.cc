#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int k, n;
    float tmp;
    float a[1010] = {0};

    while(cin >> k) {
        for(int i = 0; i < k; i++) {
            cin >> n >> tmp;
            a[n] += tmp;
        }
    }

    int cnt = 0;
    for(int i = 1000; i >= 0; i--) {
        if(a[i] != 0)   cnt++;
    }

    cout<<cnt;
    for(int i = 1000; i >= 0; i--) {
        if(a[i] == 0)   continue;
        //cout<<" "<< i << " " << a[i];
        printf(" %d %.1f", i, a[i]);
    }

    cout<<endl;

    return 0;
}