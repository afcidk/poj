#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void fail(char*, int*);
void match(char*, char*, int*);

int main() {
	int n;
	scanf("%d", &n);
	getchar();

	while(n--){
		char a[10005], b[1000005];
		int pi[10005];
		scanf("%s %s", a, b);

		fail(a, pi);

		match(b, a, pi);
	}
	return 0;
}

void fail(char *s, int *pi){
	int len=strlen(s);

	int i, cur_pos=-1;
	pi[0]=-1;
	for(i=1; i<len; ++i){

		while(~cur_pos && s[i]!=s[cur_pos+1])	cur_pos = pi[cur_pos];
		if(s[i]==s[cur_pos+1])	++cur_pos;
		pi[i] = cur_pos;
	}
}

void match(char *s, char *cmp, int *pi){
	int lena=strlen(s), lenb=strlen(cmp);

	int i, cur_pos=-1;
	int ans=0;
	for(i=0; i<lena; ++i){

		while(~cur_pos && s[i]!=cmp[cur_pos+1])	cur_pos = pi[cur_pos];
		if(s[i] == cmp[cur_pos+1])	cur_pos++;
		if(cur_pos+1 == lenb){
			ans++;
			cur_pos = pi[cur_pos];
		}
	}
	printf("%d\n", ans);
}
