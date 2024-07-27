#include <bits/stdc++.h>
using namespace std;

int n, nums[10005];
int cnt = 1, j, i;
int matrix[102][102];

bool cmp(int a, int b) {
    return a > b;
}

int main(void) {
    cin >> n;

    int col = 1, row = n;
    for(i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            col = min(i , n / i);
            row = max(i , n / i);
        }
    }

    for(i = 1; i <= n; i++) cin>>nums[i];
    sort(nums + 1, nums + n + 1, cmp);

    //几圈
    int k = 1;
    for(; k <= col / 2; k++) {
        i = j = k;
        //上
        for(; j <= col - k; j++) matrix[i][j] = nums[cnt++];

        //右
        for(; i <= row - k; i++) matrix[i][j] = nums[cnt++];

        //下
        for(; j > k; j--) matrix[i][j] = nums[cnt++];

        //左
        for(; i > k; i--) matrix[i][j] = nums[cnt++];
    }

    //把最后一条打印出来
    if(col % 2 != 0) {
        i = k;
        for(; i <= row - k + 1; i++) matrix[i][k] = nums[cnt++];
    }


    for(i = 1; i <= row; i++) {
        for(j = 1; j <= col; j++) {
            if(j != col) cout<<matrix[i][j]<<" ";
            else  cout<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}
