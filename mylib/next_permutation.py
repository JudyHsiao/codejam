def next_permutation(A):
    for i in range(len(A)-1, -1 ,-1):
        for j in range(i, -1, -1):
            if A[j] < A[i]:
                #print(i, j, A[i], A[j], A)
                A[i],A[j] = A[j], A[i]
                #print(i, j, A[i], A[j], A)
                A[j+1:] = A[j+1:][::-1]
                return A
    
    return None