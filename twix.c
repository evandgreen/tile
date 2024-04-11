#include <X11/Xlib.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "config.h"

#define VERSION 0.01

int main(int argc, char *argv[])
{
	Display *dpy;
	XWindowAttributes attr;
	XEvent event;
	XButtonEvent start;

	
	if (!(dpy = XOpenDisplay(NULL))) {
		printf("unable to open display server\n");
		return 1;
	} else printf("successfully opened display server\n");

	start.subwindow = None;

	while (1) {
		XNextEvent(dpy, &event);

		XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym("space")), Mod1Mask,
				DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);

		if (event.type == KeyPress && event.xkey.subwindow != None) /* keypress occurred in subwindow */
			XRaiseWindow(dpy, event.xkey.subwindow);
	}

	XCloseDisplay(dpy);
	return 0;
}
