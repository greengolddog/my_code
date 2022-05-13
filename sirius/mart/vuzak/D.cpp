#include<bits/stdc++.h>
typedef long long ll;
#define double long double

using namespace std;

mt19937 rnd(time(0));

struct vct {
	double x, y;
	vct(double x = 0, double y = 0): x(x), y(y) {}
	double operator* (vct v) {
		return x * v.x + y * v.y;
	}
	double operator% (vct v) {
		return x * v.y - y * v.x;
	}
	bool operator<= (vct v) {
		return *this % v <= 0;
	}
	bool operator< (vct v) {
		return *this % v < 0;
	}
};

struct point {
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
	vct operator- (point p) {
		return vct(x - p.x, y - p.y);
	}
};

struct polygon {
	vector<point> arr;
	polygon(vector<point> arr): arr(arr) {}
	bool point_in(point p) {
		if ((arr[1] - arr[0]) < (p - arr[0]) || (p - arr[0]) < (arr.back() - arr[0])) {
			return false;
		}
		ll l = 1, r = arr.size() - 1;
		while (r - l > 1) {
			ll mid = (l + r) / 2;
			if ((arr[mid] - arr[0]) <= (p - arr[0])) {
				r = mid;
			} else {
				l = mid;
			}
		}
		return (p - arr[l]) <= (arr[r] - arr[l]);
	}
};

ll gcd(ll a, ll b) {
	return (min(a, b) == 0 ? max(a, b) : gcd(max(a, b) % min(a, b), min(a, b)));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, mx = 0, my = 0;
	cin >> n;
	vector<point> arr(n);
	polygon poly(arr);
	for (auto& i : poly.arr) {
		cin >> i.x >> i.y;
		if (i.x > mx) {
			mx = i.x;
		}
		if (i.y > my) {
			my = i.y;
		}
	}
	ll ans = 0;
	for (ll i = 1; i <= mx; i++) {
		bool b = false;
		for (ll j = 1; j <= my; j++) {
			if (gcd(i, j) == 1) {
				if (poly.point_in(point(i, j))) {
					ans++;
					b = true;
				} else {
					if (b) {
						break;
					}
				}
			}
		}
	}
	cout << ans;
}
