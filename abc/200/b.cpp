#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    ll n;
    int k;
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        if(n % 200 == 0){
            n /= 200;
        }
        else{
            n = n * 1000 + 200;
        }
    }
    cout << n << endl;
}