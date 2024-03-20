#include <iostream>

using namespace std;

int counter(int& Qmin, int& Qmax, int& Pmin, int& Pmax) {
    int ans;
    if (Qmin >= Pmin && Qmax <= Pmax)
        ans = Pmax - Pmin + 1;
    else if (Qmin <= Pmin && Qmax <= Pmax && Qmax >= Pmin)
        ans = Pmax - Qmin + 1;
    else if (Qmax < Pmin)
        ans = Qmax - Qmin + Pmax - Pmin + 2;
    else
        return counter(Pmin, Pmax, Qmin, Qmax);
    
    return ans;
}

int main() {
    int P, V, Q, M;
    cin >> P >> V >> Q >> M;

    int Pmin = P - V,
        Pmax = P + V,
        Qmin = Q - M,
        Qmax = Q + M;
    
    cout << counter(Qmin, Qmax, Pmin, Pmax);

    return 0;
}