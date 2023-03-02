# Test program "prime_generator"

This test program demonstrates the stepwise transformation of a prime number generator into a coroutine-enabled program.

It starts off with **base** making no use of couroutines at all. 

It then continues with **step1**, where the generator part of the program is making use of coroutines, by using `co_yield` and `co_return`.

Finally, in **step2**, the printing part is also converted into a coroutine, making use of `co_await`.