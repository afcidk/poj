#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#define MAX 2000
using namespace std;

struct S{
    int h;
    char gend;
    string mus;
    string spo;
}peo[MAX];

int llink[MAX], rlink[MAX];
int visited[MAX];
vector<int> edge[MAX];

int solve(int nL);
bool DFS(int now);
void init(){
    memset(llink, 0, sizeof(llink));
    memset(rlink, 0, sizeof(rlink));
    for(int i=0; i<MAX; ++i)   edge[i].clear();
}

int main() {

    int n;
    scanf("%d", &n);
    while(n--){
        init();

        int x;
        scanf("%d", &x);
        //real: x people
        // see: x*x people
        for(int i=1; i<=x; ++i){
            cin>>peo[i].h>>peo[i].gend>>peo[i].mus>>peo[i].spo;

            for(int j=i-1; j>=1; --j){

                int ma=max(peo[i].h,peo[j].h);
                int mi=min(peo[i].h,peo[j].h);
                if(!(ma-mi>40 || peo[i].gend == peo[j].gend || peo[i].mus!=peo[j].mus || peo[i].spo==peo[j].spo)){
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }

        x*=2;
        printf("%d\n",(x-solve(x))/2);
    }
    return 0;
}

int solve(int nL){

    int ret=0;
    for(int i=1; i<=nL; ++i){

        memset(visited, 0, sizeof(visited));
        if(DFS(i)) ++ret;
    }
    return ret;
}

bool DFS(int now){

    for(int i=0; i<edge[now].size(); ++i){

        int nxt = edge[now][i];
        if(!visited[nxt]){

            visited[nxt]=1;
            if(!rlink[nxt] || DFS(rlink[nxt])){

                rlink[nxt] = now;
                llink[now] = nxt;
                return true;
            }
        }
    }
    return false;
}
