#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int inf =99999999;

struct station {
  double price;
  double distence;
};

int comp(struct station &a, struct station &b) {
	if(a.distence < b.distence)	return 1;
	else if(a.distence == b.distence){
		return a.price < b.price;
	}
	return 0;
}

int main(void) {
  double cmax, total_distence, davg;
  int station_num;
  scanf("%lf%lf%lf%d", &cmax, &total_distence, &davg, &station_num);
  vector<station> sta;
  struct station s;

  //把终点也抽象成一站
  s.price = 0.00;
  s.distence = total_distence;
  sta.push_back(s);

  //输入加排序
  for (int i = 0; i < station_num; i++) {
    cin >> s.price >> s.distence;
    sta.push_back(s);
  }
  sort(sta.begin(), sta.end(), comp);

  //如一开始就没有加油站，那就一公里都开不了
  if (sta[0].distence != 0) {
    printf("The maximum travel distance = 0.00");
    return 0;
  }

  double cur_dis = 0, max_dis = 0.0, cur_price = sta[0].price,left_dis = 0.0;
  double ans = 0.0;

  while(cur_dis < total_distence){
	  max_dis = cur_dis + cmax * davg;
	  double minPrice = inf,minPricedis = 0;
	  int flag = 0;
	  //找最大公里之中的站
	  for(int i =1; i <= station_num && sta[i].distence <= max_dis; i++){
		  if(sta[i].distence <= cur_dis)	continue;	//跳过之前的站
		  //每次遇到比自己价格低的站，就刚好开到那里
		  if(sta[i].price < cur_price){
			  ans += (((sta[i].distence - cur_dis - left_dis)/davg) * cur_price);		//刚好到站的油钱
			  cur_dis = sta[i].distence;
			  cur_price = sta[i].price;
			  left_dis = 0.0;
			  flag =1;
			  break;
		  }
		  //如果没有，那就直接在范围内找便宜的
		  if(minPrice > sta[i].price){
			  minPrice = sta[i].price;
			  minPricedis = sta[i].distence;
		  }
	  }

	  //如果找到了最小价格的站，就把当前站的油加满
	  if(flag == 0 && minPrice != inf){
		  ans += (cmax - left_dis / davg)*cur_price;	//加满的油钱
		  left_dis = cmax * davg -(minPricedis - cur_dis);	//还剩几公里可以跑
		  cur_dis = minPricedis;
		  cur_price = minPrice;
	  }
	  
	  //如果在最大范围内没有一个站，那就是到不了了
	  if(flag == 0 && minPrice ==inf){
		  cur_dis += cmax * davg;
		  printf("The maximum travel distance = %.2lf",cur_dis);
		  return 0;
	  }

  }
  printf("%.2f",ans);

  return 0;
}
