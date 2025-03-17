#include <cstdio>
#include <algorithm>

using namespace std;

struct N{
    int x,f,t,c;
    bool operator<(const N&a)const{
        if(x != a.x) return x<a.x;
        return c<a.c;
    }
}d[61];
int n,i,j,t[20001],v,s;
double x,y,z,q;

int main() {
    scanf("%d",&n);
    n *=2;
    for(i=1;i<=n;i+=2)
    {
        scanf("%lf%lf%lf%lf",&x,&y,&z,&q);
        x += 0.001; y+= 0.001; z+= 0.001; q+= 0.001;
        d[i].x=x*10;
        d[i+1].x=(x+z)*10;
        d[i].f=d[i+1].f=y*10;
        d[i].t=d[i+1].t=(y+q)*10;
        d[i].c=1;d[i+1].c=-1;
    }
    
    sort(d+1,d+n+1);
    
    for(i=1;i<=n;i++)
    {
        for(v=j=0;j<20001;j++)
            v+= !!t[j];
            
        s += (d[i].x-d[i-1].x)*v;
        for(j=d[i].f;j<d[i].t;j++)
            t[j] += d[i].c;
    }
    
    printf("%d",s/100);
    if(s%100)
        printf(".%02d",s%100);
    return 0;
}
