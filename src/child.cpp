#include "child.h"
#include <iostream>



Child::Child()
	:Entity()
{

}

Child::~Child()
{
}

void Child::Start()
{
	std::cout << "call" << GetName() << "::Start" << std::endl;
}

void Child::Update()
{
	std::cout << "call" << GetName() << "::Update" << std::endl;
}

