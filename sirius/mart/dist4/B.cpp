#include <bits/stdc++.h>
typedef long long ll;

const ll INF = 9'000'000'000'000'000'000;

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

using namespace std;

mt19937_64 rnd(228);

void solve() {
	ll n, mm;
	cin >> n >> mm;
	vector<ll> hash(n);
	ll sum = 0;
	for (ll i = 0; i < n; i++) {
		hash[i] = rnd() % 1'000'000'000'000;
		sum += hash[i];
	}
	vector<ll> sums(n, 0);
	vector<vector<ll>> arr(n);
	vector<set<ll>> all(n);
	for (ll i = 0; i < mm; i++) {
		ll a, b;
		cin >> a >> b;
		a--;
		b--;
		arr[a].push_back(b);
		arr[b].push_back(a);
		all[a].insert(b);
		all[b].insert(a);
		sums[a] += hash[b];
		sums[b] += hash[a];
	}
	vector<set<ll>> nall(n);
	vector<ll> ans(n, -2);
	vector<ll> be;
	map<ll, vector<ll>> h;
	for (ll i = 0; i < n; i++) {
		all[i].insert(i);
		nall[i].insert(i);
		sums[i] += hash[i];
		h[sums[i]].push_back(i);
	}
	map<ll, set<ll>> s, to;
	for (auto&[a, b] : h) {
		for (auto j : arr[b[0]]) {
			if (arr[j].size() > arr[b[0]].size()) {
				s[a].insert(sums[j]);
			}
			//if (sums[j] != a && arr[j].size() == arr[b[0]].size()) {
			//	cout << "No\n";
			//	return;
			//}
		}
		//if (s[a].find(a) != s[a].end()) {
		//	s[a].erase(a);
		//}
		for (auto j : s[a]) {
			to[j].insert(a);
		}
	}
	queue<ll> q;
	if (h.find(sum) == h.end()) {
		cout << "No" << '\n';
		return;
	}
	vector<ll> pp(1, h[sum][0]);
	ans[h[sum][0]] = -1;
	for (ll i = 1; i < h[sum].size(); i++) {
		ans[h[sum][i]] = h[sum][i - 1];
		pp.push_back(h[sum][i]);
	}
	q.push(sum);
	while (!q.empty()) {
		ll x = q.front();
		q.pop();
		for (auto i : to[x]) {
			s[i].erase(x);
			if (s[i].size() == 0) {
				ans[h[i][0]] = h[x].back();
				pp.push_back(h[i][0]);
				for (ll j = 1; j < h[i].size(); j++) {
					ans[h[i][j]] = h[i][j - 1];
					pp.push_back(h[i][j]);
				}
				q.push(i);
			}
		}
	}
	ll m = -1;
	for (auto i : ans) {
		assign_min(m, i);
	}
	if (m == -2) {
		cout << "No" << '\n';
		return;
	}
	for (auto i : pp) {
		if (ans[i] == -1) {
			continue;
		}
		for (auto j : nall[ans[i]]) {
			nall[i].insert(j);
			if (all[i].find(j) == all[i].end()) {
				cout << "No\n";
				return;
			}
		}
	}
	reverse(pp.begin(), pp.end());
	for (auto i : pp) {
		if (ans[i] == -1) {
			continue;
		}
		for (auto j : nall[i]) {
			nall[ans[i]].insert(j);
			if (all[ans[i]].find(j) == all[ans[i]].end()) {
				cout << "No\n";
				return;
			}
		}
	}
	if (nall != all) {
		cout << "No\n";
		return;
	}
	cout << "Yes" << '\n';
	for (auto i : ans) {
		cout << i + 1 << ' ';
	}
	cout << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t;
	cin >> t;
	for (ll _ = 0; _ < t; _++) {
		solve();
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
