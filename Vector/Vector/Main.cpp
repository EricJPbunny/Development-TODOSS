#include <iostream>
#include "String.h"
#include "Vector.h"

int main() 
{
	String s1 = "Pedro";
	String s2 = "Juan";
	s1 = s2;
	vec3<float> vector1, vector2{3,2,1};

	vector1 = vector2;
	vector2.normalize();

	std::cout << s1.text << std::endl;

	system("pause");
	return 0;
}