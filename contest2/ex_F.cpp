#include <iostream>
#include <vector>

using namespace std;

int main() {
    // кол-во сегментов на колесе
    int n;
    cin >> n;
    vector<int> segments(n);
    int max_ = -1;
    for (int i = 0; i < n; ++i) {
        cin >> segments[i];
        max_ = max(max_,segments[i]);
    }

    int v_min, v_max, k;
    cin >> v_min >> v_max >> k;

    int ans = 0;
    for (int v = v_min; v <= v_max; v+=k) {
        int v1,v2 = segments[0];
        if (v % k) {
            int tmp = (v / k) % n;
            v1 = segments[tmp];
            if (tmp)
                v2 = segments[n-tmp];
        }
        else {
            int tmp = (v / k -1) % n;
            v1 = segments[tmp];
            if (tmp)
                v2 = segments[n-tmp];
        }

        int best = max(v1,v2);
        ans = max(ans,best);
        if (ans == max_)
            break;
        // cout << v << ' ' << v/k << ' ' << best << endl;
    }

    cout << ans;
    return 0;
}
