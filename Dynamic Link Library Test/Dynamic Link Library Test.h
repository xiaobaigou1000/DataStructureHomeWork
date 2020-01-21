// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DYNAMICLINKLIBRARYTEST_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DYNAMICLINKLIBRARYTEST_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef DYNAMICLINKLIBRARYTEST_EXPORTS
#define DYNAMICLINKLIBRARYTEST_API __declspec(dllexport)
#else
#define DYNAMICLINKLIBRARYTEST_API __declspec(dllimport)
#endif

// This class is exported from the dll
class DYNAMICLINKLIBRARYTEST_API CDynamicLinkLibraryTest {
public:
	CDynamicLinkLibraryTest(void);
	// TODO: add your methods here.
};

extern DYNAMICLINKLIBRARYTEST_API int nDynamicLinkLibraryTest;

DYNAMICLINKLIBRARYTEST_API int fnDynamicLinkLibraryTest(void);
