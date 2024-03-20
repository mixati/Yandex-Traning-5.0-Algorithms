#include <iostream>
#include <cmath>
#include <limits.h>

using namespace std;

int v_1(int x, int y, int p) {
    int count = 1;
    int defenders = p;
    // count - кол-во ходов
    // defenders - кол-во защищающих солдат в данный момент

    y -= x; // первый круг
    if (y <= 0)
        return 1;
    double fib = 1.6180339887;
    while (x > 0 && (y > 0 || defenders > 0)) {
        if (x >= y && fib*x > (double)(defenders+y)) {
            defenders -= (x-y);
            y = 0;
        }
        else if (x > defenders) {
            y -= (x-defenders);
            defenders = 0;
        }

        x -= defenders;
        if (y > 0)
            defenders += p;
        ++count;
    }

    if (x > 0)
        return count;
    return INT_MAX;
}
int v_2(int x, int y, int p) {
    int count = 1;
    int defenders = p;
    // count - кол-во ходов
    // defenders - кол-во защищающих солдат в данный момент

    y -= x; // первый круг
    if (y <= 0)
        return 1;
    double fib = 1.6180339887;

    bool flag = false;
    while (x > 0 && (y > 0 || defenders > 0)) {
        if (flag) {
            defenders -= (x-y);
            y = 0;
        }
        else if (x >= y && fib*x > (double)(defenders+y)) {
            flag = true;
            y -= (x-defenders);
            defenders = 0;
        }
        else if (x > defenders) {
            y -= (x-defenders);
            defenders = 0;
        }

        x -= defenders;
        if (y > 0)
            defenders += p;
        ++count;
    }

    if (x > 0)
        return count;
    return INT_MAX;
}

int main() {
    int x, y, p;
    // x - кол-во ваших солдат
    // y - кол-во очков здоровья казармы
    // p - кол-во производимых за раунд казармой солдат
    cin >> x >> y >> p;

    int a1 = v_1(x,y,p);
    int a2 = v_2(x,y,p);
    if (a1 != INT_MAX || a2 != INT_MAX)
        cout << min(a1, a2);
    else
        cout << -1;

    return 0;
}