#include "iostream"
#include "stdlib.h"
#include "math.h"
using namespace std;
#define size 10
#define range 1000
#define range_2 10

void convert(float*);
void bucketMaker(float*);
void display(float*,int);
void display(int*,int);

/*Linked List :- Class Node*/
class node{
  public:
    float data;
    node *next,*prev;

    node(float data,node *next = NULL,node *prev = NULL){
      this->data = data;
      this->next = next;
      this->prev = prev;
    }
};

/*Linked List :- Main Class*/
class LL{
  private:
    node *head;
    node *tail;
  public:
    void insert(float ele);
    void printList();
};

void LL::insert(float ele){
  node *p = new node(ele);
  if(head == NULL && tail == NULL){
    tail = head = p;
  }else if (head->data > p->data) {
    p->next = head;
    head->prev = p;
    head = p;
  }else if (tail->data < p->data) {
    p->prev = tail;
    tail->next = p;
    tail = p;
  }else{
    node *p1 = head;
    while (p1 != NULL && p1->data < p->data) {
      p1 = p1->next;
    }
    p->next = p1;
    p->prev = p1->prev;
    (p1->prev)->next = p;
    p1->prev = p;
  }
}

void LL::printList(){
  node *p = head;
  while (p != NULL) {
    cout << " -> " << p->data;
    p = p->next;
  }
}

void mergeList(LL* list){
  int *arrFinal = new int[size];
  int i = 0,j = 0;
  while(i < 10){
    node *p = list[i].head;
    while (p != NULL) {
      arrFinal[j++] = p->data;
      p = p->next;
    }
    i++;
  }
  display(arrFinal,size);
}
/*End of Linked List*/

int main() {
  float *a = new float[size];
  srand(time(NULL));
  for(int i = 0; i < size; i++){
    int k = 1 + rand()%range;
    a[i] = k;
  }
  std::cout << " Origianl Array ..." << '\n';
  display(a,size);
  convert(a);
  bucketMaker(a);
  // cout << "\nArray after conversion...\n";
  // display(a,size);
  return 0;
}

void  bucketMaker(float *a){
  LL *list = new LL[10];
  for(int i = 0; i < size; i++){
    int index = floor(range_2*a[i]);
    //cout << "\na["<<i<<"] = " << a[i] << " : INDEX -> " << index << endl;
    list[index].insert(a[i]*1000);
  }

/*Printing List
  for(int i = 0; i < 10; i++){
    cout << "\n\nList ["<<i<<"] ....\n";
    list[i].printList();
    std::cout << '\n';
  }
*/
  mergeList(list);
}

void convert(float *a){
  for(int i = 0; i < size; i++){
    a[i] /= range;
  }
}

void display(float *a, int s){
  int i = 0;
  cout << "  ";
  while (i < size) {
    cout << " |" << a[i] << "| ";
    i++;
  }
  cout << '\n';
}

void display(int *a, int s){
  int i = 0;
  cout << "  ";
  while (i < size) {
    cout << " |" << a[i] << "| ";
    i++;
  }
  cout << '\n';
}
