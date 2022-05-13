#include<bits/stdc++.h>
typedef long long ll;

using namespace std;

const ll INF = 9'000'000'000'000'000'000, COLC = 10;

template<typename T>
T assign_max(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
T assign_min(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	ll k;
	cin >> k;
	vector<deque<ll>> arr(COLC);
	for (ll i = 0; i < s.size(); i++) {
		arr[s[i] - '0'].push_back(i);
	}
	ll ak = s.size() - k;
	string ans;
	ll lk = 0;
	for (ll i = 0; i < ak; i++) {
		for (ll x = COLC - 1; x >= 0; x--) {
			if (arr[x].empty()) {
				continue;
			}
			if (arr[x].front() - lk <= k) {
				k -= arr[x].front() - lk;
				lk = arr[x].front() + 1;
				ans.push_back(x + '0');
				break;
			}
		}
		for (auto& i : arr) {
			while (!i.empty() && i.front() < lk) {
				i.pop_front();
			}
		}
	}
	cout << ans;
}
