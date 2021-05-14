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


void solvebf(vector<ll> &arr,ll currsum,ll sum,ll ind,ll &ans) {

    if(ind == arr.size()) {
        ans = min(ans,abs(currsum - (sum - currsum)));
        return;
    }

    solvebf(arr,currsum + arr[ind],sum,ind + 1,ans);
    solvebf(arr,currsum,sum,ind + 1,ans);

    return;

}

char arr[9][9];
 
void solvebf(ll ind,ll &ans) {
    if(ind == 9) {
        ans++;
        return;
    }
    for(ll i = 1;i <= 8; i++) {
        if(arr[ind][i] != '*') {

            bool checkCol = true;
            bool checkLdig = true;
            bool checkRdig = true;
            for(ll row = ind - 1;row >= 1;row--) {
                if(arr[row][i] == 'q') checkCol = false;
            } 

            ll row = ind - 1;
            ll col = i - 1;
            while(row >= 1 && col >= 1) {
              if(arr[row][col] == 'q') checkLdig = false;  
              row--;
              col--;
            }

            row = ind - 1;
            col = i + 1;

            while(row >= 1 && col <= 8) {
              if(arr[row][col] == 'q') checkRdig = false;  
              row--;
              col++;
            }

            if(checkCol && checkLdig && checkRdig) {
                arr[ind][i] = 'q';
                solvebf(ind + 1,ans);
                arr[ind][i] = '.';
            }

        }
    }
} 

void solve() {
    for(ll i = 1;i <= 8;i++) {
        for(ll j = 1;j <= 8;j++) {
            char ch;
            cin>>ch;
            arr[i][j] = ch;
            // cout<<arr[i][j];
        }
        // cout<<"\n";
    }
    ll ans = 0;
    solvebf(1,ans);
    cout<<ans<<"\n";
    return;
}    
 
 
int main(){
    // fio;
    // cinll(t);
///////////////////////////////////////////    
    #ifndef ONLINE_JUDGE
    freopen("input.txt" , "r", stdin);
    freopen("output.txt", "w" , stdout);
    #endif
///////////////////////////////////////////
    // cinll(t);
    // for(ll i=1;i<=t;i++) {
        solve();
    // }
  return 0;
}