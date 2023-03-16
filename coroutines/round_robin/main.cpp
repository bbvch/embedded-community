#include "coro_scheduler.h"
#include "example_task.h"

#include <iostream>

int main()
{
    auto scheduler = std::make_shared<CoroScheduler>();
    exampleTask1(scheduler, "Sophie", 2);
    exampleTask2(scheduler, "Stephen");
    exampleTask1(scheduler, "Hermann", 5);
    std::cout << "Exec round 1" << std::endl;
    scheduler->executeRound();
    exampleTask1(scheduler, "Clive", 1);
    std::cout << "Exec round 2" << std::endl;
    scheduler->executeRound();
    std::cout << "Exec round 3" << std::endl;
    scheduler->executeRound();
    return 0;
}
