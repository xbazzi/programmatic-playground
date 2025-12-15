#include <vector>

int binary_search(const std::vector<int> &v, int target)
{
    auto left = v.begin();
    auto right = v.end();
    for (; left != right;)
    {
        auto mid = left + (right - left) / 2;
        if (*mid == target)
            return std::distance(v.begin(), mid);
        else if (*mid < target)
            left = mid;
        else
            right = mid;
    }
}

#include <print>
int main()
{
    std::vector<int> v{1, 2, 3};
    std::print("{}", binary_search(v, 2));
    return 0;
}