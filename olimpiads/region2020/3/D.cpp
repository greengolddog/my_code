#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int mvv (int x1, int y1, int x2, int y2) {
	if ((x1 < x2 and y1 < y2 and x2 < y1) or (x2 < x1 and y2 < y1 and x1 < y2)) {
		return 1;
	} else {
		return 0;
	}
}

int rec (vector<pair<int, pair<int, int>>>& arr, int cv) {
	vector<pair<int, pair<int, int>>> vec;
	int nx, ny, maxx = 0;
	for (auto i : arr) {
		if (i.second.second == cv) {
			nx = i.first;
			ny = i.second.first;
		}
	}
	for (auto i : arr) {
		if (mvv(nx, ny, i.first, i.second.first) == 1) {
			vec.push_back(i);
		}
	}
	while (vec.size() > 0) {
		maxx = max(rec(vec, vec[vec.size()-1].second.second),maxx);
		vec.pop_back();
	}
	return maxx + 1;
}

int main() {
	int n, k, mu;
	cin >> n;
	vector<int> m(n,0);
	vector<pair<int, pair<int, int>>> arr(n, {0,{0,0}});
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second.first;
		arr[i].second.second = i;
	}
	sort(arr.begin(), arr.end());
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> mu;
		if (m[mu-1] == 0) {
			m[mu-1] = rec(arr,mu-1);
		}
		cout << m[mu-1] << endl;
	}
}