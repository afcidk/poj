#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX 1005
using namespace std;

struct Dot{

    int x, y;
    bool operator< (const struct Dot &t) const{
        if(y==t.y)  return x>t.x;
        return y>t.y;
    }
}dot[MAX*MAX];

int v[MAX*MAX];

int lowbit(int x){  return x&(-x);}
long long getSum(int x);
void modify(int index);

void init(){
    for(int i=0; i<MAX*MAX; ++i)    dot[i].x=dot[i].y=v[i]=0;
}

int main() {

    int T, cc=0;
    scanf("%d", &T);
    while(T--){

        init();
        int a, b, q;
        scanf("%d%d%d", &a, &b, &q);
        for(int i=1; i<=q; ++i){
            scanf("%d%d", &dot[i].x, &dot[i].y);
        }
        dot[0].x=0x7fffffff; dot[0].y=0x7fffffff;

        sort(dot, dot+q+1);

        long long ans=0;

        for(int i=1; i<=q; ++i){
            modify(dot[i].x);
            ans += getSum(dot[i].x-1);
        }
        printf("Test case %d: %I64d\n", ++cc, ans);
    }
    return 0;
}

void modify(int index){

    for(int i=index; i<MAX*MAX; i+=lowbit(i)){
        ++v[i];
    }
}

long long getSum(int index){

    int ret=0;
    while(index){
        ret += v[index];
        index -= lowbit(index);
    }
    return ret;
}
