class Node { 
    int key, height; 
    Node left, right; 

    Node(int d) { 
        key = d; 
        height = 1; 
    } 
} 

public class AVLTree { 

    Node root; 
    
    
    //preorder
    void preorder_traversal(Node node) { 
        if (node != null) { 
            System.out.print(node.key + " "); 
            preorder_traversal(node.left); 
            preorder_traversal(node.right); 
        }
    }
    
    int height(Node N) { 
        if (N == null) 
            return 0; 

        return N.height; 
    } 

    int max_element(int a, int b) {
        if(a>b){
            return a;
        }
        else{
            return b;
        }
    } 
    
  //left rotate
    Node lr(Node x) { 
        Node y = x.right; 
        Node T2 = y.left; 
        y.left = x; 
        x.right = T2; 
        x.height = max_element(height(x.left), height(x.right)) + 1; 
        y.height = max_element(height(y.left), height(y.right)) + 1; 
        return y; 
    } 

//right rotate
    Node rr(Node y) { 
        Node x = y.left; 
        Node T2 = x.right;
        x.right = y; 
        y.left = T2; 
        y.height = max_element(height(y.left), height(y.right)) + 1; 
        x.height = max_element(height(x.left), height(x.right)) + 1; 
        return x; 
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
        // Left Right Case  || LR
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

        //creating input array
        int arr[]={100, 200, 150, 170, 165, 180, 220, 163, 164};
        AVLTree tree = new AVLTree(); 
        for(int i=0;i<9;i++){
            tree.root = tree.insert(tree.root, arr[i]);
        }
        System.out.println("Preorder traversal of  tree is : "); 

        //calling preorder_traversal method with our tree node as parameter
        tree.preorder_traversal(tree.root); 
    } 
} 
