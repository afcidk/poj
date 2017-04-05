#include<iostream>
#include<cstdio>
#define MAX 0xfffffff
using namespace std;

struct S{
	int a, b;
	int val;
}vertix[4005];

int main() {
	int T, N;
	while(scanf("%d%d", &T, &N)==2){
		int dots[1005];
		for(int i=0; i<=N; ++i)	dots[i]=MAX;
		int a, b, c;

		T*=2;
		for(int i=0; i<T; i+=2){
			scanf("%d%d%d", &a, &b, &c);
			vertix[i].a=a;	vertix[i].b=b;	vertix[i].val=c;
			vertix[i+1].a=b;	vertix[i+1].b=a;	vertix[i+1].val=c;
		}

		dots[1] = 0;
		for(int j=0; j<N-1; ++j){
			for(int i=0; i<T; ++i){
	
				int nowa=vertix[i].a, nowb=vertix[i].b, nowCost=vertix[i].val;
				if(dots[nowa]+nowCost < dots[nowb]){
					dots[nowb]=dots[nowa]+nowCost;
				}
			}
		}
		printf("%d\n", dots[N]);
	}
	return 0;
}
