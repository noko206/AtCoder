#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    double r, x, y;
    cin >> r >> x >> y;
    double d = sqrt(x * x + y * y);
    if(d < r){
        cout << 2 << endl;
    }
    else{
        cout << ceil(d / r) << endl;
    }
}