#include <iostream>

// TODO: Delete, just for debugging purposes
#define PRINT(thing) std::cout << thing << "\n";


enum GA_VALTYPE
{
	GA_INT = 0,
	GA_FLOAT32 = 1
};




void combine(void* a, void* b, void* c, GA_VALTYPE kind)
{
	// Cast the void pointers into unsigned int to be able to do the combination easier
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
	int a = 0x003f1dff;
	int b = 0x010201dd;
	int comb = 0x013f01ff;
	PRINT(a);
	PRINT(b);
	PRINT(comb);
	comb = 0x00000000;
	combine( &a, &b, &comb, GA_INT);
	PRINT(a);
	PRINT(b);
	PRINT(comb);
	std::cin.get();
	return 0;
}