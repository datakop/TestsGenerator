
int __attribute__ ((noinline)) function_{{NUM}}() 
{
	// printf("function_{{NUM}}\n");
	int a = 10, i;
	for(i = 0; i < 100; ++i)
		a++;
	return a;
}