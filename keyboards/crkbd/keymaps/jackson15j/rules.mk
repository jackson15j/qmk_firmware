# Build Options
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.

BOOTLOADER = atmel-dfu

OLED_DRIVER_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes       # Disable if you run out of usb endpoints. Media keys need this to work.

ifneq ($(strip $(OLED_DRIVER_ENABLE)), yes)
    RGB_MATRIX_SPLIT_RIGHT=yes
endif

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/glcdfont.c \
        ./lib/rgb_state_reader.c \
        ./lib/layer_state_reader.c \
        ./lib/logo_reader.c \
        ./lib/keylogger.c \
