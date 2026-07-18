LTO_ENABLE = yes            # Link Time Optimization enabled
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
OLED_ENABLE = no           # OLED display

SERIAL_DRIVER = vendor
BOOTLOADER = rp2040
SPLIT_KEYBOARD = yes

VIA_ENABLE = yes
VIAL_ENABLE = yes

RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underglow (data on GP12).
RGBLIGHT_DRIVER = ws2812
WS2812_DI_PIN = GP12
