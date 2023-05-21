#include <bits/stdc++.h>
using namespace std;
#define INF (long long)2e+18
int main() {
	long long n,m,x,ans=INF;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		x=(m+i-1)/i;
		if(x<=n)ans=min(ans,i*x);
		if(i>x)break;
	}
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0;
}