import math

size = 8
stages = int(math.log2(size))
print(stages)

n_butterflys = pow(2, stages-1)
print(n_butterflys)


for s in range(stages):
    print(s)
    m            = pow(2, s+1) # Wn => Wn(j*N/m)
    distance     = pow(2, s)
    groups       = m
    #groups   = 1<<(s+1) => m!!
    #sections = 1<<s     => distance!!
    for g in range(groups):
        print(g)
        print(g, m)
        print(n_butterflys, groups)
        for n in range(n_butterflys//groups):
            u_idx = g*m + n
            v_idx = g*m + n + distance
            w_idx =0 
            print(f'\tu: {u_idx}, v: {v_idx}, w:{w_idx}')
    print('\n')

print('ou')


    

#
#for s in range(stage):
#    groups = 1<<(s+1)
#    sections = 1<<s
#    n_groups_per_section = 2
#    data_per_sections = size // sections
#    data_per_group = size // groups
#    print(f'Stage: {s}')
#    print(f'Groups: {groups}')
#    print(f'Sections: {sections}')
#    print(f'Data per section: {data_per_sections}')
#    print(f'Data per group: {data_per_group}')
#    w_idx_0 = 0
#    for z in range(sections): 
#        for ng in range(n_groups_per_section):
#            for g in range(data_per_group):
#                u_idx = g + z*(data_per_sections) 
#                v_idx = g + z*(data_per_sections) + data_per_group
#                w_idx = + ng * (size>>1)
#                #print(f'z: {z}, ng: {ng}')
#                print(f'\tu: {u_idx}, v: {v_idx}, w:{w_idx}')
#    print('\n')

