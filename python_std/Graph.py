from typing import List, Any
from enum import Enum, auto

class State(Enum):
    UNVISITED = auto()
    VISITING = auto()
    VISITED = auto()

class Graph:
    def __init__(self, directed: bool=False):
        self.adjacency_list = {}
        self.directed = directed
        self.state = {}

    def add_vertex(self, vertex):
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []
            self.state[vertex] = State.UNVISITED

    def add_edge(self, src, dst):
        self.add_vertex(src)
        self.add_vertex(dst)
        self.adjacency_list[src].append(dst)
        if not self.directed:
            self.adjacency_list[dst].append(src)
    
    def remove_vertex(self, vertex):
        if vertex in self.adjacency_list:
            for v in self.adjacency_list:
                if vertex in self.adjacency_list[v]:
                    self.adjacency_list[v].remove(vertex)
            del self.adjacency_list[v]

    def remove_edge(self, src, dst):
        if src in self.adjacency_list and dst in self.adjacency_list[src]:
            self.adjacency_list[src].remove(dst)
        if not self.directed and dst in self.adjacency_list and src in self.adjacency_list[dst]:
            self.adjacency_list[dst].remove(src)
    
    def get_vertices(self) -> List[Any]:
        return list(self.adjacency_list.keys())

    
    def display(self):
        for vertex, edges in self.adjacency_list.items():
            print(f"{vertex}: {edges}")
