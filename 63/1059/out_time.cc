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
  int Max = 0;
  int tmp,tmp_n = n;
  for (int i = 0; i < n; i++) {
	  tmp_n = n - i;
    tmp = a[i] * p;
    for (int j = n - 1; j > i; j--) {
      if (tmp >= a[j]){ Max = max(Max, j - i + 1); break; }
    }
	if(Max >= tmp_n -1)	break;
  }

  cout<<Max<<endl;
  return 0;
}
