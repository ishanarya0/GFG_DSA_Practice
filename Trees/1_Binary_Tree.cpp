#include <bits/stdc++.h> 
using namespace std;

struct node{
	int data;
	node *left;
	node *right;
};

//////////////////////////////////////

class Tree{
	node *root;
	public:
		Tree(){
			root = NULL;
		}
	int isempty(){
		return (root==NULL);
	}
	
	void insert(int item);
	
	void delNode(int key);
	void delNode(node*,int key);
	void delDeepNode(node*,node*);
	
	void printInorder();
	void printPreorder();
	void printPostorder();
	
	void printInorder(node* );
	void printPreorder(node* );
	void printPostorder(node* );
	
	void printInorderIter();
	void printPreorderIter();
	void printPostorderIter();
	
	void printInorderIter(node* );
	void printPreorderIter(node* );
	void printPostorderIter(node* );
	
	void printLevelOrder();
	void printLevelOrderRev();
	
	void printLevelOrder(node*);
	void printLevelOrderRev(node*);
	
	void search(int key);
	void search(node*,int key);
	
	int height();
	int height(node*);
	
	int diameter();
	int diameter(node*);
	
	void mirror();
	void mirror(node*);
	
	bool checkBalanced();
	bool checkBalanced(node*);
	
	int maxVal();
	int maxVal(node*);
	
	void makeUnbalanced(){
		root->right->right = NULL;
		root->right->left = NULL;	
	}
	void make(){
		root->left = new node();
		root->left->data = 2;
		
		root->left->right = new node();
		root->left->right->data = 4;
		
		root->left->right->right = new node();
		root->left->right->right->data = 7;
		
		root->left->right->left = new node();
		root->left->right->left->data = 6;
		
		root->right = new node();
		root->right->data = 3;
		
		root->right->left = new node();
		root->right->left->data = 5;
		
		root->right->left->left = new node();
		root->right->left->left->data = 8;
	}
	
	void topView();
	void topView(struct node *root);
	void printInorderr(struct node* curr,int limit);
	
	
};

//////////////////////////////////////

void Tree::insert(int item){
		
	node *p = new node;
	p->data = item;
	p->left = NULL;
	p->right =NULL;

	if(isempty()){
		root = p;
	}
	else{
		queue<node*> q;
		q.push(root);
		
		while(!q.empty()){
			node* temp = q.front();
			q.pop();
			
			if(!temp->left){
				temp->left = p;
				break;
			}
			else
				q.push(temp->left);
			
			if(!temp->right){
				temp->right = p;
				break;
			}
			else
				q.push(temp->right);
			
		}				
	}
}

/////////////////////////////////

//---------RECURSIVE APPROACH----------


void Tree::printInorder(){
	printInorder(root);
}

void Tree::printPreorder(){
	printPreorder(root);
}

void Tree::printPostorder(){
	printPostorder(root);
}

void Tree::printInorder(struct node* curr){
	if(curr==NULL)
		return;
	printInorder(curr->left);
	cout<<curr->data<<" ";
	printInorder(curr->right);
}

void Tree::printPreorder(struct node* curr){
	if(curr==NULL)
		return;
	cout<<curr->data<<" ";
	printPreorder(curr->left);
	printPreorder(curr->right);
}

void Tree::printPostorder(struct node* curr){
	if(curr==NULL)
		return;
	printPostorder(curr->left);
	printPostorder(curr->right);
	cout<<curr->data<<" ";
}

/////////////////////////////////

//---------ITERATIVE APPROACH----------


void Tree::printInorderIter(){
	printInorderIter(root);
}

void Tree::printPreorderIter(){
	printPreorderIter(root);
}

void Tree::printPostorderIter(){
	printPostorderIter(root);
}

void Tree::printInorderIter(struct node* curr){
	stack <node*> s;
	node* temp = curr;
	while(!(temp == NULL) || !s.empty() ){
			while(temp != NULL){
				s.push(temp);
				temp = temp->left;
			}
			temp = s.top();
			s.pop();
			cout<<temp->data<<" ";
			temp = temp->right;		
	}
	return;
}

