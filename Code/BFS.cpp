#include "iostream"
using namespace std;

/*  Node Class for Linked List */
class node{
private:
  int data;
  node *next;
public:
  node(int data,node* next = NULL){
    this->data = data;
  }
};

/*  Linked List */
class ll{
private:
  node* head;
public:
  void insert(int ele){
    node* elementInserted = new node(ele);
    node* p = head;
    if (p == NULL) {
      head = p;
    }else {
      p->next = head;
      head = p;
    }
  }
};

/* Queue */
class Queue{
private:
  node* head, tail;
public:
  void insert(int ele){
    node* elementInserted = new node(ele);
    node* p = head;
    if (head == NULL) {
      head = tail = p;
    }else {
      
    }
  }
};

int main() {

  return 0;
}
