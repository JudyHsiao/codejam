def counting_sort(A, R): #A:array, R: range
    B=[0] * R
    for i in A:
        B[i] +=1

    ans= []
    for k,v in enumerate(B):
        if v > 0:
            ans += [k] * v

    return ans