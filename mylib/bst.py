
# A Binary Tree Node
class Node:
    # Constructor to create a new node
    def __init__(self, key):
        self.key = key 
        self.left = None
        self.right = None
 
 
# A utility function to do inorder traversal of BST
class BST(object):
    def __init__(self):
        self.root = None

    def inorder(self):
        self._inorder(self.root)

    def _inorder(self, n):
        if n is not None:
            self._inorder(n.left)
            print(n.key)
            self._inorder(n.right)

    def insert(self, key):
        self.root = self._insert(self.root, key)

    # A utility function to insert a new node with given key in BST
    def _insert(self, node, key):
        # If the tree is empty, return a new node
        if node is None:
            return Node(key)
    
        # Otherwise recur down the tree
        if key < node.key:
            node.left = self._insert(node.left, key)
        else:
            node.right = self._insert(node.right, key)
    
        # return the (unchanged) node pointer
        return node

    def upperBound(self, D):  # node.key <= D 
        ans = None
        n = self.root
        while n is not None:
            if n.key > D:
                n = n.left
            elif n.key == D:
                ans = n
                return ans.key
            else:
                if ans is None or n.key > ans.key:
                    ans = n
                n = n.right
       
        if ans == None:
            return None
        else:
            return ans.key

    def lowerBound(self, D):  # node.key >= D 
        ans = None
        n = self.root
        while n is not None:
            if n.key > D:
                if ans is None or n.key < ans.key:
                    ans = n
                n = n.left
            elif n.key == D:
                ans = n
                return ans.key
            else:
                n = n.right
       
        if ans == None:
            return None
        else:
            return ans.key
 
    def _minValueNode(self, n):
        current = n
    
        # loop down to find the leftmost leaf
        while(current.left is not None):
            current = current.left 
    
        return current 

    def delete(self, key):
        self._deleteNode(self.root, key)
 
    # Given a binary search tree and a key, this function
    # delete the key and returns the new root
    def _deleteNode(self, n, key):
    
        # Base Case
        if n is None:
            return n 
    
        # If the key to be deleted is smaller than the root's
        # key then it lies in  left subtree
        if key < n.key:
            n.left = self._deleteNode(n.left, key)
    
        # If the kye to be delete is greater than the root's key
        # then it lies in right subtree
        elif(key > n.key):
            n.right = self.deleteNode(n.right, key)
    
        # If key is same as root's key, then this is the node
        # to be deleted
        else:
            
            # Node with only one child or no child
            if n.left is None :
                temp = n.right 
                n = None
                return temp 
                
            elif n.right is None :
                temp = n.left 
                n = None
                return temp
    
            # Node with two children: Get the inorder successor
            # (smallest in the right subtree)
            temp = self._minValueNode(n.right)
    
            # Copy the inorder successor's content to this node
            n.key = temp.key
    
            # Delete the inorder successor
            n.right = self._deleteNode(n.right , temp.key)
        return n 

bst = BST()
bst.insert(50)
bst.insert(30)
bst.insert(20)
bst.insert(40)
bst.insert(70)
bst.insert(60)
bst.insert(80)

bst.inorder()
n = bst.upperBound(50)
print("upper Bound {}".format(n))
n = bst.lowerBound(50)
print("lower Bound {}".format(n))


bst.delete(50)
bst.inorder()
n = bst.upperBound(50)
print("upper Bound {}".format(n))
n = bst.lowerBound(50)
print("lower Bound {}".format(n))