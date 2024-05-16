#include<bits/stdc++.h>
using namespace std;

int main(void) {
  int num;
  int ori_arr[101], cur_arr[101];
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> ori_arr[i];
  }

  for (int i = 0; i < num; i++) {
    cin >> cur_arr[i];
  }

  int i, j;
  //下面两个for就是来判断是Insert ， 还是merge
  for (i = 0; i < num - 1 && cur_arr[i] <= cur_arr[i + 1]; i++);  //先把前面那些顺序排序的数字跳过
  for (j = i + 1; j < num && ori_arr[j] == cur_arr[j]; j++);	  //看看后面的上下两个数组是不是一样

  //说明是这个是插入排序的
  if (j == num) {
    cout << "Insertion Sort" << endl;
    sort(ori_arr, ori_arr + i + 2);  //这个+2是因为排序到末尾

  } else {
    //这段就是并归排序
    cout << "Merge Sort" << endl;
    int k = 1, flag = 1;

    while (flag) 
	{
      flag = 0;

	  //判断是不是和给出那个情况重合了
      for (i = 0; i < num; i++) 
	  {
        if (ori_arr[i] != cur_arr[i]) 
		{
          flag = 1;
          break;
        }
      }

      k = k * 2;  //这里就是并归排序的实现
      for (i = 0; i < num / k; i++)
        sort(ori_arr + i * k, ori_arr + (i + 1) * k);
      sort(ori_arr + i * k, ori_arr + num);
    }
  }

  for(i = 0;i<num;i++){
      if(i != 0)	cout<<" ";
      cout<<ori_arr[i];
  }
  cout<<endl;

  return 0;
}
