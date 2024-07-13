#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int n, m;
    cin>> n >> m;
    int a[n];

    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }

    //这两个%n 是重点
    int begin = (n - m % n) % n;
    printf("%d", a[begin]);
    for (int i = 0; i < n - 1; i++) {
        begin = (begin + 1) % n;
        printf(" %d", a[begin]);
    }
    printf("\n");
    return 0;
}