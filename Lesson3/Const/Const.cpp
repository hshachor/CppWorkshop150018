void SimpleRules();
void PointerRules();

int main()
{
	SimpleRules();
	PointerRules();



}

void SimpleRules()
{
	// simple rules:
	int i1;
	i1 = 7; // good.
	
	// Now lets try those operations with const:
	// const int i2; // error. you cannot declare const without immediately give value to it.
	const int i2 = 5; // good.
	//i2 = 0; // error. you cannot change const variable.
}

void PointerRules()
{
	int i, j;
	const int c = 7;
	int* p;
	p = &i; // good.
	*p = 5; // good.
	*p = c; // good. copy c into *p.
	p = &j; // good, we can change the address p points to.
	//p = &c; // error. p as int* cannot point to const int.

	// Now lets try those operations with const:
	const int* p1;
	p1 = &i; // good. const int* can point to "regular" int.
	//*p1 = 1; // error. while we can change i directly, we cannot change it by p1.
	p1 = &c; // good, we can change p1 address, and even point it to const int.

	//int const* p1; // same as const int * p1;

	//int* const p2; //error. now the address is const, so we should immediately give value.
	int* const p2 = &i;
	//p2 = &j; //error. you cannot change p2 address.
	*p2 = -1; // good.
	
	//int* const p3 = &c; // error. p2 is constant pointer to "regular" int

	
}
