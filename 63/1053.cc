#include <algorithm>
#include <iostream>
#include <string>
#include<vector>
using namespace std;

struct Person {
  string id;
  int virtue;
  int talent;
};

int compare(struct Person &a, struct Person &b) {
  if ((a.virtue + a.talent) < (b.virtue + b.talent)) return 0;
  else if ((a.virtue + a.talent) > (b.virtue + b.talent)) return 1;
  else {
    if (a.virtue < b.virtue) return 0;
    else if (a.virtue > b.virtue) return 1;
    else return a.id < b.id ? 1 : 0;
  }
}

int main(void) {
  struct Person p[100000];
  vector<struct Person> v0,v2,v3,v1;
  int n, low_L, high_L,cnt_0 = 0,cnt_1 = 0,cnt_2 = 0,cnt_3 = 0;
  cin >> n >> low_L >> high_L;

  for (int i = 0; i < n; i++) {
	  cin>>p[i].id>>p[i].virtue>>p[i].talent;
  }

  for(int i = 0; i < n;i++){
	  if(p[i].talent >= high_L && p[i].virtue >= high_L){
		  v0.push_back(p[i]);
		  cnt_0++;
	  }else if(p[i].talent >= low_L && p[i].virtue >= low_L){
		  if(p[i].virtue >= high_L){
			  cnt_1++;
			  v1.push_back(p[i]);
		  }
		  else if(p[i].virtue >= p[i].talent){
			  v2.push_back(p[i]);
			  cnt_2++;
		  }
		  else{
			  cnt_3++;
			  v3.push_back(p[i]);
		  }
	  }
  }

  sort(v0.begin(),v0.end(),compare);
  sort(v1.begin(),v1.end(),compare);
  sort(v2.begin(),v2.end(),compare);
  sort(v3.begin(),v3.end(),compare);

  int cnt = cnt_0 + cnt_1+ cnt_2 + cnt_3;
  cout<<(cnt)<<endl;
  for (int i = 0; i < cnt_0; i++) {
	  cout<<v0[i].id<<" "<<v0[i].virtue<<" "<<v0[i].talent<<endl;
  }
  for (int i = 0; i < cnt_1; i++) {
	  cout<<v1[i].id<<" "<<v1[i].virtue<<" "<<v1[i].talent<<endl;
  }
 
  for (int i = 0; i < cnt_2; i++) {
	  cout<<v2[i].id<<" "<<v2[i].virtue<<" "<<v2[i].talent<<endl;
  }
  for (int i = 0; i < cnt_3; i++) {
	  cout<<v3[i].id<<" "<<v3[i].virtue<<" "<<v3[i].talent<<endl;
  }
  return 0;
}
