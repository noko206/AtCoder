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
    vector<pair<int, string>> s(n);
    for (int i = 0; i < n; i++){
        cin >> s[i].second >> s[i].first;
    }
    sort(s.begin(), s.end());
    cout << s[n - 2].second << endl;
}