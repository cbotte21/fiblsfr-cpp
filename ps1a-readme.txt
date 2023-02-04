Cody Botte

I decided to use a bit array for my implementation. It is a solid choice for minimizing memory usage, as opposed to a string implementation. It works by defining taps, locations to XOR with the lost bit. The lost bit comes from the farmost left bit after a left shift operation. The final XOR values gets put in the last array position.

My test files test both public functions using the data provided in the pdf. I dynamically use memory, allowing for an easy implementation of loading a spec from a test file.