#include <bits/stdc++.h>
#define ll long long
#define elif else if
using namespace std;

int main() {
	int n,m,ml=0, minl=10000000, ml1=0, ml2=0, mv=0;
	cin >> n >> m;
	vector<vector<int>> nl(n,vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> nl[i][j];
			ml = max(ml,nl[i][j]);
			minl = min(minl,nl[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			nl[i][j] -= minl;
			cout << nl[i][j] << ' ';
		}
		cout << endl;
	}
	cout << ml << ' ' << minl << endl;
	ml -= minl;
	vector<vector<vector<vector<int>>>> d(ml+1,vector<vector<vector<int>>>(ml+1,vector<vector<int>>(n+2,vector<int>(m+2,0))));
	for (int l1 = 0; l1 <= ml; l1++) {
		for (int l2 = 0; l2 <= ml; l2++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << l1 << ' ' << l2 << ' ' << i << ' ' << j << ' ';
					if ((nl[i][j] == l1) or (nl[i][j] == l2)) {
						d[l1][l2][i+1][j+1] = max(d[l1][l2][i][j+1],d[l1][l2][i+1][j])+1;
					} else {
						d[l1][l2][i+1][j+1] = 0;
					}
					if (d[l1][l2][i+1][j+1] >= mv) {
						mv = d[l1][l2][i+1][j+1];
						ml1 = l1;
						ml2 = l2;
					}
					cout << d[l1][l2][i+1][j+1] << endl;
				}
			}
		}
	}
	cout << mv << endl << ml1 << ' ' << ml2;
}