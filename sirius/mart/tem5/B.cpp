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

mt19937 rnd(time(0));

void dfs(ll x, ll y, ll xp, ll yp, vector<vector<ll>>& color, vector<vector<char>>& arr, vector<pair<ll, ll>>& go) {
	color[x][y] = color[xp][yp];
	for (auto[a, b] : go) {
		ll nx = a + x, ny = b + y;
		if (nx >= 0 && ny >= 0 && nx < color.size() && ny < color[0].size()) {
			if (color[nx][ny] == -1) {
				if (arr[nx][ny] == arr[x][y]) {
					dfs(nx, ny, x, y, color, arr, go);
				}
			}
		}
	}
}

ll count(vector<vector<char>>& arr) {
	ll ans = 0;
	vector<pair<ll, ll>> go;
	go.push_back(make_pair(1, 0));
	go.push_back(make_pair(-1, 0));
	go.push_back(make_pair(0, 1));
	go.push_back(make_pair(0, -1));
	vector<vector<ll>> color(arr.size(), vector<ll>(arr[0].size(), -1));
	for (ll i = 0; i < color.size(); i++) {
		for (ll j = 0; j < color[0].size(); j++) {
			if (color[i][j] == -1) {
				color[i][j] = ans;
				dfs(i, j, i, j, color, arr, go);
				ans++;
			}
		}
	}
	return ans;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, p;
	cin >> n >> p;
	vector<vector<char>> arr(n, vector<char>(n, '?'));
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() > 1) {
			char c = s.back();
			s.pop_back();
			ll a = stoi(s);
			a--;
			arr[a][i] = c;
			for (ll j = 0; j < a; j++) {
				arr[j][i] = '-';
			}
		}
		if (s == "0") {
			for (ll j = 0; j < n; j++) {
				arr[j][i] = '-';
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() > 1) {
			char c = s.back();
			s.pop_back();
			ll a = stoi(s);
			a--;
			arr[i][a] = c;
			for (ll j = 0; j < a; j++) {
				arr[i][j] = '-';
			}
		}
		if (s == "0") {
			for (ll j = 0; j < n; j++) {
				arr[i][j] = '-';
			}
		}
		cin >> s;
		if (s.size() > 1) {
			char c = s.back();
			s.pop_back();
			ll a = stoi(s);
			arr[i][n - a] = c;
			for (ll j = n - a + 1; j < n; j++) {
				arr[i][j] = '-';
			}
		}
		if (s == "0") {
			for (ll j = 0; j < n; j++) {
				arr[i][j] = '-';
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s.size() > 1) {
			char c = s.back();
			s.pop_back();
			ll a = stoi(s);
			arr[n - a][i] = c;
			for (ll j = n - a + 1; j < n; j++) {
				arr[j][i] = '-';
			}

		}
		if (s == "0") {
			for (ll j = 0; j < n; j++) {
				arr[j][i] = '-';
			}
		}
	}
	vector<pair<ll, ll>> all;
	vector<vector<char>> ans = arr;
	ll x = 0;
	for (auto& i : ans) {
		ll y = 0;
		for (auto& j : i) {
			if (j == '?') {
				all.push_back(make_pair(x, y));
				ll x = rnd() % 3;
				j = (x == 0 ? '-' : (x == 1 ? 'B' : 'M'));
			}
			y++;
		}
		x++;
	}
	vector<vector<char>> best_ans = ans;
	ll col = count(ans);
	ll mc = col;
	ll N = 1000;
	for (ll i = 0; i < N; i++) {
		auto[x, y] = all[rnd() % all.size()];
		ll cc = rnd() % 3;
		char c = (cc == 0 ? '-' : (cc == 1 ? 'B' : 'M'));
		if (c == ans[x][y]) {
			i--;
			continue;
		}
		ll oc = ans[x][y];
		ans[x][y] = c;
		ll new_col = count(ans);
		if (new_col < col) {
			col = new_col;
		} else {
			double x = rnd() % 1'000'000'000;
			x /= 1'000'000'000;
			if (x > exp(-(double)i / N * 2.28)) {
				col = new_col;
			} else {
				ans[x][y] = oc;
			}
		}
		if (col < mc) {
			mc = col;
			best_ans = ans;
		}
	}
	for (auto i : best_ans) {
		for (auto j : i) {
			cout << j;
		}
		cout << '\n';
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
