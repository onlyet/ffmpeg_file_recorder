#pragma once
class MyDll
{
};

#ifdef DLL1_EXPORTS
#define MYAPI __declspec(dllexport)
#else
#define MYAPI __declspec(dllimport)
#endif

// 动态库项目只有导出了函数才会生成导出库（my.lib），否则只生成.dll
extern "C"
{
	MYAPI int  TEST_Export(int a, int b);
}
