#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 200005
#define INF 0x7fffffff
using namespace std;

struct Node{

	int ma, mi;
	Node *l, *r;

	void update(int x){
		ma = x;
		mi = x;
	}

	void pull(){
		ma = max(l->ma, r->ma);
		mi = min(l->mi, r->mi);
	}
};
int num[MAX];

Node* build(int L, int R){

	Node *now = new Node();
	if(L==R){
		now->update(num[L]);
		return now;
	}

	int mid = (L+R)>>1;

	now->l = build(L, mid);
	now->r = build(mid+1, R);

	now->pull();
	return now;
}
int findMax(Node *n, int L, int R, int x, int y);
int findMin(Node *n, int L, int R, int x, int y);

int main() {
	int n, m;
	while(scanf("%d%d", &n, &m)==2){
		
		int i;
		for(i=0; i<n; ++i){
			scanf("%d", &num[i]);
		}
			
		Node *node = build(0, n-1);

		int a, b;
		for(i=0; i<m; ++i){

			scanf("%d%d", &a, &b);
			printf("%d\n", findMax(node, 0, n-1, a-1, b-1)-findMin(node, 0, n-1, a-1, b-1));
		}
	}
	return 0;
}

int findMax(Node *now, int L, int R, int x, int y){

	if(x>R || y<L)	return -INF;
	if(x<=L && y>=R)	return now->ma;

	int mid = (L+R)>>1;
	return max(findMax(now->l, L, mid, x, y), findMax(now->r, mid+1, R, x, y));
}
int findMin(Node *now, int L, int R, int x, int y){

	if(x>R || y<L)	return INF;
	if(x<=L && y>=R)	return now->mi;

	int mid = (L+R)>>1;
	return min(findMin(now->l, L, mid, x, y), findMin(now->r, mid+1, R, x, y));
}
