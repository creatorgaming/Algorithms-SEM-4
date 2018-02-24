#include "iostream"
#include "stdlib.h"
using namespace std;
class node{
	public:
		int data;
		int height
		node *lchild, *rchild, *parent;
		node(int data, int height = 0, node* lchild = NULL,node* rchild = NULL){
			this->data = data;
			this->lchild = lchild;
			this->rchild = rchild;
			this->height = height;
		}
};

class AVL_Tree{
	private:
		node *root;
		node* rightRotate(node*);
		node* leftRotate(node*);
		node* insertBst(int ele);
		void insert(node*,int);
		int height(node*);
		int max(int x, int y);
	public:
		AVL_Tree(){
			root = NULL;
		}
		void insert(int);
};

node* AVL_Tree::insertBst(int ele){
	node* q = new node(ele);
	if(root == NULL){
		root = q;
		q->parent = NULL;
		return q;
	}
	node* p = root;
	node* fp = 0;
	while(p != NULL){
		fp = p;
		if(ele < p->data)
			p = p->lchild;
		else
			p = p->rchild;
	}
	if(fp->data > ele)
		fp->lchild = q;
	else
		fp->rchild = q;
	
	q->parent = fp;

	return q;
}

int max(int a, int b){
	if(a > b)
		return a;
	else
		return b;
}

node* AVL_Tree::rightRotate(node *root){
	node *newRoot = root->lchild;
	root->lchild = newRoot->rchild;
	newRoot->rchild = root;
	root->height = max(height(y->left), height(y->right))+1;
	newRoot->height = max(height(x->left), height(x->right))+1;

	return newRoot;
}

node* AVL_Tree::leftRotate(node* root){
	node *newRoot = root->rchild;
	root->rchild = newRoot->lchild;
	newRoot->lchild = root;
	root->height = max(height(y->left), height(y->right))+1;
	newRoot->height = max(height(x->left), height(x->right))+1;

	return newRoot;
}

node* AVL_Tree::insert(node* root, int ele){

}

void insert(int ele){
	node *valid = insert(root,ele);
}

int main(){
  
  int choice,temp;
  AVL_Tree tree;

  while (1) {
    cout << "\n\n!!! WELOCOME TO AVL TREE !!!!" << '\n';
    cout<<"1. Add new Node"<<endl;
    cout<<"2. Print Tree"<<endl;
    cout<<"0. Exit"<<endl;
    cout<<"Choice: ";
    cin>>choice;
    cout << '\n';

    switch(choice){
        case 1:{
          cout<<"Enter Element: ";
          cin>>temp;
          tree.insert(temp);
        }
        break;

        case 2:{
        	tree.print();
        }
        break;

        case 0:
          exit(1);

        default:
          cout << "Wrong choice" << '\n';
          break;
    }
  }
	return 0;
}