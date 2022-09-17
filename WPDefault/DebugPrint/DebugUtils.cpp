#include <stdarg.h>
#include "Framework.h"

#ifdef _DEBUG
	#ifdef UNICODE
		#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
	#else
		#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
	#endif
#endif

//! 주의 !! 스레드에 안전하지 않습니다.
// printf와 사용법 동일.
void	DebugPrint(const char* pFormat, ...)
{
	static char logBuf[8192];
	va_list args;
	va_start(args, pFormat);

	vsprintf_s(logBuf, pFormat, args);
	va_end(args);

	printf(logBuf);
}
