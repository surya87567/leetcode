#include<iostream>
#include<vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = left; i <= right; i++) {
            if (isPrime[i]) primes.push_back(i);
        }
        if (primes.size() < 2) return { -1, -1 };
        int minDiff = INT_MAX, p1 = -1, p2 = -1;
        for (int i = 1; i < primes.size(); i++) {
            if (primes[i] - primes[i - 1] < minDiff) {
                minDiff = primes[i] - primes[i - 1];
                p1 = primes[i - 1];
                p2 = primes[i];
            }
        }
        return { p1, p2 };
    }
};
