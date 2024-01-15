#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
ll gcd(ll x, ll y){ return (x % y) ? gcd(y, x % y) : y; }

int main() {
  int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }
  vector<int> x(n), y(n);
  rep(i,n) cin >> x[i] >> y[i];
  map<tuple<int,int,ll>,int> cnt;
  rep(i,n)rep(j,i) {
    int a = x[i]-x[j], b = y[i]-y[j];
    if (a < 0) {
      a = -a; b = -b;
    }
    if (a == 0) b = 1;
	else if(b == 0) a = 1;
	else {
		int g = gcd(a,b);
      a /= g; b /= g;
    }
    ll c = (ll)a*y[i]-(ll)b*x[i];
    cnt[{a,b,c}]++;
	cout << b << ' ' << a << ' ' << c << endl;
  }
  cout << cnt.size() << endl;
  int ans = 0;
  for (auto p : cnt) {
    if (p.second >= k*(k-1)/2) ++ans;
  }
  cout << ans << endl;
  return 0;
}