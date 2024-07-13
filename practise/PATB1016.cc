#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void) {
    int a1, a2, b1, b2;
    int num1 = 0, num2 = 0;
    int k = 1;

    cin>>a1>>a2>>b1>>b2;

    while (a1 > 0) {
        if(a1 % 10 == a2) {
            num1 = num1 * 10 + a2;
        } 
        a1 /= 10;
    }

    while (b1 > 0) {
        if (b1 % 10 == b2) {
            num2 = num2 * 10 + b2;
        }
        b1 /= 10;
    }

    cout<< num1 + num2 <<endl;

    return 0;
}