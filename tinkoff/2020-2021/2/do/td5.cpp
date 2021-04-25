#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

struct segment_tree {
    vector<pair<ll, ll>> t;
    ll len;
    segment_tree(vector<ll> a = vector<ll>(1, 0)) {
        len = a.size();
        t.resize(a.size() * 4, {0, 0});
        build(a, 1, 0, a.size()-1);
    }
    void build(vector<ll>& a, ll v, ll l, ll r) {
        if (l == r) {
            t[v] = {a[l], l};
            return;
        }
        ll mid = (l + r)/2;
        build(a, v*2, l, mid);
        build(a, v*2+1, mid+1, r);
        t[v] = max(t[v*2], t[v*2+1]);
    }
    ll get_max(ll l, ll r) {
        return get_max_help(1, 0, len-1, l, r).second + 1;
    }
    pair<ll, ll> get_max_help(ll v, ll vl, ll vr, ll l, ll r) {
        if ((vr < l) || (vl > r)) {
            return {-100000000000, 0};
        }
        if ((vl >= l) && (vr <= r)) {
            return t[v];
        }
        ll mid = (vl+vr)/2;
        return max(get_max_help(v*2, vl, mid, l, r), get_max_help(v*2+1, mid+1, vr, l, r));
    }
    void change(ll p, ll x) {
        change_help(1, 0, len-1, p, x);
    }
    void change_help(ll v, ll l, ll r, ll p, ll x) {
        if ((p < l) || (p > r)) {
            return;
        }
        if (l == r) {
            t[v] = {x, t[v].second};;
            return;
        }
        ll mid = (l+r)/2;
        change_help(v*2, l, mid, p, x);
        change_help(v*2+1, mid+1, r, p, x);
        t[v] = max(t[v*2], t[v*2+1]);
    }
    ll descend_for_max(ll l, ll r, ll k) {
        return descend_for_max_help(1, 0, len-1, l, r, k);
    }
    ll descend_for_max_help(ll v, ll vl, ll vr, ll l, ll r, ll k) {
        if (vl == vr) {
            return t[v].second;
        }
        ll mid = (vl+vr)/2;
        if (get_max_help(v*2, vl, mid, l, r).first < k) {
            return descend_for_max_help(v*2+1, mid+1, vr, l, r, k);
        }
        return descend_for_max_help(v*2, vl, mid, l, r, k);
    }
    friend istream& operator>> (istream& inp, segment_tree& p);
};

istream& operator>> (istream& inp, segment_tree& p) {
    ll len;
    inp >> len;
    vector<ll> a(len);
    for (ll i = 0; i < len; i++) {
        inp >> a[i];
    }
    p = segment_tree(a);
    return inp;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("nearandmore.in", "r", stdin);
	freopen("nearandmore.out", "w", stdout);
	ll len;
	cin >> len;
	ll col;
    cin >> col;
	vector<ll> a(len);
	for (ll i = 0; i < len; i++) {
        cin >> a[i];
	}
	segment_tree t(a);
    for (ll i = 0; i < col; i++) {
        ll s;
        ll l, r;
        cin >> s >> l >> r;
        if (s == 1) {
            ll num = t.descend_for_max(l - 1, t.len - 1, r);
            if (a[num] < r) {
                cout << -1 << "\n";
            } else {
                cout << num + 1 << "\n";
            }
        } else {
            t.change(l - 1, r);
            a[l - 1] = r;
        }
    }
}
