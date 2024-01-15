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
    vector<ll> a(200, 0);
    int tmp;
    for (int i = 0; i < n; i++){
        cin >> tmp;
        a[tmp % 200]++;
    }
    ll cnt = 0;
    for (int i = 0; i < 200; i++){
        cnt += a[i] * (a[i] - 1) / 2;
    }
    cout << cnt << endl;
}