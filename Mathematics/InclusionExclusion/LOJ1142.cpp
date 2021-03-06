#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mod 100000007
#include <bits/stdc++.h>
using namespace std;
ll a[100],n,sum,x,y;
ll fact[1000006];


//--- mod inverse(iterative extended euclid)---

ll modInverse(ll a, ll m){
  ll m0 = m;
  ll y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1){
    ll q, t;
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}

//----- mod inverse end----


//------nCr----------
ll nCr(ll n, ll k){
  if(k>n)return 0;
  if(k==n)return 1;
  ll ret;
  ret = ( (fact[n])%mod * (modInverse(fact[n-k],mod))%mod )%mod;
  ret = ( ret%mod * (modInverse(fact[k],mod)) %mod) % mod;
  return ret;
}

//----------nCr end--------



//----------Factorial----------
void factorials(){
  fact[0] = 1;
  for(int i=1;i<=1000001;i++){
    fact[i] = (((fact[i-1])%mod)*((i)%mod))%mod;
  }
}
//-------Factorial End----------

int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  factorials();
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(a,0,sizeof(a));
    scanf("%lld%lld",&n,&sum);
    for(int i=1;i<=n;i++){
      scanf("%lld%lld",&x,&y);
      sum-=x;
      a[i] = y-x;
    }
    //cout<<"OK"<<endl;
    if(sum<0){
      printf("Case %d: %lld\n",ii,0);
      continue;
    }
    ll ans,pns,tem;
    ans = nCr(sum+n-1,n-1);
    pns = 0;
    for(int i=1;i<(1<<n);i++){
      ll cnt , res;
      cnt  = res = 0;
      for(int j=0;j<n;j++){
        if(i&(1<<j)){
          cnt++;
          res += a[j+1]+1;
        }
      }
      if(res>sum)continue;
      tem = nCr(sum-res+n-1,n-1);
      //cout<<cnt<<" ++ "<<res<<"++"<<tem<<endl;
      if(cnt&1)pns = ( (pns%mod) + (nCr(sum-res+n-1,n-1)%mod))%mod;
      else pns = (( (pns%mod) - (nCr(sum-res+n-1,n-1)%mod))+mod)%mod;
    }
    //cout<<ans<<" ++ "<<pns<<endl;
    ans =  (( (ans%mod) - (pns%mod))+mod)%mod;
    printf("Case %d: %lld\n",ii,ans);
  }

  return 0;
}
