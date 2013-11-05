
int main(int argc, char const *argv[])
{
	
	{{#FUNC_CALLS}}function_{{FUNC_CALL}}();
	{{/FUNC_CALLS}}

	return 0;
}