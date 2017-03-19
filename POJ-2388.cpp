#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

int main() {
	int n;
	int num[10005];
	while(scanf("%d", &n) == 1){
		int i;
		for(i=0; i<n; i++)	scanf("%d", &num[i]);
		sort(num, num+n);

		if(n%2==1){
			printf("%d\n", num[(n-1)/2]);
		}
		else printf("%d\n", (num[n/2]+num[n/2-1])/2);
	}
	return 0;
}
