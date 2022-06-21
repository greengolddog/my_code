#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF64 = 9'000'000'000'000'000'000, INF32 = 2'000'000'000, MOD = 1'000'000'007;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

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

template<typename T>
T square(T a) {
	return a * a;
}

template<>
struct std::hash<pair<ll, ll>> {
	ll operator() (pair<ll, ll> p) {
		return ((__int128)p.first * MOD + p.second) % INF64;
	}
};

struct point {
	ll x, y;
	point(ll x = 0, ll y = 0): x(x), y(y) {}
	point operator- (point p) {
		return point(x - p.x, y - p.y);
	}
	point operator+ (point p) {
		return point(x + p.x, y + p.y);
	}
};

struct vct {
	point p;
	vct(point s = point(), point f = point()) {
		p = s - f;
	}
	ll operator^ (vct v) {
		return p.x * v.p.y - p.y * v.p.x;
	}
};

bool check(point p1, point p2, point p3) {
	return ((vct(p2, p1) ^ vct(p3, p1)) <= 0);
}

void solve() {
	ll n;
	cin >> n;
	vector<point> arr(n);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}
	ll t;
	cin >> t;
	for (ll j = 0; j < t; j++) {
		point p;
		cin >> p.x >> p.y;
		bool b = true;
		point last = arr.back();
		for (ll i = 0; i < n; i++) {
			if (!check(last, arr[i], p)) {
				b = false;
				break;
			}
			last = arr[i];
		}
		if (!b) {
			cout << 0 << '\n';
			continue;
		}
		vector<ll> ans(n);
		ll u = 1;
		for (ll i = 0; i < n; i++) {
			while (check(arr[i], arr[u], p)) {
				u++;
				u %= n;
			}
			ans[i] = u;
		}
		u = 1;
		ll na = ans[0] - 1, col = 1;
		ll a = 0;
		for (ll i = 0; i < n; i++) {
			if (ans[i] > i) {
				na -= ans[i] - i - 1;
			} else {
				na -= (ans[i] + n) - i - 1;
			}
			col--;
			while (u != ans[i]) {
				col++;
				if (ans[u] > u) {
					na += ans[u] - u - 1;
				} else {
					na += (ans[u] + n) - u - 1;
				}
				u++;
				u %= n;
			}
			a += na - col * (col - 1) / 2;
		}
		cout << a / 3 << '\n';
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}
