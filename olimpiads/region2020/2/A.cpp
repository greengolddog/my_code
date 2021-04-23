#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	int n,m,maxi = -100000,mini = 100000,ans=-10000000;
	cin >> n >> m;
	char a;
	vector<int> str(n,0),stb(m,0);
	vector<vector<int>> sp(n,vector<int>(0,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			if (a == '-') {
				str[i] -= 1;
				stb[j] -= 1;
			} elif (a == '?') {
				str[i] += 1;
				stb[j] -= 1;
				sp[i].push_back(j);
			} else {
				str[i] += 1;
				stb[j] += 1;
			}
		}
		maxi = max(maxi,str[i]);
	}
	multiset<int> stbn;
	for (int j = 0; j < m; j++) {
		mini = min(mini,stb[j]);
		stbn.insert(stb[j]);
	}
	vector<pair<int,int>> strn;
	for (int i = 0; i < n; i++) {
		strn.push_back({str[i],i});
	}
	for (auto i : strn) {
		for (auto j : sp[i.second]) {
			stbn.erase(stbn.find(stb[j]));
			stb[j] += 2;
			stbn.insert(stb[j]);
		}
		ans = max(ans,i.first-(*stbn.begin()));
		for (auto j : sp[i.second]) {
			stbn.erase(stbn.find(stb[j]));
			stb[j] -= 2;
			stbn.insert(stb[j]);
		}
	}
	cout << ans;
}