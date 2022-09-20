replicaJunction - Keyboardio Atreus
===================================

A 44-key layout designed for daily programming usage and occasional, light gaming.

Most of the interesting logic in this is defined and described in [my userspace](../../../../../users/replicaJunction/readme.md), so check that out if you're interested in how things work. The CAPSWORD and NUMWORD features are especially important for a keyboard this size.

# Notes

AVRDUDESS settings:
* Programmer: Atmel AppNote AVR109 Boot Loader
* MCU: ATmega32U4

This keyboard requires that the physical lower-left key be depressed during the reset in order to enter the bootloader. This means that with my layout, the "reset to bootloader" sequence is this:

1. Press and hold the lower-left key
2. Press and hold either the LA_FN or the LA_MACR keys (middle finger or pinky on bottom row)
3. Press the QK_BOOT key (right hand, inner "extra" key)
