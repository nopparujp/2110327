#include <bits/stdc++.h>
#include <iomanip>
#include <queue>
using namespace std;
#define pdd pair<double, double>
#define vpdd vector<pair<double, double>>
#define t tuple<double, int, double, double>
int n;
vpdd v;
double mp(int s, double limit) {
    double mx = 0;
    for (int i = s; i < n; ++i) {
        if (v[i].second > limit)
            return mx + limit * (v[i].first / v[i].second);
        limit -= v[i].second;
        mx += v[i].first;
    }
    return mx;
}
int main() {
    double weight, mxp = 0;
    cin >> weight >> n;
    v = vpdd(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].first;
    }
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
    }
    sort(v.begin(), v.end(), [](auto &l, auto &r) {
        return l.first / l.second > r.first / r.second;
    });
    // bound state sump sumw
    class comp {
      public:
        bool operator()(t l, t r) { return get<0>(l) < get<0>(r); }
    };
    priority_queue<t, vector<t>, comp> pq;
    pq.push({mp(0, weight), 0, 0, 0});
    while (!pq.empty()) {
        auto [ub, s, sp, sw] = pq.top();
        pq.pop();
        if (s == n) {
            mxp = max(mxp, sp);
        } else {
            pq.push({mp(s + 1, weight - sw) + sp, s + 1, sp, sw});
            if (sw + v[s].second < weight)
                pq.push({mp(s + 1, weight - sw - v[s].second) + sp + v[s].first,
                         s + 1, sp + v[s].first, sw + v[s].second});
        }
        if (ub < mxp) {
            cout << fixed << setprecision(4) << mxp << "\n";
            return 0;
        }
    }
}