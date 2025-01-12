from collections import deque


bfs = deque()
graph = {}
graph['you'] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []
bfs += graph["you"]


def person_is_seller(name):
    return name[-1] == 'm'


while bfs:
    print(bfs)
    person = bfs.popleft()
    if person_is_seller(person):
        print(person, "is a mango seller!")
        break
        # return True
    else:
        bfs += graph[person]
# return False

# print(bfs)
