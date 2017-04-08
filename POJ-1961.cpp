#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1000005
using namespace std;

void fail(char*, int*);
int match(char*, int, int*);

int main() {
	int len, ca=0;
	while(scanf("%d", &len)==1 && len){
		getchar();
		char s[MAX];
		int pi[MAX];
		scanf("%s", s);

		fail(s, pi);
		int i;

		printf("Test case #%d\n", ++ca);

		for(i=0; i<len; ++i){
			/** if the substring(i+1) can be divide by substring(i+1) minus nearest same substring(pi[i]+1)**/
			if(pi[i]!=-1 && (i+1)%(i-pi[i])==0){
				printf("%d %d\n", i+1, (i+1)/(i-pi[i]));
			}
		}
		puts("");
	}
	return 0;
}

void fail(char *s, int *pi){
	int len = strlen(s);
	int i, cur_pos=-1;

	pi[0]=-1;
	for(i=1; i<len; ++i){

		while(~cur_pos && s[i]!=s[cur_pos+1])	cur_pos = pi[cur_pos];
		if(s[i]==s[cur_pos+1])	cur_pos++;
		pi[i]=cur_pos;
	}
}

int match(char *s, int max_len, int *pi){
	int len = strlen(s);

	int i, cur_pos=-1;
	int count=0;
	for(i=0; i<len; ++i){
		
		while(~cur_pos && s[i]!=s[cur_pos+1]){
			if(s[i]!=s[cur_pos+1])	return 0;
			cur_pos = pi[cur_pos];
		}
		if(s[i]==s[cur_pos+1])	cur_pos++;
		else{
			return 0;
		}
		if(cur_pos+1 == max_len){
			++count;
			if(count>1)	printf("%d %d\n", i+1, count);
			cur_pos = pi[cur_pos];
		}
	}
	return 1;
/*	int step=0;
	for(i=0; i<len; ++i){
		if(s[i]!=s[step]){
			return 0;
		}
		else{
			++step;
			if(step == max_len){
				++count;
				if(count>1){
					printf("%d %d\n", i+1, count);
				}
				step=0;
			}
		}
	}
	return 1;*/
}
