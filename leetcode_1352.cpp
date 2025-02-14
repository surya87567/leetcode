#include <iostream>
#include <vector>

using namespace std;

class ProductOfNumbers {
private:
    vector<int> prefixProduct;

public:
    ProductOfNumbers() {
        prefixProduct.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
        } else {
            prefixProduct.push_back(prefixProduct.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefixProduct.size();
        if (k >= n) {
            return 0;
        }
        return prefixProduct[n - 1] / prefixProduct[n - 1 - k];
    }
};