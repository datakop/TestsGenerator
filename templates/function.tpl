
int __attribute__ ((noinline)) function_{{NUM}}() 
{
	int a = 10, i;
	for(i = 0; i < 100; ++i)
		a++;
	return a;
}