
#include "addresses.h"
#include "module.h"
#include "common.h"
#include "tier0/memdbgon.h"


void addresses::Initialize()
{
	modules::tier0 = new CModule(ROOTBIN, "tier0");
}