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
	ll n, ans = 0;
	cin >> n;
	vector<ll> arr(1, 0);
	vector<vector<ll>> tree(1, vector<ll>(30, -1));
	for (ll i = 0; i < n; i++) {
		ll v;
		cin >> v;
		v--;
		char c;
		cin >> c;
		if (tree[arr[v]][c-'a'] == -1) {
			ans++;
			tree[arr[v]][c-'a'] = arr.size();
			arr.push_back(tree.size());
			tree.push_back(vector<ll>(30, -1));
		} else {
			arr.push_back(tree[arr[v]][c-'a']);
		}
		cout << ans << '\n';
	}
}
