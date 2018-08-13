import io
import sys
import collections

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
        A =[]
        self._inorder(self.root, A)
        return A

    def _inorder(self, n, A):
        if n is not None:
            self._inorder(n.left, A)
            A.append(n.key)
            self._inorder(n.right, A)

    def insert(self, key):
        #self.root = self._insert(self.root, key)
        if self.root is None:
            self.root = Node(key)
            return
        
        n = self.root
        while True:
            if n.key > key:
                if n.left is None:
                    n.left = Node(key)
                    return
                n = n.left
            else:
                if n.right is None:
                    n.right = Node(key)
                    return
                n = n.right

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
        self.root = self._deleteNode(self.root, key)
 
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
            n.right = self._deleteNode(n.right, key)
    
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

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def countOdds(A, s ,t):
    o = 0
    for i in range(s, t+1):
        if A[i] %2 ==1:
            o+=1
    return o


def main():
    T = int(input())  # read a line with a single integer

    for t in range(1, T + 1):
        
        [N, O, D] = [int(s) for s in input().split()]
        [X1, X2, A, B, C, M, L] = [int(s) for s in input().split()]
        X = [0] * (N+1)
        X[1] = X1
        X[2] = X2
        S = [0] * (N+1)
        for i in range(3,N+1):
            X[i] = (A*X[i-1] + B*X[i-2] + C) % M 

        for i in range(1, N+1):
            S[i] = X[i] + L
        
        PS = [0] * (N+1)
        for i in range(1, N+1):
            PS[i] = PS[i-1] + S[i]

        bst = BST()
        bst.insert(0)
        odd = 0
        left = 1
        maxSum = -float("inf")
        for i in range(1, N+1):
            if S[i] % 2 == 1:
                odd +=1

            while odd > O and left < i:
                if S[left] % 2 == 1:
                    odd -=1 
                bst.delete(PS[left-1])
                left+=1 

            s = bst.lowerBound(PS[i] - D)
            if s is not None:
                tmp = PS[i] - s
                if tmp > maxSum:
                    maxSum = tmp

            bst.insert(PS[i])

        if maxSum == -float("inf"):
            print("Case #{}: IMPOSSIBLE".format(t))
        else:
            print("Case #{}: {}".format(t, maxSum))
        


if __name__ == "__main__":
    main()