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
    vector<int> a(n), b(200, 0);  // b[i]==2になったら終了
    vector<vector<int>> c(200);   // indexを管理
    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] %= 200;
        b[a[i]]++;
        if(b[a[i]] == 2){
            cout << "Yes" << endl;
            cout << "1 " << i + 1 << endl;
            cout << "1 " << c[a[i]][0] + 1 << endl;
            return 0;
        }
        else{
            c[a[i]].push_back(i);
        }
    }
    for (int bit = 0; bit < (1 << n); ++bit)
    {
        vector<int> S;
        for (int i = 0; i < n; ++i)
        {
            if (bit & (1 << i))
            {
                S.push_back(i);
            }
        }
        if((int)S.size() == 0 || (int)S.size() == 1){
            continue;
        }
        int tmp = 0;
        for (int i = 0; i < (int)S.size(); ++i)
        {
            tmp = (tmp + a[S[i]]) % 200;
        }
        b[tmp]++;
        if(b[tmp] == 2){
            // Yesのとき
            cout << "Yes" << endl;
            cout << (int)S.size() << " ";
            for (int i = 0; i < (int)S.size(); ++i){
                cout << S[i] + 1 << " ";
            }
            cout << endl;
            cout << (int)c[tmp].size() << " ";
            for (int i = 0; i < (int)c[tmp].size(); ++i)
            {
                cout << c[tmp][i] + 1 << " ";
            }
            cout << endl;
            return 0;
        }
        else{
            for (int i = 0; i < (int)S.size(); ++i)
            {
                c[tmp].push_back(S[i]);
            }
        }
    }
    // Noのとき
    cout << "No" << endl;
}