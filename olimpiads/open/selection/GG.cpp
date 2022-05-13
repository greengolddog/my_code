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
	ll n;
	cin >> n;
	if (n == 1) {
		cout << 0;
		return 0;
	}
	string sti, st;
	cin >> sti;
	vector<ll> c(1, 1);
	st.push_back(sti[0]);
	for (ll i = 1; i < n; i++) {
		if (sti[i] != sti[i - 1]) {
			st.push_back(sti[i]);
			c.push_back(1);
		} else {
			c.back()++;
		}
	}
	n = st.size();
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {
		arr[i] = st[i] - 'a';
	}
	vector<ll> prefc(1, 0), prefnc(1, 0);
	for (ll i = 0; i < n; i++) {
		if (i % 2 == 0) {
			prefc.push_back(prefc.back() + c[i]);
		} else {
			prefnc.push_back(prefnc.back() + c[i]);
		}
	}
	vector<ll> col(26, 0);
	set<ll> s;
	s.insert(arr[0]);
	s.insert(arr[1]);
	col[arr[0]]++;
	col[arr[1]]++;
	ll lc = 0, lnc = 0;
	for (ll i = 2; i < n; i++) {
		if (i > 2) {
			if (col[arr[i - 3]] == 1) {
				s.erase(arr[i - 3]);
			}
			col[arr[i - 3]]--;
		}
		if (col[arr[i]] == 0) {
			s.insert(arr[i]);
		}
		col[arr[i]]++;
		if (s.size() == 2) {
			if (i % 2 == 0) {
				ans += ((prefnc[i / 2] - prefnc[lc]) + 1) * ((prefc.back() - prefc[i / 2 + 1]) + 1);
				lc = i / 2;
			} else {
				ans += ((prefc[i / 2] - prefc[lnc]) + 1) * ((prefnc.back() - prefnc[i / 2 + 1]) + 1);
				lnc = i / 2;
			}
		}
	}
	s.clear();
	col.clear();
	col.resize(26, 0);
	cout << ans;
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
