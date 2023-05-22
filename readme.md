# The wjdp Planck Layout

## Setup
- Install qmk:
    - `pip install --user qmk`
    - `qmk setup`
- Link this repo inside the qmk firmware directory
    - `ln -s ~/local/planck-olbk ~/qmk_firmware/keyboards/planck/keymaps/wjdp`
- Set keyboard and keymap defaults
    - `qmk config user.keyboard=planck/rev6_drop`
    - `qmk config user.keymap=wjdp`
- Build and flash
    - `qmk compile`
    - `qmk flash`
