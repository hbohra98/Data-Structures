/*
Algorithm
Time complexity : o(n)
Space complexity : Best,average case -> o(log(n)) & Worst -> o(n)
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
/*
Recurisvely call for same sub problems in the depth
*/

/* Pre order traversal */ 

void preorder(Node *root){
	if(root==NULL)return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

/* Post order traversal */ 

void postorder(Node *root){
	if(root==NULL)return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	
}

/* Inorder traversal */ 

void inorder(Node *root){
	if(root==NULL)return ;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main(){

	/*
	
	                    6
			   / \
			  4   7
			 / \   \
			1   5   9
    
	*/


	Node* root = NULL;
	//Node* root = NULL;
	root = Insert(root,'6'); root = Insert(root,'4');
	root = Insert(root,'7'); root = Insert(root,'1'); 
	root = Insert(root,'5'); root = Insert(root,'9');
 	cout<<"Preorder\n";
	preorder(root);
	cout<<"\nPostorder\n";
	postorder(root);
	cout<<"\nInorder\n";
	inorder(root);

}
