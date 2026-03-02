import math

size = 8
stages = int(math.log2(size))
#print(stages)

n_butterflys = pow(2, stages-1)
print(n_butterflys)

for s in range(stages):
    print(s)
    m            = pow(2, s+1) # Wn => Wn(j*N/m)
    distance     = pow(2, s)
    groups       = size // m
    print(groups)
    for g in range(groups):
        for n in range(n_butterflys//groups):
            print(g, m, n)
            u_idx = g*m + n
            v_idx = g*m + n + distance
            w_idx = n*(size // m ) # n*groups
            print(f'\tu: {u_idx}, v: {v_idx}, w:{w_idx}')
    print('\n')

