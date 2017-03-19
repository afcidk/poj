#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

map<string, vector<string>> m;
map<string, vector<string>>::iterator iter;

int main() {
	char s[105];
	while(scanf("%s", s) && strcmp(s, "XXXXXX")!=0){
		char temp[105];
		strcpy(temp, s);
		sort(temp, temp+strlen(s));
		m[temp].push_back(s);
	}
	while(scanf("%s", s) && strcmp(s, "XXXXXX")!=0){
		sort(s, s+strlen(s));
		if((iter=m.find(s)) != m.end()){
			string temp[10000];
			int i;
			for(i=0; i<iter->second.size(); i++)	temp[i]=iter->second[i];
			sort(temp, temp+iter->second.size());
			for(i=0; i<iter->second.size(); i++)	cout<<temp[i]<<endl;
		}
		else{
			cout<<"NOT A VALID WORD"<<endl;
		}
		cout<<"******"<<endl;
	}
	return 0;
}
