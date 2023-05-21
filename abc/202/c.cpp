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
    vector<ll> a(n), b(n), cnt(n + 5, 0);
    ll c;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        cnt[b[c - 1]]++;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += cnt[a[i]];
    }
    cout << ans << endl;
}