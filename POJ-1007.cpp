#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;

struct S{
	string s;
	int cmp;

	bool operator< (const struct S &t) const{
		return cmp<t.cmp;
	}

}str[105];
int count(string);

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)==2){
		getchar();
		int i;
		for(i=0; i<m; i++){	
			cin>>str[i].s;
			str[i].cmp=count(str[i].s);
		}
		sort(str, str+m);

		for(i=0; i<m; i++)	cout<<str[i].s<<endl;
	}
	return 0;
}

int count(string s){
	int len = s.length();
	int i, j, ret=0;

	for(i=0; i<len; i++){
		for(j=i+1; j<len; j++){
			if(s.at(j)<s.at(i))	ret++;
		}
	}
	return ret;
}
