#include <iostream>
#include "namespaces.h"
#include <string>
#include <vector>

//namespace mycode {
//	void foo()
//  {
//		std::cout << "foo() called in the mycode namespace" << std::endl;
//	}
//}


void mycode::foo()
{
	std::vector<int> a;
	
	for(int q; q <5; q++) {
	}

	std::cout << "foo() called in the mycode namespace" << std::endl;
}
