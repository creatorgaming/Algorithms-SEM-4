#include "iostream"
#include "stdlib.h"
using namespace std;
int COUNT = 10; //To Print Tree
enum color{
		RED,BLACK
};

class node{
public:
	int data;
	node *lchild, *rchild, *parent;
	enum color ownColor;
	node(int data, node* lchild = NULL,node* rchild = NULL,color ownColor = RED){
		this->data = data;
		this->lchild = lchild;
		this->rchild = rchild;
		this->parent = parent;
		this->ownColor = ownColor;
	}
};

class rbTree{
	private:
		node* root;
		node* nullLeaves;
		void print(node*, int);
	public:
		rbTree(){
			root = NULL;
		}
		node* insertBst(int);
		void insert(int);
		void leftRotate(node*);
		void rightRotate(node*);
		void print();
};

node* rbTree::insertBst(int ele){
	node* q = new node(ele);
	if(root == NULL){
		root = q;
		root->ownColor = BLACK;
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

void rbTree::leftRotate(node* x){
	node *x_right = x->rchild;
	x->rchild = x_right->lchild;

	if (x->rchild != NULL)
		x->rchild->parent = x;

	x_right->parent = x->parent;

	if (x->parent == NULL)
		root = x_right;
	else if (x == x->parent->lchild)
		x->parent->lchild = x_right;
	else
		x->parent->rchild = x_right;

	x_right->lchild = x;
	x->parent = x_right;
}

void rbTree::rightRotate(node* x){
	node *x_left = x->lchild;
	x->lchild = x_left->lchild;

	if (x->lchild != NULL)
		x->lchild->parent = x;

	x_left->parent = x->parent;

	if (x->parent == NULL)
		root = x_left;
	else if (x == x->parent->rchild)
		x->parent->rchild = x_left;
	else
		x->parent->lchild = x_left;

	x_left->lchild = x;
	x->parent = x_left;
}

void rbTree::insert(int ele){
	node *x = insertBst(ele);
	node *uncle = NULL;
	// if(p->parent != NULL){
	// 	cout << "\n\nELEMENT DATA : " << p->data;
	// 	cout << "\nELEMENT color : " << p->ownColor;
	// 	cout << "\nELEMENT PARENT DATA : " << p->parent->data;
	// 	cout << "\nELEMENT PARENT color : " << p->parent->ownColor;
	// }
	while(x != root && x->parent->ownColor == RED){
		if (x->parent == x->parent->parent->lchild){
			uncle = x->parent->parent->rchild;
			if (uncle != NULL && uncle->ownColor == RED){
				x->parent->ownColor = BLACK;
				uncle->ownColor = BLACK;
				x->parent->parent->ownColor = RED;
				x = x->parent->parent;
			}else{
				if(x == x->parent->rchild){
  					x = x->parent;
					leftRotate(x);
				}
				x->parent->ownColor = BLACK;
				x->parent->parent->ownColor = RED;
				rightRotate(x->parent->parent);
			}
		}else{
			uncle = x->parent->parent->lchild;
			if (uncle != NULL && uncle->ownColor == RED){
				x->parent->ownColor = BLACK;
				uncle->ownColor = BLACK;
				x->parent->parent->ownColor = RED;
				x = x->parent->parent;
			}else{
				if(x == x->parent->lchild){
					x = x->parent;
					rightRotate(x);
				}
				x->parent->ownColor = BLACK;
				x->parent->parent->ownColor = RED;
				leftRotate(x->parent->parent);
			}
		}
	}
	root->ownColor = BLACK;
}

void rbTree::print(node *root, int space){
    if (root == NULL)
        return;
    space += COUNT;
    print(root->rchild, space);
    cout << endl;

    for(int i = COUNT; i < space; i++){
        cout << " ";
    }

    cout<< root->data << " " << root->ownColor << '\n';
    print(root->lchild, space);
}

void rbTree::print(){
   print(root, 0);
}

int main(){

  int choice,temp;
  rbTree tree;

  while (1) {
    cout << "\n\n!!! WELOCOME TO RED - BLACK TREE !!!!" << '\n';
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
