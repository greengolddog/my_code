#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m,0));
	vector<int> count(m, 0);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			char c;
			cin >> c;
			a[i][j] = c - '0';
			if (a[i][j] == 1){
				count[j]++;
			}
		}
	}
	for (int i = 0; i < n; i++){
		bool check = false;
		for (int j = 0; j < m; j++){
			if (a[i][j]){
				count[j]--;
			}
			if (count[j] == 0){
				check = true;
				break;
			}
		}
		for (int j = 0; j < m; j++){
			count[j] += a[i][j];
		}
		if (!check){
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0
}
