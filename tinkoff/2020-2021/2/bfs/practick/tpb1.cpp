#include <bits/stdc++.h>
#define ll long long
#define elif else if
#define vecotr vector
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, m, x1, x2, y1, y2;
    char a;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    vector<vector<ll>> arr(n*m, vector<ll>(0, 0)), arr2(n + 2, vector<ll>(m + 2, 0));
	vector<pair<ll, ll>> ar(1, {-1, 0});
	map<ll, char> ma;
	ma[m] = 'S';
	ma[1ll] = 'E';
	ma[-1ll] = 'W';
	ma[-m] = 'N';
	ar.push_back({1, 0});
	ar.push_back({0, 1});
	ar.push_back({0, -1});
    for (ll i = 1; i <= n; i++) {
	    for (ll j = 1; j <= m; j++) {
	        cin >> a;
	        if (a == '#') {
		    	arr2[i][j] = 0;
	        } elif(a == '.') {
		        arr2[i][j] = 1;
	        } elif(a == 'W') {
		        arr2[i][j] = 2;
	        }
	    }
    }
    for (ll i = 1; i <= n; i++) {
		for (ll j = 1; j <= m; j++) {
			for (auto k : ar) {
				if (arr2[i + k.first][j + k.second] == 1) {
					arr[(i - 1) * m + j - 1].push_back((i + k.first - 1) * m + j + k.second - 1);
					// cout << (i - 1) * m + j - 1 << ' ' << (i + k.first - 1) * m + j + k.second - 1 << endl;
				} elif(arr2[i + k.first][j + k.second] == 2) {
					arr[(i - 1) * m + j - 1].push_back(arr.size());
					arr.push_back(vector<ll>(1, (i + k.first - 1) * m + j + k.second - 1));
					// cout << (i - 1) * m + j - 1 << ' ' << arr.size() - 1 << ' ' << (i + k.first - 1) * m + j + k.second - 1 << endl;
				}
			}
		}
    }
	arr2 = vector<vector<ll>>(0, vector<ll>(0, 0));
	arr2.push_back(vector<ll>(arr.size(), -1));
	arr2.push_back(vector<ll>(arr.size(), -1));
	// cout << arr2[0][24] << endl;
    arr2[0][(x1 - 1) * m + y1 - 1] = 0;
    queue<ll> q;
    q.push((x1 - 1) * m + y1 - 1);
    while (!q.empty()) {
	    ll v = q.front();
		// cout << v << endl;
	    q.pop();
	    for (auto i : arr[v]) {
	        if (arr2[0][i] == -1) {
                arr2[1][i] = v;
		        arr2[0][i] = arr2[0][v] + 1;
		        q.push(i);
	        }
        }
    }
	arr.clear();
	cout << arr2[0][(x2 - 1) * m + y2 - 1] << endl;
    ll now = (x2 - 1) * m + y2 - 1;
	if (arr2[0][(x2 - 1) * m + y2 - 1] != -1) {
		arr2[0].clear();
		vector<ll> ans(1, now);
		while (arr2[1][now] != -1) {
			if (arr2[1][now] < m*n) {
				ans.push_back(arr2[1][now]);
			}
			now = arr2[1][now];
		}
		reverse(ans.begin(), ans.end());
		for (ll i = 1; i < ans.size(); i++) {
			ll no = (ans[i] - ans[i - 1]);
			cout << ma[no];
		}
	}
}
