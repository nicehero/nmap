#include "nmap.hpp"
#include <stdio.h>
using namespace nicehero;
struct S1{
	int a = 0;
	int b = 0;
	~S1(){
		printf("~S1 %d,%d\n",a,b);
		a = -1;
		b = -1;
	}
};

struct S2 {
	S2() {

	}
	S2(const S2&) = delete;
	int a = 0;
	int b = 0;
	~S2() {
		printf("~S2 %d,%d\n", a, b);
		a = -1;
		b = -1;
	}
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
	const_smart_ref r2b = std::as_const(mmb).get(2, { 5,6 });
	printf("%d,%d\n", r1b->a,r1b->b);
	printf("%d,%d\n", r2b->a, r2b->b);

	auto r3b = std::move(r1b);
	auto r4b = std::move(r2b);
	//auto r5b = r4b; //error smart_ref::copy_constructor = delete
	
	nmap<int, std::string> mmc;
	mmc[1] = "abc";
	const char* r1c = mmc.get(1);
	auto r2c = mmc.get(2, "def");
	printf("%s at %p\n", r1c,r1c);
	printf("%s at %p\n", r2c,r2c);
	
	nmap<int, S2> mmd;
	mmd[1];
	mmd[1].a = 50;
	mmd[1].b = 51;
	auto r1d = mmd.get(1);
	auto r2d = mmd.get(2);
	//auto r3d = mmd.get(2,S2()); // error if V::copy_constructor==delete
	printf("%p\n", r1d);
	if (r1d){
		printf("%d,%d\n", r1d->a,r1d->b);
	}
	printf("%p\n", r2d);

	printf("\n");
}