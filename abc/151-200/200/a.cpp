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
    if(n % 100 == 0){
        cout << n / 100 << endl;
    }
    else{
        cout << (n / 100) + 1 << endl;
    }
}