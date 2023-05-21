#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    vector<int> a(3);
    for (int i = 0; i < 3; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    if(a[2] - a[1] == a[1] - a[0]){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}