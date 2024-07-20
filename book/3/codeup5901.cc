#include <bits/stdc++.h>
using namespace std;

//直接看一下，两个人相加没有超出
//那就直接使用加法
void func(string s)
{
    int i = 0, j = s.length() - 1;
    for (; i < j; i++, j--) {
        if (s[i] != s[j]) {
            printf("NO\n");
            return ;
        }
    }
    printf("YES\n");
}

int main(void)
{
    string s;

    while (cin >> s) {
        func(s);
    }

    return 0;
}