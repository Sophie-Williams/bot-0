/*
 * targetKeyStroke.cpp
 *
 *  Created on: 5 mai 2015
 *      Author: Teddy
 */

#include <iostream>

#include "bot-0.hpp"
#include <windows.h>
#include <Winuser.h>

void targetKeyStroke(void)
{
	HWND handle;

	// find the window corresponding to the target string (class found using spy from Autohotkey)
	handle = FindWindowEx(0, 0, "TorqueJuggernaughtWindow", "LiF - Release build");
	if (handle != NULL)
		std::cout << "handle aquired" << std::endl;

	DWORD wid = GetWindowThreadProcessId(handle, NULL); // target process id;
	DWORD tid =  GetCurrentProcessId(); // this process id
	AttachThreadInput(wid, tid, TRUE);

	sendKeyStroke(keycode); // Here, we send the keystroke

	AttachThreadInput(wid, tid, FALSE);
}
