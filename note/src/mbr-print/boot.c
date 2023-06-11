/* barebone from http://dc0d32.blogspot.tw/2010/06/real-mode-in-c-with-gcc-writing.html */



asm(".code16gcc\n");

#define __NOINLINE  __attribute__((noinline))
#define __REGPARM   __attribute__ ((regparm(3)))
#define __NORETURN  __attribute__((noreturn))

		
void __NOINLINE __REGPARM print(const char *s) {
	while(*s) {
		asm volatile (
			"movw	$0x0001, %%bx\n"
			"movb	$0x0E, %%ah\n"
			"movb	%b0, %%al\n"
			"int	$0x10"
			: 
			: "al"(*s++):"ah","bx");
	}
}

/* and for everything else you can use C! Be it traversing the filesystem, or verifying the kernel image etc.*/
void __NORETURN __attribute__((section("__start"))) main(){
	print("Hello, MBR!11333rrrr\r\noooo");
	while(1);
}

