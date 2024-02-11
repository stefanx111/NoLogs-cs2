#include "NoLogs.h"
#include "utils/detours.h"
#include "utils/addresses.h"
#include "tier0/memdbgon.h"
#include "utils/cdetour.h"

NoLogs g_NoLogs;

PLUGIN_EXPOSE(NoLogs, g_NoLogs);
bool NoLogs::Load(PluginId id, ISmmAPI *ismm, char *error, size_t maxlen, bool late)
{
	PLUGIN_SAVEVARS();
	META_CONPRINTF("[No-Logs] No-Logs Loaded. \n");
	addresses::Initialize();
	InitDetours();
	return true;
}

bool NoLogs::Unload(char *error, size_t maxlen)
{
	FlushAllDetours();
	return true;
}

void NoLogs::AllPluginsLoaded()
{
}

bool NoLogs::Pause(char *error, size_t maxlen)
{
	return true;
}

bool NoLogs::Unpause(char *error, size_t maxlen)
{
	return true;
}

const char *NoLogs::GetLicense()
{
	return "";
}

const char *NoLogs::GetVersion()
{
	return "1.0.0";
}

const char *NoLogs::GetDate()
{
	return __DATE__;
}

const char *NoLogs::GetLogTag()
{
	return "NoLogs";
}

const char *NoLogs::GetAuthor()
{
	return "StefanX";
}

const char *NoLogs::GetDescription()
{
	return "NoLogs - Shoutout Source2ZE, Poggu, xen, bklol";
}

const char *NoLogs::GetName()
{
	return "CS2 NoLogs";
}

const char *NoLogs::GetURL()
{
	return "";
}
