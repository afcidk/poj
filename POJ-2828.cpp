#include <iostream>
#include <cstdio>
#define MAX 2000000
using namespace std;

struct S{
	int pos, val;
}peo[MAX];
int sum[MAX];
int ans[MAX];
void build(int l, int r, int nn);
int modify(int tar, int l, int r, int nn);

int main() {

	int n;
	while(scanf("%d", &n)==1){

		for(int i=0; i<n; ++i){
			scanf("%d%d", &peo[i].pos, &peo[i].val);
		}

		build(1, n, 1);

		for(int i=n-1; i>=0; --i){

			ans[modify(peo[i].pos, 1, n, 1)] = peo[i].val;
		}

		printf("%d", ans[1]);
		for(int i=2; i<=n; ++i){
			printf(" %d", ans[i]);
		}
		puts("");
	}
	return 0;
}

void build(int l, int r, int nn){

	sum[nn]=r-l+1;
	if(l==r)	return;
	int mid = (l+r)/2;
	build(l, mid, nn*2);
   	build(mid+1, r, nn*2+1);	
}

int modify(int tar, int l, int r, int nn){

	--sum[nn];
	if(l==r){
		return l;
	}
	int mid = (l+r)/2;
	if(sum[nn*2]>tar){
		modify(tar, l, mid, nn*2); 
	}
	else{
		//tar-sum[nn*2] -> remainder
		modify(tar-sum[nn*2],mid+1, r, nn*2+1);
	}
}
