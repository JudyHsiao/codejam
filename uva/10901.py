import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def other_side(side):
    if side == 0:
        side =1
    else:
        side = 0
    return side

def main():

    T = int(input())  # read a line with a single integer
    for i in range(1, T + 1):
        [n, t, m] = [ int(s) for s in input().split()]
        L = collections.deque()
        R = collections.deque()
        for j in range(m):
            [a, side] = [s for s in input().split()]
            if side == 'left':
                L.append((int(a),j))
            else:
                R.append((int(a),j))

        side = 0
        current_time = 0
        F = [L, R]
        ans=[0] * m
        while len(F[0]) or len(F[1]):
            count = 0
            while len(F[side]) and F[side][0][0] <=current_time and count < n:
                car = F[side].popleft()
                ans[car[1]] = current_time + t
                count +=1
            
            if count > 0:
                side = other_side(side)
                current_time +=t
            else:
                if len(L) > 0 and len(R) > 0:
                    if F[other_side(side)][0][0] < F[side][0][0]:  
                        current_time = max(F[other_side(side)][0][0], current_time) +t
                        side = other_side(side)
                    else:
                        current_time = F[side][0][0]
                elif len(L) == 0:
                    current_time = max(R[0][0], current_time)
                    if side != 1:
                        current_time +=t
                        side = other_side(side)
                else:
                    current_time = max(L[0][0], current_time)
                    if side != 0:
                        current_time +=t
                        side = other_side(side)
                   


        
        for j in range(m):
            print(ans[j])

        if i < T:
            print()





            
        


if __name__ == "__main__":
    main()