# # Userspace options
USER_CAPS_WORD_ENABLE = yes
# USER_HANDS_DOWN_ENABLE = yes
# USER_MOUSE_JIGGLE_ENABLE = yes
USER_NUM_WORD_ENABLE = yes
# USER_SECRETS_ENABLE = yes
# USER_SUPER_ALT_TAB_ENABLE = no

# DYNAMIC_MACRO_ENABLE = yes

COMBO_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes


# Extra features that are nice but takes space. Enable only if they're
# used in the layout.
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similar
MOUSEKEY_ENABLE = no        # Them mouse keys yo
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no        # Keyboard RGB underglow
RGB_MATRIX_ENABLE = no


# Features I definitely don't care aboud
CONSOLE_ENABLE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
GRAVE_ESC_ENABLE = no
LTO_ENABLE = yes
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
VERBOSE = no


ifeq ($(strip $(USER_CAPS_WORD_ENABLE)), yes)
	SRC += lib/caps_word.c
    OPT_DEFS += -DUSER_CAPS_WORD_ENABLE
endif

ifeq ($(strip $(USER_NUM_WORD_ENABLE)), yes)
	SRC += lib/num_word.c
    OPT_DEFS += -DUSER_NUM_WORD_ENABLE
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
	SRC += lib/rj_combos.c
endif

ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
	SRC += lib/rj_key_overrides.c
endif


SRC += lib/adaptive_keys.c \
	   lib/process_records.c
