#include <algorithm>
#include <concepts>
#include <cstdlib>
#include <vector>

// Meh way of doing it:
//
// template <class T>
// void partition(std::vector<T>& v, bool (*predicate)(T))
//
// Better:
template <class T, class Predicate>
    requires std::is_trivially_constructible_v<T> and std::invocable<Predicate, T>
void partition(std::vector<T>& v, Predicate pred)
{
    class std::vector<T>::size_type n = v.size();
    class std::vector<T>::size_type j = n - 1;
    std::vector<T> res(n, T {});

    for (auto i { n - n }; i < v.size(); ++i) {
        if (pred(v[i]))
            res[i] = v[i];
        else
            res[j++] = v[i];
    }

    std::ranges::move(res, v);
}

int main()
{
    return EXIT_SUCCESS;
}