void Tree::printPreorderIter(struct node* curr){
	stack <node*> s;
	node* temp = curr;
	while(!(temp == NULL) || !s.empty() ){
			while(temp != NULL){
				cout<<temp->data<<" ";
				s.push(temp);
				temp = temp->left;
			}
			temp = s.top();
			s.pop();
			temp = temp->right;	
	}
	return;
	
}

/*
void Tree::printPostorderIter(struct node* curr){
	stack <node*> s;
	node* temp = curr;
	
	while((temp!=NULL) || (!s.empty())){
		if(temp!=NULL){
			s.push(temp);
			temp = temp->left;
		}
		else{
			node* t = s.top();
			t = t->right;
			if(t==NULL){
				t = s.top();
				s.pop();
			 	cout<<t->data<<" ";
			 	node* l = s.top();
			 	while((!s.empty())&&(t==l->right)){
			 		t = s.top();
			 		s.pop();
			 		l = s.top();
			 		cout<<t->data<<" ";
				}
			}
			else{
				temp = t;
			}	
		}	
	}
	return;
}*/

/*
1.1 Create an empty stack
2.1 Do following while root is not NULL
	a) Push root's right child and then root to stack
	b) Set root as root's left child
2.2 Pop an item from stack and set it as root
	a) If the popped item has a right child and the right child is at top of stack
		, then remove the right child from stack, push the root back
		and set root as root's right child.
	b) Else print root's data and set root as NULL;
2.3 Repeat steps 2.1 and 2.2 while stack is not empty	
*/

void Tree::printPostorderIter(struct node* root){
		stack<struct node*> s;
		if(root == NULL)
			return;
		do{
			while(root != NULL){
				if(root->right){		
					s.push(root->right);
				}
				s.push(root);
				
				root = root->left;
			}
			
			root = s.top();
			s.pop();
			if(s.empty()){
				cout<<root->data;
				return;
			}
			
			if((root->right )&& (root->right == s.top())){
				s.pop();
				s.push(root);
				root = root->right;
			}
			else{
				cout<<root->data<<" ";
				root = NULL;
			}
			
		}while(!s.empty());
}

/////////////////////////////////
//------Level Order Trav-----

void Tree::printLevelOrder(){
	printLevelOrder(root);
}

void Tree::printLevelOrderRev(){
	printLevelOrderRev(root);
}

void Tree::printLevelOrder(struct node* curr){
	if(curr== NULL)
		return;
	
	queue<node*> q;
	q.push(curr);
	
	while(!q.empty()){
		node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left !=NULL)
			q.push(temp->left);
			
		if(temp->right !=NULL)
			q.push(temp->right);
				
	}
	
}

void Tree::printLevelOrderRev(struct node* curr){
	if(curr== NULL)
		return;
	
	queue<node*> q;
	stack<int> s;
	q.push(curr);
	
	while(!q.empty()){
		node* temp = q.front();
		s.push(temp->data);
		q.pop();
		
		if(temp->left !=NULL)
			q.push(temp->left);
			
		if(temp->right !=NULL)
			q.push(temp->right);
				
	}
	while(!s.empty()){
		cout<<s.top()<<" ";
		s.pop();}
	
}

/////////////////////////////////

void Tree::search(int key){
	search(root,key);
}

void Tree::search(node* curr,int key){
	if(curr== NULL)
		return;
	
	queue<node*> q;
	q.push(curr);
	
	while(!q.empty()){
		node* temp = q.front();
		if(temp->data == key){
			cout<<"Found!";
			return;}
			
		q.pop();
		if(temp->left !=NULL)
			q.push(temp->left);
			
		if(temp->right !=NULL)
			q.push(temp->right);
				
	}
	cout<<"Not found!";
	return;
	
}

/////////////////////////////////
//---------Height of tree--------

int Tree::height(){
	return height(root);
}

int Tree::height(node* curr){
	if(curr == NULL)
		return 0;
	if(curr->left == NULL && curr->right == NULL)
		return 0;
	else{
		return 1+max( height(curr->left) , height(curr->right) );
	}
}

/////////////////////////////////
//--------Diameter of Tree-------

int Tree::diameter(){
	return diameter(root);
}

