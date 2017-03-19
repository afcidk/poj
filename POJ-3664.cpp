#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct S{
	int ind;
	int a, b;

	bool operator< (const struct S &t) const{
		return a>t.a;
	}

}cows[50005];

int main() {
	int n, k;
	while(scanf("%d%d", &n, &k)==2){
		int i;
		for(i=0; i<n; i++){
			scanf("%d %d", &cows[i].a, &cows[i].b);
			cows[i].ind = i+1;
		}

		sort(cows, cows+n);

		int ma=cows[0].b, maind=0;

		for(i=0; i<k; i++){
			if(ma < cows[i].b){
				ma = cows[i].b;
				maind = i;
			}
		}

		printf("%d\n", cows[maind].ind);
	}
	return 0;
}

