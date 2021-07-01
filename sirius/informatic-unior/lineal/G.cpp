#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct qmin {
	queue<ll> q;
	deque<ll> m;
	qmin() {
	}
	void push(ll n) {
		while (!m.empty() && m.back() > n) {
			m.pop_back();
		}
		m.push_back(n);
		q.push(n);
	}
	ll pop() {
		ll ans = q.front();
		if (ans == m.front()) {
			m.pop_front();
		}
		q.pop();
		return ans;
	}
	ll min() {
		return m.front();
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	qmin q;
	for (ll i = 0; i < k; i++) {
		q.push(arr[i]);
	}
	cout << q.min() << '\n';
	for (ll i = k; i < n; i++) {
		q.push(arr[i]);
		q.pop();
		cout << q.min() << '\n';
	}
}
