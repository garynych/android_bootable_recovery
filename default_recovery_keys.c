#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"


int device_toggle_display(volatile char* key_pressed, int key_code)
{
    int alt = key_pressed[KEY_LEFTALT] || key_pressed[KEY_RIGHTALT];
    if (alt && key_code == KEY_L)
        return 1;
    return 0;
}

int device_handle_key(int key_code, int visible) {
	if (visible)
	{
		switch (key_code)
		{
			case KEY_CAPSLOCK:
			case KEY_DOWN:
			case KEY_VOLUMEDOWN:
				return HIGHLIGHT_DOWN;

			case KEY_LEFTSHIFT:
			case KEY_UP:
			case KEY_VOLUMEUP:
				return HIGHLIGHT_UP;

			case KEY_POWER:
				return SELECT_ITEM;

			case 528://camera button
                     case KEY_BACKSPACE:
				return GO_BACK;
		}
	}

	return NO_ACTION;
}
