
class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def append(self, val): 
        new_node = Node(val)
        if not self.head:
            self.head = new_node
            return
        last = self.head
        while last.next:
            last = last.next
        last.next = new_node
    
    def print(self) -> None:
        current = self.head
        while current:
            print(current.val, end=" -> ")
            current = current.next
        print("None")

def main():
    ll = LinkedList()
    ll.append(32)
    ll.append(31)
    ll.append(39)
    ll.print()

if __name__ == "__main__":
    main()