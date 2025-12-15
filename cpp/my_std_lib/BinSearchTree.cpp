#include "LinkedList.cpp"
#include <iostream>
#include <memory>

namespace tree
{
template <typename T> class BinSearchTree
{
  public:
    std::unique_ptr<BinSearchTree> left;
    std::unique_ptr<BinSearchTree> right;

    // Default constructor
    BinSearchTree(T inVal) : val{inVal}, left{nullptr}, right{nullptr}, duplicates{}
    {
    }

    // Move constructor
    BinSearchTree(BinSearchTree &&other) noexcept
        : val{std::move(other.val)}, left{std::move(other.left)}, right{std::move(other.right)},
          duplicates{std::move(other.duplicates)}
    {
        other.left = nullptr;
        other.right = nullptr;
    }

    ~BinSearchTree() = default;

    /// @brief  Return the value of the node
    /// @param  node
    /// @return Value of node
    auto get_val(const BinSearchTree<T> *node) const -> int
    {
        return node->val;
    }

    /// @brief  Insert a new node into the tree with inorder traversal
    /// @param  newVal
    auto insert(const T newVal) -> const void
    {
        if (newVal < val)
        {
            if (this->left)
            {
                this->left->insert(newVal);
            }
            else
            {
                this->left = std::make_unique<BinSearchTree>(newVal);
            }
        }
        else if (newVal > val)
        {
            if (this->right)
            {
                this->right->insert(newVal);
            }
            else
            {
                this->right = std::make_unique<BinSearchTree>(newVal);
            }
        }
        else
        { // newVal == val
            duplicates.insert_end(val);
        }
    }

    auto operator+(int inc) -> BinSearchTree<T>
    {
        BinSearchTree<T> curNode = this;
        while (curNode)
        {
            if (curNode->left)
            {
                curNode->left;
            }
            else if (curNode->right)
            {
                curNode->right;
            }
        }
    }

    auto print_preorder() const -> void
    {
        std::cout << get_val(this) << " ";
        if (duplicates.head)
        {
            duplicates.print_list();
        }
        if (left)
            left->print_preorder();
        if (right)
            right->print_preorder();
    }

    auto print_inorder() const -> void
    {
        if (left)
            left->print_inorder();
        std::cout << get_val(this) << " ";
        if (duplicates.head)
        {
            duplicates.print_list();
        }
        if (right)
            right->print_inorder();
    }

    auto print_postorder() const -> void
    {
        if (left)
            left->print_inorder();
        if (right)
            right->print_inorder();
        std::cout << get_val(this) << " ";
        if (duplicates.head)
        {
            duplicates.print_list();
        }
    }

  private:
    LinkedList<T> duplicates;
    T val;
};

template <typename T> auto main() -> int
{
    int val = 1;
    auto root = std::make_unique<BinSearchTree<int>>(val);

    root->insert(7);
    root->insert(7);
    root->insert(3);
    root->insert(9);
    root->insert(8);

    root->print_preorder();
    std::cout << std::endl;

    root->print_inorder();
    std::cout << std::endl;

    root->print_postorder();
    std::cout << std::endl;

    return 0;
}

} // namespace tree

int main()
{
    return tree::main<int>();
}