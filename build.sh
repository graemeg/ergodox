#!/bin/bash
KEYBOARD=ergodox_ez
KEYMAP=gg_dvorak
QMK_DIR=qmk_firmware
# FreeBSD uses 'gmake', Linux uses 'make'
MAKECMD=gmake

# 0. Clean
rm -rf .build

# 1. Copy my files into their appropriate locations inside QMK
mkdir -p $QMK_DIR/keyboards/$KEYBOARD/keymaps/$KEYMAP
cp -r src/keymaps/$KEYMAP $QMK_DIR/keyboards/$KEYBOARD/keymaps/
#cp -r src/keymaps/overrides/ $QMK_DIR/keyboards/$KEYBOARD

# 2. Run string replacement to tweak EZ defaults (this is an alternative to
# copying the overrides dir)

# 3. Make clean
cd $QMK_DIR
$MAKECMD $KEYBOARD:$KEYMAP:clean

# 4. Make teensy build
$MAKECMD $KEYBOARD:$KEYMAP

# 5. Clean up
cp .build/*.hex ../
#cp -r .build ../.build
git clean -x -f -d
git checkout -- .
cd ..
