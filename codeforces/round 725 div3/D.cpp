#include <bits/stdc++.h>
typedef long long ll;
 
using namespace std;
 
ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	if (a == b) {
		return a;
	}
	return gcd(a%b, b%a);
}
 
int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll iii = 0; iii < t; iii++) {
		ll a, b, k;
		cin >> a >> b >> k;
		if (k == 1) {
			cout << ((((a % b == 0) || (b % a == 0)) && (a != b)) ? "YES\n" : "NO\n");
		} else {
			ll cg = 0, ca = 0, cb = 0, g = gcd(a, b);
			a = a/g;
			b = b/g;
			while (a % 2 == 0) {
				ca++;
				a /= 2;
			}
			for (ll i = 3; i*i <= a; i += 2) {
				while (a % i == 0) {
					ca++;
					a /= i;
				}
			}
			while (b % 2 == 0) {
				cb++;
				b /= 2;
			}
			for (ll i = 3; i*i <= b; i += 2) {
				while (b % i == 0) {
					cb++;
					b /= i;
				}
			}
			while (g % 2 == 0) {
				cg++;
				g /= 2;
			}
			for (ll i = 3; i*i <= g; i += 2) {
				while (g % i == 0) {
					cg++;
					g /= i;
				}
			}
			if (a != 1) {
				ca++;
			}
			if (b != 1) {
				cb++;
			}
			if (g != 1) {
				cg++;
			}
			if (ca + cb >= k) {
				cout << "YES\n";
			} else {
				if (ca + cb + cg*2 < k) {
					cout << "NO\n";
				} else {
					if (ca + cb > 1) {
						cout << "YES\n";
					} else {
						if (ca + cb == 1) {
							if (k % 2 == 1) {
								cout << "YES\n";
							} else {
								if (ca + cb + cg*2 == k) {
									cout << "NO\n";
								} else {
									cout << "YES\n";
								}
							}
						} else {
							if (k % 2 == 0) {
								cout << "YES\n";
							} else {
								if (cg*2 == k) {
									cout << "NO\n";
								} else {
									cout << "YES\n";
								}
							}
						}
					}
				}
			}
		}
	}
}
