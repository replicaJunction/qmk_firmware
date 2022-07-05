# Userspace options
USER_CALLUM_ONESHOT_ENABLE = yes
USER_CAPS_WORD_ENABLE = yes
USER_MOUSE_JIGGLE_ENABLE = yes
USER_NUM_WORD_ENABLE = yes
USER_REPEAT_KEY_ENABLE = yes
USER_SECRETS_ENABLE = yes
USER_SUPER_ALT_TAB_ENABLE = yes

# Features to enable
# ADAPTIVE_KEYS_ENABLE = yes
COMBO_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
KEY_LOCK_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

# Extra features that are nice but takes space. Enable only if they're
# used in the layout.
WPM_ENABLE = no
# EXTRAKEY_ENABLE = no        # For volume keys and similar
# MOUSEKEY_ENABLE = no        # Them mouse keys yo
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
# RGBLIGHT_ENABLE = no        # Keyboard RGB underglow
RGB_MATRIX_ENABLE = no

# Features I definitely don't care aboud
BOOTMAGIC_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
DEBUG_MATRIX = no
DEBUG_MATRIX_SCAN_RATE  = no
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
VERBOSE = no

ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards/
endif
