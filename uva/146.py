import io
import sys
import collections


# Simulate the redirect stdin.
if len(sys.argv) > 1:
    filename = sys.argv[1]
    inp = ''.join(open(filename, "r").readlines())
    sys.stdin = io.StringIO(inp)

def main():

   for line in sys.stdin:
        line = line.strip()
        if line == "#":
           exit(0)
        print(sorted(line,reverse=True))
        if line == sorted(line,reverse=True):
            print("No Successor")
        


if __name__ == "__main__":
    main()
