/*
 * Copyright (C) 2009 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <linux/input.h>

#include "recovery_ui.h"
#include "common.h"
#include "extendedcommands.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "minini/minIni.h"

#define sizearray(a)  (sizeof(a) / sizeof((a)[0]))

const char inifile[] = "/sdcard/bootmenu/settings.ini";

char **MENU_ITEMS;

char menutitle[10][20];
char kernel[10][350];
char ramdisk[10][350];
char cmdline[10][350];

int bootmenu_cnt = 0;

void set_multiboot_menu(void) {

	char section[20];
	char key[20];
	char val[350];
	long n;
	int s, k;

	MENU_ITEMS = (char **)malloc(sizeof(char *) * 12 * 20);

	MENU_ITEMS[0] = (char *)malloc(sizeof(char) * 20);
	MENU_ITEMS[1] = (char *)malloc(sizeof(char) * 20);
	sprintf(MENU_ITEMS[0], "reboot");
	sprintf(MENU_ITEMS[1], "shutdown");

	for (s = 0; ini_getsection(s, section, sizearray(section), inifile) > 0 && s <= 10; s++) {
		//ui_print("    [%s]\n", section);

		bootmenu_cnt += 1;

		for (k = 0; ini_getkey(section, k, key, sizearray(key), inifile) > 0; k++) {
			//ui_print("\t%s=", key);

			ini_gets(section, key, "", val, sizearray(val), inifile);
			//ui_print("%s\n", val);

			if (strcmp(key,"menutitle")==0)
				sprintf(menutitle[s], "%s", val);
			if (strcmp(key,"kernel")==0)
				sprintf(kernel[s], "%s", val);
			if (strcmp(key,"ramdisk")==0)
				sprintf(ramdisk[s], "%s", val);
			if (strcmp(key,"cmdline")==0)
				sprintf(cmdline[s], "%s", val);
		}

		MENU_ITEMS[s + 2] = (char *)malloc(sizeof(char) * 20);
		sprintf(MENU_ITEMS[s + 2], "%s", menutitle[s]);
	}
	MENU_ITEMS[s + 2] = NULL;
}

char* MENU_HEADERS[] = { NULL };

void device_ui_init(UIParameters* ui_parameters) {
}

extern int ensure_path_mounted(const char* path);

int device_recovery_start() {
    int check_m = ensure_path_mounted("/sdcard");
    set_multiboot_menu();
    return 0;
}

int device_reboot_now(volatile char* key_pressed, int key_code) {
    return 0;
}

int device_perform_action(int which) {
    return which;
}

int device_wipe_data() {
    return 0;
}
