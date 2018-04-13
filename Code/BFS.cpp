#include "iostream"
using namespace std;

/*  Node Class for Linked List */
class node{
public:
  int data;
  node *next;
  node(int data,node* next = NULL){
    this->data = data;
  }
};

/*  Linked List */
class ll{
public:
  node* head = NULL;
  node* tail = NULL;
  void insert(int ele){
    node* elementInserted = new node(ele);
    if (head == NULL && tail == NULL) {

      head = tail = NULL;
    }else {
      tail->next = elementInserted;
      tail = elementInserted;
    }
  }
};

/* Queue */
class Queue{
public:
  node *head = NULL;
  node *tail = NULL;
  void enQueue(int ele){
    node* elementInserted = new node(ele);
    if (head == NULL && tail == NULL) {
      head = elementInserted;
      tail = elementInserted;
    }else {
      tail->next = elementInserted;
      tail = elementInserted;
    }
  }
  node* deQueue(){
    node* temp = new node(head->data);
    if (head == tail){
      head = tail = NULL;
    }else {
      node* deletedNode = head;
      head = head->next;
      delete deletedNode;
    }
    return temp;
  }
};

/* Graph class */
class graph{
private:
  ll* graphList = NULL;
  int vertices;
public:
  graph(int vertices){
    this->vertices = vertices;
    graphList = new ll[vertices];
  }

  void addEdge(int src, int dest){
    if ( (src >= 0 && dest >= 0) && (src < vertices && dest < vertices) ) {
      graphList[src].insert(dest);      
      graphList[dest].insert(src);      
      cout << "\n!!! Edge Added Successfully !!! \n";
    }else {
      cout << "\n !!! Invalid Index Entered !!! \n";
    }
  }

  void bfsTraverse(){
    if (graphList != NULL){
      cout << "OUTPUT:- ";
      int *array = new int[vertices];
      Queue queue;
      for (int i = 0; i < vertices; i++){
        array[i] = 0;
      }
      for (int i = 0; i < vertices; i++){
        if (!array[i]){
          queue.enQueue(i);
        }        
        while( queue.head != NULL && queue.tail != NULL){
          node *temp = queue.deQueue();
          if(array[temp->data] == 0){
            cout << temp->data << " ";
          }
          node *visit = graphList[temp->data].head;
          while(!array[temp->data] && visit){
            array[temp->data] = 1;
            if(!array[visit->data]){
              queue.enQueue(visit->data);
            }
            visit = visit->next;
          }
        }
      }
      cout << "\n";
    }else {
      cout << "\n !!! There is no graph Created !!! \n";
    }
  }
};

int main() {
  int noOfVertices;
  cout << "Enter the no of vertices in Graph : ";
  cin >> noOfVertices;
  graph g(noOfVertices);

  system("cls");
  while(1){
    char choice;
    cout << "\n\n !!!! BFS GRAPH TRAVERSAL !!!! \n\n";
    cout << "1. Add Edge\n";
    cout << "2. BFS Traversal\n";
    cout << "0. EXIT\n";
    cout << "Choice --> ";
    cin >> choice;
    cout << '\n';
    switch(choice){
      case '1':
        int src, dest; 
        cout << "Enter source node: ";
        cin >> src;
        cout << "Enter destination node: ";
        cin >> dest;
        g.addEdge(src,dest);
        break;

      case '2':
        g.bfsTraverse();

      case '0':
        exit(0);

      default:
        cout << "\n !!! Wrong choice !!! \n";
    }
  }
  return 0;
}
