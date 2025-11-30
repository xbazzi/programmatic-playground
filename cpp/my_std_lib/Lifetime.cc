#include <algorithm>
#include <cstdlib>
#include <deque>
#include <print>
#include <queue>
#include <source_location>
#include <thread>
#include <utility>
#include <vector>

void print(const std::source_location& loc = std::source_location::current())
{
    std::println("{}", loc.function_name());
}

template <class Type>
void print(const Type& value, const std::source_location& loc = std::source_location::current())
{
    std::println("{}\t{}", value, loc.function_name());
}

template <class Type1, class Type2>
void print(const Type1& value1, const Type2& value2, const std::source_location& loc = std::source_location::current())
{
    std::println("{}->{}\t{}", value1, value2, loc.function_name());
}

struct Lifetime {
    static inline std::size_t m_global_id { 0 };
    std::size_t m_id { ++m_global_id };

    Lifetime()
    {
        ::print(m_id);
    }

    Lifetime(const Lifetime& other)
    {
        ::print(m_id, other.m_id);
    }

    // Lifetime(Lifetime&& other) noexcept
    // {
    //     ::print(m_id, other.m_id);
    //     m_id = std::exchange(other.m_id, m_id);
    // }

    Lifetime& operator=(Lifetime&& other) noexcept
    {
        if (this != &other) {
            ::print(m_id, other.m_id);
            m_id = other.m_id;
        }
        return *this;
    }

    Lifetime& operator=(const Lifetime& other)
    {
        ::print(m_id, other.m_id);
        return *this;
    }

    ~Lifetime()
    {
        ::print(m_id);
    }
};

namespace std {
template <>
struct allocator<Lifetime> {
    using value_type = Lifetime;

    [[nodiscard]]
    constexpr Lifetime* allocate(std::size_t n)
    {
        ::print(n * sizeof(Lifetime), "bytes allocated");
        return static_cast<value_type*>(::operator new(sizeof(Lifetime) * n, align_val_t(alignof(Lifetime))));
    }

    constexpr void deallocate(value_type* l, std::size_t n)
    {
        ::print(n * sizeof(Lifetime), "bytes deleted");
        ::operator delete(l, align_val_t(alignof(Lifetime)));
    }
};
}

static std::vector<Lifetime> get_lifetimes()
{
    // return std::vector<Lifetime>{ Lifetime{}, Lifetime(), Lifetime()};
    return { {}, {}, {} };
}

#include <optional>
std::optional<Lifetime> get_lifetime(std::uint64_t key)
{
    if (key < 42ULL) {
        return std::nullopt;
    }
    return std::optional<Lifetime> { std::in_place };
}

void do_work(Lifetime lifetime)
{
    using namespace std::chrono_literals;
    while (true) {
        int x = x + 1;
        std::print("{} ", lifetime.m_id);
        std::this_thread::sleep_for(1s);
    }
    lifetime = Lifetime {};
}

int main()
{
    int x = 5;
    const int & y = 5;
    for (const auto& _ : get_lifetimes()) {
        std::println("blah");
    }
    // std::ranges::for_each(get_lifetimes(), [](const auto& v) { ; });
    // std::println("sizeof(Lifetime): {}", sizeof(Lifetime));
    // Lifetime a;
    // Lifetime b;
    // Lifetime c;
    // c = b;
    // Lifetime(d);
    // std::vector<Lifetime> q;
    // q.push_back(Lifetime {});
    // std::println("{} ", sizeof(q));
    // d = a;
    // std::optional<Lifetime> a = get_lifetime(100ULL);
    // if (a.has_value()) {
    //     do_work(a.value());
    // }
    return 0;
    // std::cout << a.has_value() << std::endl;
    // if (a.has_value()) {
    //     std::cout << "hi mom" << std::endl;
    // }

    // return a.has_value();
    return 1;
}
