#include<iostream>
#include<forward_list>
#include<climits>
using namespace std;

struct edge{
    int node;
    int weight;
};

class graph{
public:
    int n;
    int*weights;
    int*explored;
    int*parents;
    forward_list<edge>*arr;
    graph(int n){
        this->n = n;
        this->arr = new forward_list<edge>[n];
        this->weights = new int[n];
        this->explored = new int[n];
        this->parents = new int[n];
        for(int i = 0;i<n;i++)explored[i] = 0;
    }

    void addEdge(int src, int dest, int weight){
        edge e1;
        e1.node = dest;
        e1.weight = weight;

        edge e2;
        e2.node = src;
        e2.weight = weight;

        arr[src].push_front(e1);
        arr[dest].push_front(e2);
    }

    void showGraph(){
        for(int i = 0; i<n; i++){
            cout<<i<<" -> ";
            for (edge&e : arr[i])
                cout << e.node << "("<<e.weight<<") ";
            cout<<"\n";
        }
    }

    int minKey(){
        int min = INT_MAX,index;
        for(int i = 0;i<n;i++)if(weights[i] < min && !explored[i]){index = i;min = weights[i];}
        return index;
    }

    void printTree(){
        cout<<"Parent  Child \tWeight"<<endl;
        for(int i = 0;i<n;i++)cout<<parents[i]<<"\t  "<<i<<"\t"<<weights[i]<<"\n";
    }

    void prims(int root){
        for(int i = 0;i<n;i++){
            if(i != root)weights[i] = INT_MAX;
            else weights[i] = 0;
        }
        parents[root] = -1;

        for(int a = 0;a<n;a++){
            int i = minKey();
            //cout<<"\n"<<i<<"\n";
            explored[i] = 1;
            for(edge&e : arr[i]){
                if(!explored[e.node] && e.weight < weights[e.node]){
                    parents[e.node] = i;
                    weights[e.node] = e.weight;
                }
            }
        }
    }

};

int main(){
    int n , flag = 1;
    cout<<"Enter Number of nodes in graph : ";
    cin>>n;
    graph g(n);
    cout<<"Enter edges set as (u v w) where u and v are nodes & w is the weight of the edge between which the edge exists ! \n";
    cout<<"Enter -1 -1 for termination\n";

    int temp[3];
    while(flag){
        cin>>temp[0]>>temp[1]>>temp[2];
        if(temp[0] == -1 && temp[1] == -1 && temp[2] == -1)flag = 0;
        else g.addEdge(temp[0],temp[1],temp[2]);
    }

    cout<<"Entered Graph is\n";
    g.showGraph();
    g.prims(0);
    g.printTree();
}