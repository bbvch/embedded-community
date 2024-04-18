module;

#include <string>

export module simpsons:homer;

import :person;

namespace simpsons
{

export class Homer : public Person
{
public:
    std::string getName() const override
    {
        return "Homer";
    }
    ~Homer() override = default;
};

} // namespace simpsons
