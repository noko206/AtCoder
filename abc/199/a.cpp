#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a*a + b*b < c*c){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}