# Test program "non_blocking_reader"

This program shows an example of a non-blocking read call similar to the UNIX system call `read()`.

The actual reading loop is placed in the method `readTest()` and just performs a call to `read()` in a do-while loop until the `read()` returns the error code `ISEOF`. Then the whole read buffer is returned to the caller via `co_return`.

If the reader cannot read because there are currently no data in the buffer, it will return the error could `WOULDBLOCK`. In this case the awaiter transfers control back to the caller (`main()` in this case), which could perform other tasks in the meantime. With a call to `ReadResult::hasResult()` it enters again the coroutine and returns in the return value, if the coroutine did terminate and provided the result, which can then be retrieved with a call to `ReadResult::getResult()`.

Lots of debug messages allows to reproduce, what is going on exactly.