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
	HashString(istream& input) {
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
	char operator[] (ll x) {
		return s[x];
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll p = 57, mod = 1000000007, p2 = 61, mod2 = 1000000009;
	vector<ll> tree(1, 0), tree2(1, 0);
	set<pair<ll, ll>> s;
	ll m;
	cin >> m;
	for (ll i = 0; i < m; i++) {
		ll v;
		cin >> v;
		v--;
		char c;
		cin >> c;
		tree.push_back((tree[v]*p%mod+(c-'a'+1))%mod);
		tree2.push_back((tree2[v]*p2%mod2+(c-'a'+1))%mod2);
		s.insert({tree.back(), tree2.back()});
		cout << s.size() << '\n';
	}
}
