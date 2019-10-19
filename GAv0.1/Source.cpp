#include <iostream>

// TODO: Delete, just for debugging purposes
#define PRINT(thing) std::cout << thing << "\n";


void combine(const void *a, const void *b, void *c)
{
	// Cast the pointers into unsigned int to be able to add to access next byte in memory
	unsigned int num1 = (unsigned int)a;
	unsigned int num2 = (unsigned int)b;
	unsigned int comb = (unsigned int)c;

	// Combine the bytes of the ints in intervals of 1 byte
	memcpy((void*)(comb), (const void*)(num1), 1);
	memcpy((void*)(comb + 1), (const void*)(num2 + 1), 1);
	memcpy((void*)(comb + 2), (const void*)(num1 + 2), 1);
	memcpy((void*)(comb + 3), (const void*)(num2 + 3), 1);
}




int main()
{
	// Create two ints in hex form. Int comb represents the combination
	// of "a" and "b" by alternating their byte sequences
	// Comb therefore is the first byte of "a", the second byte of "b",...
	int a = 0x003f1dff;
	int b = 0x010201dd;
	int comb = 0x013f01ff;
	PRINT("The value of a:");
	PRINT(a);

	PRINT("The value of b:");
	PRINT(b);

	PRINT("Manual combination of a and b:");
	PRINT(comb);

	// Reset the value of comb, to insure that the function works properly
	comb = 0x00000000;

	combine( (const void *)&a, (const void *)&b, &comb);
	PRINT("Using the combination function:");
	PRINT(comb);

	std::cin.get();
	return 0;
}