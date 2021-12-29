#pragma once
#include "Tester.h"
#include "Tests2.h"
#include <stdint.h>
#include "AllMono.h"

using namespace std;
class Tests
{
public:
	Tests()
	{
		cout << "Tests::.ctor\n";
		mString = mono_string_new(mono_domain_get(), "");
	}
	MonoString* mString;
	MonoString* get_GetStringTestProp()
	{
		cout << "Tests::get_GetStringTestProp\n";
		return mString;
	}
	void set_GetStringTestProp(MonoString* value)
	{
		cout << "Tests::set_GetStringTestProp\n";
		mString = value;
	}
	Tests2* getNewTests2()
	{
		Tests2* ptr = new Tests2();
		static int32_t imsi = (int)mString;
		ptr->set_GetIntTestProp(&imsi);
		return ptr;
	}
	Tests2* getNewTests2(int32_t* value)
	{
		Tests2* ptr = new Tests2();
		ptr->set_GetIntTestProp(value);
		return ptr;
	}
	static MonoString* GetStringTest(Tests* instance)
	{
		return instance->get_GetStringTestProp();
	}
	static void SetStringTest(Tests* instance, MonoString* str)
	{
		instance->set_GetStringTestProp(str);
	}
	static void CtorTest(Tests* instance)
	{
		*instance = *(new Tests());
	}
	static Tests2* GetNewTests2Test(Tests* instance)
	{
		return instance->getNewTests2();
	}
	static Tests2* GetNewTests2Test_i(Tests* instance, int32_t* value)
	{
		return instance->getNewTests2(value);
	}
};


