#include<iostream>
#include<cstdio>
#define INF 0x7fffffff
using namespace std;

struct S{
	int a, b;
	int val;
}edge[6000];

int main() {
	int F;
	scanf("%d", &F);

	while(F--){
		int N, M, W;
		int dots[600];
		for(int i=0; i<600; ++i)	dots[i] = INF;
		scanf("%d%d%d", &N, &M, &W);
		
		int a, b, c;
		M*=2;
		for(int i=0; i<M; i+=2){
			scanf("%d%d%d", &a, &b, &c);
			edge[i].a = a; edge[i].b = b; edge[i].val = c;
			edge[i+1].a = b; edge[i+1].b = a; edge[i+1].val = c;
		}
    	for(int i=0; i<W; ++i){
    		scanf("%d%d%d", &a, &b, &c);
    		edge[i+M].a = a;
    		edge[i+M].b = b;
    		edge[i+M].val = -c;
    	}

		int size = M+W;

		dots[1]=0;
		for(int j=0; j<N-1; ++j){

			for(int i=0; i<size; ++i){
				int na = edge[i].a, nb=edge[i].b, nval=edge[i].val;
				if(dots[na] == INF)	continue;
				else{
					if(dots[na]+nval < dots[nb])	dots[nb] = dots[na]+nval;
				}
			}
		}

		int ok=0;
		for(int i=0; i<size; ++i){
			int na = edge[i].a, nb=edge[i].b, nval=edge[i].val;
			if(dots[na] == INF)	continue;
			else{
				if(dots[na]+nval < dots[nb]){
					ok=1;
					break;
				}
			}
		}
		if(!ok)	printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
