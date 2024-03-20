#include <iostream>
#include <limits.h>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);

    double L, x1, v1, x2, v2;
    cin >> L >> x1 >> v1 >> x2 >> v2;

    double x_both = (x1 + x2) / 2 ;
    double v_both = (v1+v2) / 2 ;
    double ans = LLONG_MAX;

    // сначала рассмотрели все варианты, 
    // когда участники оказались на одинаковом
    // расстоянии от старта, но в разных точках
    
    if (x_both == (double)0 || x_both == L/2 || x1 == x2 || x1 == L-x2)
        ans = 0;
    else if (v1 == 0 && v2 == 0) {
        cout << "NO";
        return 0;
    }
    else if (x_both > 0 && v_both > 0) {
        if (x_both > L/2)
            ans = (L-x_both) / v_both;
        else if (x_both < L/2)
            ans = (L/2-x_both) / v_both;
    }
    else if (x_both > 0 && v_both < 0) {
        if (x_both < L/2)
            ans = -x_both / v_both;
        else if (x_both > L/2)
            ans = (L/2-x_both) / v_both;
    }

    // теперь рассмотрим ситуацию, когда участники оказались в одной точке

    double var_2 = LLONG_MAX;
    if (v1 != v2) {
        if (v2 > v1 && x1 > x2)
            var_2 = (x1-x2) / (v2-v1);
        else if (v1 > v2 && x2 > x1)
            var_2 = (x2-x1)/(v1-v2);
        else if (v2 > v1 && x2 > x1)
            var_2 = -(L-x2+x1)/(v1-v2);
        else if (v1 > v2 && x1 > x2)
            var_2 = -(L-x1+x2)/(v2-v1);
    }

    ans = min(ans,var_2);

    cout << "YES\n" << ans;

    return 0;
}
