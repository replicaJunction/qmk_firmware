SRC += replicajunction.c

# Only load these source files if the features are enabled. Keyboards can
# enable or disable these features in their own rules.mk files.

ifeq ($(strip $(USER_CALLUM_ONESHOT_ENABLE)), yes)
	SRC += features/callum_oneshot.c
    OPT_DEFS += -DUSER_CALLUM_ONESHOT_ENABLE
endif

ifeq ($(strip $(USER_CAPS_WORD_ENABLE)), yes)
	SRC += features/caps_word.c
    OPT_DEFS += -DUSER_CAPS_WORD_ENABLE
endif

ifeq ($(strip $(USER_MOUSE_JIGGLE_ENABLE)), yes)
	SRC += features/mouse_jiggle.c
    OPT_DEFS += -DUSER_MOUSE_JIGGLE_ENABLE
endif

ifeq ($(strip $(USER_NUM_WORD_ENABLE)), yes)
	SRC += features/num_word.c
    OPT_DEFS += -DUSER_NUM_WORD_ENABLE
endif

ifeq ($(strip $(USER_REPEAT_KEY_ENABLE)), yes)
	SRC += features/repeat.c
    OPT_DEFS += -DUSER_REPEAT_KEY_ENABLE
endif

ifeq ($(strip $(USER_SECRETS_ENABLE)), yes)
	SRC += features/secrets.c
    OPT_DEFS += -DUSER_SECRETS_ENABLE
endif

ifeq ($(strip $(USER_SUPER_ALT_TAB_ENABLE)), yes)
	SRC += features/super_alt_tab.c
    OPT_DEFS += -DUSER_SUPER_ALT_TAB_ENABLE
endif

ifeq ($(strip $(USER_ENABLE_HOME_ROW_MODS)), yes)
	OPT_DEFS += -DUSER_ENABLE_HOME_ROW_MODS
endif

# Keyboard layouts

ifeq ($(strip $(USER_LAYOUT_QWERTY)), yes)
	SRC += layouts/qwerty/overrides.c
	OPT_DEFS += -DUSER_LAYOUT_QWERTY
else
	SRC += layouts/colemak_dh/overrides.c
	OPT_DEFS += -DUSER_LAYOUT_COLEMAK_DH
endif


# Define these last so any other logic can set up some defines first
SRC += matrix_scan.c \
		process_records.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
endif
