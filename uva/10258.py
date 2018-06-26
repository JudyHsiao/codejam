import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():

    t = int(input())  # read a line with a single integer
    input()
    for i in range(1, t + 1):
        T = collections.defaultdict(dict)
        F = collections.defaultdict(dict)
        for line in sys.stdin:
            if line.strip() == "":
                break

            [c, p, t, L] = [s for s in line.strip().split(" ")]
            
            if p not in T[c] or T[c][p] == 0: 
                if L =="I":
                    T[c][p] = 0
                    if p not in F[c]:
                        F[c][p] = 1
                    else:
                        F[c][p]+=1
                elif L =="C":
                    if p not in F[c]:
                        fail_count  = 0
                    else:
                        fail_count = F[c][p]
                    T[c][p] = int(t) + 20 * fail_count
                else :
                    T[c][p] = 0

            A = []
            for k ,D in T.items():
                count = 0
                time = 0
                for t in D.values():
                    if t > 0:
                        count += 1
                        time += t
                A.append((k, count , time))
            
            A = sorted(A, key=lambda x: x[0])
            A = sorted(A, key=lambda x: x[2])
            A = sorted(A, key=lambda x: x[1], reverse= True)

        for x in A:   
            print("{} {} {}".format(x[0], x[1], x[2]))
        
        


if __name__ == "__main__":
    main()