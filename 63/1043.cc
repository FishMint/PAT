#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main(void) {
  int m, n;
  cin >> m >> n;
  int tmp;
  unordered_map<int, int> u_map;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tmp;
      u_map[tmp]++;
    }
  }

  int max = -1,ans;
  for (auto it = u_map.begin(); it != u_map.end(); it++) {
	  if(max < it->second){
		  ans = it->first;
		  max = it->second;
	  }
  }
  cout<<ans<<endl;

  return 0;
}
