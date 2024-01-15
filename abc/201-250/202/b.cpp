#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++){
        if(s[i] == '6'){
            s[i] = '9';
        }
        else if(s[i] == '9'){
            s[i] = '6';
        }
    }
    cout << s << endl;
}