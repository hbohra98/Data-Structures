/*
Time complexity : o(n)
Space complexity : Best -> o(1) & Worst -> o(n)
*/
#include<bits/stdc++.h>
using namespace std;
struct Node{
	char data;
	Node *left;
	Node *right;
}; 
/*
inserting as in binary search tree
*/
Node* Insert(Node *root,char data) {
	if(root == NULL) {
		root = new Node();
		root->data = data;
		root->left = root->right = NULL;
	}
	else if(data <= root->data) root->left = Insert(root->left,data);
	else root->right = Insert(root->right,data);
	return root;
}
/* Level order traversal */ 

void levelorder(Node *root){
	if(root==NULL)return ;
	
	//queue which store the nodes that are to be visited
	
	queue<Node *> Q;
	
	Q.push(root);
	
	while(!Q.empty()){
		
		Node *current=Q.front();
			/*
		remove the element as its visited and left and right are 
		pushed into the queue 
		*/
		
		Q.pop();
		
		cout << current->data << " ";
			
		/*
		push left and right as the traversal is level order and 
		we have to traverse next level rather than depth
		*/
	
		if(current->left!=NULL)Q.push(current->left);
		if(current->right!=NULL)Q.push(current->right);		
	}
}
int main(){

	/*
	
	                    H
			   / \
			  E   A
			 / \   \
			L   T   H
    
	*/


	Node* root = NULL;
	//Node* root = NULL;
	root = Insert(root,'H'); root = Insert(root,'E');
	root = Insert(root,'A'); root = Insert(root,'L'); 
	root = Insert(root,'T'); root = Insert(root,'H');
 
	levelorder(root);
	
}
