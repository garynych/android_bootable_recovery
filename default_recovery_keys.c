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

extern short k_a_t;
static short temp_k_a_t = 0; //shift to the first kexec kernel and select them
short disable_k_a_t = 0; //disable auto reboot timer

int device_handle_key(int key_code, int visible) {
	if (visible)
	{
		switch (key_code)
		{
			case KEY_CAPSLOCK:
			case KEY_DOWN:
			case KEY_VOLUMEDOWN:
				disable_k_a_t = 1;
				return HIGHLIGHT_DOWN;

			case KEY_LEFTSHIFT:
			case KEY_UP:
			case KEY_VOLUMEUP:
				disable_k_a_t = 1;
				return HIGHLIGHT_UP;

			case KEY_POWER:
				if (!k_a_t) {
					temp_k_a_t += 1;
					if (temp_k_a_t == 1)
						return GO_BACK;
					if (temp_k_a_t == 2)
						return HIGHLIGHT_DOWN;
					if (temp_k_a_t == 3)
						return HIGHLIGHT_DOWN;
				}
				return SELECT_ITEM;

			case 528://camera button
                     case KEY_BACKSPACE:
				return GO_BACK;
		}
	}

	return NO_ACTION;
}
