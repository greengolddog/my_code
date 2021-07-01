#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

__int128 power(__int128 a, __int128 p, __int128 m = (ll)1e18) {
	if (p == 0) {
		return 1;
	}
	if (p % 2 == 0) {
		__int128 ans = power(a, p/2, m);
		return ans*ans%m;
	} else {
		return power(a, p-1, m)*a%m;
	}
}

ll gcd(ll a, ll b) {
	if (a == 0) {
		return b;
	}
	if (b == 0) {
		return a;
	}
	return gcd(min(a, b), max(a, b)%min(a, b));
}

ll lcm(ll a, ll b) {
	return a*b/gcd(a, b);
}

ll sub(ll a, ll b, ll m) {
	if (a-b < 0) return a-b+m;
	return a-b;
}

ll sum(ll a, ll b, ll m) {
	if (a+b >= m) return a+b-m;
	return a+b;
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr;
	for (ll i = 0; i <= n; i++) {
		arr.push_back(i);
	}
	vector<pair<ll, ll>> ans;
	for (ll i = 2; i <= n; i++) {
		if (arr[i] != 1) {
			ans.push_back({i, 1});
			for (ll j = i+arr[i]; j <= n; j += arr[i]) {
				while (arr[j] % arr[i] == 0) {
					ans.back().second++;
					arr[j] /= arr[i];
				}
			}
		}
	}
	ll otv = 1;
	for (auto i : ans) {
		otv = (otv*(i.second+1))%1000000007;
	}
	cout << otv;
}
