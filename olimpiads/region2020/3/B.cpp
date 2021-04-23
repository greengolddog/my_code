#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;
vector<vector<int>> arr;
vector<vector<int>> arr2;
int n, m;

int rec(int x, int y, int maxr2) {
	int maxr = maxr2;
	if ((x-1 >= 0) and (arr[x-1][y] == 0) and ((arr2[x-1][y]-1) == arr2[x][y])) {
		arr[x-1][y] = 1;
		maxr = max(maxr, rec(x-1,y,maxr2+1));
	}
	if ((y-1 >= 0) and (arr[x][y-1] == 0) and ((arr2[x][y-1]-1) == arr2[x][y])) {
		arr[x][y-1] = 1;
		maxr = max(maxr, rec(x,y-1,maxr2+1));
	}
	if ((x+1 < n) and (arr[x+1][y] == 0) and ((arr2[x+1][y]-1) == arr2[x][y])) {
		arr[x+1][y] = 1;
		maxr = max(maxr, rec(x+1,y,maxr2+1));
	}
	if ((y+1 < m) and (arr[x][y+1] == 0) and ((arr2[x][y+1]-1) == arr2[x][y])) {
		arr[x][y+1] = 1;
		maxr = max(maxr, rec(x,y+1,maxr2+1));
	}
	return maxr;
}

int main() {
	int c, maxr = 1;
	cin >> n >> m;
	arr = vector<vector<int>>(n, vector<int>(m,0));
	arr2 = arr;
	vector<pair<int,pair<int,int>>> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr2[i][j] = c;
			s.push_back({c,{i,j}});
		}
	}
	sort(s.begin(), s.end());
	for (auto i : s) {
		if (arr[i.second.first][i.second.second] == 0) {
			arr[i.second.first][i.second.second] = 1;
			maxr = max(maxr, rec(i.second.first,i.second.second,1));
		}
	}
	cout << maxr;
}