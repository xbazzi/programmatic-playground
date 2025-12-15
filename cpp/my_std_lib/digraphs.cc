#include <cstdlib>
#include <print>

auto main() -> int
<%
    std::print("{}", sizeof(void));
    return EXIT_SUCCESS;
%>
