#include<iostream>
#include<cstdio>
#include<map>
#include<string>
#include<cstring>
using namespace std;

const string trans="22233344455566677778889999";

int main() {
	int n;
	while(scanf("%d", &n)==1){
	map<string, int> m;
	map<string, int>::iterator iter;
	getchar();
	while(n--){
		char s[100];
		string temp="";
		scanf("%s", s);
		getchar();
		int len = strlen(s);
		int i;
		for(i=0; i<len; i++){
			if(s[i]<='9' && s[i]>='0')	temp+=s[i];
			else if(s[i]<='Z' && s[i] >='A')	temp+=trans.at(s[i]-'A');
		}
		if(m.find(temp) == m.end())	m[temp]=1;
		else m[temp]++;
	}
	int success=0;

	for(iter=m.begin(); iter!=m.end(); iter++){
		if(iter->second>1){
			success=1;
			cout<<iter->first.substr(0,3)<<"-"<<iter->first.substr(3,4)<<" "<<iter->second<<endl;
		}
	}
	if(!success)	printf("No duplicates.\n");
	}
	return 0;
}
