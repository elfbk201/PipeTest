// Pipe.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


#define BUFSIZE 4096 

HANDLE g_hChildStd_IN_Rd = NULL;
HANDLE g_hChildStd_IN_Wr = NULL;
HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;

HANDLE g_hInputFile = NULL;

void ErrorExit(PTSTR);

int main()
{
	Pipe p = Pipe();
	p.ReadPipe("");

	return 0;
}

bool Pipe::CheckPipe(std::string cool[][2], int s, std::string str)
{
	if(str =="")
		return false;
	int strsize = std::size(str);
	bool find = false;
	bool error = false;
	for (int i = 0;i < s;i++)
	{
		int badsize = std::size(cool[i][1]);
		for (int j = 0;j < strsize;j++)
		{
			if (find == true)
			{
				if (badsize == 0)
					break;
				for (int b = 0;b < badsize;b++)
					if (str[j] == cool[i][1][b])
					{
						return false;
					}
			}
			else
				if (str[j] == cool[i][0][0])
					find = true;
		}
		find = false;
	}
	return true;
}

std::string Pipe::ReadPipe(std::string name)
{
	SECURITY_ATTRIBUTES saAttr;
	saAttr.nLength = sizeof(SECURITY_ATTRIBUTES);
	saAttr.bInheritHandle = TRUE;
	saAttr.lpSecurityDescriptor = NULL;
	if (!CreatePipe(&g_hChildStd_OUT_Rd, &g_hChildStd_OUT_Wr, &saAttr, 0))
		return "";
	if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0))
		return "";
	if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
		return "";
	if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
		return "";

	TCHAR szCmdline[] = TEXT("child");
	PROCESS_INFORMATION piProcInfo;
	STARTUPINFO siStartInfo;
	BOOL bSuccess = FALSE;

	ZeroMemory(&piProcInfo, sizeof(PROCESS_INFORMATION));
	ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
	siStartInfo.cb = sizeof(STARTUPINFO);
	siStartInfo.hStdError = g_hChildStd_OUT_Wr;
	siStartInfo.hStdOutput = g_hChildStd_OUT_Wr;
	siStartInfo.hStdInput = g_hChildStd_IN_Rd;
	siStartInfo.dwFlags |= STARTF_USESTDHANDLES;

	bSuccess = CreateProcess(TEXT("../lab2.exe"),
		szCmdline,     // command line 
		NULL,          // process security attributes 
		NULL,          // primary thread security attributes 
		TRUE,          // handles are inherited 
		0,             // creation flags 
		NULL,          // use parent's environment 
		NULL,          // use parent's current directory 
		&siStartInfo,  // STARTUPINFO pointer 
		&piProcInfo);  // receives PROCESS_INFORMATION 

					   // If an error occurs, exit the application. 
	if (!bSuccess)
		return "";
	else
	{
		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	}

	//Sleep(2000);

	DWORD dwRead;
	CHAR chBuf[BUFSIZE];

	HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, NULL); //chBuf вывод
	std::string str = "";
	while (chBuf[i] != -52)
	{
		str += chBuf[i];
		i++;
	}

	//std::cout << str;

	return str;
}

