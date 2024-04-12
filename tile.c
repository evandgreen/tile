#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TERMINAL_CMD "st &"

Display *dpy;
Screen *screen;

/* prototyping*/
void configure_window(const XConfigureRequestEvent event);
void map_window(const XMapRequestEvent event);
void handle_keypress(XKeyEvent event);
void grabkey(char *key);

int main(int argc, char *argv[])
{
	XWindowAttributes attr;
	XEvent event;
	
	if (!(dpy = XOpenDisplay(NULL))) {
		printf("unable to open display server\n");
		return 1;
	} else printf("opening display server...\n");

	screen = DefaultScreenOfDisplay(dpy);

	grabkey("Return");
	grabkey("c");
	grabkey("q");
	grabkey("p");

	while (1) {
		XNextEvent(dpy, &event);

		switch (event.type) {
		case ConfigureRequest:
			configure_window(event.xconfigurerequest);
			break;
		case MapRequest:
			map_window(event.xmaprequest);
			break;
		case KeyPress:
			handle_keypress(event.xkey);
			break;
		}
	}

	XCloseDisplay(dpy);
	return 0;
}

void configure_window(const XConfigureRequestEvent event)
{
	XWindowChanges change;
	change.x = event.x;
	change.y = event.y;
	change.width = event.width;	
	change.height = event.height;
	change.border_width = event.border_width;
	change.sibling = event.above;
	change.stack_mode = event.detail;
	XConfigureWindow(dpy, event.window, event.value_mask, &change);
}

void map_window(const XMapRequestEvent event)
{
	XMapWindow(dpy, event.window);
}

void handle_keypress(XKeyEvent event)
{
	if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("Return")))
		system(TERMINAL_CMD);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("c")))
		XKillClient(dpy, event.subwindow);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("q")))
		XCloseDisplay(dpy);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("p")))
		system("dmenu_run &");
}

void grabkey(char *key)
{
	XGrabKey(dpy, XKeysymToKeycode(dpy, XStringToKeysym(key)),
			Mod1Mask|ShiftMask, DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
}
