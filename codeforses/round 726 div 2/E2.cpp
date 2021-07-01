#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string ms = "";
	for (ll i = 0; i < k; i++) {
		ms += "z";
	}
	ll l = 0, r = n + 1;
	for (ll _ = 0; _ < 3; _++) {
		ll mid1 = l+(r-l)/3, mid2 = l+(r-l)/3*2;
		string now1 = "", now2 = "";
		for (ll i = 0; i < mid1; i++) {
			now1 += s[i];
		}
		for (ll i = 0; i < mid2; i++) {
			now2 += s[i];
		}
		string ans1 = "", ans2 = "";
		while (ans1.size() < k) {
			ans1 += now1;
		}
		while (ans1.size() > k) {
			ans1.pop_back();
		}
		while (ans2.size() < k) {
			ans2 += now2;
		}
		while (ans2.size() > k) {
			ans2.pop_back();
		}
		if (ans1 > ans2) {
			l = mid1;
		} else {
			r = mid1;
		}
	}
	for (ll i = l; i < r; i++) {
		string now = "";
		for (ll j = 0; j < i; j++) {
			now += s[j];
		}
		string ans = "";
		while (ans.size() < k) {
			ans += now;
		}
		while (ans.size() > k) {
			ans.pop_back();
		}
		ms = min(ms, ans);
	}
	cout << ms;
}
