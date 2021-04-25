#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

struct segment_tree {
    vector<ll> t;
    ll len;
    segment_tree(vector<ll> a) {
        len = a.size();
        t = vector<ll>(a.size()*2);
        build(a, 1, 0, a.size()-1);
    }
    void build(vector<ll>& a, ll v, ll l, ll r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        ll mid = (l + r)/2;
        build(a, v*2, l, mid);
        build(a, v*2+1, mid+1, r);
        t[v] = t[v*2] + t[v*2+1];
    }
    ll get_sum(ll l, ll r) {
        return get_sum_help(1, 0, len - 1, l, r);
    }
    ll get_sum_help(ll v, ll vl, ll vr, ll l, ll r) {
        if ((vr < l) || (vl > r)) {
            return 0;
        }
        if ((vl >= l) && (vr <= r)) {
            return t[v];
        }
        ll mid = (vl+vr)/2;
        return get_sum_help(v*2, vl, mid, l, r) + get_sum_help(v*2+1, mid+1, vr, l, r);
    }
    void change(ll p, ll x) {
        change_help(1, 0, len - 1, p, x);
    }
    void change_help(ll v, ll l, ll r, ll p, ll x) {
        if ((p < l) || (p > r)) {
            return;
        }
        if (l == r) {
            t[v] = x;
            return;
        }
        ll mid = (l+r)/2;
        change_help(v*2, l, mid, p, x);
        change_help(v*2+1, mid+1, r, p, x);
        t[v] = t[v*2] + t[v*2+1];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll len;
	cin >> len;
	vector<ll> a(len);
	for (ll i = 0; i < len; i++) {
        cin >> a[i];
	}
	segment_tree t(a);
	ll col;
	cin >> col;
    for (ll i = 0; i < col; i++) {
        ll l, r;
        cin >> l >> r;
        cout << t.get_sum(l - 1, r - 1) << "\n";
    }
}
