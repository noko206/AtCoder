#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main()
{
    int n, q, t, a, b;
    string s;
    bool is_flip = false;
    cin >> n >> s >> q;
    for (int i = 0; i < q; i++){
        cin >> t >> a >> b;
        if(t == 1){
            char tmp;
            a -= 1;
            b -= 1;
            if(is_flip){
                a = (a + n) % (2 * n);
                b = (b + n) % (2 * n);
            }
            tmp = s[a];
            s[a] = s[b];
            s[b] = tmp;
        }
        if(t == 2){
            is_flip = (is_flip + 1) % 2;
        }
    }
    if(is_flip){
        cout << s.substr(n, n) << s.substr(0, n) << endl;
    }
    else{
        cout << s << endl;
    }
}