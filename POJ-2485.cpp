#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 505
using namespace std;

struct S{
	int x, y, dis;
	bool operator< (const struct S &t) const{
		return dis<t.dis;
	}
}road[MAX*MAX];
int road_num;
int p[MAX];

int find(int x);
void init(){
	road_num=0;
	for(int i=0; i<MAX; ++i){
		p[i]=i;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	while(n--){
		init();

		int m;
		scanf("%d", &m);
		int a, b;
		for(int i=0; i<m; ++i){
			for(int j=0; j<m; ++j){
				scanf("%d", &a);

				road[road_num].x = i;
				road[road_num].y = j;
				road[road_num].dis = a;
				++road_num;
			}
		}

		sort(road, road+road_num);

		int max_len=-1;
		for(int i=0; i<road_num; ++i){

			int xx = find(road[i].x);
			int yy = find(road[i].y);
			if(xx!=yy){
				p[xx]=yy;
				max_len = max(max_len, road[i].dis);
			}
		}

		printf("%d\n", max_len);
	}
}

int find(int x){
	if(x == p[x])	return x;
	return p[x] = find(p[x]);
}

