#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mod = 1000000007, p = 67, p2 = 73;

ll mul(ll a, ll b) {
	return (a*b)%mod;
}

ll add(ll a, ll b) {
	ll ans = a+b;
	if (ans >= mod) {
		ans -= mod;
	}
	if (ans < 0) {
		ans += mod;
	}
	return ans;
}

ll sub(ll a, ll b) {
	ll ans = a-b;
	if (ans >= mod) {
		ans -= mod;
	}
	if (ans < 0) {
		ans += mod;
	}
	return ans;
}

ll vh(vector<ll>& hash, ll l, ll r, vector<ll>& step_p) {
	return sub(hash[r], mul(hash[l], step_p[r - l]));
}

ll vh2(vector<unsigned long long>& hash, ll l, ll r, vector<unsigned long long>& step_p) {
	return hash[r] - hash[l] * step_p[r - l];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	ll n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	string s;
	cin >> s;
	vector<ll> step_p(n + 1, 1), hash(n + 1, 0);
	vector<unsigned long long> step_p2(n + 1, 1), hash2(n + 1, 0);
	for (ll i = 1; i <= n; i++) {
		step_p2[i] = step_p2[i-1]*p2;
		hash2[i] = hash2[i-1]*p2+s[i-1]-'a'+1;
		step_p[i] = mul(step_p[i-1], p);
		hash[i] = add(mul(hash[i-1], p), s[i-1]-'a'+1);
	}
	ll ansl = -1, ansr = -1;
	for (ll i = 0; i < n; i++) {
		ll ph = 0, sh = 0;
		unsigned long long ph2 = 0, sh2 = 0;
		if (i == n/2) {
			ph = vh(hash, 0, i, step_p);
			sh = vh(hash, i+1, n, step_p);
			ph2 = vh2(hash2, 0, i, step_p2);
			sh2 = vh2(hash2, i+1, n, step_p2);
			if ((ph == sh) && (ph2 == sh2)) {
				if (ansl != -1) {
					//cout << "NOT UNIQUE1" << endl;
					//return 0;
					break;
				} else {
					//cout << 1 << endl;
					//return 0;
					ansl = i+1;
					ansr = n;
				}
			}
		}
		if (i < n/2) {
			sh = vh(hash, n/2+1, n, step_p);
			ph = add(mul(vh(hash, 0, i, step_p), step_p[n/2-i]), vh(hash, i+1, n/2+1, step_p));
			sh2 = vh2(hash2, n/2+1, n, step_p2);
			ph2 = vh2(hash2, 0, i, step_p2)*step_p2[n/2-i]+vh2(hash2, i+1, n/2+1, step_p2);
			if ((ph == sh) && (sh2 == ph2)) {
				if (ansl != -1) {
					//cout << "NOT UNIQUE1" << endl;
					//return 0;
					//ansl = n/2+1;
					//ansr = n;
					//cout << "NOT POSSIBLE" << endl;
					//return 0;
					break;
				} else {
					//cout << 1 << endl;
					//return 0;
					ansl = n/2+1;
					ansr = n;
				}
			}
		}
		if (i > n/2) {
			ph = vh(hash, 0, n/2, step_p);
			sh = add(mul(vh(hash, n/2, i, step_p), step_p[n-i-1]), vh(hash, i+1, n, step_p));
			ph2 = vh2(hash2, 0, n/2, step_p2);
			sh2 = vh2(hash2, n/2, i, step_p2) * step_p2[n-i-1] + vh2(hash2, i+1, n, step_p2);
			if ((ph == sh) && (sh2 == ph2)) {
				if (ansl != -1) {
					cout << "NOT UNIQUE" << endl;
					return 0;
				} else {
					//cout << 1 << endl;
					//return 0;
					ansl = 0;
					ansr = n/2;
				}
			}
		}
	}
	if (ansl == -1) {
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	for (ll i = ansl; i < ansr; i++) {
		cout << s[i];
	}
	cout << endl;
}
