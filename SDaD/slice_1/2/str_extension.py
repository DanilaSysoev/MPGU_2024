def max_cnt_symbols(data):
    unique = unique_symbols(data)
    max_cnt = 0
    result = ''
    for s in unique:
        cnt = data.count(s)
        if cnt > max_cnt:
            max_cnt = cnt
            result = s
        elif cnt == max_cnt:
            result += s
    return result


def min_cnt_symbols(data):
    unique = unique_symbols(data)
    min_cnt = len(data) + 1
    result = ''
    for s in unique:
        cnt = data.count(s)
        if cnt < min_cnt:
            min_cnt = cnt
            result = s
        elif cnt == min_cnt:
            result += s
    return result


def unique_symbols(data):
    return ''.join(set(data))


def get_words(data, seps=' '):
    res = []
    parts = [data]
    for sep in seps:
        res = []
        for part in parts:
            ws = part.split(sep)
            res += [w for w in ws if w]
        parts = res
    return res


def names(data):
    words = get_words(data)
    res = []
    for word in words:
        if word[0].isupper():
            res.append(word)
    return res
