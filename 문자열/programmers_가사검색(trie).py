class Node:
    def __init__(self):
        self.count = 0
        self.children = {}

class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, word):
        cur = self.root

        for ch in word:
            cur.count += 1

            if ch not in cur.children:
                cur.children[ch] = Node()
            cur = cur.children[ch]

    def search(self, query):
        cur = self.root
        for ch in query:
            if ch not in cur.children:
                return 0
            cur = cur.children[ch]
        return cur.count


def solution(words, queries):
    answer = []

    starts = [Trie() for _ in range(10001)]
    ends = [Trie() for _ in range(10001)]

    for w in words:
        starts[len(w)].insert(w)
        ends[len(w)].insert(w[::-1])

    for que in queries:
        if que[0] == '?':
            answer.append(ends[len(que)].search(que[::-1].strip('?')))
        else:
            answer.append(starts[len(que)].search(que.strip('?')))

    return answer