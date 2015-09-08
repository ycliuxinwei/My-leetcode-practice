#include <iostream>
using namespace std;

/* Implement pow(x, n).分治 */
double myPow1(double x, int n) {
	if (n < 0) return 1.0/myPow1(x, -n);
	if (n == 0) return 1.0;
	double y = myPow1(x*x, n/2);
	if (n%2 == 0) return y;
	return y*x;
}

/*非递归*/
double myPow2(double x, int n) {
	double d = 1.0;
    int m = n;
    while(n!=0) {
            if (n%2) d *= x;
            x *= x;
            n /= 2;
    }
    return m >= 0 ? d : 1.0/d;
}

int main() {
	cout << myPow1(-2,-3) << endl;
	cout << myPow2(-2,-3) << endl;
	return 0;
}