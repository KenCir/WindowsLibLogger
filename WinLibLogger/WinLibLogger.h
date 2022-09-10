#pragma once
#include <Windows.h>
#include "ConsoleUtility.h"

namespace Ken_Cir_GT_Logger
{
	class Logger
	{
	public:
		// ファイル出力なし
		Logger(bool useConsole);
		// ファイル出力あり
		Logger(const wchar_t* fileName, bool useConsole);
		~Logger();
		/* マルチバイト文字列を書き込む */
		void write(const char* str);
		/* ワイド文字列を書き込む */
		void write(const wchar_t* wstr);

	private:
		const wchar_t* fileName;
		HANDLE h;
		Ken_Cir_GT_ConsoleUtility::ConsoleUtility* console;
	};
}