#include <bits/stdc++.h>
using namespace std;

//这里其实可以擦边过
//就是第一次运算长度的时候直接使用一个循环来计算

int main(void) {
    int n;
    cin>>n;
    int d[n + 1], m, d1, d2;
    int tmp = 0;
    
    //计算出 路段的总和
    d[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin>>d[i];
        tmp += d[i];
        d[i] = tmp;
    }

    int sum;
    cin>>m;
    for(int i = 0; i < m; i++) {
        sum = 0;
        cin>>d1>>d2;

        if(d1 > d2) swap(d1, d2);
        sum = d[d2 - 1] - d[d1 - 1];              //通过差值计算长度
        cout<<min(sum, d[n] - sum)<<endl;         //因为是一个圆，总和-长度 = 反向长度

    }

    return 0;
}