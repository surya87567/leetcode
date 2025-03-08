#include<iostream>
using namespace std;

class Solution {
  public:
      int minimumRecolors(string blocks, int k) {
          int minW = 101;
          int count;
          int n = blocks.length();
          for (int i = 0; i <= n - k; i++) {
              count = 0;
              for (int j = i; j < k + i; j++) {
                  if (blocks[j] == 'W')
                      count++;
              }
              minW = min(minW, count);
          }
          return minW;
      }
  };