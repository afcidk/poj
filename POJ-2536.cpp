#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#define MAX 105
using namespace std;

vector<int> edge[MAX];
int visited[MAX];
int rlink[MAX];

int solve(int n);
bool DFS(int cur);
void init(){
    for(int i=0; i<MAX; ++i){
        edge[i].clear();
        rlink[i]=0;
    }
}

int main() {

    int n, m, s, v;
    while(scanf("%d%d%d%d", &n, &m, &s, &v)==4){

        init();
        double x[MAX], y[MAX];
        for(int i=1; i<=n; ++i)  scanf("%lf%lf", &x[i], &y[i]);

        double dis;
        double a, b;
        for(int i=1; i<=m; ++i){

            scanf("%lf%lf", &a, &b);
            for(int j=1; j<=n; ++j){
                dis = sqrt(pow(x[j]-a, 2)+pow(y[j]-b, 2));

                if(dis <= s*v){
                    edge[j].push_back(i);
                }
            }
        }

        printf("%d\n",n-solve(n));
    }
    return 0;
}

int solve(int n){

    int ret=0;

    for(int i=1; i<=n; ++i){

        memset(visited, 0, sizeof(visited));
        if(DFS(i)) ++ret;
    }
    return ret;
}

bool DFS(int cur){

    for(int i=0; i<edge[cur].size(); ++i){

        int nxt = edge[cur][i];
        if(!visited[nxt]){

            visited[nxt] = 1;
            if(!rlink[nxt] || DFS(rlink[nxt])){

                rlink[nxt] = cur;
                return true;
            }
        }
    }
    return false;
}
