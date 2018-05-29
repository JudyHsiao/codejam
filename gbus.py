import io
import sys

# Kickstart Practice Round 2018
# https://code.google.com/codejam/contest/4374486/dashboard
# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def getBusCount(c, I):
    count = 0
    for i in I:
        if i[0]<=c :
            if i[1] >=c:
                count +=1
        else:
            break

    return count
def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        #C =  input().strip().split(" ")
        #print(C)
        cities = [int(s) for s in input().strip().split(" ")]
        #print(cities)
        I = []
        for j in range(0,2*n,2):
            I.append((cities[j], cities[j+1]))
      
        I = sorted(I)
        #print(I)
        P= int(input())
        ans=[]
        for p in range(P):
           c = int(input())
           ans.append(str(getBusCount(c, I))) 
        input()
        print("Case #{}: {}".format(i, " ".join(ans)))
        


if __name__ == "__main__":
    main()

    