#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int cnt = 0;
    int i;
    scanf("%d", &i);

    while (i != 1) {
        //偶数
        if (i % 2 == 0)
            i >>= 1;
        else
            i = (i * 3 + 1) / 2;

        cnt++;
    }

    cout<<cnt<<endl;
    return 0;
}