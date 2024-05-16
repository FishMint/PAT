#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
  int start_addr;
  int N, K;
  int cur_val[100005], next[100005], list[100005], result[100005];
  int tmp;
  cin >> start_addr >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> tmp;  //这个就是地址
    //这里直接利用哈希表来直接快速定位
    cin >> cur_val[tmp] >> next[tmp];
  }

  int cnt = 0;
  //把地址串成一个list
  while (start_addr != -1) {
    list[cnt++] = start_addr;
    start_addr = next[start_addr];
  }
 // for (int i = 0; i < cnt; i++) result[i] = list[i]; 最后的改动
  int per_begin;
  for (int i = 0; i < cnt / K; i++) {
    per_begin = i * K;
    for (int j = (i + 1) * K - 1; j >= i * K; j--) {
      result[per_begin++] = list[j];
    }
  }
  //for (; per_begin < cnt; per_begin++) result[per_begin] = list[per_begin];最后的改动,cnt =8 , K = 4,就爆炸

//for (int i = 0; i < N -1; i++) 
//  //这里输出的地址要是下一个的地址
//  cout << result[i] << " " << cur_val[result[i]] << " " << result[i + 1]<< endl;
//cout << result[N-1] << " " << cur_val[result[N -1]] << " " << -1 << endl;

  for (int i = 0; i < cnt -1; i++) 
	  printf("%05d %d %05d\n",result[i],cur_val[result[i]],result[i+1]);
  printf("%05d %d -1\n",result[cnt-1],cur_val[result[cnt -1]]);
  return 0;
}
