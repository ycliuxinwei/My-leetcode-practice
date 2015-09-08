#include <iostream>
using namespace std;

template <typename T>
T abs(T a) { return a>0? a : -a; }


/*divide and conquer*/
int mySqrtDC(unsigned long long x, unsigned long long start, unsigned long long end) {
	if (end-start <= 1) return start;
	unsigned long long mid = (end - start)/2 + start;
	if (mid*mid == x) return mid;
	if (mid*mid > x) return mySqrtDC(x, start, mid);
	if (mid*mid < x) return mySqrtDC(x, mid, end);
}

int mySqrt1(int x) {
	if (x==1) return 1;
	return mySqrtDC(x, 0, x);
}

/*
Carmack's method:
http://en.wikipedia.org/wiki/Fastinversesquare_root
*/
int mySqrt2(int x) {
	uint64_t i;
	double x2, y;
	x2 = x * 0.5;
	y = x;
	i = *(uint64_t *) &y;
	i = 0x5fe6eb50c7b537a9 - (i >> 1); // This magic number is taken from wikipedia.
	y = *(double *) &i; // initial guess of the inverse square root
	y = y * (1.5 - (x2 * y * y)); // Newton for inverse square root.
	y = y * (1.5 - (x2 * y * y));
	y = y * (1.5 - (x2 * y * y));
	y = y * (1.5 - (x2 * y * y)); // repeate 4 times to get enough precision.
	return x * y;
}

/*
牛顿法
对 f(x) 在 x_i 进行一阶泰勒展开，有 f(x) = f(x_i) + f’(x_i)*(x-x_i) = 0
于是，x_{i+1} = x_i - f(x_i) / f’(x_i)
本题 f(x) = x^2 - n = 0，化简得到：x_{i+1} = (x_i + n/x_i)/2
判断 x_{i+1} 和 x_i 是否无限接近
*/
int mySqrt3(int x) {
	if (x == 0) return 0;
	double pre = 0, cur = 1;
	while (abs(cur-pre) > 0.00001) {
		pre = cur;
		cur = x/(2.0*pre) + pre/2.0;
	}
	return int(cur);
}

int main() {
	long long int a = 2232;
	
	long long int x = mySqrt1(a);
	cout << "sqrt1(" << a << ") = " << x << endl;
	cout << x*x << "<" << a << "<" << (x+1)*(x+1) << endl;
	
	long long int y = mySqrt2(a);
	cout << "sqrt2(" << a << ") = " << y << endl;
	cout << y*y << "<" << a << "<" << (y+1)*(y+1) << endl;
	
	long long int z = mySqrt3(a);
	cout << "sqrt2(" << a << ") = " << z << endl;
	cout << z*z << "<" << a << "<" << (z+1)*(z+1) << endl;
	return 0;
}