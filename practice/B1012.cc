#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int n, k = 1;
    cin>>n;
    int a[n];
    int A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    int A1_cnt = 0, A2_cnt = 0, A5_cnt = 0;
    int A4_sum = 0, A4_cnt = 0;
    
    for(int i = 0; i < n; i++) { 
        cin>>a[i];
    }

    for(int i = 0; i < n; i++) { 
        if(a[i] % 5 == 0 && a[i] % 2 == 0) {
            A1 += a[i];
            A1_cnt++;
        } 
        else if(a[i] % 5 == 1) {
            A2 += a[i] * k;
            k *= (-1);
            A2_cnt++;
        } 
        else if(a[i] % 5 == 2) {
            A3++;
        }
        else if(a[i] % 5 == 3) {
            A4_cnt++;
            A4_sum += a[i];
        }
        else if(a[i] % 5 == 4) {
            A5 = max(A5, a[i]);
            A5_cnt++;
        }

    }

    if(A1_cnt == 0) printf("N "); else printf("%d ", A1);
    if(A2_cnt == 0) printf("N "); else printf("%d ", A2);
    if(A3 == 0)     printf("N "); else printf("%d ", A3);
    if(A4_cnt == 0) printf("N "); else printf("%.1f ", (float)A4_sum / A4_cnt);
    if(A5_cnt == 0) printf("N "); else printf("%d", A5);


    return 0;
}