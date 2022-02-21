#include "pch.h"
#include "MyDll.h"

MYAPI int TEST_Export(int a, int b)
{
    return a + b;
}

//RECORDAPI int MR_Add(int a, int b)
//{
//	return a + b;
//}
