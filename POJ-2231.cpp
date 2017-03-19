#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	int num[10005];
	while(scanf("%d", &n)==1){
		int i, j;
		long long int ans=0;
		for(i=0; i<n; i++){
			scanf("%d", &num[i]);
			for(j=i-1; j>=0; j--){
				ans+=abs(num[i]-num[j]);
			}
		}
		printf("%lld\n", ans*2);
	}	
	return 0;
}
