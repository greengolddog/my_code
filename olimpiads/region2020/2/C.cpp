#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	ll n,l,k,now,now2;
	cin >> n >> l >> k;
	vector<ll> ns(k+1,-100);
	for (ll i = 0; i < k; i++) {
		cin >> ns[i];
		ns[i]--;
	}
	vector<double> len(n,0.0);
	double dd=0.0,x1,y1,x,y,xp,yp;
	cin >> x1 >> y1;
	xp = x1;
	yp = y1;
	now = 0;
	for (ll i = 0; i < (n-1); i++) {
		cin >> x >> y;
		len[i] = sqrt(((x-xp)*(x-xp))+((y-yp)*(y-yp)));
		xp = x;
		yp = y;
		if (i == ns[now]) {
			dd+= len[i];
			now++;
		}
	}
	len[n-1] = sqrt(((x1-xp)*(x1-xp))+((y1-yp)*(y1-yp)));
	if (n-1 == ns[now]) {
		dd+= len[n-1];
		now++;
	}
	double ans,r=0.0;
	ll u1;
	u1 = 0;
	pair<ll,double> u2;
	u2 = {0,0.0};
	now = 0;
	now2 = 0;
	while(((r + len[u2.first]) <= l) and (dd > 0.0)) {
		r += len[u2.first];
		if (ns[now] == u2.first) {
			dd -= len[u2.first];
			now++;
		}
		u2.first++;
		if (u2.first > n) {
			u2.first = 0;
			now = 0;
		}
	}
	u2.second = l-r;
	if (ns[now] == u2.first) {
		dd -= u2.second;
	}
	ans = max(0.0,dd);
	while(true) {
		if (ns[now] == u2.first) {
			dd += u2.second;
		}
		u2.second = 0.0;
		if (ns[now2] == u1) {
			dd += len[u1];
			now2++;
		}
		r -= len[u1];
		u1++;
		if (u1 > n) {
			break;
		}
		while(((r + len[u2.first]) <= l) and (dd > 0.0)) {
			r += len[u2.first];
			if (ns[now] == u2.first) {
				dd -= len[u2.first];
				now++;
			}
			u2.first++;
			if (u2.first > n) {
				u2.first = 0;
				now = 0;
			}
		}
		u2.second = l-r;
		if (ns[now] == u2.first) {
			dd -= l-r;
		}
		ans = min(max(0.0,dd),ans);
		if (ans == 0.0) {
			break;
		}
	}
	cout << ans;
}