#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll mul(ll a, ll b, ll m) {
	return a*b%m;
}

ll mul(ll a, ll b) {
	return a*b;
}

ll add(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	if (a+b < 0) return a+b+m;
	return a+b;
}

ll add(ll a, ll b) {
	return a+b;
}

ll sub(ll a, ll b, ll m) {
	if (a-b >= m) return a-b-m;
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sub(ll a, ll b) {
	return a-b;
}

struct HashString {
	string s;
	ll mod = 1000000009, p = 57;
	vector<ll> hash, power;
	HashString(string& s): s(s) {
		hash.resize(s.size()+1, 0);
		power.resize(s.size()+1, 1);
		for (ll i = 1; i <= s.size(); i++) {
			power[i] = mul(power[i-1], p, mod);
			hash[i] = add(mul(hash[i-1], p, mod), (s[i-1]-'a'+1), mod);
		}
	}
	HashString(string& s, ll p, ll mod): s(s), p(p), mod(mod) {
		hash.resize(s.size()+1, 0);
		power.resize(s.size()+1, 1);
		for (ll i = 1; i <= s.size(); i++) {
			power[i] = mul(power[i-1], p, mod);
			hash[i] = add(mul(hash[i-1], p, mod), (s[i-1]-'a'+1), mod);
		}
	}
	HashString(istream& input) {
		input >> s;
		hash.resize(s.size()+1, 0);
		power.resize(s.size()+1, 1);
		for (ll i = 1; i <= s.size(); i++) {
			power[i] = mul(power[i-1], p, mod);
			hash[i] = add(mul(hash[i-1], p, mod), (s[i-1]-'a'+1), mod);
		}
	}
	HashString(istream& input, ll p, ll mod): p(p), mod(mod) {
		input >> s;
		hash.resize(s.size()+1, 0);
		power.resize(s.size()+1, 1);
		for (ll i = 1; i <= s.size(); i++) {
			power[i] = mul(power[i-1], p, mod);
			hash[i] = add(mul(hash[i-1], p, mod), (s[i-1]-'a'+1), mod);
		}
	}
	ll get(ll l, ll r) {
		return sub(hash[r], mul(hash[l], power[r-l], mod), mod);
	}
	ll all() {
		return hash[s.size()];
	}
	ll size() {
		return s.size();
	}
	bool match(ll l1, ll r1, ll l2, ll r2) {
		return get(l1, r1) == get(l2, r2);
	}
	char operator[] (ll x) {
		return s[x];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	HashString s1(s), s2(s, 1000000007, 61);
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		a--;
		c--;
		cout << ((s1.match(a, b, c, d) && s2.match(a, b, c, d)) ? "Yes" : "No") << '\n';
	}
}
