#include <bits/stdc++.h>
using namespace std;

struct moon
{
    double m;
    double price;
    double avrg;
};

bool cmp(moon a, moon b){
    return a.avrg > b.avrg;
}

int main(void) {
    int n;
    double result = 0, tons;
    cin>>n>>tons;

    vector<moon> m(n);

    for(int i = 0; i < n; i++)  cin>>m[i].m;
    for(int i = 0; i < n; i++)  cin>>m[i].price;
    for(int i = 0; i < n; i++)  m[i].avrg = m[i].price / m[i].m;

    sort(m.begin(), m.end(), cmp);
    for(int i = 0; i < n; i++) { 
        if(m[i].m < tons) {
            result += m[i].price;
            tons -= m[i].m; 
        }else {
            result += m[i].avrg * tons; 
            break;
        }
    }

    printf("%.2f\n", result);

    return 0;
}