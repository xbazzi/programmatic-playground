class BinTreeNode:
    value: int
    left: "BinTreeNode | None"
    right: "BinTreeNode | None"
    def __init__(self, value=0):
        self.value = value
        self.left = None
        self.right = None

    def insert(self, new_val):
        if new_val < self.value:
            if self.left:
                self.left.insert(new_val)
            else:
                self.left = BinTreeNode(new_val)
        else:
            if self.right:
                self.right.insert(new_val)
            else:
                self.right = BinTreeNode(new_val)
    

    @staticmethod
    def print_inorder(root):
        if not root:
            return
        BinTreeNode.print_inorder(root.left)
        print(root.value)
        BinTreeNode.print_inorder(root.right)

    @staticmethod
    def print_left(root):
        if not root:
            return
        print(root.value)
        BinTreeNode.print_inorder(root.left)

    @staticmethod
    def print_right(root):
        if not root:
            return
        print(root.value)
        BinTreeNode.print_inorder(root.right)

    @staticmethod
    def levels(root) -> int:
        if not root:
            return 0
        resultL = 1 + BinTreeNode.levels(root.right)
        resultR =  1 + BinTreeNode.levels(root.left)
        return max(resultL, resultR)


def main():
    root = BinTreeNode(3)
    root.insert(0)
    root.insert(-1)
    root.insert(1)
    # root.insert(2)
    # root.insert(6)
    # root.insert(5)
    # root.insert(11)
    # root.insert(-1)
    root.insert(4)
    # root.insert(7)
    # root.insert(8)
    # root.insert(87)
    # root.insert(289)

    BinTreeNode.print_inorder(root)
    # BinTreeNode.print_left(root)
    # BinTreeNode.print_left(root)

    print(f"Tree is {BinTreeNode.levels(root)} deep.")

if __name__ == "__main__":
    main()