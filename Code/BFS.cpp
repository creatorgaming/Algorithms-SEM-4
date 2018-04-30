#include "iostream"
using namespace std;

/*  Node Class for Linked List */
class node{
public:
  int data;
  node *next;
  int parent;
  node(int data,int parent = -1,node* next = NULL){
    this->data = data;
    this->next = next;
    this->parent = parent;
  }
};

/*  Linked List */
class ll{
public:
  node* head = NULL;
  node* tail = NULL;
  
  void insert(int ele,int parent){
    node* elementInserted = new node(ele,parent);
    if (head == NULL && tail == NULL) {
      head = tail = elementInserted;
    }else {
      tail->next = elementInserted;
      tail = elementInserted;
    }
  }

  void listDisplay(){
    node* p = head;
    while(p){
      cout << "-> " << p->data;
      p = p->next;
    }
  }
};

/* Queue */
class Queue{
public:
  node *head = NULL;
  node *tail = NULL;
  void enQueue(node *elementInserted){
    if (head == NULL && tail == NULL) {
      head = elementInserted;
      tail = elementInserted;
    }else {
      tail->next = elementInserted;
      tail = elementInserted;
    }
  }
  node* deQueue(){
    node* temp = new node(head->data,head->parent);
    if (head == tail){
      head = tail = NULL;
    }else {
      node* deletedNode = head;
      head = head->next;
      delete deletedNode;
    }
    return temp;
  }

  bool isEmpty(){
    return (head != NULL && tail != NULL);
  }

  void queueDisplay(){
    node* p = head;
    while(p != NULL){
      cout << p->data << "-> ";
      p = p->next;
    }
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
      graphList[src].insert(dest,src);      
      graphList[dest].insert(src,dest);      
      //cout << "\n!!! Edge Added Successfully !!! \n";
    }else {
      cout << "\n !!! Invalid Index Entered !!! \n";
    }
  }

  void bfsTraverse(int startNode){
    if (graphList){
      cout << "List : \n";
      for (int i = 0; i < vertices; ++i){
        cout << i << " : " ;
        graphList[i].listDisplay();
        cout << "\n";
      }
      cout << "\nOUTPUT:- ";
      int *array = new int[vertices];
      Queue queue;

      for (int i = 0; i < vertices; i++){
        array[i] = 0;
      }
      
      node *temp = new node(startNode);
      queue.enQueue(temp);    
      while(queue.isEmpty()){
        node *temp = queue.deQueue();
        if(array[temp->data] == 0){
          if(temp->parent == -1){
            cout << temp->data << "(rootNode) ";
          }else {
            cout << temp->data << "("<<temp->parent<<") "; 
          }
          
          array[temp->data] = 1;
          node *visit = graphList[temp->data].head;
          while(visit){
            if(!array[visit->data]){
              queue.enQueue(visit);
            }
            visit = visit->next;
          }
        }
      }
      cout  << "\n";
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
/*  
  // HardCoded Data
  g.addEdge(0, 3);
  g.addEdge(0, 1);
  g.addEdge(2, 1);
  g.addEdge(1, 3);
  g.bfsTraverse(0);
*/  
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
