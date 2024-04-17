module;

#include <string>

export module simpsons:lisa;

import :person;

namespace simpsons
{

export class Lisa : public Person
{
public:
    std::string getName() const override
    {
        return "Lisa";
    }
    ~Lisa() override = default;
};

} // namespace simpsons
