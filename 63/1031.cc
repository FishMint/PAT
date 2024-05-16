#include<iostream>
#include<string>
#include<vector>

int main(void){
	int n;
	int rand[55];
	int ans1[55],ans2[55];

	std::cin>>n;

	for(int i = 1;i < 55;i++)
	{
		std::cin>>rand[i];
		ans2[i] = i;
	}

	for(int i = 0;i < n; i++)
	{
		for(int j =1; j < 55;j++)
			ans1[j] = ans2[j];

		for(int j = 1; j < 55; j++)
			ans2[rand[j]] = ans1[j];
	}

	char c[6] = "SHCDJ";
	for(int i = 1; i < 54;i++)
	{
		printf("%c%d ",*(c + ((ans2[i] -1) / 13)),(ans2[i] -1) % 13 +1);
	}
	printf("%c%d\n",*(c + ((ans2[54] -1) / 13)),(ans2[54] -1) % 13 +1);

	return 0;
}

