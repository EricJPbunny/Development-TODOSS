#include <iostream>
#include "String.h"
#include "Vector.h"

int main() 
{
	String a("hello");
	String b("hello2");
	
	printf("%s %s", a.GetString(), b.GetString());

	system("pause");
	return 0;
}