#pragma once
class MyDll
{
};

#ifdef DLL1_EXPORTS
#define MYAPI __declspec(dllexport)
#else
#define MYAPI __declspec(dllimport)
#endif

// ��̬����Ŀֻ�е����˺����Ż����ɵ����⣨my.lib��������ֻ����.dll
extern "C"
{
	MYAPI int  TEST_Export(int a, int b);
}
