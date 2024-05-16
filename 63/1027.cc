#include<iostream>
#include<string.h>
#include<map>

int main(void){
	std::string line,s = "";
	std::map<std::string,int> s_map;

	std::getline(std::cin,line);
	for(int i =0; i < line.size();i++)
	{
		if(isalnum(line[i]))
		{
			line[i] = tolower(line[i]);	//变成小写
			s += line[i];
		}
		if(!isalnum(line[i]) || i == line.size() -1)
		{
			s_map[s]++;
			s = "";
		}
	}
	
	int ans_num = -1;
	std::string ans_s = "";
	for(auto it = s_map.begin(); it != s_map.end(); it++)
	{
		if(it->first != "")
		{
			if(it->second > ans_num)
			{
				ans_num = it->second;
				ans_s = it->first;
			}
		}
	}

	std::cout<<ans_s<<" "<<ans_num<<std::endl;

	return 0;
}

