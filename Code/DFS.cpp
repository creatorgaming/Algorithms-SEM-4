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

/* stack */
class stack{
public:
  node *top = NULL;
  void push(node *elementInserted){
    if (!isEmpty()) {
      top = elementInserted;
    }else {
      elementInserted->next = top;
      top = elementInserted;
    }
  }

  node* pop(){
    node* temp = new node(top->data,top->parent);
    if (!top->next){
      top = NULL;
    }else {
      node* deletedNode = top;
      top = top->next;
      delete deletedNode;
    }
    return temp;
  }

  bool isEmpty(){
    return (top != NULL);
  }

  void stackDisplay(){
    node* p = top;
    while(p){
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
  int *array;
public:
  graph(int vertices){
    this->vertices = vertices;
    graphList = new ll[vertices];
    array = new int[vertices];
    for (int i = 0; i < vertices; i++){
        array[i] = 0;
    }
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

  void dfs(node* temp){
    if(temp->parent == -1){cout << temp->data << "(rootNode) ";}
    else{cout << temp->data << "("<<temp->parent<<") ";}
    array[temp->data] = 1;
    node *visit = graphList[temp->data].head;
    if (!array[visit->data]){
      dfs(visit);
    }
    while(visit){
      while(visit && array[visit->data])  visit = visit->next;
      if(visit)
        dfs(visit);
      else return;
    }
  }

  void dfsTraverse(int startNode){
    if(graphList){
      cout << "List : \n";
      for (int i = 0; i < vertices; ++i){
        cout << i << " : " ;
        graphList[i].listDisplay();
        cout << "\n";
      }
      cout << "\nOUTPUT:- ";
      node *temp = new node(startNode);
      dfs(temp); 
    }else{
      cout << "\n !!! There is no graph Created !!! \n";
    }
  }
};

int main() {
  int noOfVertices = 5;
  cout << "Enter the no of vertices in Graph : ";
  cin >> noOfVertices;
  graph g(noOfVertices);
/*
  // HardCoded Data
  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(1, 4);
  g.addEdge(3, 4);
  g.addEdge(0, 2);
  g.addEdge(2, 4);
  g.dfsTraverse(0);
*/  
  system("cls");
  while(1){
    char choice;
    cout << "\n\n !!!! DFS GRAPH TRAVERSAL !!!! \n\n";
    cout << "1. Add Edge\n";
    cout << "2. DFS Traversal\n";
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
        g.dfsTraverse();

      case '0':
        exit(0);

      default:
        cout << "\n !!! Wrong choice !!! \n";
    }
  }
  return 0;
}
