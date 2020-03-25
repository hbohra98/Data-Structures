Node insert(Node node, int key) { 

		if (node == null) 
			return (new Node(key)); 

        if (key > node.key){ 
			node.right = insert(node.right, key);
        }
		else if (key < node.key){ 
			node.left = insert(node.left, key); 
		}
		else
			return node; 

	
		node.height = 1 + max_element(height(node.left),height(node.right)); 

        
	int balance = 0; 
        if (node != null) 
			balance=height(node.left) - height(node.right); 
		// Left Right Case  || LR
		if (balance > 1 && key > node.left.key) { 
			node.left = lr(node.left); 
			return rr(node); 
		}
		// Right Left Case || RL
		if (balance < -1 && key < node.right.key) { 
			node.right = rr(node.right); 
			return lr(node); 
		} 
	    // Left Left Case || LL 
		if (balance > 1 && key < node.left.key){
			return rr(node); 
        }
		// Right Right Case || RR
		if (balance < -1 && key > node.right.key){
			return lr(node); 
		}

		return node; 
	} 

//main method
	public static void main(String[] args) { 
	    int arr[]={100, 200, 150, 170, 165, 180, 220, 163, 164};
		AVLTree tree = new AVLTree(); 
		for(int i=0;i<9;i++){
		    tree.root = tree.insert(tree.root, arr[i]);
		}
		System.out.println("Preorder traversal of  tree is : "); 
		tree.preorder_traversal(tree.root); 
	} 
} 

Node insert(Node node, int key) { 

		if (node == null) 
			return (new Node(key)); 

        if (key > node.key){ 
			node.right = insert(node.right, key);
        }
		else if (key < node.key){ 
			node.left = insert(node.left, key); 
		}
		else
			return node; 

	
		node.height = 1 + max_element(height(node.left), 
							height(node.right)); 

        
		int balance = 0; 
        if (node != null) 
			balance=height(node.left) - height(node.right); 
		// Left Right Case  || LR
		if (balance > 1 && key > node.left.key) { 
			node.left = lr(node.left); 
			return rr(node); 
		}
		// Right Left Case || RL
		if (balance < -1 && key < node.right.key) { 
			node.right = rr(node.right); 
			return lr(node); 
		} 
	    // Left Left Case || LL 
		if (balance > 1 && key < node.left.key){
			return rr(node); 
        }
		// Right Right Case || RR
		if (balance < -1 && key > node.right.key){
			return lr(node); 
		}

		return node; 
	} 

//main method
	public static void main(String[] args) { 
	    int arr[]={100, 200, 150, 170, 165, 180, 220, 163, 164};
		AVLTree tree = new AVLTree(); 
		for(int i=0;i<9;i++){
		    tree.root = tree.insert(tree.root, arr[i]);
		}
		System.out.println("Preorder traversal of  tree is : "); 
		tree.preorder_traversal(tree.root); 
	} 
} 

