from collections import deque


graph = {}
graph['you'] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []


def is_mango_seller(name):
    return name[-1] == 'j'


def search(name):
    bfs = deque()
    bfs += graph[name]
    watched = []
    while bfs:
        person = bfs.popleft()
        if person not in watched:
            if is_mango_seller(person):
                print(person, "is mango seller!")
                return True
            else:
                bfs += graph[person]
                watched.append(person)
    print("There is not any mango seller")
    return False


search("you")
