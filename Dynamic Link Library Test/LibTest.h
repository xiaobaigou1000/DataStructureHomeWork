#pragma once

#ifdef DYNAMICLINKLIBRARYTEST_EXPORTS
#define DYNAMICLINKLIBRARYTEST_API __declspec(dllexport)
#else
#define DYNAMICLINKLIBRARYTEST_API __declspec(dllimport)
#endif

class DYNAMICLINKLIBRARYTEST_API LibTest
{
public:
    void test();
};

