#ifndef ADEFINES_H
#define ADEFINES_H

#define XPERIA_GO
//#define XPERIA_SOLA
//#define XPERIA_P
//#define XPERIA_U

#if !(defined XPERIA_GO || defined XPERIA_SOLA)
#define HAVE_NOT_EXTERNAL_SDCARD
#endif

/* extendendcommands.c */
#define BOARD_UMS_LUNFILE	"/sys/devices/virtual/android_usb/android0/f_mass_storage/lun/file"
#ifndef HAVE_NOT_EXTERNAL_SDCARD
#define BOARD_UMS_LUNFILE_INT	"/sys/devices/virtual/android_usb/android0/f_mass_storage/lun/file"
#endif

#define BATTERY_LEVEL_FILE  "/sys/devices/platform/ab8500-i2c.0/ab8500-fg.0/power_supply/ab8500_fg/capacity"
#define BATTERY_STATUS_CHARGING_FILE_USB  "/sys/devices/platform/ab8500-i2c.0/ab8500-charger.0/power_supply/ab8500_usb/online"
#define BATTERY_STATUS_CHARGING_FILE_AC  "/sys/devices/platform/ab8500-i2c.0/ab8500-charger.0/power_supply/ab8500_ac/online"

/* ui.c */
#define USB_STATE_FILE "/sys/class/android_usb/android0/state"

#if (defined XPERIA_GO || defined XPERIA_SOLA)
#define RED_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0040/leds/red/brightness"
#define GREEN_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0040/leds/green/brightness"
#define BUTTON_BACKLIGHT "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0040/leds/button-backlight/brightness"
#endif
#ifdef XPERIA_P
#define RED_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0036/leds/red/brightness"
#define GREEN_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0036/leds/green/brightness"
#define BUTTON_BACKLIGHT "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0036/leds/button-backlight/brightness"
#endif
#ifdef XPERIA_U
#define RED_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0040/leds/pwr-red/brightness"
#define GREEN_LED_FILE "/sys/devices/platform/nmk-i2c.2/i2c-2/2-0040/leds/pwr-green/brightness"
#endif

#endif
