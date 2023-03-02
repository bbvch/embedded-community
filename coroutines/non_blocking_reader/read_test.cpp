#include "read_test.h"

#include "read_result.h"
#include "read_stub.h"
#include "read_promise.h"
#include "read_awaiter.h"

#include <string>
#include <iostream>

ReadResult readTest(ReadStub& stub)
{
    std::string returnValue;
    int readResult{ 0 };
    do
    {
        std::cout << "readTest: before co_await" << std::endl;
        readResult = co_await stub.read(returnValue);
        std::cout << "readTest: after co_await. result=" << readResult << std::endl;
    } while (readResult != ReadStub::ISEOF);
    co_return returnValue;
}
