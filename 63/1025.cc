#include<iostream>

int main(void)
{
	int array[100001], n,t,cnt =0;
	std::cin>>n;

	//输入 array[ val ] =  val 的cur_pos
	for(int i =0;i < n;i++)
	{
		std::cin>>t;
		array[t] = i;
	}

	//确保n - 1 个数到达自己的位置
	for(int i =1; i < n;i++)
	{
		if(array[i] != i)
		{
			while(array[0] != 0)	//0号没有归位,先让0号归位
			{
				std::swap(array[0], array[array[0]]);
				cnt++;
			}

			if(array[i] != i)
			{
				std::swap(array[0] , array[i]);
				cnt++;
			}
		}
	}
	std::cout<<cnt<<std::endl;

	return 0;
}
