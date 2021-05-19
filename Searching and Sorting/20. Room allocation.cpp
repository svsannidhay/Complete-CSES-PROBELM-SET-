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
    if (a.f == b.f) {
        return a.s < b.s; 
    } 
    return a.f < b.f;
}


void solve() {
    cinll(n);
    set< pair<ll,pair<ll,ll>> > arr;
    map<ll,ll> allotment;
    stack<ll> pool;
    ll room_no = 0;
    for(ll i = 0;i < n; i++) {
        cinll(a);cinll(b);
        arr.insert(mp(a,mp(-1,i)));
        arr.insert(mp(b,mp(1,i)));
    }

    for(auto it = arr.begin(); it != arr.end(); it++) {
        if((*it).s.f == -1) {
            if(pool.empty()) {
                room_no++;
                pool.push(room_no);
            }
            allotment[(*it).s.s] = pool.top();
            pool.pop(); 
        } else {
            pool.push(allotment[(*it).s.s]);
        }
    }
    cout<<room_no<<"\n";
    for(ll i = 0;i < n; i++) {
        cout<<allotment[i]<<" ";
    }
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
