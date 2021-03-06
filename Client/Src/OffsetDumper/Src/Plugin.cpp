#include "stdafx.h"
#include "Plugin.hpp"
#include "Test.hpp"

std::ofstream out;

typedef int (__cdecl* tGetForm)(int a1, int a2, int a3, int a4);
tGetForm oGetForm ;

int __cdecl dGetForm(int constantMaybeLogOrVM, int unk1, int staticFunctionTag, int formID)
{
	return oGetForm(constantMaybeLogOrVM, unk1, staticFunctionTag, formID);
}

TestPlugin::TestPlugin()
	:ran(false), time(0)
{
	out.open("FreeScript.log", std::ios::trunc);
	out << "FreeScript Tests \n\n" << std::endl;

	oGetForm = (tGetForm)DetourFunction((PBYTE)0x8EFEB0, (PBYTE)dGetForm);
}

TestPlugin::~TestPlugin()
{
	out << "TestPlugin closed" << std::endl;
	out.flush();
	out.close();
}

void TestPlugin::Update()
{
	if(Game::GetPlayer()->parentCell)
	{
		if(!ran)
		{
			RunActorDump();
			ran = true;
			Debug::MessageBOX("Actor dump worked !");
		}
		else if(clock() - time > 10)
		{
			std::ostringstream os;
			os << "Hellou" << clock() - time;
			FreeScript::Debug::Notification(os.str().c_str());

			time = clock();
		}
	}
}