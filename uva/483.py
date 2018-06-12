import sys

def main():

    for line in sys.stdin:
        t = line.strip('\n')[::-1]
        l = t.split(" ")[::-1]
        print("{}".format(" ".join(l)))

if __name__ == "__main__":
    main()