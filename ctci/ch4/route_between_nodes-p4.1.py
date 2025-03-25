# BFS implementation

import queue
from python_std.Graph import Graph, State
import tracemalloc
import gc

def is_valid_route(g: Graph, src, dst) -> bool:

    q = queue.Queue()
    q.put(src)
    g.state[src] = State.VISITING
    while not q.empty():
        if (u := q.get()):
            for neighbor in g.adjacency_list[u]:
                print(neighbor)
                if g.state[neighbor] is not State.VISITED:
                    if neighbor == dst:
                        return True
                    else:
                        g.state[neighbor] = State.VISITING 
                        q.put(neighbor)
            g.state[u] = State.VISITED
    return False

def is_valid_route_dfs(g: Graph, src, dst) -> bool:
    def dfs(current) -> bool:
        if current == dst:
            return True
        
        g.state[current] = State.VISITING

        for neighbor in g.adjacency_list[current]:
            if g.state[neighbor] == State.UNVISITED:
                if dfs(neighbor): 
                    return True
        g.state[current] = State.VISITED
        return False

    return dfs(src)

def main():
    print(tracemalloc.start())
    print(gc.get_stats())

    g = Graph()
    g.add_edge("A", "B")
    g.add_edge("B", "C")
    g.add_edge("B", "F")

    g.display()
    print(is_valid_route_dfs(g, "A", "F"))

    # Memory performance
    current, peak = tracemalloc.get_traced_memory()
    print(f"Current memory usage: {current / 1024:.2f} KB")
    print(f"Peak memory usage: {peak / 1024:.2f} KB")

    snapshot = tracemalloc.take_snapshot()
    top_stats = snapshot.statistics('lineno')

    print("\nTop 5 memory allocations:")
    for stat in top_stats[:5]:
        print(stat)

    tracemalloc.stop()

    print(gc.get_stats())

if __name__ == "__main__":
    main()