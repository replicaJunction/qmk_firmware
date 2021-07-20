# Adaptive Keys :id=adaptive-keys

Adaptive keys allow you to change the behavior of a key based on the last key pressed. For example, a key could be `W` most of the time, but if the user quickly types `qw`, the adaptive behavior sends `qu`.

Adaptive keys are especially useful for common [bigrams](https://en.wikipedia.org/wiki/Bigram) that are inconvenient or uncomfortable to type.

There are three components to an adaptive key setup:

1. **Prefix**: the key that precedes an adaptive key and lets QMK know an adaptive key might be coming
2. **Trigger**: the "normal" value of the adaptive key, which should be sent if the adaptive behavior isn't active
3. **Replacement**: the "adaptive" value of the key

## Setup

First, set `ADAPTIVE_KEY_ENABLE = yes` in your `rules.mk` file. This will enable the feature.

Next, define a series of adaptive key definitions in your `keymap.c` file. Each definiton should be a `const adaptive_key_t` value. It's easiest to use the `ADAPTIVE_KEY()` macro to do this, which takes the form `ADAPTIVE_KEY(prefix_keycode, trigger_keycode, replacement_keycode)`.

Finally, define the `adaptive_keys` array, which is an array of pointers to the definitions you just set up. The array should be `NULL`-terminated (the last value in the list should be `NULL`).

For example, you could implement the QW-QU adaptive key behavior described above by adding this to your `keymap.c`:

```c
const adaptive_key_t qw_qu_adaptive = ADAPTIVE_KEY(KC_Q, KC_W, KC_U);

const adaptive_key_t **adaptive_keys = (const adaptive_key_t *[]){
    &qw_qu_adaptive,
    NULL
};
```

## Advanced usage

Adaptive keys can coexist with mod-tap keys, but you need to include the whole `MT()` definition in the adaptive key definition in order for the adaptive keys code to recognize the keycode.

You may want to enable or disable adaptive keys based on some other criteria. To do this, you can use these functions:

```c
void enable_adaptive_keys(void);
void disable_adaptive_keys(void);
void toggle_adaptive_keys(void);
```

For example, here's how you'd disable adaptive keys when entering a layer dedicated to gaming (assume `_GAME` is defined in your layer definitions enum):

```c
layer_state_t layer_state_set_user(layer_state_t state) {
    if (LAYER_ON(state, _GAME)) {
        disable_adaptive_keys();
    }
    else {
        enable_adaptive_keys();
    }
    return state;
}
```

## Notes

Remember that an adaptive key cannot change the prefix!
