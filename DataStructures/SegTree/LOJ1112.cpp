#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[(MX*4)];

void build(int node, int start, int end){
    if(start == end){
        sum[node] = a[end];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int query(int node, int start, int end, int i, int j){
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return p+q;
}

void update0(int node, int start, int end, int x){
    if(start>x || end<x)return;
    if(start == end){
        sum[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    update0(node*2, start, mid, x);
    update0((node*2)+1, mid+1, end, x);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

void updateX(int node, int start, int end, int x, int val){
    if(start>x || end<x)return;
    if(start == end){
        sum[node] += val;
        return;
    }
    int mid = (start + end) / 2;
    updateX(node*2, start, mid, x, val);
    updateX((node*2)+1, mid+1, end, x, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);

    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",ii);
        for(int i=1;i<=q;i++){
            int x, l, r, ans;
            scanf("%d", &x);
            if(x == 1){
                scanf("%d", &x);x++;
                ans = query(1,1,n,x,x);
                printf("%d\n",ans);
                update0(1,1,n,x);
            }
            else if(x == 2){
                scanf("%d%d", &x, &r);x++;
                updateX(1,1,n,x,r);
            }
            else{
                scanf("%d%d", &l, &r);l++;r++;
                ans = query(1,1,n,l,r);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
