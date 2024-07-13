#include <bits/stdc++.h>
using namespace std;

//平润年的12月的日期
// 平 ， 润
int month[13][2] = {
    {0, 0},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
};

int IsLeaf(int year) {
    if(year % 400 == 0 || 
      (year % 100 != 0 && year % 4 == 0)) 
    {
        return 1;
    }
    return 0;
}

int main(void) {
    int time1, time2;
    while (scanf("%d %d", &time1, &time2) != EOF)
    {
        int cnt = 1;
        if (time1 < time2)  swap(time1, time2);

        int year1 = time1 / 10000, month1 = (time1 / 100) % 100, day1 = time1 % 100;
        int year2 = time2 / 10000, month2 = (time2 / 100) % 100, day2 = time2 % 100;

        while (year1 > year2 || month1 > month2 || day1 > day2)
        {
            day2++;

            //到了新的月
            if (day2 == month[month2][IsLeaf(year2)] + 1) {
                month2++;
                day2 = 1;
            }

            //到了新的年
            if(month2 == 13) {
                month2 = 1;
                year2++;
            }

            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}