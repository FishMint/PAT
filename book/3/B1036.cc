#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    char c;
    scanf("%d %c", &n, &c);

    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }

    printf("\n");
    int row = (n + 1) /2;
    for (int i = 0; i < row - 2; i++)
    {
        printf("%c", c);

        for (int i = 0; i < n - 2; i++)
            printf(" ");

        printf("%c\n", c);
    }

    for (int i = 0; i < n; i++) {
        printf("%c", c);
    }

    return 0;
}