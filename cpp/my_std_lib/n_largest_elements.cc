#include <algorithm>
#include <cstdlib>
#include <print>
#include <queue>
#include <ranges>
#include <vector>

template <bool Ordered = false> std::vector<int> n_largest_elements(const std::vector<int> &v, int n)
{
    if (n > v.size())
        return v;
    std::vector<int> result{v};
    if constexpr (Ordered)
    {
        std::ranges::partial_sort(result, result.begin() + n, std::ranges::greater{});
    }
    else
    {
        std::ranges::nth_element(result, result.begin() + n, std::ranges::greater{});
    }

    return result | std::views::take(n) | std::ranges::to<std::vector<int>>();
}

#include <print>
int main()
{
    std::vector<int> v{1, 2, 32, 40, 15, 6, 7};

    std::ranges::for_each(n_largest_elements<true>(v, 10), [](const auto &el) { std::print("{} ", el); });
    return EXIT_SUCCESS;
}