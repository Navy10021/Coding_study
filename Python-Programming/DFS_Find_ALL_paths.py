class GNode:
    def __init__(self, data, color = "W"):
        self.data = data 
        self.color = color 
    
    def __str__(self):
        return "(" + self.data + ")" 
    
def find_all_paths(G, start, end, path = None):
    if path is None:
        path = []
    # Base case 
    #path = path + [start.data]
    path.append(start.data)
    if start == end:
        return [path]
    
    if start not in G:
        return []
    
    paths = []
    for nxt in G[start]:
        if nxt.data not in path:        # Need to not modifiy original path.
            new_paths = find_all_paths(G, nxt, end, path.copy())    # new copy path preventing the issue of modifying the Original path
            for p in new_paths:
                paths.append(p)
    
    return paths

A, B, C = GNode("A"), GNode("B"), GNode("C")
D, E, F, G = GNode("D"), GNode("E"), GNode("F"), GNode("G")

# Adj List (Directed edges)
#Graph = dict()
G = dict()
G[A] = [B, C]
G[B] = [A, D]
G[C] = [A, D]
G[D] = [B, C, F, E]
G[E] = [D, F]
G[F] = [D, E]

start_vertex = A 
end_vertex = F 
all_paths = find_all_paths(G, start_vertex, end_vertex)
print(all_paths)