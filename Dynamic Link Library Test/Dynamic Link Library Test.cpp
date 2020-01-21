// Dynamic Link Library Test.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Dynamic Link Library Test.h"


// This is an example of an exported variable
DYNAMICLINKLIBRARYTEST_API int nDynamicLinkLibraryTest=0;

// This is an example of an exported function.
DYNAMICLINKLIBRARYTEST_API int fnDynamicLinkLibraryTest(void)
{
    return 0;
}

// This is the constructor of a class that has been exported.
CDynamicLinkLibraryTest::CDynamicLinkLibraryTest()
{
    return;
}
