#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__int128 power(__int128 a, __int128 p, __int128 m = (ll)1e18) {
	if (p == 0) {
		return 1%m;
	}
	if (p % 2 == 0) {
		__int128 ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(min(a, b), max(a, b)%min(a, b));
}

ll gcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll d = gcd(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

ll sub(ll a, ll b, ll m) {
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sum(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	return a+b;
}

__int128 fi(__int128 a) {
	__int128 ans = a;
	for (__int128 i = 2; i*i <= a; i++) {
		if (a % i == 0) {
			while (a % i == 0) {
				a /= i;
			}
			ans -= ans/i;
		}
	}
	if (a > 1) {
		ans -= ans/a;
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll a, b, c, m;
	cin >> a >> b >> c >> m;
	cout << (ll)power(a, power(b, c, fi(m)), m);
}
