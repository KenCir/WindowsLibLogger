// WinLibLogger.cpp : スタティック ライブラリ用の関数を定義します。
//

#include "WinLibLogger.h"
#include <stdexcept>
#include "StringUtility.h"

using namespace Ken_Cir_GT_StringUtility;
using namespace Ken_Cir_GT_ConsoleUtility;

Ken_Cir_GT_Logger::Logger::Logger(bool useConsole) : fileName(nullptr), h(nullptr)
{
	this->console = nullptr;

	if (useConsole)
	{
		this->console = new ConsoleUtility("Logger");
	}
}

Ken_Cir_GT_Logger::Logger::Logger(const wchar_t* fileName, bool useConsole) : fileName(fileName)
{
	this->console = nullptr;

	if (useConsole)
	{
		this->console = new ConsoleUtility("Logger");
	}

	// ファイル、オープン
	this->h = CreateFile(fileName,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ,
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (this->h == INVALID_HANDLE_VALUE)
	{
		throw new std::runtime_error(StringUtility::Format("ファイル %ls が開けませんでした", fileName));
	}

	this->write(StringUtility::FormatToWide("ファイル %s を開きました", fileName).c_str());
}

Ken_Cir_GT_Logger::Logger::~Logger()
{
	if (this->h != nullptr)
	{
		CloseHandle(this->h);
		this->h = nullptr;
	}
}

void Ken_Cir_GT_Logger::Logger::write(const char* str)
{
	if (this->console != nullptr)
	{
		this->console->writeConsole(str);
	}

	if (this->h != nullptr)
	{
		DWORD dwWriteSize;
		WriteFile(this->h,
			str,
			strlen(str),
			&dwWriteSize,
			NULL);
	}
}

void Ken_Cir_GT_Logger::Logger::write(const wchar_t* wstr)
{
	if (this->console != nullptr)
	{
		this->console->writeConsole(wstr);
	}

	if (this->h != nullptr)
	{
		DWORD dwWriteSize;
		WriteFile(this->h,
			wstr,
			wcslen(wstr),
			&dwWriteSize,
			NULL);
	}
}
