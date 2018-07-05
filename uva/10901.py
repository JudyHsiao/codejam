import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)


def main():

    T = int(input())  # read a line with a single integer
    for i in range(1, T + 1):
        [n, t, m] = [ int(s) for s in input().split()]
        L = collections.deque()
        R = collections.deque()
        for j in range(m):
            [n, side] = [for s in input().split()]
            if side == 'left':
                L.append(int(n))
            else:
                R.append(int(n))

        side = 0
        current_time = 0
        F = [L, R]
        while len(F[0]) or len(F[1]):
            count = 0
            while F[side][0] <=current_time and count < n:
                print(current_time +t)
                F[side].popleft()
                count +=1
            
            current_time +=t
            if side == 0:
                side =1
            else:
                side = 0





            
        


if __name__ == "__main__":
    main()