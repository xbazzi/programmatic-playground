#include <algorithm>
#include <concepts>
#include <cstdlib>
#include <print>
#include <vector>

// Meh way of doing it:
//
// template <class T>
// void partition(std::vector<T>& v, bool (*predicate)(T))
//
// Better:
template <class T, class Predicate>
    requires std::is_trivially_constructible_v<T> and std::invocable<Predicate, T>
void bad_partition(std::vector<T> &v, Predicate pred)
{
    typename std::vector<T>::size_type n = v.size();
    typename std::vector<T>::size_type i = 0;
    typename std::vector<T>::size_type j = n - 1;
    std::vector<T> res(n);

    for (auto k{0}; k < v.size(); ++k)
    {
        if (pred(v[k]))
            res[i++] = v[k];
        else
            res[j--] = v[k];
    }

    v = std::move(res);
}

template <class T, class Predicate>
    requires std::is_trivially_constructible_v<T> and std::invocable<Predicate, const T &>
auto iter_partition(std::vector<T> &v, Predicate pred) -> decltype(v.begin())
{
    auto first = v.begin();
    auto last = v.end();
    first = std::ranges::find_if_not(v, pred);
    if (first == last)
        return first;

    for (auto it = std::next(first); it != last; ++it)
    {
        if (pred(*it))
        {
            std::iter_swap(it, first);
            ++first;
        }
    }
    return first;
}

int main()
{
    std::vector v{1, 2, 3, 4, 5};
    auto pred = [](const int i) { return i < 6; };
    auto partition_point = iter_partition(v, pred);
    std::println("Partition point index: {}", std::distance(v.begin(), partition_point));
    std::ranges::for_each(v, [](const auto &val) { std::print("{} ", val); });
    std::println("");
    return EXIT_SUCCESS;
}