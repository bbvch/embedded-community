#pragma once

#include <string_view>

#include "definitions.h"

void exampleTask1(const CoroSchedulerPtr& sched, std::string_view msg, int iterations = 10);
void exampleTask2(const CoroSchedulerPtr& sched, std::string_view msg);