int Tree::diameter(node* curr){
	if(curr==NULL)
		return 0;
	
	int lht = height(curr->left) + 1;
	int rht = height(curr->right) + 1;
	
	int ldia = diameter(curr->left);
	int rdia = diameter(curr->right);
	
	return max(lht+rht+1 , max(ldia,rdia));
	
}

/////////////////////////////////
//-------Check Balanced---------

bool Tree::checkBalanced(){
	return checkBalanced(root);
}

bool Tree::checkBalanced(node* curr){
	if(curr == NULL)
		return true;
	
	int lht = height(curr->left);
	int rht = height(curr->right);
	if(abs(lht-rht)>1)
		return false;
	else{
		return (checkBalanced(curr->left)&&checkBalanced(curr->right));
	}
	
}

/////////////////////////////////
//--------Mirror of Tree--------
void Tree::mirror(){
	mirror(root);
}

void Tree::mirror(node* curr){
	if(curr == NULL)
		return;
	
	node* temp = curr->left;
	curr->left = curr->right;
	curr->right = temp;
	
	mirror(curr->left);
	mirror(curr->right);
}


/////////////////////////////////
//---------Max Value---------
int Tree::maxVal(){
	return maxVal(root);
}

int Tree::maxVal(node* curr){
	if(curr == NULL)
		return INT_MIN;
	
	return max(curr->data, max(maxVal(curr->left), maxVal(curr->right)));
	
}

/////////////////////////////////

void Tree::delDeepNode(node* curr, node* del){
	queue<struct node*> q;
	q.push(curr);
	
	struct node* temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp == del){
			temp = NULL;
			delete (del);
			return;
		}
		if(temp->right){
			if(temp->right == del)
			{
				temp->right = NULL;
				delete (del);
				return;
			}
			else
				q.push(temp->right);
		}
		
		if(temp->left){
			if(temp->left == del)
			{
				temp->left = NULL;
				delete (del);
				return;
			}
			else
				q.push(temp->left);
		}
		
		
	}
	
}


void Tree::delNode(node* curr, int key){
	if(curr == NULL)
		return;
	if(curr->left == NULL && curr->right == NULL){
		if(curr->data == key)
			delete(curr);
		else
			return;
			
		return;
	}
	
	queue<struct node*> q;
	q.push(curr);
	
	struct node* deep; //will store the deepest node
	struct node* del_node = NULL; //will store the node to be deleted
	
	while(!q.empty()){
		deep = q.front();
		q.pop();
		
		if(deep->data == key)
			del_node = deep;
		
		if(deep->left)
			q.push(deep->left);
		if(deep->right)
			q.push(deep->right);
	}
	
	if(del_node != NULL){
		int var = deep->data;
		delDeepNode(root,deep);
		del_node->data = var;
	}
	return;
}


void Tree::delNode(int key){
	delNode(root,key);
}
////////////////////////////////


int main(){
	Tree root;
	root.insert(1);
	root.make();
	root.insert(2);
	root.insert(3);
	root.insert(4);
	root.insert(5);
	root.insert(6);
	root.insert(7);
	root.insert(8);
	root.insert(9);
	root.insert(10);
	root.insert(11);
	root.insert(12);
	root.insert(13);
	root.insert(14);
	root.insert(15);
	root.insert(16);
	root.insert(17);
	
	
	root.makeUnbalanced();
	
	root.printInorder();
	cout<<endl;
	root.printInorderIter();
	cout<<endl;
	root.printPreorder();
	cout<<endl;
	root.printPreorderIter();
	cout<<endl;
	root.printPostorder();
//	cout<<endl;
//	root.printPostorderIter();
	cout<<endl;
	root.printLevelOrder();
	cout<<endl;
	root.printLevelOrderRev();
	cout<<endl;
	root.search(1);
	cout<<endl;
	root.search(12);
	cout<<endl;
	cout<<root.height();
	cout<<endl;
	cout<<root.diameter();
	root.mirror();
	cout<<endl;
	root.printLevelOrder();
	cout<<endl;
	cout<<root.checkBalanced();
	cout<<endl;
	cout<<root.maxVal();
	
	cout<<endl;
	root.printLevelOrder();
	
	return 0;
}
