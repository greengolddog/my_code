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

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll st = time(0);
	ll n, m;
	cin >> n >> m;
	vector<string> ans;
	vector<tuple<ll, ll, string>> all, nall;
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		l--;
		string s;
		cin >> s;
		all.emplace_back(l, r, s);
	}
	sort(all.begin(), all.end());
	if (true) {
		vector<string> arr;
		for (auto[l, r, s] : all) {
			bool bb = true;
			vector<ll> nums(arr.size(), 0);
			for (ll i = 0; i < (ll)arr.size(); i++) {
				nums[i] = i;
			}
			//shuffle(nums.begin(), nums.end(), rnd);
			for (auto j : nums) {
				bool b = true;
				for (ll k = l; k < r; k++) {
					if (s[k - l] != arr[j][k]) {
						b = false;
						break;
					}
				}
				if (b) {
					bb = false;
					for (ll k = l; k < r; k++) {
						arr[j][k] = s[k - l];
					}
					break;
				}
			}
			if (bb) {
				nall.emplace_back(l, r, s);
				string ss;
				for (ll k = 0; k < l; k++) {
					ss.push_back('?');
				}
				for (ll k = l; k < r; k++) {
					ss.push_back(s[k - l]);
				}
				for (ll k = r; k < m; k++) {
					ss.push_back('?');
				}
				arr.push_back(ss);
			}
		}
	}
	all = nall;
	if (time(0) - st <= 1) {
		//sort(all.begin(), all.end());
		vector<string> arr;
		for (auto[l, r, s] : all) {
			bool bb = true;
			vector<ll> nums(arr.size(), 0);
			for (ll i = 0; i < (ll)arr.size(); i++) {
				nums[i] = i;
			}
			//shuffle(nums.begin(), nums.end(), rnd);
			ll col = -1, x = 0;
			for (auto j : nums) {
				bool b = true;
				ll nc = 0;
				for (ll k = l; k < r; k++) {
					nc += s[k - l] == arr[j][k];
					if (s[k - l] != arr[j][k] && arr[j][k] != '?') {
						b = false;
						break;
					}
				}
				if (b) {
					bb = false;
					if (nc > col) {
						col = nc;
						x = j;
					}
				}
			}
			if (!bb) {
				for (ll k = l; k < r; k++) {
					arr[x][k] = s[k - l];
				}
			}
			if (bb) {
				string ss;
				for (ll k = 0; k < l; k++) {
					ss.push_back('?');
				}
				for (ll k = l; k < r; k++) {
					ss.push_back(s[k - l]);
				}
				for (ll k = r; k < m; k++) {
					ss.push_back('?');
				}
				arr.push_back(ss);
			}
		}
		if (ans.size() == 0 || arr.size() < ans.size()) {
			ans = arr;
		}
	}
	cout << ans.size() << '\n';
	for (auto i : ans) {
		for (auto j : i) {
			cout << (j == '?' ? 'a' : j);
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
