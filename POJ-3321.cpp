#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define MAX 1000000
using namespace std;

struct Node{
	int in, out;
}node[MAX*4];
vector< vector<int> > edge(MAX);
int dfn;
bool visited[MAX];
bool exist[MAX];
int seg[MAX*4];

void dfs(int now);
void build(int l, int r, int nn);
int query(int l, int r, int x, int y, int nn);
void modify(int l, int r, int x, int nn, int exist);
void init(){
	edge.clear();
	memset(node, 0, sizeof(struct Node));
	memset(visited, 0, sizeof(visited));
	dfn=0;
	for(int i=0; i<MAX; ++i)	exist[i] = 1;
}

int main() {

	int n;
	while(scanf("%d", &n)==1){

		int a, b;
		for(int i=0; i<n-1; ++i){
			scanf("%d%d", &a, &b);
			edge[a].push_back(b);
			edge[b].push_back(a);
		}

		dfs(1);
		build(1,n,1);

		int m;
		char ch[5];
		scanf("%d", &m);
		for(int i=0; i<m; ++i){
			scanf("%s%d", ch, &a);
			if(ch[0] == 'Q'){
				int posx=node[a].in, posy=node[a].out;
				printf("%d\n", query(1, n, posx, posy, 1));
			}
			else{
				int pos = node[a].in, ex;
				if(exist[a])	ex=1;
				else ex=-1;
				modify(1, n, pos, 1, ex);
				exist[a] = !exist[a];
			}
		}
	}
	return 0;
}
void dfs(int now){

	node[now].in = ++dfn;
	visited[now]=1;
	for(int i=0; i<edge[now].size(); ++i){

		int cur=edge[now][i];
		if(!visited[cur]){
			dfs(cur);
		}
	}
	node[now].out = dfn;
}

void build(int l, int r, int nn){

	seg[nn] = r-l+1;
	if(l==r)	return ;
	int mid = (l+r)/2;
	build(l, mid, nn*2);
	build(mid+1, r, nn*2+1);
}

int query(int l, int r, int x, int y, int nn){

	if(y<l || x>r)	return 0;
	if(x<=l && r<=y)	return seg[nn];

	int mid = (l+r)/2;
	return query(l, mid, x, y, nn*2) + query(mid+1, r, x, y, nn*2+1);
}

void modify(int l, int r, int x, int nn, int exist){

	if(l==r){
		seg[nn] += exist;
		return;
	}

	int mid = (l+r)/2;
	if(x<=mid)	modify(l, mid, x, nn*2, exist);
	else modify(mid+1, r, x, nn*2+1, exist);
	seg[nn] = seg[nn*2] + seg[nn*2+1];
}
