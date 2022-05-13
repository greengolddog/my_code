#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 1'000'000'000'000'000;

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

struct block {
	ll sum = 0;
	vector<ll> arr;
	block(ll k = 0) {
		arr.resize(k, 0);
	}
	ll size() {
		return arr.size();
	}
	bool get() {
		return sum == size();
	}
	ll& operator[] (ll x) {
		return arr[x];
	}
	void insert(ll x) {
		sum += arr[x] == 0;
		arr[x]++;
	}
	void erase(ll x) {
		arr[x]--;
		sum -= arr[x] == 0;
	}
};

struct MEX {
	vector<block> arr;
	ll k = 300, col;
	MEX(ll n = 0) {
		col = (n / k + 1) * k;
		arr.resize(n / k + 1, block(k));
	}
	ll get() {
		ll ans = 0;
		bool b = false;
		for (ll i = 0; i < arr.size(); i++) {
			if (!arr[i].get()) {
				for (ll j = 0; j < arr[i].size(); j++) {
					if (arr[i][j] == 0) {
						b = true;
						break;
					}
					ans++;
				}
			}
			if (b) {
				break;
			}
			ans += k;
		}
		return ans;
	}
	void insert(ll x) {
		if (x < col) {
			arr[x / k].insert(x % k);
		}
	}
	void erase(ll x) {
		if (x < col) {
			arr[x / k].erase(x % k);
		}
	}
};

void dfs(ll v, ll p, vector<vector<pair<ll, ll>>>& arr, vector<ll>& ans, vector<ll>& start) {
	start[v] = ans.size();
	for (auto[i, num] : arr[v]) {
		if (i != p) {
			ans.push_back(num);
			dfs(i, v, arr, ans, start);
			ans.push_back(num);
		}
	}
}

struct MO {
	vector<pair<ll, ll>> q;
	MEX m;
	ll k = 300;
	vector<ll> col, cost, start, arr, ans;
	ll nr = -1, nl = 0;
	MO(vector<vector<pair<ll, ll>>>& a, vector<ll>& c) {
		cost = c;
		m = MEX(c.size() * 2);
		start.resize(a.size());
		dfs(0, 0, a, arr, start);
		col.resize(arr.size(), 0);
	}
	void add(ll l, ll r) {
		l = start[l];
		r = start[r];
		ans.push_back(0);
		if (l > r) {
			swap(l, r);
		}
		r--;
		q.push_back({l, r});
	}
	void insert(ll x) {
		col[x]++;
		if (col[x] == 1) {
			m.insert(cost[x]);
		} else {
			m.erase(cost[x]);
		}
	}
	void erase(ll x) {
		col[x]--;
		if (col[x] == 0) {
			m.erase(cost[x]);
		} else {
			m.insert(cost[x]);
		}
	}
	void move_l(ll x) {
		if (nl >= x) {
			for (nl; nl > x; nl--) {
				insert(arr[nl - 1]);
			}
		} else {
			for (nl; nl < x; nl++) {
				erase(arr[nl]);
			}
		}
	}
	void move_r(ll x) {
		if (nr >= x) {
			for (nr; nr > x; nr--) {
				erase(arr[nr]);
			}
		} else {
			for (nr; nr < x; nr++) {
				insert(arr[nr + 1]);
			}
		}
	}
	ll get(ll l, ll r) {
		//for (ll i = l; i <= r; i++) {
		//	insert(arr[i]);
		//}
		//ll ans = m.get();
		//for (ll i = l; i <= r; i++) {
		//	erase(arr[i]);
		//}
		//return ans;
		move_r(r);
		move_l(l);
		return m.get();
	}
	void end() {
		vector<tuple<pair<ll, ll>, pair<ll, ll>, ll>> nq;
		for (ll i = 0; i < q.size(); i++) {
			nq.push_back(make_tuple(make_pair(q[i].first / k, q[i].second), make_pair(q[i].first, q[i].second), i));
		}
		sort(nq.begin(), nq.end());
		for (auto[_, i, num] : nq) {
			if (i.first > i.second) {
				ans[num] = 0;
				continue;
			}
			ans[num] = get(i.first, i.second);
		}
	}
	ll get_ans(ll x) {
		return ans[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, q;
	cin >> n >> q;
	vector<vector<pair<ll, ll>>> arr(n);
	vector<ll> cost;
	for (ll i = 0; i < n - 1; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		arr[a].push_back({b, i});
		arr[b].push_back({a, i});
		cost.push_back(c);
	}
	MO m(arr, cost);
	for (ll i = 0; i < q; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		r--;
		m.add(l, r);
	}
	m.end();
	for (ll i = 0; i < q; i++) {
		cout << m.get_ans(i) << '\n';
	}
}

/*
⣿⣿⣿⣿⣻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣵⣿⣿⣿⠿⡟⣛⣧⣿⣯⣿⣝⡻⢿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⠋⠁⣴⣶⣿⣿⣿⣿⣿⣿⣿⣦⣍⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⢷⠄⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣏⢼⣿⣿⣿⣿
⢹⣿⣿⢻⠎⠔⣛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⣿⣿⣿⣿
⢸⣿⣿⠇⡶⠄⣿⣿⠿⠟⡛⠛⠻⣿⡿⠿⠿⣿⣗⢣⣿⣿⣿⣿
⠐⣿⣿⡿⣷⣾⣿⣿⣿⣾⣶⣶⣶⣿⣁⣔⣤⣀⣼⢲⣿⣿⣿⣿
⠄⣿⣿⣿⣿⣾⣟⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⢟⣾⣿⣿⣿⣿
⠄⣟⣿⣿⣿⡷⣿⣿⣿⣿⣿⣮⣽⠛⢻⣽⣿⡇⣾⣿⣿⣿⣿⣿
⠄⢻⣿⣿⣿⡷⠻⢻⡻⣯⣝⢿⣟⣛⣛⣛⠝⢻⣿⣿⣿⣿⣿⣿
⠄⠸⣿⣿⡟⣹⣦⠄⠋⠻⢿⣶⣶⣶⡾⠃⡂⢾⣿⣿⣿⣿⣿⣿
⠄⠄⠟⠋⠄⢻⣿⣧⣲⡀⡀⠄⠉⠱⣠⣾⡇⠄⠉⠛⢿⣿⣿⣿
⠄⠄⠄⠄⠄⠈⣿⣿⣿⣷⣿⣿⢾⣾⣿⣿⣇⠄⠄⠄⠄⠄⠉⠉
⠄⠄⠄⠄⠄⠄⠸⣿⣿⠟⠃⠄⠄⢈⣻⣿⣿⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⢿⣿⣾⣷⡄⠄⢾⣿⣿⣿⡄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠸⣿⣿⣿⠃⠄⠈⢿⣿⣿⠄⠄⠄⠄⠄⠄⠄
*/
