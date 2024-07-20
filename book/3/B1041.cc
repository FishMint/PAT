#include <bits/stdc++.h>
using namespace std;

struct stu
{
    string id;
    int examSeat;
};


int main(void) {
    int n, seat;
    cin>>n;

    string id;
    struct stu s[1001], tmp;

    //对应的id和考试位置，放到下标为机考座位s里
    for (int i = 0; i < n; i++) {
        cin>> tmp.id >> seat >> tmp.examSeat;
        s[seat] = tmp;
    }
    
    int k, t;
    cin>>k;
    for(int i = 0; i < k; i++) {
        cin>>t;
        cout<<s[t].id<<" "<<s[t].examSeat<<endl;
    }

    return 0;
}