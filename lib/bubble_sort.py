

def bubble_sort(A):
    swap = 0  #least number of swaps of two adjacent number 
    for i in range(len(A)):
        for j in range(i, len(A)):
            if A[i] > A[j]:
                A[i], A[j] = A[j], A[i]
                swap+=1
    
    return swap