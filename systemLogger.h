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

#ifndef __systemLogger_h__
#define __systemLogger_h__

#include <stdio.h>

/**
 * Logs various information about the computer. Simply calls the logCompInfo()
 * and logUserInfo() functions.
 */
void logSysInfo(FILE*);

/**
 * Logs the username of the currently logged in user.
 */
void logUserInfo(FILE*);

/**
 * Logs the computer name, the system time, and the local time.
 */
void logCompInfo(FILE*);

#endif