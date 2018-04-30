#include "iostream"
using namespace std;
class node{
	private:
		int data,weight;
		node *next;
	public:
		node(int data, int weight = -1, node *next = NULL){
			this->data = data;
			this->weight = weight;
			this->next = next;
		}
};

class graph{
	private:
		
};

int main(){
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
    cout << "\n\n !!!! MINIMUM SPANING TREE MAKING !!!! \n\n";
    cout << "1. Add Edge\n";
    cout << "2. Show Mimimum Spaning Tree\n";
    cout << "0. EXIT\n";
    cout << "Choice --> ";
    cin >> choice;
    cout << '\n';
    switch(choice){
      case '1':
        int src, dest, weight; 
        cout << "Enter source node: ";
        cin >> src;
        cout << "Enter destination node: ";
        cin >> dest;
        cout << "Weight of edge: ";
        cin >> weight;
        g.addEdge(src,dest,weight);
        break;

      case '2':
        g.spanTree();

      case '0':
        exit(0);

      default:
        cout << "\n !!! Wrong choice !!! \n";
    }
  }
  return 0;
	return 0;
}