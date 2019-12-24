// https://leetcode-cn.com/problems/powx-n/
#include <cstdio>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		unordered_map<int, double> cache;
		return calcPow(x, n, cache);
	}
private:
	double calcPow(double x, int n, unordered_map<int, double>& cache) {
		auto it = cache.find(n);
		if (it != cache.end()) return it->second;
		double r;
		if (n == 0) {
			r = 1;
		} else if (n < 0) {
			if (n != INT_MIN) {
				r = 1 / calcPow(x, -n, cache);
			} else {
				r = 1 / calcPow(x, INT_MAX, cache) / x;
			}
		} else if (n == 1) {
			r = x;
		} else {
			r = calcPow(x, n / 2, cache);
			r *= r;
			if (n % 2 == 1) {
				r *= x;
			}
		}
		cache[n] = r;
		return r;
	}
};

int main()
{
	Solution s;
	printf("%.5f\n", s.myPow(2.00000, 10)); // answer: 1024.00000
	printf("%.5f\n", s.myPow(2.10000, 3));  // answer: 9.26100
	printf("%.5f\n", s.myPow(2.00000, -2)); // answer: 0.25000
	return 0;
}
