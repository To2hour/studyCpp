#include <iostream>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
class Link {
private:
  struct linkNode {
    string val;
    linkNode *front;
    linkNode *next;
    linkNode(string v, linkNode *f, linkNode *n) : val(v), front(f), next(n) {}
  };
  int size;
  linkNode *head;
  linkNode *end;

public:
  Link() : size(0), head(nullptr), end(nullptr){};
  Link(string val) {
    linkNode *node = new linkNode(val, nullptr, nullptr);
    this->head = node;
    this->end = node;
    size = 1;
  }
  void add(string val) {
    linkNode *node = new linkNode(val, nullptr, nullptr);
    linkNode *cur = head;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = node;
    node->front = cur;
    end = node;
    size++;
  }
  bool insert(int target, string val) {

    if (target > size) {
      return false;
    }
    if (head == nullptr) {
      head = end = new linkNode(val, nullptr, nullptr);
      size = 1;
      return true;
    }
    linkNode *node = new linkNode(val, nullptr, nullptr);
    linkNode *cur = head;
    if (target == 0) {
      head = node;
      head->next = cur;
      cur->front = head;
      size++;
      return true;
    }
    if (target == size) {
      end->next = node;
      node->front = end;
      end = node;
      size++;
      return true;
    }
    while (target > 1) {
      target--;
      cur = cur->next;
    }
    node->next = cur->next;
    cur->next = node;
    node->next->front = node;
    node->front = cur;
    size++;
    return true;
  }
  bool edit(int target, string val) {
    if (target >= size) {
      return false;
    }
    linkNode *cur = head;
    while (target--) {
      cur = cur->next;
    }
    cur->val = val;
    return true;
  }
  bool deleteByTarget(int target) {
    if (target > size) {
      return false;
    }
    linkNode *cur = head;
    if (target == 1) {
      if (head == nullptr) {
        return false;
      }
      head = head->next;
      delete cur;
      size--;
      return true;
    }
    if (target == size) {
      if (end == nullptr) {
        return false;
      }
      cur = end;
      end = end->front;
      delete cur;
      size--;
      return true;
    }
    while (target > 1) {
      target--;
      cur = cur->next;
    }
    linkNode *de = cur->next;
    cur->next = cur->next->next;
    cur->next->next->front = cur;
    delete de;
    size--;
    return true;
  }
  bool deleteByVal(string val) {
    // todo
    return false;
  }
};
int main() { 
    Link *l = new Link(); 
    vector<vector<int>> num(4,vector<int>(10,5));
}