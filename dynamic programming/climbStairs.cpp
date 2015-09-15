/* Copyright 2015 Edmund Liu

You are climbing a stair case. It takes n steps to reach to the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

#include <iostream>

using namespace std;

int climbStairs(int n) {
    int way0 = 0, way1 = 1, tmp;
    for (int i = 0; i < n; i++) {
        tmp = way1;
        way1 += way0;
        way0 = tmp;
    }
    return way1;
}

int main() {
    cout << climbStairs(5);
    return 0;
}
