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
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> pref(n, INF), suff(n, -INF), nump(n, 0), nums(n, 0);
	for (ll i = 1; i < n; i++) {
		pref[i] = pref[i - 1];
		nump[i] = nump[i - 1];
		if (assign_min(pref[i], arr[i - 1])) {
			nump[i] = i - 1;
		}
	}
	for (ll i = n - 2; i >= 0; i--) {
		suff[i] = suff[i + 1];
		nums[i] = nums[i + 1];
		if (assign_max(suff[i], arr[i + 1])) {
			nums[i] = i + 1;
		}
	}
	for (ll i = 0; i < n; i++) {
		if ((pref[i] < arr[i]) && (arr[i] < suff[i])) {
			cout << nump[i] + 1 << ' ' << i + 1 << ' ' << nums[i] + 1;
			return 0;
		}
	}
	cout << 0;
}
