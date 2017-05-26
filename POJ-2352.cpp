#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 40000
using namespace std;

int v[MAX], level[MAX];


int lowbit(int in){
	return in&(-in);
}
void modify(int index, int val);
int getSum(int index);
void init(){
	memset(v, 0, sizeof(v));
	memset(level, 0, sizeof(level));
}

int main() {

	int N;
	while(scanf("%d", &N)==1){
		init();

		int a, b;
		for(int i=0; i<N; ++i){

			scanf("%d%d", &a, &b);
			++a;
			modify(a, 1);
			++level[getSum(a)-1];
		}

		for(int i=0; i<N; ++i){
			printf("%d\n", level[i]);
		}
	}
	return 0;
}

void modify(int index, int val){
	
	for(int i=index; i<MAX; i+=lowbit(i)){
		v[i]+=val;
	}
}

int getSum(int index){

	int ret=0;
	while(index>0){

		ret+=v[index];
		index-=lowbit(index);
	}
	return ret;
}
