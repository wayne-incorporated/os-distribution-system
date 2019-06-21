#include "redistConsole.h"

const std::string showVersion(int version)
{
	return version == 13 ? std::string("Microsoft Visual C++ 2013 Redistributable(x86)") : std::string("Microsoft Visual C++ 2015 Redistributable(x86)");
}

int checkVersion(const CString& ver)
{
	return (ver.Find(_T("12.0"), 0) != -1) ? 13 : 15;
}

void showStatus(const CString& ver, LONG result)
{
	if (result != ERROR_SUCCESS)
	{
		std::cout << showVersion(checkVersion(ver)) << INSTALL << std::endl;
	}
	else std::cout << ALREADY_INSTALLED << showVersion(checkVersion(ver)) << std::endl;
}

const PROCESS_INFORMATION runExApp(const CString& ver, BOOL& STATE)
{
	STARTUPINFO si = { 0, };
	PROCESS_INFORMATION pi = { 0, };
	si.cb = sizeof(si);
	TCHAR command[DIR_LEN];
	GetModuleFileName(NULL, command, sizeof(command));
	PathRemoveFileSpec(command);
	TCHAR* exe = new TCHAR[ver.GetLength()+1];
	memset(exe, 0, ver.GetLength()+1);
	StrCpy(exe, ver.GetString());
	StrCatBuff(command, exe, sizeof(command));
	BOOL state;
	state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	STATE = state;
	delete [] exe;
	return pi;
}

void checkAppRunning(PROCESS_INFORMATION& pi)
{
	unsigned long l;
	if (pi.hProcess)
	{
		GetExitCodeProcess(pi.hProcess, &l);
		while (l == STILL_ACTIVE)
		{
			GetExitCodeProcess(pi.hProcess, &l);
		}
	}
}

void isInstalled(HKEY& hKey, const CString& ver)
{
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, ver, 0, KEY_READ, &hKey) == ERROR_SUCCESS)
	{
		std::cout << SUCCESS << showVersion(checkVersion(ver)) << std::endl;
	}
	else
	{
		std::cout << FAIL << showVersion(checkVersion(ver)) << std::endl;
		exit(0);
	}
}

void checkMainRunning(BOOL state)
{
	state ? std::cout << "main installer will be running!" << std::endl : std::cout << "It fails to run the main installer!" << std::endl;
}
