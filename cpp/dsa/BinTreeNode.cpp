#include <iostream>
#include <memory>

namespace tree {
template<typename T>
class BinTreeNode {
public:
    std::unique_ptr<BinTreeNode> left;
    std::unique_ptr<BinTreeNode> right;

    BinTreeNode(T inVal) : val{inVal}, left{nullptr}, right{nullptr} {}

    BinTreeNode(BinTreeNode &&other) noexcept : val{std::move(other.val)}, left{std::move(other.left)}, right{std::move(other.right)} {
        other.left = nullptr;
        other.right = nullptr;
    }

    auto getVal(const BinTreeNode<T>* node) const -> int {
        return node->val;
    }

    /// @brief  Insert a new node into the tree with inorder traversal
    /// @param newVal 
    void insert(const T newVal) {
        if (newVal < val) {
            if (this->left) {
                this->left->insert(newVal);
            } else {
                this->left = std::make_unique<BinTreeNode>(newVal);
            }
        } else if (newVal > val) {
            if (this->right) {
                this->right->insert(newVal);
            } else {
                this->right = std::make_unique<BinTreeNode>(newVal);
            }
        } else { // newVal == val
            return;
        }
    }

    auto operator+(int inc) -> BinTreeNode<T> {
        BinTreeNode<T> curNode = this;
        while(curNode) {
            if(curNode->left) {
                curNode->left;
            } else if (curNode->right) {
                curNode->right;
            }
        }

    }

    auto print_preorder() const -> void {
        std::cout << getVal(this) << " ";
        if (left) left->print_preorder();
        if (right) right->print_preorder();
    }

    auto print_inorder() const -> void {
        if (left) left->print_inorder();
        std::cout << getVal(this) << " ";
        if (right) right->print_inorder();
    }

    auto print_postorder() const -> void {
        if (left) left->print_inorder();
        if (right) right->print_inorder();
        std::cout << getVal(this) << " ";
    }


private:
    T val;
};

template<typename T>
auto main() -> int {
    int val = 1;
    auto root = std::make_unique<BinTreeNode<int>>(val);
    root->insert(1);
    root->insert(7);
    root->insert(1);
    root->insert(3);
    root->insert(9);
    root->insert(8);
    //root->left = std::make_unique<BinTreeNode<int>>(++val);
    //root->right = std::make_unique<BinTreeNode<int>>(++val);
    //root->right->left = std::make_unique<BinTreeNode<int>>(++val);
    //root->right->right = std::make_unique<BinTreeNode<int>>(BinTreeNode(++val));
    root->print_preorder();
    std::cout << std::endl;
    root->print_inorder();
    std::cout << std::endl;
    return 0;
}

}

int main() {
    return tree::main<int>();
}