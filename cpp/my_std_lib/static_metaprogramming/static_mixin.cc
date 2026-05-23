#include <string>
#include <cstring>

template <class Derived>
class Printable
{
public:
    void print()
    {
        printf("%s", static_cast<Derived*>(this)->to_string());
    }

};

template <class Derived>
class Comparable
{
public:
    bool operator==(const Derived& other)
    {
        return static_cast<Derived*>(this)->compare(other);
    }
};


class User :
    public Printable<User>,
    public Comparable<User>
{
public:
    const char* to_string()
    {
        return name;
    }

    bool compare(User& other)
    {
        const char* other_tok = other.name;
        const char* tok = name;
        size_t count{0};

        if (*tok == '\0' && *other_tok == '\0')
            return true;
        else if(*tok == '\0' || *other_tok == '\0')
            return false;

        while (*tok != '\0' && *other_tok != '\0')
        {
            if (*tok != *other_tok)
                return false;
            other_tok++;
            tok++;
            ++count;
        }
        return other_tok[count] != '\0' || tok[count] != '\0';
    }

    void set_name(const char* new_name)
    {
        std::strcpy(name, new_name);
    }
private:
    char name[14]{};
};

auto main() -> int
{

    User user1;
    user1.set_name("Alex");
    user1.print();
    printf("\n");
    User user2;
    user1.set_name("Alex");
    printf("strings are %s", user1.compare(user2)? "equal": "not equal :/");

    return user1.compare(user2);
}