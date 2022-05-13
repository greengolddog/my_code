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
	string s;
	cin >> s;
	ll k;
	cin >> k;
	k--;
	s += '#';
	ll n = s.size();
	vector<ll> nums(n);
	for (ll i = 0; i < n; i++) {
		nums[i] = s[i] - '#';
	}
	for (ll k = 2; k <= 2 * n; k *= 2) {
		vector<pair<pair<ll, ll>, ll>> arr;
		for (ll i = 0; i < n; i++) {
			arr.push_back(make_pair(make_pair(nums[i], nums[(i + k / 2) % n]), i));
		}
		sort(arr.begin(), arr.end());
		nums[arr[0].second] = 0;
		ll now = 0;
		for (ll i = 1; i < n; i++) {
			if (arr[i].first != arr[i - 1].first) {
				now++;
			}
			nums[arr[i].second] = now;
		}
	}
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n; i++) {
		ans[nums[i]] = i;
	}
	vector<ll> lcp(n, 0);
	for (ll i = 0; i < n - 1; i++) {
		if (nums[i] == n - 1) {
			continue;
		}
		if (i != 0) {
			lcp[nums[i]] = max(0ll, lcp[nums[i - 1]] - 1);
		}
		while (s[lcp[nums[i]] + i] == s[lcp[nums[i]] + ans[nums[i] + 1]]) {
			lcp[nums[i]]++;
		}
	}
	for (ll i = 1; i < n; i++) {
		k -= n - ans[i] - 1;
		k += lcp[i - 1];
		if (k < 0) {
			for (ll j = 0; j < lcp[i - 1]; j++) {
				cout << s[ans[i] + j];
			}
			for (ll kk = ans[i] + lcp[i - 1]; kk < n + k; kk++) {
				cout << s[kk];
			}
			return 0;
		}
	}
	for (ll i = ans.back(); i < n - 1; i++) {
		cout << s[i];
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
