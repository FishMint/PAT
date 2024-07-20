#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int n;
    int id, score;
    int ans_id, ans_score = -1;
    unordered_map<int, int> umap;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &id, &score);
        umap[id] += score;
    }

    for (auto it = umap.begin(); it != umap.end(); it++) {
        if (ans_score < it->second) {
            ans_score = it->second;
            ans_id = it->first;
        } 
    }
    cout<< ans_id << " " << ans_score <<endl;
    return 0;
}
