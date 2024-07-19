#include <bits/stdc++.h>
using namespace std;

#define MAXSIZE 1010

struct stu
{
    string name;
    string id;
    int score;
};


int main(void) {
    int n, score;
    string name, id;
    stu stu_max, stu_min;


    cin>>n;
    stu_max.score = 0;
    stu_min.score = 101;
    for(int i = 0; i < n; i++) {
        cin>>name>>id>>score;
        if(stu_max.score < score) {
            stu_max.name = name;
            stu_max.id = id;
            stu_max.score = score;
        }
        if (stu_min.score > score){
            stu_min.name = name;
            stu_min.id = id;
            stu_min.score = score;
        }
    }

    cout<<stu_max.name<<" "<<stu_max.id<<endl;
    cout<<stu_min.name<<" "<<stu_min.id<<endl;

    return 0;
}