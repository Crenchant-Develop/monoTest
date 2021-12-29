#pragma once
#include "Tester.h"
#include "Tests.h"
#include <stdint.h>
#include "AllMono.h"
using namespace std;

class Tests2
{
public:
	Tests2()
	{
		cout << "Tests2::.ctor\n";
	}
	int32_t* value;
	int32_t* get_GetIntTestProp()
	{
		cout << "Tests2::get_GetIntTestProp\n";
		return value;
	}
	void set_GetIntTestProp(int32_t* value)
	{
		cout << "Tests2::set_GetIntTestProp\n";
		this->value = value;
	}
	static void CtorTest(Tests2* instance)
	{
		*instance = *(new Tests2());
	}
	static int32_t* GetIntTest(Tests2* instance)
	{
		return instance->get_GetIntTestProp();
	}
	static void SetIntTest(Tests2* instance, int32_t* value)
	{
		instance->set_GetIntTestProp(value);
	}
};