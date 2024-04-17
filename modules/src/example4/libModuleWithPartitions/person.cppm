module;

#include <string>

export module simpsons:person;

namespace simpsons
{

class Person
{
public:
    virtual std::string getName() const
    {
        return "Unknown";
    };
    virtual ~Person() = default;
};

} // namespace simpsons
