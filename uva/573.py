import sys

def main():

    for line in sys.stdin:
        [H, U, D, F] = [int(c) for c in line.split()]
        if H == 0:
            exit(0)
        d = 1
        h = 0
        fatigue = float(F * U) / 100.0

        while h < H :
            u = U - (d-1) * fatigue
            if u < 0:
                u = 0 
            h += u
            if h > H:
                print("success on day {}".format(d))
                break
            h -=D
            if h <0:
                print("failure on day {}".format(d))
                break
            d+=1
        
    
    exit(0)
        


if __name__ == "__main__":
    main()