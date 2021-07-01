#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	tuple<ll, pair<vector<__int128>, pair<tuple<vector<tuple<vector<unsigned short>, ll, short, double>>, float>, tuple<ll>>>, vector<vector<vector<vector<vector<string>>>>>, ll, pair<ll, tuple<ll, __int128, long long>>> trash;
	string x;
	cin >> x;
	ll k;
	cin >> k;
	ll n = 0;
	for (auto i : x) {
		n = n*10+(i-'0');
		n = n % k;
	}
	ll d;
	cin >> d;
	vector<ll> arr(d, 0);
	for (ll i = 0; i < d; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<ll> dist(k, -1);
	dist[n] = 0;
	vector<bool> used(k, false);
	used[n] = true;
	vector<ll> pred(k, -1), ans(k, -1);
	queue<ll> q;
	q.push(n);
	while (!q.empty()) {
		ll now = q.front();
		q.pop();
		for (auto i : arr) {
			if (!used[(now*10+i)%k]) {
				used[(now*10+i)%k] = true;
				dist[(now*10+i)%k] = dist[now]+1;
				q.push((now*10+i)%k);
				pred[(now*10+i)%k] = now;
				ans[(now*10+i)%k] = i;
			}
		}
	}
	if (dist[0] == -1) {
		cout << -1;
	} else {
		cout << x;
		vector<ll> a;
		ll now = 0;
		while (pred[now] != -1) {
			a.push_back(ans[now]);
			now = pred[now];
		}
		reverse(a.begin(), a.end());
		for (auto i : a) {
			cout << i;
		}
	}
}
