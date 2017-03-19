#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

struct S{
	double rate;
	int eat, dis;

	bool operator< (const struct S &t) const{
		return rate>t.rate;
	}

}cows[100005];

int main() {
	int n;
	while(scanf("%d", &n)==1){
		int i, j;
		int a, b;
		long long int sum=0;
		for(i = 0; i<n; i++){
			scanf("%d%d", &a, &b);
			cows[i].rate=(double)b/a;
			cows[i].eat = b;
			cows[i].dis = a;
			sum+=b;
		}
		sort(cows, cows+n);

		long long int ans=0;
		for(i=0; i<n; i++){
			sum-=cows[i].eat;
			ans+=sum*cows[i].dis*2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
