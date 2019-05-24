while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break

    sample = dict()
    for i in range(n):
        sample[i + 1] = None

    for _ in range(m):
        ex_input = input().split()
        if ex_input[0] == '!':
            a, b, c = int(ex_input[1]), int(ex_input[2]), int(ex_input[3])
            if sample[a] is None and sample[b] is None:
                sample[a], sample[b] = 0, c
            elif sample[a] is None and sample[b] is not None:
                sample[a] = sample[b] - c
            elif sample[a] is not None and sample[b] is None:
                sample[b] = sample[a] + c
        else:
            a, b = int(ex_input[1]), int(ex_input[2])

            if sample[a] is None or sample[b] is None:
                print('UNKNOWN')
            else:
                print(sample[b] - sample[a])
