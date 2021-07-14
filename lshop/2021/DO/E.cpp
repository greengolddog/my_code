#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct f_tree {
	vector<vector<vector<ll>>> arr;
	ll s;
	f_tree(ll n): s(n) {
		arr.resize(n, vector<vector<ll>>(n, vector<ll>(n, 0)));
	}
	void add(ll x, ll y, ll z, ll n) {
		ll oy = y, oz = z;
		for (; x < s; x |= x+1) {
			for (; y < s; y |= y+1) {
				for (; z < s; z |= z+1) {
					arr[x][y][z] += n;
				}
				z = oz;
			}
			y = oy;
		}
	}
	ll get(ll x, ll y, ll z) {
		ll ans = 0;
		ll oy = y, oz = z;
		for (; x >= 0; x = (x&(x+1))-1) {
			for (; y >= 0; y = (y&(y+1))-1) {
				for (; z >= 0; z = (z&(z+1))-1) {
					ans += arr[x][y][z];
				}
				z = oz;
			}
			y = oy;
		}
		return ans;
	}
	ll get(ll x1, ll x2, ll y1, ll y2, ll z1, ll z2) {
		return get(x2, y2, z2) - get(x2, y2, z1-1) - get(x2, y1-1, z2) - get(x1-1, y2, z2) + get(x1-1, y1-1, z2) + get(x1-1, y2, z1-1) + get(x2, y1-1, z1-1) - get(x1-1, y1-1, z1-1);
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);
	ll n;
	cin >> n;
	f_tree t(n);
	ll c;
	cin >> c;
	while (c != 3) {
		if (c == 1) {
			ll x, y, z, k;
			cin >> x >> y >> z >> k;
			t.add(x, y, z, k);
		} else {
			ll x1, x2, y1, y2, z1, z2;
			cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << t.get(x1, x2, y1, y2, z1, z2) << '\n';
		}
		cin >> c;
	}
}
