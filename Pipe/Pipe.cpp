// Pipe.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


#define BUFSIZE 4096 

HANDLE g_hChildStd_IN_Rd = NULL;
HANDLE g_hChildStd_IN_Wr = NULL;
HANDLE g_hChildStd_OUT_Rd = NULL;
HANDLE g_hChildStd_OUT_Wr = NULL;

HANDLE g_hInputFile = NULL;

void CreateChildProcess(void);
void WriteToPipe(void);
void ReadFromPipe(void);
void ErrorExit(PTSTR);

int main()
{
	Pipe p = Pipe();
	//std::string as = "C:\\Users\\Ko4evnik\\Documents\\Visual Studio 2015\\Projects\\lab2.1\\Debug\\lab2.1.exe";
	p.ReadPipe("C:\\Users\\Ko4evnik\\Documents\\Visual Studio 2015\\Projects\\lab2.1\\Debug\\lab2.1.exe");

	printf("\n->End of parent execution.\n");
	return 0;
}

bool Pipe::CheckPipe(std::string cool[][2], int s, std::string str)
{
	//std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "a" },{ "e", "a" },{ "g", "cb" },{ "f","d" },{ "h","bc" },{ "i","bc" },{ "k","hgfe" },{ "m","hgfe" },{ "n","ikm" } };
	//std::string str = "aaaaabedbedbdedebdbedebbdeebdbdedebecfecfecfecfcfeihgghigihihggihihihhihihiikmkmimikkimimkmmmmmnnnnn";
	//int coolsize = std::size(*cool);
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
		ErrorExit(TEXT("StdoutRd CreatePipe"));
	if (!SetHandleInformation(g_hChildStd_OUT_Rd, HANDLE_FLAG_INHERIT, 0))
		ErrorExit(TEXT("Stdout SetHandleInformation"));
	if (!CreatePipe(&g_hChildStd_IN_Rd, &g_hChildStd_IN_Wr, &saAttr, 0))
		ErrorExit(TEXT("Stdin CreatePipe"));
	if (!SetHandleInformation(g_hChildStd_IN_Wr, HANDLE_FLAG_INHERIT, 0))
		ErrorExit(TEXT("Stdin SetHandleInformation"));

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

	bSuccess = CreateProcess(TEXT("../lab2.1.exe"),
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
		ErrorExit(TEXT("CreateProcess"));
	else
	{
		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	}

	Sleep(2000);

	DWORD dwRead;
	CHAR chBuf[BUFSIZE];
	//BOOL bSuccess = FALSE;
	HANDLE hParentStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bSuccess = ReadFile(g_hChildStd_OUT_Rd, chBuf, BUFSIZE, &dwRead, NULL); //chBuf �����
	std::string str = "";
	while (chBuf[i] != -52)
	{
		str += chBuf[i];
		i++;
	}
	//std::string str(chBuf);
	std::cout << str;
//	std::string cool[][2] = { { "a", "" },{ "b", "" },{ "c", "a" },{ "d", "a" },{ "e", "a" },{ "g", "cb" },{ "f","d" },{ "h","bc" },{ "i","bc" },{ "k","hgfe" },{ "m","hgfe" },{ "n","ikm" } };
	//int coolsize = std::size(*cool);
//	CheckPipe(cool, std::size(cool),str);
//	system("Pause");
	return str;
}



void ErrorExit(PTSTR lpszFunction)
{
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40)*sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	ExitProcess(1);
}
