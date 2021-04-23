#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	int n, m, l, inp;
	cin >> n >> m;
	pair<int,int> p;
	vector<int> a(n+1,-1), ans(n+1,-1);
	vector<pair<int,pair<int,int>>> b(m+2, {-1, {0,1}});
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i].first;
		b[i].second = {i - 1,i + 1};
	}
	int now = m;
	for (int i = n; i > 0; i--) {
		while (b[b[now].second.first].first >= a[i]) {
			now = b[now].second.first;
		}
		if (b[now].first >= a[i]) {
			ans[i] = now;
			b[b[now].second.first].second.second = b[now].second.second;
			b[b[now].second.second].second.first = b[now].second.first;
			now = b[now].second.second;
		}
		
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << endl;
	}
}