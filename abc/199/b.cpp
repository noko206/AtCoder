#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int n;
    int a = 1;
    int b = 1000;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        a = max(a, tmp);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        b = min(b, tmp);
    }
    if(a > b){
        cout << 0 << endl;
    }
    else{
        cout << b - a + 1 << endl;
    }
}