#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <string>
#include <cmath>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <fstream>
#include <cassert>
#include <random>
#include <cstring>
#include <climits>
#include <time.h>
#include <chrono>
#include <fstream>

typedef int_fast64_t ll;
typedef unsigned long long ull;
typedef long double ld;

#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define mset multiset
#define umset unordered_multiset
#define vll __int128

//#define x first
//#define y second

//#define int int_fast64_t
//#define DEBUG

std::mt19937 rnd(time(0));
using namespace std;

const ll INF = 4e18, MOD = 1e9 + 7, MOD2 = 998244353, LOG = 30;
const ld EPS = 1e-9, PI = acos(-1);

template<typename T>
bool assign_max(T& a, T b) {
  if (b > a) {
    a = b;
    return true;
  }
  return false;
}
 
template<typename T>
bool assign_min(T& a, T b) {
  if (b < a) {
    a = b;
    return true;
  }
  return false;
}

void solve() {
	map<string, ll> col;
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		col[s]++;
	}
	ll ans = 0;
	for (char c = 'a'; c <= 'k'; c++) {
		for (char c2 = 'a'; c2 <= 'k'; c2++) {
			for (char c3 = 'a'; c3 <= 'k'; c3++) {
				string s;
				s.push_back(c);
				s.push_back(c2);
				string s2 = s;
				if (c != c3) {
					s2[0] = c3;
					ans += col[s] * col[s2];
					s2[0] = c;
				}
				if (c2 != c3) {
					s2[1] = c3;
					ans += col[s] * col[s2];
				}
			}
		}
	}
	cout << ans / 2 << '\n';
}

signed main() {
 ios_base::sync_with_stdio(0);
 cin.tie(0);

 int t = 1;
 cin >> t;
 while (t--)
  solve();
 return 0;
}
