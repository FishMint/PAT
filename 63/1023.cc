#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  long long a, b, c;
  int tmp1, tmp2, tmp3;

  for (int i = 1; i <= n; i++) {
    cin >> a >> b >> c;
	//如果是异号
    if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
      if (a + b > c) printf("Case #%d: true\n", i);
      else printf("Case #%d: false\n", i);
    }
	//如果是同号
	else {
		  tmp1 = a & 1;
		  tmp2 = b & 1;
		  tmp3 = c & 1;
		  a = a >> 1;
		  b = b >> 1;
		  c = c >> 1;
		  cout<<a<<b<<c<<endl;
		  cout<<tmp1<<tmp2<<tmp3<<endl;
		  if (a + b > c){ printf("Case #%d: true\n", i); }
		  else if (a + b == c) { 
			  //前几位相同，比较后几位
			  if (tmp1 + tmp2 > tmp3) printf("Case #%d: true\n", i);
			  else printf("Case #%d: false\n", i);
		  }
		  else printf("Case #%d: false\n", i);
	}
  }

  return 0;
}
