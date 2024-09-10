#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* configuration */
#define CMD_TERM "st &"
#define CMD_DMENU "dmenu_run &"

#define KEY_MOD Mod1Mask | ShiftMask
#define KEY_TERM XK_Return
#define KEY_CYCLE XK_j
#define KEY_CYCLE_DOWN XK_k
#define KEY_CLOSE XK_c
#define KEY_EXIT XK_Delete
#define KEY_DMENU XK_p

void configure_window(const XConfigureRequestEvent event);
void map_window(const XMapRequestEvent event);
void handle_keypress(XKeyEvent event);
void grabkey(int key);

Display *dpy;
Screen *screen;

int main(int argc, char *argv[])
{
	XWindowAttributes attr;
	XEvent event;
	
	if (!(dpy = XOpenDisplay(NULL))) {
		printf("unable to open display server\n");
		return 1;
	} else printf("opening display server...\n");

	screen = DefaultScreenOfDisplay(dpy);

	grabkey(KEY_TERM);
	grabkey(KEY_CLOSE);
	grabkey(KEY_EXIT);
	grabkey(KEY_DMENU);

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
	if (event.keycode == XKeysymToKeycode(dpy, XK_Return)) 
		system(CMD_TERM);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("c")))
		XKillClient(dpy, event.subwindow);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("q")))
		XCloseDisplay(dpy);
	else if (event.keycode == XKeysymToKeycode(dpy, XStringToKeysym("p")))
		system(CMD_DMENU);
}

void grabkey(int key)
{
	XGrabKey(dpy, XKeysymToKeycode(dpy, key), 
			KEY_MOD, DefaultRootWindow(dpy), True, GrabModeAsync, GrabModeAsync);
}
