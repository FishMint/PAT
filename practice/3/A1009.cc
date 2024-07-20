#include <bits/stdc++.h>
using namespace std;

int main(void) {
    double a[1010] = {0}, b[1010] = {0}, c[1010] = {0}; 
    int k, n;

    cin>>k;
    for(int i = 0; i < k; i++) {
        cin >> n;
        cin >> a[n];
    }

    cin>>k;
    for(int i = 0; i < k; i++) {
        cin >> n;
        cin >> b[n];
    }

    for(int i = 0; i < 1001; i++) {
        if(a[i] == 0) continue;

        for(int j = 0; j < 1001; j++) {
            if(b[j] == 0) continue;
            c[i + j] += a[i] * b[j];
        }
    }

    int cnt = 0;
    for(int i = 1000; i >= 0; i--) {
        if(c[i] != 0) cnt++;
    }
    cout<<cnt;
    
    for(int i = 1000; i >= 0; i--) {
        if(c[i] == 0) continue;
        printf(" %d %.1f", i, c[i]);
    }

    return 0;
}