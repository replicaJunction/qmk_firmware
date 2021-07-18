# "Hands Down" inspired layout

At present, this branch is probably not compatible with the core QMK repo. It's based off [sevanteri/early_combo](https://github.com/sevanteri/qmk_firmware/tree/early_combo), but I also merged the latest commits from [qmk_firmware/develop](https://github.com/qmk/qmk_firmware/tree/develop) in order to leverage the [Key Overrides](https://github.com/qmk/qmk_firmware/blob/develop/docs/feature_key_overrides.md) feature.

## Features

### Base layer

Alpha keys are based on the **Hands Down _Gold_** layout, as described at 2021-07-17. I have modified a couple of the symbols for my own preferences.

```
j  k  m  f  v    -  u  o  y  w
r  s  n  h  p    ,  a  e  i  c
x  g  l  d  b    ?  .  =  "  '
            t    _
```

You may notice that Z and Q are missing. These are delegated to combos, described below.

The symbols on the base layer also send different codes when shifted:

| Normal | Shift |
|--------|-------|
|   -    |   +   |
|   ?    |   !   |
|   ,    |   ;   |
|   .    |   :   |
|   =    |   _   |
|   "    |   #   |
|   '    |   @   |

### Combos

A full list of combos is defined in the file [combos.def](combos.def). Here are the prominent ones used in normal typing:

|  Keys | Result |
|-------|--------|
| J + K |   Z    |
| F + V |   Q    |
| K + M |  `lk`  |
| M + F |  `lf`  |

Note that the K+M and M+F combos both use a longer combo delay than usual. This prevents them from conflicting with the adaptive keys described below.

### Adaptive Keys

A couple of the keycodes in the base layer use "adaptive" logic to change the keycode they send if typed immediately after a different key. This takes some finger motions that would otherwise be pretty uncomfortable and makes them easier to type.

| Keys | Result |
|------|--------|
| B, D |  `bl`  |
| M, F |  `mb`  |
| F, M |  `fl`  |
| G, M |  `gl`  |
| K, M |  `kl`  |

### CAPSWORD and NUMWORD modes

Typing the key combo `D+.` (both index fingers on the lower row, in the QWERTY positions V and M) activates "NUMWORD mode," temporarily toggling on a number layer. This isn't a toggle, nor a oneshot layer, though - the layer remains active as long as number keys or certain others (backspace, dot, etc.) are typed. As soon as a key not whitelisted is typed (such as the spacebar), NUMWORD mode ends and the number layer is deactivated.

CAPSWORD is a similar concept, though different in implementation. It's activated with `L+=` (middle fingers on the lower row, QWERTY C and comma). Instead of toggling a layer, it activates the Caps Lock, then deactivates it again when a non-alpha key is pressed.
* Note: Some OSes may be configured to automatically disable Caps Lock when Shift is pressed. If this setting is turned on, it will really mess with the CAPSWORD logic here. When using CAPSWORD, the OS should only turn Caps Lock off when the Caps Lock key is "pressed."

## Inspiration

* [Hands Down _Gold_](https://sites.google.com/alanreiser.com/handsdown) and other posts by the same author
    - [Going for Gold...](https://www.reddit.com/r/KeyboardLayouts/comments/oizs1y/going_for_goldhands_down_gold/)
    - [Using Adaptive keys...](https://www.reddit.com/r/KeyboardLayouts/comments/nr0i2a/using_adaptive_keys_on_hands_down_alttx/)
* [T-34 Keyboard Layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/)
    - [Discussion thread](https://www.reddit.com/r/KeyboardLayouts/comments/nrl8dy/the_t34_keyboard_layout/)
