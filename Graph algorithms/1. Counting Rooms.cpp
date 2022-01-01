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
#define fio                         \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);
#define ll long long int
#define ull unsigned long long int
#define cinll(x) \
  ll x;          \
  cin >> x;
#define cini(x) \
  int x;        \
  cin >> x;
#define cins(x) \
  string x;     \
  cin >> x;
#define vect(x) vector<ll> x
#define vect1(x) \
  vector<ll> x;  \
  x.push_back(0);
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

ll arr[1001][1001];
ll visited[1001][1001];

void dfs(ll currx, ll curry, ll n, ll m)
{
  visited[currx][curry] = 1;
  if (currx + 1 <= n && arr[currx + 1][curry] == 1)
  {
    if (visited[currx + 1][curry] == 0)
      dfs(currx + 1, curry, n, m);
  }
  if (currx - 1 >= 1 && arr[currx - 1][curry] == 1)
  {
    if (visited[currx - 1][curry] == 0)
      dfs(currx - 1, curry, n, m);
  }
  if (curry + 1 <= m && arr[currx][curry + 1] == 1)
  {
    if (visited[currx][curry + 1] == 0)
      dfs(currx, curry + 1, n, m);
  }
  if (curry - 1 >= 1 && arr[currx][curry - 1] == 1)
  {
    if (visited[currx][curry - 1] == 0)
      dfs(currx, curry - 1, n, m);
  }
}

void solve()
{
  cinll(n);
  cinll(m);
  memset(arr, 0, sizeof(arr));
  for (ll i = 0; i < n; i++)
  {
    cins(s);
    for (ll j = 0; j < s.length(); j++)
    {
      if (s[j] == '.')
      {
        arr[i + 1][j + 1] = 1;
      }
    }
  }

  ll ans = 0;
  memset(visited, 0, sizeof(visited));
  for (ll i = 1; i <= n; i++)
  {
    for (ll j = 1; j <= m; j++)
    {
      if (visited[i][j] == 0 && arr[i][j] == 1)
      {
        ans++;
        dfs(i, j, n, m);
      }
    }
  }
  cout << ans;
}

int main()
{
  fio;
  ///////////////////////////////////////////
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  // ///////////////////////////////////////////
  solve();
  return 0;
}
