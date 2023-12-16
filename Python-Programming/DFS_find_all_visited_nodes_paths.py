# Find all visited path in graph No revisited
class GNode:
    def __init__(self, data, color="W", parent = None):
        self.data = data
        self.color = color
        self.parent = parent

def DFS(graph, curr, visited, path, all_paths):
    curr.color = "G"
    visited.add(curr.data)
    path.append(curr.data)
    
    if len(visited) == len(graph):
        all_paths.append(path.copy())
    else:
        for nxt in graph[curr]:
            if nxt.data not in visited:
                nxt.parent = curr
                DFS(graph, nxt, visited, path, all_paths)

    # Backtrack
    curr.color = "W"
    visited.remove(curr.data)
    path.pop()

def find_all_paths(graph):
    all_paths = []

    for start in graph:
        visited = set()
        path = []
        DFS(graph, start, visited, path, all_paths)

    return all_paths

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F = GNode("D"), GNode("E"), GNode("F")

G = {
    A: [B, C],
    B: [A, C, D],
    C: [A, B, D],
    D: [B, C, E],
    E : [D],
}

res = find_all_paths(G)

print(res)