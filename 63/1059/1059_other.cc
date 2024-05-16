#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
  int n, p;
  int a[100000];
  cin >> n >> p;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);
  int tmp;
  int Max = 0;
  for (int i = 0; i < n; i++) {
    tmp = a[i] * p;
    for (int j = i + Max; j < n; j++) {
      if (tmp >= a[j]) Max = max(Max, j - i + 1);
	  else break;
    }
  }

  cout << Max << endl;
  return 0;
}
