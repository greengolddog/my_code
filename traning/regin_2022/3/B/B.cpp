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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll w, h, k, t;
	cin >> w >> h >> k >> t;
	vector<vector<pair<ll, ll>>> X(h + 1), Y(w + 1);
	vector<vector<pair<ll, ll>>> XE(h + 1), YE(w + 1);
	for (ll i = 0; i < k; i++) {
		ll x, y, d;
		bool b = true;
		cin >> x >> y >> d;
		//if (x == 0 || y == 0 || x == w || y == h) {
		//	return 1;
		//}
		if (d == 1 || d == 3) {
			d = 4 - d;
		} else {
			d = 6 - d;
		}
		if (d == 1 && b) {
			X[y].push_back({x, i});
			ll nt = t % (w * 2);
			if (nt >= x) {
				nt -= x;
				x = 0;
				d = 4 - d;
			} else {
				x -= nt;
				nt = 0;
			}
			if (nt >= w) {
				x = w;
				nt -= w;
				d = 4 - d;
			} else {
				x += nt;
				nt = 0;
			}
			x -= nt;
			b = false;
			XE[y].push_back(make_pair(x, d));
		}
		if (d == 2 && b) {
			Y[x].push_back({y, i});
			ll nt = t % (h * 2);
			if (nt >= y) {
				nt -= y;
				y = 0;
				d = 6 - d;
			} else {
				y -= nt;
				nt = 0;
			}
			if (nt >= h) {
				y = h;
				nt -= h;
				d = 6 - d;
			} else {
				y += nt;
				nt = 0;
			}
			y -= nt;
			b = false;
			YE[x].push_back(make_pair(y, d));
		}
		if (d == 3 && b) {
			X[y].push_back({x, i});
			ll nt = t % (w * 2);
			if (nt >= w - x) {
				nt -= w - x;
				x = w;
				d = 4 - d;
			} else {
				x += nt;
				nt = 0;
			}
			if (nt >= w) {
				x = 0;
				nt -= w;
				d = 4 - d;
			} else {
				x -= nt;
				nt = 0;
			}
			x += nt;
			b = false;
			XE[y].push_back(make_pair(x, d));
		}
		if (d == 4 && b) {
			Y[x].push_back({y, i});
			ll nt = t % (h * 2);
			if (nt >= h - y) {
				nt -= h - y;
				y = h;
				d = 6 - d;
			} else {
				y += nt;
				nt = 0;
			}
			if (nt >= h) {
				y = 0;
				nt -= h;
				d = 6 - d;
			} else {
				y -= nt;
				nt = 0;
			}
			y += nt;
			b = false;
			YE[x].push_back(make_pair(y, d));
		}
	}
	for (auto& i : XE) {
		sort(i.begin(), i.end());
	}
	for (auto& i : YE) {
		sort(i.begin(), i.end());
	}
	for (auto& i : X) {
		sort(i.begin(), i.end());
	}
	for (auto& i : Y) {
		sort(i.begin(), i.end());
	}
	vector<tuple<ll, ll, ll>> ans(k);
	for (ll i = 0; i <= h; i++) {
		for (ll j = 0; j < XE[i].size(); j++) {
			ans[X[i][j].second] = make_tuple(XE[i][j].first, i, 4 - XE[i][j].second);
		}
	}
	for (ll i = 0; i <= w; i++) {
		for (ll j = 0; j < YE[i].size(); j++) {
			ans[Y[i][j].second] = make_tuple(i, YE[i][j].first, 6 - YE[i][j].second);
		}
	}
	for (auto[a, b, c] : ans) {
		cout << a << ' ' << b << ' ' << c << '\n';
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
