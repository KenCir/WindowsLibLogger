#pragma once
#include <Windows.h>
#include "ConsoleUtility.h"

namespace Ken_Cir_GT_Logger
{
	class Logger
	{
	public:
		// �t�@�C���o�͂Ȃ�
		Logger(bool useConsole);
		// �t�@�C���o�͂���
		Logger(const wchar_t* fileName, bool useConsole);
		~Logger();
		/* �}���`�o�C�g��������������� */
		void write(const char* str);
		/* ���C�h��������������� */
		void write(const wchar_t* wstr);

	private:
		const wchar_t* fileName;
		HANDLE h;
		Ken_Cir_GT_ConsoleUtility::ConsoleUtility* console;
	};
}