#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string str, s;
    ll end, start;
    char z;
    cin >> start;
    cin >> end;
    vector<vector<ll>> arr(10000, vector<ll>(0, 0));
    for (ll i = 1111; i < 10000; i++) {
	    str = to_string(i);
        if ((str[0] != '0') && (str[1] != '0') && (str[2] != '0') && (str[3] != '0')) {
            if (str[0] != '9') {
                s = str;
                s[0] = s[0]+1;
                arr[stoi(str)].push_back(stoi(s));
            }
            if (str[3] != '1') {
                s = str;
                s[3] = s[3]-1;
                arr[stoi(str)].push_back(stoi(s));
            }
            s = str;
            z = s[0];
            s[0] = s[1];
            s[1] = s[2];
            s[2] = s[3];
            s[3] = z;
            if (s != str) {
                arr[stoi(str)].push_back(stoi(s));
            }
            s = str;
            z = s[3];
            s[3] = s[2];
            s[2] = s[1];
            s[1] = s[0];
            s[0] = z;
            if (s != str) {
                arr[stoi(str)].push_back(stoi(s));
            }
        }
    }
    vector<ll> dist(10000, -1);
    vector<ll> pred(10000, -1);
    dist[start] = 0;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
	    ll v = q.front();
	    q.pop();
	    for (auto i : arr[v]) {
	        if (dist[i] == -1) {
                pred[i] = v;
		        dist[i] = dist[v] + 1;
		        q.push(i);
	        }
        }
    }
    ll now = end;
    vector<ll> ans(1, now);
    while (pred[now] != -1) {
        ans.push_back(pred[now]);
        now = pred[now];
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans) {
        cout << i << endl;
    }
}
