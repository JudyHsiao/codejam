IN = open('input.txt', 'r')
OUT = open('output.txt', 'w')

import string

def g(s):
    if s[-1] == '`':
        return 0

    if s in g_cache:
        return g_cache[s]

    r = 0
    l = len(s)
    for x in range(l, 2*l):
        y = 2*l - x
        if x <= N and s[-y:] == s[-y:][::-1]:
            r += 1

    for x in range(2*l, N+1):
        r += L ** ((x - 2*l + 1) // 2)
        
    print('g', s, r)
    g_cache[s] = r
    return r

def f(s):
    if s in f_cache:
        return f_cache[s]
        
    r = g(s)
    for i, c in enumerate(s):
        for a in string.ascii_lowercase[:L]:
            if a >= c:
                p = s[:i] + a
                r += 1 if p == p[::-1] else 0
                break
            r += g(s[:i] + a)
    r -= 1 if p == p[::-1] else 0
    
    f_cache[s] = r
    print('f', s, r)
    return r

NUM_TESTS = int(IN.readline())

for test in range(NUM_TESTS):
    L, N, K = map(int,IN.readline().split())
    g_cache = dict()
    f_cache = dict()
    
    answer = ''
    while len(answer) < N:
        if answer and f(answer[:-1] + chr(ord(answer[-1]) - 1)) == K-1 and answer == answer[::-1]:
            break
    
        for c in string.ascii_lowercase[:L]:
            print('ccc',c)
            if f(answer + c) >= K:
                answer += c
                break
        else:
            answer = ''
            break
    print(answer)
    answer = len(answer)
    
    OUT.write('Case #{}: {}\n'.format(test+1, answer))
    print(test+1, answer)
    
IN.close()
OUT.close()
