size = 16
stage = 4
for s in range(stage):
    groups = 1<<(s+1)
    sections = 1<<s
    n_groups_per_section = 2
    data_per_sections = size // sections
    data_per_group = size // groups
    print(f'Stage: {s}')
    print(f'Groups: {groups}')
    print(f'Sections: {sections}')
    print(f'Data per section: {data_per_sections}')
    print(f'Data per group: {data_per_group}')
    w_idx_0 = 0
    for z in range(sections): 
        for ng in range(n_groups_per_section):
            for g in range(data_per_group):
                u_idx = g + z*(data_per_sections) 
                v_idx = g + z*(data_per_sections) + data_per_group
                if s == size-1:
                    w_idx = z*(size>>s+1) + ng*size//2 + 1
                else:
                    w_idx = z*(size>>s+1) + ng*size//2
                print(f'z: {z}')
                print(f'\tu: {u_idx}, v: {v_idx}, w:{w_idx}')
        print('\n')
    print('\n')
