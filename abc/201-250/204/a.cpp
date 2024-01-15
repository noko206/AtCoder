#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int x, y;
    cin >> x >> y;
    if(x == y){
        cout << x;
    }
    else{
        cout << 3 - (x + y) << endl;
    }
}