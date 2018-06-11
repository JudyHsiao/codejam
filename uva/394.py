import collections
def cal_address(A, ask):
    B = A[0]
    S = A[1]
    D = A[2]
    bounds = [(0, 0)]
    for i in range(3, len(A), 2):
        bounds.append((A[i], A[i+1]))

    C = [0] * (D+1)
    C[D] = S
    for i in range(D-1, 0 , -1):
        C[i] = C[i+1]*(bounds[i+1][1] - bounds[i+1][0] +1)
    C[0] = B
    for i in range(1,D+1):
        C[0]=C[0]-C[i]*bounds[i][1]

    ans = C[0]
    for i in range(1,D+1):
        ans += C[i]*int(ask[i])
    return ans



def main():
    [N, R] = [int(s) for s in input().split(" ")]
    A = collections.defaultdict(list)
    for i in range(N):
        tmp =  [s for s in input().split(" ")]
        A[tmp[0]] =[ int(s) for s in tmp[1:] if s != ""]
    for i in range(R):
        ask = [s for s in input().split(" ") if s != ""]
        address = cal_address(A[ask[0]], ask)
        print("{}[{}] = {}".format(ask[0], ", ".join(ask[1:]), address))


if __name__ == "__main__":
    main()