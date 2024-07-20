#include <bits/stdc++.h>
using namespace std;

//直接看一下，两个人相加没有超出
//那就直接使用加法

int main(void)
{
    string s;
    int begin = 0;
    getline(cin, s);

    reverse(s.begin(), s.end());

    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            reverse(s.begin() + begin, s.begin() + i);
            begin = i + 1;
        }
    }

    reverse(s.begin() + begin, s.end());

    cout<<s<<endl;

    return 0;
}