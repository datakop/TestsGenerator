
int main(int argc, char const *argv[])
{
	
	{{#FUNC_CALLS}}function_{{FUNC_CALL}}();
	{{/FUNC_CALLS}}

	{{BODY}}

	return 0;
}