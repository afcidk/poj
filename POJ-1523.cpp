#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 1005
using namespace std;

vector<int> road[MAX];
vector<int> record;
int dfn[MAX], low[MAX], clc;

void dfs(int cur, int parent);
void init(){
    clc=0;
    record.clear();
    for(int i=0; i<MAX; ++i){
        dfn[i]=low[i]=0;
        road[i].clear();
    }
}

int main()
{
    int a, b, exit=0;
    int cc=0;
    init();
    while(scanf("%d", &a)==1){
        if(exit==1 && a==0) break;
        if(a==0){

            exit=1;
            for(int i=0; i<MAX; ++i){
                if(!dfn[i]) {
                    dfs(i, -1);
                }
            }

            printf("Network #%d\n", ++cc);
            if(record.size()==0){
                puts("  No SPF nodes");
            }
            else {

                sort(record.begin(), record.end());
                for(int i=0; i<record.size(); ++i){

                    int now=record[i];
                    int rec[MAX]={0}, subs=0;
                    for(int j=0; j<road[now].size(); ++j){

                        int l = low[road[now][j]];
                        if(!rec[l]){
                            rec[l]=1;
                            ++subs;
                        }
                    }
                    printf("  SPF node %d leaves %d subnets\n", now, subs);
                }
            }
            puts("");

            init();
            continue;
        }
        scanf("%d", &b);
        exit=0;

        road[a].push_back(b);
        road[b].push_back(a);
    }
    return 0;
}

void dfs(int cur, int parent){

    int child=0;
    int flag=0;
    dfn[cur]=low[cur]=++clc;

    for(int i=0; i<road[cur].size(); ++i){

        int nxt = road[cur][i];
        if(!dfn[nxt]){

            ++child;
            dfs(nxt, cur);

            low[cur] = min(low[cur], low[nxt]);
            if(low[nxt]>=dfn[cur])  flag=1;
        }
        else if(nxt != parent){
            low[cur] = min(low[cur], dfn[nxt]);
        }
    }

    if((child>=2 && parent==-1) || (flag==1 && parent!=-1)){
        record.push_back(cur);
    }
}

