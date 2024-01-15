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
    int cnt = 0;
    for (int i = 0; i < 10000; i++){
        vector<int> is(10, false);
        is[i % 10] = true;
        is[(i / 10) % 10] = true;
        is[(i / 100) % 10] = true;
        is[i / 1000] = true;
        bool is_ok = true;
        for (int j = 0; j < 10; j++){
            if (s[j] == 'o')
            {
                if(!is[j]){
                    is_ok = false;
                    break;
                }
            }
            else if (s[j] == 'x')
            {
                if(is[j]){
                    is_ok = false;
                    break;
                }
            }
        }
        if(is_ok){
            cnt++;
        }
    }
    cout << cnt << endl;
}