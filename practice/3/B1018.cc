#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int cmp(char c1, char c2) {
    if(c1 == c2) return 0;
    if(c1 == 'C' && c2 == 'J')  return 1;
    if(c1 == 'B' && c2 == 'C')  return 1;
    if(c1 == 'J' && c2 == 'B')  return 1;
    return 2;
}


int main(void) {
    int n;
    char c1, c2;
    int A_time[3] = {0,0,0}, B_time[3] = {0,0,0};
    //BCJ
    int A_pos[3] = {0,0,0}, B_pos[3] = {0,0,0};

    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>c1>>c2;

        if(cmp(c1, c2) == 0) {
            A_time[1]++;
        }
        else if(cmp(c1, c2) == 1) {
            A_time[0]++;
            if(c1 == 'B') A_pos[0]++;
            else if(c1 == 'C') A_pos[1]++;
            else if(c1 == 'J') A_pos[2]++;
            
        }else{
            A_time[2]++;
            if(c2 == 'B') B_pos[0]++;
            else if(c2 == 'C') B_pos[1]++;
            else if(c2 == 'J') B_pos[2]++;
        }
    }

    printf("%d %d %d\n", A_time[0], A_time[1], A_time[2]);
    printf("%d %d %d\n", A_time[2], A_time[1], A_time[0]);


//这里一定要注意BCJ要按着对应的顺序写
//这样就不用比较 字母的大小了
    int max_max = -1;
    int k = 0;
    for(int i = 0; i < 3; i++) {
        if(A_pos[i] > max_max)  {
            max_max = A_pos[i];
            k = i;
        }
    }
    if(k == 0) cout<<"B ";
    if(k == 1) cout<<"C ";
    if(k == 2) cout<<"J ";


    max_max = -1;
    k = 0;
    for (int i = 0; i < 3; i++) {
        if (B_pos[i] > max_max) {
            max_max = B_pos[i];
            k = i;
        }
    }
    if (k == 0) cout << "B";
    if (k == 1) cout << "C";
    if (k == 2) cout << "J";

    return 0;
}