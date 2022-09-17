#pragma once
#include <stdio.h>

void DebugPrint(const char* pFormat, ...);

#define DEBUG_PRINT DebugPrint

#ifdef _DEBUG
//현재 주소와 라인 프린트
	#define FILE_PRINT() printf("[%s:%d]\n", __FILE__, __LINE__)
//원하는 텍스트 프린트.
	#define DEBUG_PRINT  DebugPrint

#else
	#define FILE_PRINT() __noop
	#define DEBUG_PRINT __noop
#endif