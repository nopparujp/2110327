#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> intervals(N);
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].second;
    }
    for (int i = 0; i < N; ++i) {
        cin >> intervals[i].first;
    }

    sort(intervals.begin(), intervals.end());
    int count = 1;
    int current_finish = intervals[0].first;

    for (const auto &interval : intervals) {
        if (interval.second >= current_finish) {
            ++count;
            current_finish = interval.first;
        }
    }

    cout << count << endl;
}
