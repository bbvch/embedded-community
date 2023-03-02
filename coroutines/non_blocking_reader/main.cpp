#include "read_result.h"
#include "read_stub.h"
#include "read_test.h"

#include <iostream>
#include <cassert>

int main(void)
{
    {
        ReadStub stub;
        std::cout << "***TEST 1***" << std::endl;
        stub.write("the quick brown fox ");
        stub.write("jumps over the lazy dog.");
        stub.setEOF();
        auto result = readTest(stub);
        std::cout << "main: <-- from coroutine" << std::endl;
        assert(result.hasResult());
        std::cout << "main: Result is: " << result.getResult() << std::endl;
    }

    {
        ReadStub stub;
        std::cout << "***TEST 2***" << std::endl;
        stub.write("the quick brown fox ");
        auto result = readTest(stub);
        std::cout << "main: <-- from coroutine" << std::endl;
        assert(!result.hasResult());
        stub.write("jumps over the lazy dog.");
        stub.setEOF();
        assert(result.hasResult());
        std::cout << "main: Result is: " << result.getResult() << std::endl;
    }

    {
        ReadStub stub;
        std::cout << "***TEST 3***" << std::endl;
        auto result = readTest(stub);
        std::cout << "main: <-- from coroutine" << std::endl;
        assert(!result.hasResult());
        stub.write("the quick brown fox ");
        assert(!result.hasResult());
        assert(!result.hasResult());
        stub.write("jumps over the lazy dog.");
        assert(!result.hasResult());
        stub.setEOF();
        assert(result.hasResult());
        std::cout << "main: Result is: " << result.getResult() << std::endl;
    }
    return 0;
}

