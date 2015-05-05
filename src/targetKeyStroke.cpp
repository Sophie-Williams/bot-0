/*
 * targetKeyStroke.cpp
 *
 *  Created on: 5 mai 2015
 *      Author: Teddy
 */

#include <iostream>

#include "bot-0.hpp"

void targetKeyStroke(unsigned int keycode)
{
	HWND handle;

	// find the window corresponding to the target string (class found using spy from Autohotkey)
	handle = FindWindowEx(0, 0, "TorqueJuggernaughtWindow", "LiF - Release build");
	if (handle != NULL)
		std::cout << "handle aquired" << std::endl;

	DWORD wid = GetWindowThreadProcessId(handle, NULL); // target process id;
	DWORD tid =  GetCurrentProcessId(); // this process id

	HWND previous = GetForegroundWindow();
	DWORD wid2 = GetWindowThreadProcessId(previous, NULL);
	AttachThreadInput(wid, tid, TRUE);

	SetForegroundWindow(handle);
	SetActiveWindow(handle);
	SetFocus(handle);

	Sleep(100); // necessary to let window time to switch
	sendKeyStroke(keycode, handle); // Here, we send the keystroke

	AttachThreadInput(wid, tid, FALSE);

	/* Bringing back previous window*/

	AttachThreadInput(wid2, tid, TRUE);
	SetForegroundWindow(previous);
	SetActiveWindow(previous);
	SetFocus(previous);
	Sleep(100);
	AttachThreadInput(wid2, tid, FALSE);
}
