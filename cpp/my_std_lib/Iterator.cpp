#include <iostream>
#include <memory>
#include <vector>

template <typename T> class Iterator
{
  public:
    Iterator() : _vec{0}
    {
    }
    Iterator(std::vector<T> &vec) : _vec{vec}
    {
    }
    Iterator(std::vector<T> &&vec) : _vec{std::move(vec)}
    {
    }

    T *begin()
    {
        ptr = &_vec[0];
        return ptr;
    }

    T *end()
    {
        ptr = &_vec[_vec.size() - 1];
        return ptr;
    }

    // void const print(const Iterator& start = _vec.Iterator::begin(), const Iterator& end = _vec.Iterator::end())
    // const
    static void const print(const T *start, const T *end)
    {
        /// @todo Implement this properly, not with values; there could be duplicates.
        while (*start != *end)
        {
            std::cout << *++start << " ";
        }
        std::cout << std::endl;
    }

  private:
    T *ptr;
    std::vector<T> _vec;
};

int main()
{
    std::vector<int> test(2);
    test.push_back(1);
    test.push_back(5);

    const std::unique_ptr<Iterator<int>> it = std::make_unique<Iterator<int>>(test);
    std::cout << *it->begin() << std::endl;
    std::cout << *it->end() << std::endl;
    Iterator<int>::print(it->begin(), it->end());
}