#include <cstdlib>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    std::unordered_map<std::string, std::vector<std::string>> map;
    map.insert({"A", {"B", "C", "D"}});

    return EXIT_SUCCESS;
}