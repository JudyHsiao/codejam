import sys
import collections

def minDiff(C, n):
    mDiff = float('inf')
    ans = -1
    for i in range(1, n):
        tmp = 0
        for j in range(1, n):
            if C[j]['r'] != C[i]['r']:
                tmp +=1
            if C[j]['o'] != C[i]['o']:
                tmp +=1
            if C[j]['y'] != C[i]['y']:
                tmp +=1
            if C[j]['g'] != C[i]['g']:
                tmp +=1
            if C[j]['b'] != C[i]['b']:
                tmp +=1
        if tmp < mDiff:
            ans =i
            mDiff = tmp
    return ans



def main():
    while(1):
        C = collections.defaultdict(dict)
        i = 1
        for line in sys.stdin:
            if line[0] == "e":
                ans = minDiff(C,i)
                print(ans)
                break
            if line[0] =="#":
                exit(0)
            mappings = line.split(",")
            for m in mappings:
                [c, t] = [ s.strip() for s in m.split('/')]
                C[i][c] = t
            i +=1


if __name__ == "__main__":
    main()