#include <iostream>
#include<cctype>
#include <string>
using namespace std;

void week(char c){
	switch(c){
		case 'A':
			cout<<"MON"<<" ";
			break;
		case 'B':
			cout<<"TUE"<<" ";
			break;
		case 'C':
			cout<<"WED"<<" ";
			break;
		case 'D':
			cout<<"THU"<<" ";
			break;
		case 'E':
			cout<<"FRI"<<" ";
			break;
		case 'F':
			cout<<"SAT"<<" ";
			break;
		case 'G':
			cout<<"SUN"<<" ";
			break;
	}
}

void hour(char c){
	if(isdigit(c))
		printf("%02d",(int)(c-'0'));
	else
		printf("%02d",(int)(c-'A') + 10);
}

int main(void) {
  string s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
  int min_size = min(s1.size(),s2.size()), cnt = 1;

  for(int i = 0; i < min_size; i++){
	  //是不是第二个字母
	  if(cnt == 2 && s1[i] == s2[i]){
		  hour(s1[i]);
		  break;
	  }

	  //是不是第一个字母，是不是一样的，是不是大写
	  if(cnt == 1 && s1[i] == s2[i] && isupper(s1[i])){
		  week(s1[i]);
		  cnt++;
	  }
  }

  min_size = min(s3.size(),s4.size());
  for(int i =0;i < min_size;i++){
	  if(s3[i] == s4[i] &&isalpha(s3[i])){
		  printf(":%02d",i);
		  break;
	  }
	  
  }
  cout<<endl;
  return 0;
}
