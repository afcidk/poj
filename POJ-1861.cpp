#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 20005
using namespace std;

struct S{
	int x, y, dis;

	bool operator< (const struct S &t) const{
		return dis<t.dis;
	}
}road[MAX];
int p[MAX];

int find(int x);
void init(){
	for(int i=0; i<MAX; ++i){
		road[i].x=road[i].y=road[i].dis=0;
		p[i] = i;
	}
}

int main() {
	
	int N, M;
	while(scanf("%d%d", &N, &M)==2){
		init();

		for(int i=0; i<M; ++i){
			scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].dis);
		}

		sort(road, road+M);

		int max_ans=0;
		for(int i=0; i<M; ++i){

			int xx = find(road[i].x);
			int yy = find(road[i].y);
			if(xx!=yy){
				p[xx]=yy;
				max_ans = max(road[i].dis, max_ans);
			}
		}
		printf("%d\n", max_ans);
	}
	return 0;
}

int find(int x){
	if(x == p[x])	return x;
	return p[x] = find(p[x]);
}
