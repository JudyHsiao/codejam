def main():
    t = int(input())  # read a line with a single integer
    for i in range(1, t + 1):
        n = int(input())
        opt = [int(s) for s in raw_input().split(" ")]
        err = burger_opt(n, opt)

        print("Case #{}: {}".format(i, err))
        


if __name__ == "__main__":
    main()