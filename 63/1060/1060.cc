#include <iostream>
#include <string>
using namespace std;

//求最简形式
void simp_func(long long m, long long d);

//最大公约数
long long gcd(long long m, long long d);

int main(void) {
  long long a, b, c, d;
  scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

  simp_func(a,b); printf(" + "); simp_func(c,d); printf(" = "); simp_func((a*d + c*b),b*d); printf("\n");
  simp_func(a,b); printf(" - "); simp_func(c,d); printf(" = "); simp_func((a*d - c*b),b*d);printf("\n");
  simp_func(a,b); printf(" * "); simp_func(c,d); printf(" = "); simp_func((a*c),b*d);printf("\n");
  simp_func(a,b); printf(" / "); simp_func(c,d); printf(" = "); simp_func((a*d),b*c);printf("\n");
  return 0;
}

void simp_func(long long m, long long d) {
	if (d == 0) {
		cout << "Inf";
		return ;
  }

  //判断正负的标志
  bool flag = false;
  if ((m < 0 && d > 0) || (m > 0 && d < 0)) flag = true;

  if (m != 0) {
    //取绝对值,化简
    long long max_com = gcd(abs(m), abs(d));
    m = abs(m) / max_com;
    d = abs(d) / max_com;

    cout << (flag ? "(-" : "");
   // if (m / d != 0) cout << m / d;       //前面的数字
   // if (m % d != 0 && m /d != 0) cout<<" " << m % d << "/" << d;  //如果可以整除的话
   // if (m % d != 0 && m /d == 0) cout<< m % d << "/" << d;  

   //有代数的时候 
	if(m / d != 0){	
		cout << m / d;
		if(m % d != 0)	cout<<" " << m % d << "/" << d;
	}
	//没有代数的时候
	else {	
		cout<< m % d << "/" << d;
	}

    cout << (flag ? ")" : "");
  }else{
	  cout<<0;
  }
}

//	这里直接使用辗转相除法
long long gcd(long long d, long long m) {
  return d % m == 0 ? m : gcd(m, d % m);
}
