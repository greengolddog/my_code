#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll a, b;
	cin >> a >> b;
	vector<ll> dist(10001, -1);
	vector<bool> used(10001, false);
	vector<ll> pred(10001, -1);
	dist[a] = 0;
	used[a] = true;
	queue<ll> q;
	q.push(a);
	while(!q.empty()) {
		ll now = q.front();
		q.pop();
		if (now % 10 != 1) {
			if (!used[now-1]) {
				dist[now-1] = dist[now]+1;
				used[now-1] = true;
				q.push(now-1);
				pred[now-1] = now;
			}
		}
		if (now / 1000 != 9) {
			if (!used[now+1000]) {
				dist[now+1000] = dist[now]+1;
				used[now+1000] = true;
				q.push(now+1000);
				pred[now+1000] = now;
			}
		}
		if (!used[now/10+now%10*1000]) {
			dist[now/10+now%10*1000] = dist[now]+1;
			used[now/10+now%10*1000] = true;
			q.push(now/10+now%10*1000);
			pred[now/10+now%10*1000] = now;
		}
		if (!used[now/1000+now%1000*10]) {
			dist[now/1000+now%1000*10] = dist[now]+1;
			used[now/1000+now%1000*10] = true;
			q.push(now/1000+now%1000*10);
			pred[now/1000+now%1000*10] = now;
		}
	}
	vector<ll> ans;
	ll now = b;
	while (now != -1) {
		ans.push_back(now);
		now = pred[now];
	}
	reverse(ans.begin(), ans.end());
	for (auto i : ans) {
		cout << i << '\n';
	}
}
