#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n, m, t, s1, s2, sp;
    cin >> t >> n;
    sp = 0;
    vector<pair<pair<long long, long long>, long long>> arr;
    map<long long, long long> arrv0, arrv1;
    for (long long i = 0; i < n; i++) {
	cin >> s1 >> s2;
	arr.push_back({{s1, s2 + t}, 0});
    }
    cin >> m;
    for (long long i = 0; i < m; i++) {
	cin >> s1 >> s2;
	arr.push_back({{s1, s2 + t}, 1});
    }
    sort(arr.begin(), arr.end());
    for (long long i = 0; i < (m + n); i++) {
	if (arr[i].second == 0) {
	    auto it = arrv1.begin();
	    if ((it == arrv1.end()) or ((*it).first > arr[i].first.first)) {
		sp++;
	    } else {
		arrv1[(*it).first] -= 1;
		if (arrv1[(*it).first] == 0) {
		    arrv1.erase(it);
		}
	    }
	    if (arrv0.find(arr[i].first.second) == arrv0.end()) {
		arrv0[arr[i].first.second] = 0;
	    }
	    arrv0[arr[i].first.second] += 1;
	}
	if (arr[i].second == 1) {
	    auto it = arrv0.begin();
	    if ((it == arrv0.end()) or ((*it).first > arr[i].first.first)) {
		sp++;
	    } else {
		arrv0[(*it).first] -= 1;
		if (arrv0[(*it).first] == 0) {
		    arrv0.erase(it);
		}
	    }
	    if (arrv1.find(arr[i].first.second) == arrv1.end()) {
		arrv1[arr[i].first.second] = 0;
	    }
	    arrv1[arr[i].first.second] += 1;
	}
    }
    cout << sp;
}

