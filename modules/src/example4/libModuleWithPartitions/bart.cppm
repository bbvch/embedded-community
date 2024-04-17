module;

#include <string>

export module simpsons:bart;

import :person;

namespace simpsons
{

export class Bart : public Person
{
public:
    std::string getName() const override
    {
        return "Bart";
    }
    ~Bart() override = default;
};

} // namespace simpsons
