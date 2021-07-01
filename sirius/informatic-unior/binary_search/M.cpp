#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

bool check(long double mid, vector<pair<ll, ll>>& arr, ll k) {
	vector<long double> ans;
	for (auto i : arr) {
		ans.push_back(-(i.first-mid*i.second));
	}
	long double s = 0;
	sort(ans.begin(), ans.end());
	for (ll i = 0; i < k; i++) {
		s -= ans[i];
	}
	return s >= 0;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	long double sum1 = 0, sum2 = 0;
	cin >> n >> k;
	vector<pair<ll, ll>> arr(n, {0, 0});
	for (ll i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum1 += arr[i].first;
		sum2 += arr[i].second;
	}
	long double l = 0, r = sum1/sum2*1000;
	for (ll i = 0; i < 100; i++) {
		long double mid = (l+r)/2;
		if (check(mid, arr, k)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	vector<pair<long double, ll>> ans;
	for (ll i = 0; i < n; i++) {
		ans.push_back({-(arr[i].first-l*arr[i].second), i});
	}
	sort(ans.begin(), ans.end());
	vector<ll> last_ans;
	for (ll i = 0; i < k; i++) {
		last_ans.push_back(ans[i].second+1);
	}
	sort(last_ans.begin(), last_ans.end());
	for (auto i : last_ans) {
		cout << i << ' ';
	}
}
