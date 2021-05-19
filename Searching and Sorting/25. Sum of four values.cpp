///////////////////////////////////////////////////////////////////////////////////////////////////
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
#define ll  int
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
///////////////////////////////////////////////////////////////////////////////////////////////////
using namespace std;
using u64 = uint64_t;
//Safe_hashing for minimising collisions 
//https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
// struct custom_compare {
//     bool operator ()(pair<ll,ll> a,pair<ll,ll> b) {
//         return (a.s - a.f) > (b.s- b.f);
//     }
// };
 
bool compare(pair<ll,ll> a, pair<ll,ll> b) {
    return a.f < b.f;
}
 
void solve() {
    cinll(n);cinll(x);
    map<ll, vector< pair<ll,ll> > > mapit;
    vector<ll> arr;
    for(ll i=0;i<n;i++) {
        cinll(x);
        arr.pb(x);
    }
    
    for(ll i = 0;i < n;i++) {
        for(ll j = i + 1; j < n;j++) {
            mapit[arr[i]+arr[j]].pb(mp(i,j));
        }
    }

     for(ll i = 0;i < n;i++) {
        for(ll j = i + 1; j < n;j++) {
            ll target = x - (arr[i] + arr[j]);
            if(mapit[target].size() > 0) {
                for(ll k = 0;k < mapit[target].size(); k++) {
                    if( (mapit[target][k].f != i && mapit[target][k].f != j) &&
                         (mapit[target][k].s != i && mapit[target][k].s != j) ) {
                        cout<<i+1<<" "<<j+1<<" "<<mapit[target][k].f + 1<<" "<<mapit[target][k].s + 1<<" ";
                        return;
                    }
                }
            }
        }
    }


    cout<<"IMPOSSIBLE ";
    return;
}
 
int main(){
    fio;
    // cinll(t);
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
// ///////////////////////////////////////////
    // cinll(t);
    // for(ll i=1;i<=t;i++) {
        solve();
    // }
  return 0;
}
