#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll col(vector<vector<ll>>& arr, ll a, ll b) {
	if (arr[a][b] == -1) {
		return 1;
	}
	return col(arr, a, arr[a][b])+col(arr, arr[a][b], b);
}

void p(vector<vector<ll>>& arr, ll a, ll b) {
	if (arr[a][b] == -1) {
		cout << a+1 << ' ';
		return;
	}
	p(arr, a, arr[a][b]);
	p(arr, arr[a][b], b);
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	const ll INF = 1000000000000000, MAXN = 100000;
	ll n;
	cin >> n;
	vector<vector<ll>> arr(n, vector<ll>(n, INF)), parent(n, vector<ll>(n, -1));
	for (ll i = 0; i < n; i++) {
		arr[i][i] = 0;
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			ll m;
			cin >> m;
			if (m != MAXN) {
				arr[i][j] = min(arr[i][j], m);
				if (i == j && m < 0) {
					cout << "YES\n";
					cout << 1 << '\n';
					cout << i+1;
					return 0;
				}
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll a = 0; a < n; a++) {
			for (ll b = 0; b < n; b++) {
				if (arr[a][i]+arr[i][b] < arr[a][b]) {
					parent[a][b] = i;
				}
				arr[a][b] = min(arr[a][b], arr[a][i]+arr[i][b]);
				if ((a == b) && (arr[a][b] < 0)) {
					cout << "YES\n";
					cout << col(parent, a, b) << '\n';
					p(parent, a, b);
					cout << b << endl;
					return 0;
				}
			}
		}
	}
	cout << "NO";
}
