#include <bits/stdc++.h>
#define elif else if
using namespace std;
typedef long long ll;
typedef string str;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, ans = 0, summ = 0;
	cin >> n;
	vector<ll> arr(n, 0);
	set<ll> s;
	map<ll, ll> m;
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
		summ += arr[i];
		if (i == n-1) continue;
		if (s.find(summ) == s.end()) {
			s.insert(summ);
			m[summ] = 1;
		} else {
			m[summ]++;
		}
	}
	if (summ % 3 != 0) {
		cout << 0;
		return 0;
	}
	ll new_sum = 0;
	for (ll i = 0; i < (n - 1); i++) {
		new_sum += arr[i];
		m[new_sum]--;
		if (new_sum == summ/3) {
			if (s.find(new_sum*2) != s.end()) {
				ans += m[new_sum*2];
			}
		}
	}
	cout << ans;
}
