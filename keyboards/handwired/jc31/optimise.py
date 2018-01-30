def permute(xs, low=0):
    if low + 1 >= len(xs):
        yield xs
    else:
        for p in permute(xs, low + 1):
            yield p
        for i in range(low + 1, len(xs)):
            xs[low], xs[i] = xs[i], xs[low]
            for p in permute(xs, low + 1):
                yield p
            xs[low], xs[i] = xs[i], xs[low]

file = open('possible.txt', 'w', 8192)
for p in permute(['e','t','a','o','i','n','s','r', 'h', 'l']):#,'r','h','l','d', 'c', 'u', 'm', 'f']):
    file.write(''.join(p))
    file.write('\n')
file.close()
