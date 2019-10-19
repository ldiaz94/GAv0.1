# Genetic Algorithm Combinator

This is a very simple C++ genetic algorithm integer combinator.
It is a function that takes in the addresses in memory of 3 ints, the first two ints are those to be combined, and the third address is the one where the combined int should be stored.

The combination occurs by alterating the bytes of each integer.
In other words, the combined integer will inherit byte #1 from int 1, byte #2 from int 2, and so on.

The addresses are passed into the function as void pointers which are then casted as unsigned integers. This makes it easier to then add +1 to each address to select the first byte, second byte, ...

This can be used to perform a byte combination of two different "genetic codes" in a genetic algorithm program.