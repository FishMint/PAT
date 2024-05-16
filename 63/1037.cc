#include <string.h>
#include <iostream>
#include <map>
using namespace std;

int main(void) {
  int n, m, tmp;
  int a[100001], map1[100001];
  map<int, int> ans;
  memset(a, 0, sizeof(a));
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> tmp;
    a[i] = tmp;
    map1[tmp] = 1;
  }

  for (int i = 0; i < n; i++) {
    //说明有
    tmp = m - a[i];
    if (tmp > 0 && map1[tmp] == 1) {
      ans[a[i]] = tmp;
    }
  }
  if (ans.size() == 0)
    cout << "No Solution"<< endl;
  else
    cout << ans.begin()->first << " " << ans.begin()->second << endl;

  return 0;
}
