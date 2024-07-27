#include <bits/stdc++.h>
using namespace std;

struct person {
	int come;
	int time;
};

bool cmp(person a, person b) {
    return a.time < b.time;
}

int n, tag, hh, mm, ss, t;
int k, m, tables[105];
vector<person> COM, VIP;

int main(void) {
    cin>>n;

    for(int i = 1; i <= n; i++) {
        scanf("%d:%d:%d %d %d", &hh, &mm, &ss, &t, &tag);
        int come = hh * 3600 + mm * 60 + ss;
        person p;
        p.come = come;
        p.time = t;

        if(tag == 1) VIP.push_back(p);
        else COM.push_back(p);

    }
    sort(COM.begin(), COM.end()); 
    sort(VIP.begin(), VIP.end()); 

    cin >> k >> m;
    for(int i = 1; )

    

    return 0;
}
