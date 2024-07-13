#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int c1, c2, time;
    int h, m, s;
    cin>>c1>>c2;

    time = (c2 - c1 + 50) / 100;

    h = time / 3600;
    time %= 3600;
    m = time / 60;
    s = time % 60;

    printf("%02d:%02d:%02d\n", h, m, s);
    return 0;
}