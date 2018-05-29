import io
import sys
import collections
import itertools

# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def play(n, cards):
    count = 0
    
    h = [0 for i in range(n+1)]
    
    while i < len(cards):
        first = cards[i]
        h[first]+=1
        if  h[first]==3:
            h[first] = 'C'
            i+=1
            continue

        i+=1
        if card[i] == first: #2 pass
            h[first] +=1
            if  h[first]==3:
                h[first] = 'C'
                i+=1
                continue

            i+=1
            if card[i] == first:  #3 pass
                h[first] = 'C'
                i+=1
                continue
            else:
                h[card[i]] +=1
                i+=1
                count+=1
                continue
        else:
            h[card[i]] +=1
            i+=1
            count+=1
            continue

    for a in h:
        if a != 'C':
            count+=1
    return count


def simulate(n):
    cards= []
    for i in range(1, n+1):
        cards.append(i)
        cards.append(i)
        cards.append(i)
    count = 0
    for t in itertools.permutations(cards, len(cards)):
        count +=play(n, t)
    
    return float(count) / 3**n 
    

def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        ans = simulate(n)

        print("Case #{}: {}".format(i,ans))
        


if __name__ == "__main__":
    main()