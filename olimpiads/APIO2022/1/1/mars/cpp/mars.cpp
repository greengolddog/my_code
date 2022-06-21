#include <bits/stdc++.h>
#include "mars.h"
typedef long long ll;
using namespace std;

void dfs(vector<vector<ll>>& arr, ll x, ll y, vector<vector<ll>>& color, ll lc) {
	color[x][y] = lc;
	ll n = arr.size();
	if (x + 1 < n && color[x + 1][y] == -1 && arr[x + 1][y] == 1) {
		dfs(arr, x + 1, y, color, lc);
	}
	if (y + 1 < n && color[x][y + 1] == -1 && arr[x][y + 1] == 1) {
		dfs(arr, x, y + 1, color, lc);
	}
	if (x - 1 >= 0 && color[x - 1][y] == -1 && arr[x - 1][y] == 1) {
		dfs(arr, x - 1, y, color, lc);
	}
	if (y - 1 >= 0 && color[x][y - 1] == -1 && arr[x][y - 1] == 1) {
		dfs(arr, x, y - 1, color, lc);
	}
}

std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n)
{
	if (n == 1) {
		ll now = 0;
		string ans(100, '0');
		vector<vector<ll>> color(n * 2 + 1, vector<ll>(n * 2 + 1, -1));
		vector<vector<ll>> arr(n * 2 + 1, vector<ll>(n * 2 + 1, -1));
		for (ll i = 0; i < 3; i++) {
			for (ll j = 0; j < 3; j++) {
				arr[i][j] = a[i][j][0] - '0';
			}
		}
		ll last = 0;
		for (ll i = 0; i < 3; i++) {
			for (ll j = 0; j < 3; j++) {
				if (color[i][j] == -1 && arr[i][j] == 1) {
					dfs(arr, i, j, color, last);
					last++;
				}
			}
		}
		while (last > 0) {
			ans[now] = to_string(last % 2)[0];
			last /= 2;
		       	now++;
		}
		return ans;
	}
	if (i == 2 && j == 2) {
		string ans(100, '0');
		ans[0] = a[0][0][0];
		ans[1] = a[0][1][0];
		ans[2] = a[0][2][0];
		ans[3] = a[1][0][0];
		ans[4] = a[1][1][0];
		ans[5] = a[1][2][0];
		ans[6] = a[2][0][0];
		ans[7] = a[2][1][0];
		ans[8] = a[2][2][0];
		return ans;
	}
	if (i == 0 && j == 2) {
		string ans(100, '0');
		ans[0] = a[0][0][0];
		ans[1] = a[0][1][0];
		ans[2] = a[0][2][0];
		ans[3] = a[1][0][0];
		ans[4] = a[1][1][0];
		ans[5] = a[1][2][0];
		return ans;
	}
	if (i == 2 && j == 0) {
		string ans(100, '0');
		ans[0] = a[0][0][0];
		ans[1] = a[0][1][0];
		ans[2] = a[1][0][0];
		ans[3] = a[1][1][0];
		ans[4] = a[2][0][0];
		ans[5] = a[2][1][0];
		return ans;
	}
	if (k == 1) {
		ll now = 0;
		string ans(100, '0');
		vector<vector<ll>> color(n * 2 + 1, vector<ll>(n * 2 + 1, -1));
		vector<vector<ll>> arr(n * 2 + 1, vector<ll>(n * 2 + 1, -1));
		for (ll i = 0; i < 2; i++) {
			for (ll j = 0; j < 2; j++) {
				arr[i][j] = a[i][j][0] - '0';
			}
		}
		arr[0][2] = a[0][2][0];
		arr[0][3] = a[0][2][1];
		arr[0][4] = a[0][2][2];
		arr[1][2] = a[0][2][3];
		arr[1][3] = a[0][2][4];
		arr[1][4] = a[0][2][5];
		arr[2][2] = a[2][2][0];
		arr[2][3] = a[2][2][1];
		arr[2][4] = a[2][2][2];
		arr[3][2] = a[2][2][3];
		arr[3][3] = a[2][2][4];
		arr[3][4] = a[2][2][5];
		arr[4][2] = a[2][2][6];
		arr[4][3] = a[2][2][7];
		arr[4][4] = a[2][2][8];
		arr[2][0] = a[2][0][0];
		arr[3][0] = a[2][0][1];
		arr[4][0] = a[2][0][2];
		arr[2][1] = a[2][0][3];
		arr[3][1] = a[2][0][4];
		arr[4][1] = a[2][0][5];
		ll last = 0;
		for (ll i = 0; i < 5; i++) {
			for (ll j = 0; j < 5; j++) {
				if (color[i][j] == -1 && arr[i][j] == 1) {
					dfs(arr, i, j, color, last);
					last++;
				}
			}
		}
		while (last > 0) {
			ans[now] = to_string(last % 2)[0];
			last /= 2;
		       	now++;
		}
		return ans;
	}
	return a[0][0];
}
