#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

const ll INF32 = 2'000'000'000, INF64 = 9'000'000'000'000'000'000, LOG = 20;

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct LCA {
	vector<ll> ds, de, us, ue;
	ll fl, sl;
	vector<vector<ll>> binup;
	LCA(vector<ll> ds, vector<ll> de, vector<ll> us, vector<ll> ue, ll fl, ll sl): ds(ds), de(de), us(us), ue(ue), fl(fl), sl(sl) {
		vector<ll> cgu(fl, -1);
		for (ll i = 0; i < fl; i++) {
			if (ue[de[i]] != -1) {
				cgu[i] = ue[de[i]];
			} else {
				cgu[i] = i;
			}
		}
		binup.resize(LOG, vector<ll>(fl));
		for (ll i = fl - 1; i >= 0; i--) {
			binup[0][i] = cgu[i];
			for (ll j = 1; j < LOG; j++) {
				binup[j][i] = binup[j - 1][binup[j - 1][i]];
			}
		}
	}
	ll get(ll a, ll b) {
		if (a == -1) {
			return INF32;
		}
		if (b == -1) {
			return INF32;
		}
		if (a == b) {
			return 0;
		}
		ll ans2 = INF32;
		if (a >= fl) {
			assign_min(ans2, min(min(get(ds[a], b), get(de[a], b)), min(get(us[a], b), get(ue[a], b))) + 1);
		}
		if (b >= fl) {
			assign_min(ans2, min(min(get(ds[b], a), get(de[b], a)), min(get(us[b], a), get(ue[b], a))) + 1);
		}
		if (b >= fl || a >= fl) {
			return ans2;
		}
		if (a > b) {
			return get(b, a);
		}
		ll ans = 0;
		for (ll j = LOG - 1; j >= 0; j--) {
			if (binup[j][a] < b) {
				a = binup[j][a];
				ans += (1 << j);
			}
		}
		if (binup[0][a] < b) {
			return INF32;
		}
		ans++;
		return ans * 2;
	}
};

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<pair<ll, ll>> emp(n, make_pair(-1, -1)), arr;
	arr = emp;
	vector<ll> a(n * 2);
	for (ll i = 0; i < n * 2; i++) {
		ll x;
		cin >> x;
		x--;
		a[i] = x;
		if (arr[x].first == -1) {
			arr[x].first = i;
		} else {
			arr[x].second = i;
		}
	}
	vector<ll> ds(n, -1), de(n, -1), us(n, -1), ue(n, -1);
	set<pair<ll, ll>> st, end;
	for (ll i = 0; i < n * 2; i++) {
		if (arr[a[i]].first == i) {
			if (!end.empty() && end.rbegin()->first > arr[a[i]].second) {
				ue[a[i]] = end.rbegin()->second;
			}
			end.insert(make_pair(arr[a[i]].second, a[i]));
		} else {
			end.erase(make_pair(i, a[i]));
			if (!st.empty() && st.rbegin()->first > arr[a[i]].first) {
				de[a[i]] = st.rbegin()->second;
			}
			st.insert(make_pair(arr[a[i]].first, a[i]));
		}
	}
	arr = emp;
	st.clear();
	reverse(a.begin(), a.end());
	for (ll i = 0; i < n * 2; i++) {
		ll x = a[i];
		if (arr[x].first == -1) {
			arr[x].first = i;
		} else {
			arr[x].second = i;
		}
	}
	for (ll i = 0; i < n * 2; i++) {
		if (arr[a[i]].first == i) {
			if (!end.empty() && end.rbegin()->first > arr[a[i]].second) {
				us[a[i]] = end.rbegin()->second;
			}
			end.insert(make_pair(arr[a[i]].second, a[i]));
		} else {
			end.erase(make_pair(i, a[i]));
			if (!st.empty() && st.rbegin()->first > arr[a[i]].first) {
				ds[a[i]] = st.rbegin()->second;
			}
			st.insert(make_pair(arr[a[i]].first, a[i]));
		}
	}
	arr = emp;
	st.clear();
	reverse(a.begin(), a.end());
	for (ll i = 0; i < n * 2; i++) {
		ll x = a[i];
		if (arr[x].first == -1) {
			arr[x].first = i;
		} else {
			arr[x].second = i;
		}
	}
	vector<ll> reorder(n), unreorder(n);
	vector<pair<pair<ll, ll>, ll>> nu, nd, e;
	for (ll i = 0; i < n; i++) {
		if ((us[i] == -1 && ue[i] == -1) == (ds[i] == -1 && de[i] == -1)) {
			e.emplace_back(arr[i], i);
		} else {
			if (us[i] == -1 && ue[i] == -1) {
				nu.emplace_back(arr[i], i);
			} else {
				nd.emplace_back(arr[i], i);
			}
		}
	}
	sort(nu.begin(), nu.end());
	sort(nd.begin(), nd.end());
	arr.clear();
	ll last = 0;
	for (auto[p, i] : nu) {
		arr.push_back(p);
		reorder[i] = last;
		unreorder[last] = i;
		last++;
	}
	ll fl = last;
	for (auto[p, i] : nd) {
		arr.push_back(p);
		reorder[i] = last;
		unreorder[last] = i;
		last++;
	}
	ll sl = last;
	for (auto[p, i] : e) {
		arr.push_back(p);
		reorder[i] = last;
		unreorder[last] = i;
		last++;
	}
	vector<ll> nds(n, -1), nde(n, -1), nus(n, -1), nue(n, -1);
	for (ll i = 0; i < n; i++) {
		if (ds[i] != -1) {
			nds[reorder[i]] = reorder[ds[i]];
		}
		if (de[i] != -1) {
			nde[reorder[i]] = reorder[de[i]];
		}
		if (us[i] != -1) {
			nus[reorder[i]] = reorder[us[i]];
		}
		if (ue[i] != -1) {
			nue[reorder[i]] = reorder[ue[i]];
		}
	}
	ds = nds;
	de = nde;
	us = nus;
	ue = nue;
	LCA l(ds, de, us, ue, fl, sl);
	for (ll i = 0; i < q; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		a = reorder[a];
		b = reorder[b];
		if ((arr[a].first < arr[b].first && arr[b].second < arr[a].second) || (arr[b].first < arr[a].first && arr[a].second < arr[b].second)) {
			cout << 1 << '\n';
			continue;
		}
		ll ans = l.get(a, b);
		if (ans >= 1'000'000'000) {
			cout << -1 << '\n';
		} else {
			cout << ans << '\n';
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
