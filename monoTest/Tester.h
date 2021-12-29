#pragma once
#include <iostream>
#include "AllMono.h"
#include "Tests.h"
#include "Tests2.h"
using namespace std;
class Tester
{
public:
	static int init()
	{
		mono_set_assemblies_path("C:\\Users\\CSNB\\source\\repos\\monoTest\\monoTestSharp\\bin\\Debug");
		mono_set_dirs("C:\\Program Files\\Mono\\lib", "C:\\Program Files\\Mono\\etc");
		MonoDomain* domain = mono_jit_init("monoTest_");
		MonoAssembly* assembly = mono_domain_assembly_open(domain, "C:\\Users\\CSNB\\source\\repos\\monoTest\\monoTestSharp\\bin\\Debug\\monoTestSharp.exe");
		if (!assembly) throw runtime_error("could not load the given Mono assembly");
		mono_add_internal_call("monoTestSharp.Tests::get_GetStringTestProp", Tests::GetStringTest);
		mono_add_internal_call("monoTestSharp.Tests::set_GetStringTestProp", Tests::SetStringTest);
		mono_add_internal_call("monoTestSharp.Tests::.ctor", Tests::CtorTest);
		mono_add_internal_call("monoTestSharp.Tests::GetNewTests2", Tests::GetNewTests2Test);
		mono_add_internal_call("monoTestSharp.Tests::GetNewTests2", Tests::GetNewTests2Test_i);
		mono_add_internal_call("monoTestSharp.Tests2::get_GetIntTestProp", Tests2::GetIntTest);
		mono_add_internal_call("monoTestSharp.Tests2::set_GetIntTestProp", Tests2::SetIntTest);
		mono_add_internal_call("monoTestSharp.Tests2::.ctor", Tests2::CtorTest);
		mono_add_internal_call("monoTestSharp.Tests2::GetNewTests", GetNewTests);
		const auto argc = 6;
		char* argv[argc] = { "HELLO", "WORLD", "FROM", "THE", "FUCKING", "MONO" };
		int retVal = mono_jit_exec(domain, assembly, argc, argv);
		mono_jit_cleanup(domain);
		return retVal;
	}
	static void GetNewTests(Tests* ptr)
	{
		Tests* tptr = new Tests();
		*ptr = *tptr;
	}
};