
int __attribute__ ((noinline)) function_{{NUM}}() 
{
	printf("%d\n", rand() % {{NUM}});
	int a = {{NUM}}, i;
	for(i = 0; i < (rand() % {{NUM}} + 1); ++i)
		a++;
	return a;
}