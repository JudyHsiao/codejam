import sys

def main():
    ans = []
    start = True
    for line in sys.stdin:
        for c in line:
            if c == '"':
                if start == True:
                    ans.append("``")
                else:
                    ans.append("''")
                start = not start
            else:
                ans.append(c)

    print("".join(ans))
        


if __name__ == "__main__":
    main()