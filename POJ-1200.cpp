#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAX 16000000
using namespace std;

int table[MAX], ele[512];
char s[1000000];

int main() {
	int n, nc;
	while(scanf("%d%d", &n, &nc)==2){
		memset(table, 0, sizeof(table));
		for(int i=0; i<512; ++i)	ele[i]=-1;

		getchar();
		fgets(s, 1000000, stdin);
		int len = strlen(s)-1, count=-1;

		for(int i=0; i<len; ++i){
			if(ele[s[i]] == -1){
				ele[s[i]] = ++count;
			}
			if(count == nc)	break;
		}

		int value=0, ans=1;
		int h = pow((double)nc, (double)n-1);
		for(int i=0; i<n; ++i){
			value = value*nc + ele[s[i]];
		}

		table[value] = 1;
		for(int i=n; i<len; ++i){
			value = (value-h*ele[s[i-n]])*nc + ele[s[i]];
			if(table[value]==0) {
				table[value] = 1;
				ans++;
			}
		}

		printf("%d\n", ans);
	}
	return 0;
}
