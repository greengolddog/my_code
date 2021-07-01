#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned long long ull;

using namespace std;

ll sleep() {
    return 0;
}

struct segment_tree {
    vector<ll> t;
    vector<ll> p;
    ll len;
    segment_tree(vector<ll> a) {
        len = a.size();
        p.resize(a.size()*4, -1);
        t.resize(a.size()*4, 0);
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
        t[v] = max(t[v*2], t[v*2+1]);
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
        push(v);
        return max(get_sum_help(v*2, vl, mid, l, r), get_sum_help(v*2+1, mid+1, vr, l, r));
    }
    void push(ll v) {
        if (p[v] != -1) {
            (v*2 < len ? t[v*2] = max(p[v], t[v*2]) : sleep());
            (v*2+1 < len ? t[v*2+1] = max(p[v], t[v*2+1]) : sleep());
            p[v] = -1;
        }
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
        push(v);
        change_help(v*2, l, mid, p, x);
        change_help(v*2+1, mid+1, r, p, x);
        t[v] = max(t[v*2], t[v*2+1]);
    }
    void mass_change(ll l, ll r, ll x) {
        mass_change_help(1, 0, len - 1, l, r, x);
    }
    void mass_change_help(ll v, ll vl, ll vr, ll l, ll r, ll x) {
        if ((vr < l) || (vl > r)) {
            return;
        }
        if ((vl >= l) && (vr <= r)) {
            t[v] = max(x, t[v]);
            p[v] = x;
            return;
        }
        ll mid = (vl+vr)/2;
        push(v);
        mass_change_help(v*2, vl, mid, l, r, x);
        mass_change_help(v*2+1, mid+1, vr, l, r, x);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, m;
    cin >> n >> m;
    vector<ll> summ(n+1, 0);
    segment_tree st(vector<ll>(n, 0));
    for (ll i = 0; i < m; i++) {
        ll s, f;
        cin >> s >> f;
        s--;
        f--;
        ll su = st.get_sum(s, f);
        if (su > f-s+1) {
            summ[su] += f-s+1;
            summ[f-s+2] -= f-s+1;
            st.mass_change(s, f, f-s+1);
        }
    }
    ll now = 0;
    for (ll i = 0; i < n; i++) {
        now += summ[i];
        cout << now << endl;
    }
}
