module;

#include <string>

export module simpsons:marge;

import :person;

namespace simpsons
{

export class Marge : public Person
{
public:
    std::string getName() const override
    {
        return "Marge";
    }
    ~Marge() override = default;
};

} // namespace simpsons
