#include <bits/stdc++.h>
using namespace std;

struct stu
{
    string sid;
    int score;
};


bool cmp(stu a, stu b) {
    if(a.score > b.score)   return true;
    if(a.score < b.score)   return false;
    return a.sid < b.sid;
}

bool cmp_map(pair<string, int> a, pair<string, int> b) {
     if(a.second > b.second)    return true;
     if(a.second < b.second)    return false;
     return a.first < b.first;
}

int level_Trans(char s) {
    if(s == 'A') return 1;
    if(s == 'T') return 2;
    if(s == 'B') return 0;
    return -1;
}


unordered_map<string, int> site_cnt_map, site_sum_map;
unordered_map<string, map<string, int>> date_map;
vector<stu> levelQue[3];
//date map


int main(void) {
    int n, m;
    cin >> n >> m;
    stu s[n + 5];

    for(int i = 1; i <= n; i++) {
        string str;
        int score;
        cin >> str >> score;
        s[i].sid = str;
        s[i].score =score;

        //学生分批入队
        levelQue[level_Trans(str[0])].push_back(s[i]);
        //座位计数
        site_cnt_map[str.substr(1,3)]++;
        site_sum_map[str.substr(1,3)] += s[i].score;
        //日期
        date_map[str.substr(4,6)][str.substr(1,3)]++;
    }


    // 排序
    for(int i = 0; i < 3; i++) 
        sort(levelQue[i].begin(), levelQue[i].end(), cmp);


    for(int i = 1; i <= m; i++) {
        int type;
        string term;
        char c;

        cin >> type;

        if(type == 1) {
            cin >> c;
            cout<<"Case "<<i<<": "<<type << " "<< c <<endl;

            if(level_Trans(c) == -1) {
                cout<<"NA"<<endl;
                continue;
            }

            for(auto it = levelQue[level_Trans(c)].begin();
                     it != levelQue[level_Trans(c)].end(); it++) {
                cout<< it->sid << " "<< it->score << endl;
            }

        }
        else if(type == 2) {
            cin >> term;
            cout<<"Case "<<i<<": "<<type << " "<< term <<endl;
            if(site_cnt_map[term] != 0)
                cout<<site_cnt_map[term]<<" "<<site_sum_map[term]<<endl;
            else    
                cout<<"NA"<<endl;
        }else{
            cin >> term;
            cout<<"Case "<<i<<": "<<type << " "<< term <<endl;

            //不存在
            if(date_map[term].size() == 0) {
                cout<<"NA"<<endl;
                continue;
            }

            vector<pair<string, int>> v(date_map[term].begin(), date_map[term].end());
            sort(v.begin(), v.end(), cmp_map);

            for(auto it = v.begin();
                     it != v.end(); it++) {
                cout<<it->first<<" "<<it->second<<endl;
            }
        }
    }


    return 0;
}
