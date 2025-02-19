#include<iostream>
#include<vector>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node(int x) : data(x), next(nullptr) {}
};
class Solution {
  public:
      Node* merge(Node* a, Node* b) {
          Node* c = new Node(0);
          Node* temp = c;
          while (a != nullptr && b != nullptr) {
              if (a->data <= b->data) {
                  temp->next = a;
                  a = a->next;
              } else {
                  temp->next = b;
                  b = b->next;
              }
              temp = temp->next;
          }
          temp->next = (a != nullptr) ? a : b;
          return c->next;
      }
  
      Node* mergeKLists(vector<Node*>& arr) {
          if (arr.empty()) return nullptr;
          while (arr.size() > 1) {
              Node* a = arr.back();
              arr.pop_back();
              Node* b = arr.back();
              arr.pop_back();
              arr.push_back(merge(a, b));
          }
          return arr[0];
      }
  };
  