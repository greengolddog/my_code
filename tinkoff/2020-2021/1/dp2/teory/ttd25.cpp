#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, m, nm, mcp, nmcp, ni, nj, c;
    cin >> n >> m;
    mcp = -1;
    nmcp = 0;
    vector<long long> arr2(n + 1);
    vector<long long> arr3(n + 1);
    for (long long i = 1; i <= n; i++) {
	cin >> arr2[i];
    }
    for (long long i = 1; i <= n; i++) {
	cin >> arr3[i];
    }
    vector<vector<pair<ll, ll>>> arr(n + 1, vector<pair<ll, ll>>(m + 1, {0, 0}));
    arr[0][0] = {1, 0};
    for (long long i = 1; i <= n; i++) {
	for (long long j = 0; j <= m; j++) {
	    if ((j - arr2[i]) >= 0) {
		arr[i][j].first = max(arr[i-1][j-arr2[i]].first, arr[i-1][j].first);
		if (arr[i-1][j-arr2[i]].first == 1) {
		    arr[i][j].second = max((arr[i-1][j-arr2[i]].second) + arr3[i], arr[i-1][j].second);
		    if (arr[i][j].second > mcp) {
			mcp = arr[i][j].second;
			nmcp = j;
		    }
		} else {
		    arr[i][j].second = arr[i-1][j].second;
		}
	    } else {
		arr[i][j].first = arr[i-1][j].first;
		arr[i][j].second = arr[i-1][j].second;
	    }
	}
    }
    ni = n;
    nj = nmcp;
    c = 0;
    while (nj != 0) {
	if ((nj - arr2[ni]) >= 0) {
	    if (((arr[ni-1][nj-arr2[ni]].second) + arr3[ni]) > arr[ni-1][nj].second) {
		c += 1;
		nj -= arr2[ni];
	    }
	}
	ni--;
    }
    cout << c << endl;
    ni = n;
    nj = nmcp;
    while (nj != 0) {
	if ((nj - arr2[ni]) >= 0) {
	    if (((arr[ni-1][nj-arr2[ni]].second) + arr3[ni]) > arr[ni-1][nj].second) {
		c += 1;
		nj -= arr2[ni];
		cout << ni << ' ';
	    }
	}
	ni--;
    }
}
