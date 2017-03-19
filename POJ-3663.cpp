#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int main() {
	int n, m;
	int num[20005];
	while(scanf("%d%d", &n, &m) == 2){
		int i, j;
		long long int ans=0;
		for(i=0; i<n; i++){
			scanf("%d", &num[i]);
		}
		sort(num, num+n);
		for(i=0; i<n; ++i){
			for(j=i+1; j<n&&num[i]+num[j]<=m; ++j){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
