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

#define _CRT_SECURE_NO_DEPRECATE

#include "logger.h"

void jlog(FILE *logFile, const char * format, ...)
{
	// Get params
	va_list arg_ptr;
	va_start(arg_ptr, format);
	
	// Perform the logging
	vfprintf(logFile, format, arg_ptr);
	va_end(arg_ptr);
}

FILE * openLogFile (char *logFileName)
{
	FILE *logFile = fopen(logFileName, "a");
	if (logFile == NULL)
		exit(EXIT_FAILURE);
	return logFile;
}