#include "nmap.hpp"
#include <stdio.h>
using namespace nicehero;
struct S1{
	int a = 0;
	int b = 0;
};
int main(){
	nmap<int, ui32> mm;
	mm[1] = 10;
	ui32 r1 = mm.get(1);
	auto r2 = mm.get(2 ,100);
	printf("%d\n", r1);
	printf("%d\n", r2);

	nmap<int, S1> mmb;
	mmb[1] = { 3,4 };
	const_smart_ref r1b = std::as_const(mmb).get(1, {});
	smart_ref r2b = mmb.get(2, { 5,6 });
	printf("%d,%d\n", r1b->a,r1b->b);
	printf("%d,%d\n", r2b->a, r2b->b);

	auto r3b = std::move(r1b);
	auto r4b = std::move(r2b);
	
	nmap<int, std::string> mmc;
	mmc[1] = "abc";
	const char* r1c = mmc.get(1);
	auto r2c = mmc.get(2, "def");
	printf("%s\n", r1c);
	printf("%s\n", r2c);
	printf("\n");

}