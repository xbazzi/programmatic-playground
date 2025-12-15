#include <iostream>
#include <memory>
// #include <type_traits> //C++17

// C++20 headers
#include <bitset>
#include <concepts>

// 1. The root is BLACK.
// 2. Every leaf is BLACK.
// 3. Both children of a red node are BLACK.
// 4. Every leaf (BLACK) is null.
// 5. Every leaf (BLACK) is at the same level.
// 6. Every simple path from a node to a descendant leaf
//     contains the same number of black nodes.

namespace rbtree
{

enum Color : uint8_t
{
    RED,
    BLACK
};

// C++17
// template <typename T, typename = std::enable_if<std::is_integral_v<T>>>
template <std::integral T> // C++20
class Node
{
  public:
    Node(T new_data) : data{new_data}, right{nullptr}, left{nullptr}, parent{nullptr}, color{RED}
    {
    }

    T data{};
    Color color;
    Node<T> *left{nullptr};
    Node<T> *right{nullptr};
    Node<T> *parent{nullptr};
};

template <std::integral T> // C++20
class RedBlackTree
{
  private:
    Node<T> *root;

    // TODO
    void destroy_tree(Node<T> *node)
    {
        if (!node)
            return;

        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
    }

    [[nodiscard]]
    Node<T> *clone_tree(RedBlackTree<T> &other)
    {
        if (!other)
            return nullptr;

        Node<T> *new_node = new Node(other->data);
        new_node->color = other->color;
        new_node->parent = other->parent;
        new_node->left = clone_tree(other->left, new_node);
        new_node->right = clone_tree(other->right, new_node);

        return new_node;
    }

    void rotate_left(Node<T> *node)
    {
        std::cout << "rotating left" << std::endl;
        Node<T> *right_child = node->right;
        node->right = right_child->left;

        if (right_child->left)
        {
            right_child->left->parent = node;
        }

        right_child->parent = node->parent;

        if (!node->parent)
        {
            root = right_child;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = right_child;
        }
        else
        {
            node->parent->right = right_child;
        }
    }

    void rotate_right(Node<T> *node)
    {
        std::cout << "rotating right" << std::endl;
        Node<T> *left_child = node->left;
        node->left = left_child->right;

        if (left_child->right)
        {
            left_child->right->parent = node;
        }

        left_child->parent = node->parent;

        if (!node->parent)
        {
            root = left_child;
        }
        else if (node == node->parent->left)
        {
            node->parent->left = left_child;
        }
        else
        {
            node->parent->right = left_child;
        }

        left_child->right = node;
        node->parent = left_child;
    }

    void fix_insert(Node<T> *node)
    {
        Node<T> *parent = nullptr;
        Node<T> *grandparent = nullptr;

        while (node != root && node->color == RED && node->parent->color == RED)
        {
            parent = node->parent;
            grandparent = parent->parent;

            if (parent == grandparent->left)
            {
                Node<T> *uncle = grandparent->right;

                if (uncle && uncle->color == RED)
                {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->right)
                    {
                        rotate_left(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    std::cout << "hello" << std::endl;
                    rotate_right(grandparent);
                    std::swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
            else
            {
                Node<T> *uncle = grandparent->left;

                if (uncle && uncle->color == RED)
                {
                    grandparent->color = RED;
                    parent->color = BLACK;
                    uncle->color = BLACK;
                    node = grandparent;
                }
                else
                {
                    if (node == parent->left)
                    {
                        rotate_right(parent);
                        node = parent;
                        parent = node->parent;
                    }

                    rotate_left(grandparent);
                    std::swap(parent->color, grandparent->color);
                    node = parent;
                }
            }
        }

        root->color = BLACK;
    }

    void insert_node(Node<T> *node)
    {
        Node<T> *parent = nullptr;
        Node<T> *current = root;

        while (current)
        {
            parent = current;
            if (node->data < current->data)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }

        node->parent = parent;

        if (!parent)
        {
            root = node;
        }
        else if (node->data < parent->data)
        {
            parent->left = node;
        }
        else
        {
            parent->right = node;
        }

        fix_insert(node);
    }

  public:
    RedBlackTree() : root{nullptr}
    {
    }

    // Copy ctor
    RedBlackTree(const RedBlackTree &other) : root{nullptr}
    {
        root = clone_tree(other);
    }

    // Copy assignment
    RedBlackTree &operator=(const RedBlackTree &other)
    {
        if (this != &other)
        {
            destroy_tree(root);
            root = clone_tree(other.root);
        }
        return *this;
    }

    // Move ctor
    RedBlackTree(RedBlackTree &&other) noexcept : root{other.root}
    {
        delete other.root;
    }

    // Move assignment
    RedBlackTree &operator=(RedBlackTree &&other) noexcept
    {
        if (this != &other)
        {
            destroy_tree(root);
            root = other.root;
        }
        return *this;
    }

    // Bye
    ~RedBlackTree()
    {
        destroy_tree(root);
    }

    void insert(T data)
    {
        Node<T> *new_node = new Node(data);
        insert_node(new_node);
    }

    void traverse_in_order(Node<T> *node)
    {
        if (!node)
            return;
        traverse_in_order(node->left);
        std::cout << +node->data << " ";
        traverse_in_order(node->right);
    }

    void print()
    {
        traverse_in_order(root);
        std::cout << std::endl;
    }
};

} // namespace rbtree