#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (auto &x : a)
    {
        cin >> x;
    }
    for (auto &x : b)
    {
        cin >> x;
    }
    for (auto &x : c)
    {
        cin >> x;
    }
    sort(a.begin(), a.end());
    sort(c.begin(), c.end());
    ll ans = 0;
    for(int x : b){
        // xが条件に含まれない
        ll a_cnt = lower_bound(a.begin(), a.end(), x) - a.begin();
        // xが条件に含まれる
        ll c_cnt = n - (upper_bound(c.begin(), c.end(), x) - c.begin());
        ans += a_cnt * c_cnt;
    }
    cout << ans << endl;
}