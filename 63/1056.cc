#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main(void) {
  string s;
  cin >> s;
  if (s[0] == '-') cout << "-";
  int i;
  for (i = 1; i < s.size(); i++)
    if (s[i] == 'E') break;
  int n = stoi(s.substr(i + 1));  // 10的次方

  //次方大于0
  if (n > 0) {
    //如果.后的数 < n，那就直接补0
    if (i - 3 <= abs(n)) {
      for (int j = 1; j < i; j++)
        if (s[j] != '.') cout << s[j];
      for (int j = 1; j <= abs(n) - i + 3; j++) cout << '0';  //补0
    } else {
      for (int j = 1; j < i; j++) {
        if (s[j] != '.') cout << s[j];
        if (j == abs(n) + 2) cout << '.';
      }
    }
  }
  //次方小于0
  else if (n < 0) {
    cout << "0.";
    for (int j = 1; j <= abs(n) - 1; j++) cout << '0';
    for (int j = 1; j < i; j++)
      if (s[j] != '.') cout << s[j];

  }
  // == 0
  else {
    for (int j = 1; j < i; j++) cout << s[j];
  }

  cout << endl;

  return 0;
}
