#include "bits/stdc++.h"
using namespace std;
typedef pair<int,int> pii;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(a)  (a).begin(),(a).end()
#define pb push_back
#define MAX_V 100000

vector<int> G[MAX_V];
vector<int> depth,vs;
int id[MAX_V]={};

template<class T>
class segtree{
private:
    vector<T> dat;
    int _size;
    T _init;
    
public:
    segtree(int __size=0 , T init=numeric_limits<T>::max() ):_size(__size) , _init(init) , dat(4*__size,init){
        if(__size==0)return ;
        int x=1;
        while(x<_size)x*=2;
        _size = x;
    }
    
    int size(){
        return _size;
    }
    
    void update(int m,T x){
        int i = m+_size;
        dat[i] = x;
        while(i!=1){
            dat[i/2] = min(dat[i],dat[i^1]);
            i/=2;
        }
    }
    
    // call find(s,t)
    T find(int s,int t,int num=1,int a=0,int b=-1){
        if(b==-1)b=_size-1; //I couldn't "int b=_size".
        if(b<s||t<a)return _init;
        if(s<=a&&b<=t)return dat[num];
        return min( find(s,t,num*2,a,(a+b)/2) , find(s,t,num*2+1,(a+b)/2+1,b) );
    }
};


void dfs(int d,int num){
    depth.pb(d);
    vs.pb(num);
    rep(i,G[num].size()){
        dfs(d+1,G[num][i]);
        depth.pb(d);
        vs.pb(num);
    }
    return ;
}


void init(){
    dfs(1,0);
    rep(i,vs.size()){
        if(id[ vs[i] ]==0)id[ vs[i] ]=i;
    }
}


int main(){
    int n;
    cin>>n;
    rep(i,n){
        int k;
        cin>>k;
        rep(j,k){
            int a;
            cin>>a;
            G[i].pb(a);
        }
    }
    
    init();
    segtree<pii> st(depth.size(),pii((1<<31)-1,(1<<31)-1));
    rep(i,depth.size()){
        st.update(i,pii(depth[i],vs[i]));
    }
    int q;
    cin>>q;
    rep(i,q){
        int a,b;
        cin>>a>>b;
        cout<<st.find(min(id[a],id[b]),max(id[a],id[b])).second<<endl;
    }
}