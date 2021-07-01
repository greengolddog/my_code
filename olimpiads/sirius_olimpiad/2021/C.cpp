#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct block {
	vector<ll> arr;
	ll size = 0;
	block() {}
	ll get_and_del(ll k) {
		ll now = 0, n = 0;
		while (arr[n] != k) {
			now++;
			n++;
		}
		for (ll i = n+1; i < size; i++) {
			arr[i-1] = arr[i];
		}
		arr.pop_back();
		size--;
		return now;
	}
	void push_back(ll n) {
		arr.push_back(n);
		size++;
	}
};

struct sqrt_dec {
	vector<block> arr;
	vector<ll> nb;
	ll size = 0, k = 700;
	sqrt_dec(ll n) {
		arr.resize(1, block());
		nb.resize(n, -1);
	}
	ll get_and_del(ll n) {
		ll num = nb[n], ans = 0;
		for (ll i = 0; i < num; i++) {
			ans += arr[i].size;
		}
		ans += arr[num].get_and_del(n);
		size--;
		return size-ans;
	}
	void push_back(ll n) {
		if (arr.back().size == k) {
			arr.push_back(block());
		}
		arr.back().push_back(n);
		nb[n] = arr.size()-1;
		size++;
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<ll> arr(n*2, 0);
	for (ll i = 0; i < n*2; i++) {
		cin >> arr[i];
		arr[i]--;
	}
	ll ans = 0;
	vector<bool> used(n, false);
	sqrt_dec s(n);
	for (ll i = 0; i < n*2; i++) {
		if (!used[arr[i]]) {
			s.push_back(arr[i]);
			used[arr[i]] = true;
		} else {
			ans += s.get_and_del(arr[i]);
		}
	}
	cout << ans+n;
}
