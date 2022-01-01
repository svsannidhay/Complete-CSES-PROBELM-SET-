//////////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <math.h>
#include <climits>
#include <set>
#include <cstring>
#include <unordered_map>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iomanip>
#include <cmath>
#include <bitset>
#include <stdlib.h>
#include <chrono>
 
///////////////////////////////////////////////////////////////////////////////////////////////////
#define fio  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll  long long int
#define ull unsigned long long int
#define cinll(x) ll x;cin >> x;
#define cini(x) int x;cin >> x;
#define cins(x) string x;cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) vector<ll> x;x.push_back(0);
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)
///////////////////////////////////////////////////////////////////////////////////////////////////
#define MAX 1e17
#define MIN -9223372036854775800
#define MOD 1000000007
#define f first
#define s second
#define LOG 32
#define MAX_S 100001
const ll maxN = 17;
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;
 
void addEdge(vector<ll> adj[],ll a,ll b) {
    adj[a].pb(b);
    adj[b].pb(a);
    return;
}
 
bool dfs(vector< ll > adj[], vector<bool> &visited, vector<ll> &color,ll current,ll col) {    
        visited[current] = true;
        color[current] = col;
        bool result = true;
        for(auto i : adj[current]) {
            if(!visited[i]) {
                if(dfs(adj,visited,color,i,col ^ 1) == false) return false;
            }
            else {
                if(color[current] == color[i]) return false;
            }
        }
        return result;
}
 
bool bipartite(vector<ll> adj[],vector<ll> &color,ll n) {
    bool isbp = true;
    vector<bool> visited(n+1,false);
    for(ll i = 1; i <= n; i++) {
        if(!visited[i]) { 
            bool res = dfs(adj,visited,color,i,1);
            isbp = (isbp & res);
        }
    }
    return isbp;
}
 
void solve() {
    cinll(n);cinll(m);
    vector< ll > adj[n+1];
    for(ll i=0;i<m;i++) {
        cinll(a);cinll(b);
        addEdge(adj,a,b);
    }
    vector< ll > color(n+1,0);
    if(bipartite(adj,color,n)) {
        for(ll i=0;i<n+1;i++) {
            if(color[i] == 0) color[i] = 2;
        }
        for(ll i = 1;i <= n;i++) {
            cout<<color[i]<<" "; 
        }
    } else {
        cout<<"IMPOSSIBLE";
    }
}
 
int main() {
    fio;
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
// ///////////////////////////////////////////
    solve();
  return 0;
}
