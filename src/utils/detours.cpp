#include "cdetour.h"
#include "common.h"
#include "module.h"
#include "addresses.h"
#include "detours.h"
#include "tier0/memdbgon.h"

//https://github.com/Source2ZE/CS2Fixes/blob/5346626021ac857769e6960aa8e5728b3643a3a0/src/detours.cpp#L333-L357
void Detour_Log()
{
	return;
}

bool FASTCALL Detour_IsChannelEnabled(LoggingChannelID_t channelID, LoggingSeverity_t severity)
{
	return false;
}

CDetour<decltype(Detour_Log)> g_LoggingDetours[] =
{
	//CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "Msg" ),
	//CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "ConDMsg" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "DevMsg" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "Warning" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "DevWarning" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "LoggingSystem_Log" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "LoggingSystem_LogDirect" ),
	CDetour<decltype(Detour_Log)>(	&modules::tier0, Detour_Log, "LoggingSystem_LogAssert" ),
};

CUtlVector<CDetourBase *> g_vecDetours;

void InitDetours()
{
	g_vecDetours.RemoveAll();

	for (int i = 0; i < sizeof(g_LoggingDetours) / sizeof(*g_LoggingDetours); i++)
		g_LoggingDetours[i].CreateDetour();

    for (int i = 0; i < sizeof(g_LoggingDetours) / sizeof(*g_LoggingDetours); i++)
		g_LoggingDetours[i].EnableDetour();
}

void FlushAllDetours()
{
	FOR_EACH_VEC(g_vecDetours, i)
	{
		g_vecDetours[i]->FreeDetour();
	}

	g_vecDetours.RemoveAll();
}