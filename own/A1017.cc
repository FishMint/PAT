#include <bits/stdc++.h>
using namespace std;

struct person {
	int come;
	int time;
};

bool cmp(person a, person b) {
	return a.come < b.come;
}

int main(void) {
	int n, k, cnt = 0, result = 0;
	int hh, mm, ss, tt;
	person p[10010];

	cin >> n >> k;

	//初始化记录人数
	for(int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
		//cin>> hh >> mm >> ss >> tt;
		int sum = hh * 3600 + mm * 60 + ss;

		//来晚了
		if(sum > 17 * 3600) continue;
		p[++cnt].come = sum;
		p[cnt].time = tt * 60;

	}
	sort(p + 1, p + cnt + 1, cmp);

	//定义小根堆
	priority_queue<int, vector<int>, greater<int>> q;
	
	for(int i = 1; i <= k; i++) q.push(8 * 3600);
	for(int i = 1; i <= cnt; i++) {
		if(q.top() <= p[i].come) {
			q.pop();
			q.push(p[i].time + p[i].come);
		}
		else {
			//等待时间
			result += q.top() - p[i].come;
			q.push(q.top() + p[i].time);
			q.pop();
		}
	}

	if(cnt == 0) printf("0.0\n");
	else printf("%.1f\n", (double)result/60.0/cnt);
	return 0;
}
