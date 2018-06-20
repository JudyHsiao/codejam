import sys

def convert(n):
    res = 0
    for i in range(8):

        b = n&255
        print(n, b) 
        n = n>>8
        res = res<<8
        res = res | b
    return res
    



def main():

    for line in sys.stdin:
        n = int(line)  # read a line with a single integer
        m = convert(n)
        print("{} converts to {}".format(n, m))
    
    exit(0)
        


if __name__ == "__main__":
    main()