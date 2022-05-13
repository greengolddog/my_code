#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>

typedef int_fast64_t ll;

#define print(a) for (auto& _ : a) cout << _ << " ";
#define input(a) for (auto& _ : a) cin >> _;
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

//#define int ll

using namespace std;

const ll INF = 4e18, MOD = 1e9 + 7, MOD2 = 998244353, LOG = 30;
const long double EPS = 1e-9, PI = acos(-1);

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
	ll n, m, q;
	cin >> n >> m >> q;
	swap(n, m);
	ll col = 0;
	vector<char> arr(n * m, '.');
	set<ll> s;
	for (ll i = 0; i < m; i++) {
		for (ll j = 0; j < n; j++) {
			cin >> arr[j * m + i];
			col += arr[j * m + i] == '*';
		}
	}
	for (ll i = 0; i < col; i++) {
		s.insert(i);
	}
	for (ll i = 0; i < n * m; i++) {
		if (arr[i] == '*') {
			s.erase(i);
		}
	}
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		swap(a, b);
		a--;
		b--;
		a = a * m + b;
		if (arr[a] == '.') {
			arr[a] = '*';
			if (arr[col] != '*') {
				s.insert(col);
			}
			s.erase(a);
			col++;
		} else {
			arr[a] = '.';
			col--;
			s.erase(col);
			if (a < col) {
				s.insert(a);
			}
		}
		cout << s.size() << '\n';
	}
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}
