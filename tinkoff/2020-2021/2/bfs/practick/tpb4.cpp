#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define vecotr vector
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, mina = 10000000;
    cin >> n >> m;
    vector<vector<ll>> arr(n*m, vector<ll>(0, 0)), arr2(n + 1, vector<ll>(m + 1, 1));
    vector<ll> dist(n*m, -1);
    queue<ll> q;
    for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			cin >> arr2[i][j];
        }
    }
    for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
            if (arr2[i][j] != 1) {
                for (ll c = 1; c <= (i + 1); c++) {
                    if ((c > i) || (arr2[i - c][j] == 1)) {
                        // cout << i << ' ' << j << ' ' << i - c + 1 << ' ' << j << endl;
                        arr[i * m + j].push_back((i - c + 1) * m + j);
                        if ((arr2[i + 1][j] == 1) || (arr2[i][j] == 2)) {
                            // cout << i - c + 1 << ' ' << j << ' ' << i << ' ' << j << endl;
                            arr[(i - c + 1) * m + j].push_back(i * m + j);
                        }
                        break;
                    }
                    if ((arr2[i + 1][j] == 1) || (arr2[i][j] == 2)) {
                        // cout << i - c << ' ' << j << ' ' << i << ' ' << j << endl;
                        arr[(i - c) * m + j].push_back(i * m + j);
                    }
                    if (arr2[i - c][j] == 2) {
                        // cout << i << ' ' << j << ' ' << i - c << ' ' << j << endl;
                        arr[i * m + j].push_back((i - c) * m + j);
                    }
                }
                for (ll c = 1; c <= (j + 1); c++) {
                    if ((c > j) || (arr2[i][j - c] == 1)) {
                        // cout << i << ' ' << j << ' ' << i << ' ' << j - c + 1 << endl;
                        arr[i * m + j].push_back(i * m + j - c + 1);
                        if ((arr2[i][j + 1] == 1) || (arr2[i][j] == 2)) {
                            // cout << i << ' ' << j - c + 1 << ' ' << i << ' ' << j << endl;
                            arr[i * m + j - c + 1].push_back(i * m + j);
                        }
                        break;
                    }
                    if ((arr2[i][j + 1] == 1) || (arr2[i][j] == 2)) {
                        // cout << i << ' ' << j - c << ' ' << i << ' ' << j << endl;
                        arr[i * m + j - c].push_back(i * m + j);
                    }
                    if (arr2[i][j - c] == 2) {
                        // cout << i << ' ' << j << ' ' << i << ' ' << j - c << endl;
                        arr[i * m + j].push_back(i * m + j - c);
                    }
                }
            }
		}
	}
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
	    ll v = q.front();
	    q.pop();
	    for (auto i : arr[v]) {
            // cout << v / n << ' ' << v % n << ' ' << i / n  << ' ' << i % n << ' ' << 55555 << endl;
	        if (dist[i] == -1) {
                // cout << v / m << ' ' << v % m  << ' ' << i / m  << ' ' << i % m << ' ' << dist[v] + 1 << endl;
		        dist[i] = dist[v] + 1;
		        q.push(i);
	        }
        }
    }
    for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (arr2[i][j] == 2) {
                // cout << i << ' ' << j << ' ' << dist[i * m + j] << ' ' << i * m + j << endl;
                if (dist[i * m + j] != -1) {
                    mina = min(mina, dist[i * m + j]);
                }
            }
        }
    }
	cout << mina;
}
