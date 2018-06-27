swap = 0

def merge(A, B):
    C = []
    i = 0
    j = 0 
    while i < len(A) and j < len(B):
        if A[i] <= B[j]:
            C.append(A[i])
            i+=1
        else:
            global swap
            swap+=len(A)-i
            C.append(B[j])
            j+=1


    if i < len(A):
        C = C + A[i:]

    if j < len(B):
        C = C + B[j:]
    return C

def merge_sort(A):

    if len(A) <= 1:
        return A
    
    n = len(A)
    a = merge_sort(A[:n//2])
    b = merge_sort(A[n//2:])
    return merge(a, b)
