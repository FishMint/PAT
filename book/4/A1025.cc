#include <bits/stdc++.h>
using namespace std;

struct Node
{
    string regNumber;
    int score;
    int group;
    int local_rank;
};

bool cmp(struct Node a, struct Node b) {
    if(a.score > b.score) return true;
    else if(a.score < b.score) return false;

    return (a.regNumber < b.regNumber);
}

int main(void) {
    vector<Node> node;
    int n, k, total = 0;

    cin>>n;
    for(int i = 1; i <= n; i++) {
        cin>>k;

        //开始插入t, 到vector的链表里
        for(int j = 0; j < k; j++) {
            struct Node t;
            cin >> t.regNumber >> t.score;
            t.group = i;
            node.push_back(t);
        }

        //单组排序，然后直接赋值 local_rank
        sort(node.begin() + total, node.begin() +total + k, cmp);
        node[total].local_rank = 1;

        for(int step = total + 1; step < total + k; step++) {
            if(node[step - 1].score == node[step].score)    
                node[step].local_rank = node[step - 1].local_rank;
            else
                node[step].local_rank = step + 1 - total;
        }

        total += k;
    }

    sort(node.begin(), node.end(), cmp);

    int final_rank = 1;
    
    cout<<total<<endl;
    cout<<node[0].regNumber<<" 1 "<< node[0].group<<" 1"<<endl;
    for(int i = 1; i < total; i++) {
        if(node[i - 1].score == node[i].score) {
            cout<< node[i].regNumber  << " "
                << final_rank         << " "
                << node[i].group      << " "
                << node[i].local_rank << endl;
        }else {
            final_rank = i + 1;
            cout<< node[i].regNumber  << " "
                << final_rank         << " "
                << node[i].group      << " "
                << node[i].local_rank << endl;
        }

    }

    return 0;
}