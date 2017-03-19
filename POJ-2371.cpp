#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	int num[100005];
	while(scanf("%d", &n) == 1){
		int i;
		string s;
		for(i=0; i<n; i++)	scanf("%d", &num[i]);
		sort(num, num+n);

		cin>>s;
		scanf("%d", &n);
		int x;
		for(i=0; i<n; i++){
			scanf("%d", &x);
			printf("%d\n", num[x-1]);
		}
	}
	return 0;
}
