#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
struct node {
    string t;
    int value;
};
bool cmp(const node &a, const node &b) {
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}

/*
柳神的思想就是
先把全部的都存进去v[]
然后每次有查询任务进来的时候, 每次一次都直接查询所有成员

for(i : m)
1-> 一个个找这个点, 是的话，入队排序
2-> 一个个找这个点是不是 对应教室，是的话cnt++， sum+=
3-> 一个个找， 是不是对应日期，是的话, umap[教室号]++， umap变成vector然后对着排序
最后统一判断是不是 空 输出 NA
*/

int main() {
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;

    for (int i = 1; i <= k; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans;
        int cnt = 0, sum = 0;

        if (num == 1) {
            for (int j = 0; j < n; j++)
                if (v[j].t[0] == s[0]) ans.push_back(v[j]);
        } 
        else if (num == 2) {
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
        } 
        else if (num == 3) {
            unordered_map<string, int> m;
            for (int j = 0; j < n; j++)
                if (v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
            for (auto it : m) ans.push_back({it.first, it.second});
        }

        sort(ans.begin(), ans.end(),cmp);
        for (int j = 0; j < ans.size(); j++)
            printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
            
            //如果 1，3没有v ， 2的cnt是0，就打印NA
        if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) printf("NA\n");
    }
    return 0;
}