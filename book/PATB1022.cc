#include <bits/stdc++.h>
using namespace std;

//直接看一下，两个人相加没有超出
//那就直接使用加法
int main(void) {
    int a, b, d, sum, ans[40], cnt = 0;
    scanf("%d%d%d", &a, &b, &d);
    sum = a + b;

    while (sum > 0) {
        ans[cnt++] = sum % d;
        sum /= d;
    }

    for(int i = cnt - 1; i >= 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
