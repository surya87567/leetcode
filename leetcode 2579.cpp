#include<iostream>
using namespace std;

class Solution {
  public:
      long long coloredCells(int n) {
         long long x=0,count=1;
         for(int i=0;i<n;i++){
          count=count+x;
          x=x+4;
         }
         return count;
      }
  };