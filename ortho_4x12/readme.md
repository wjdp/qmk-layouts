# wjdp's Keyboard Layouts

## Setup
- Install qmk:
    - `pipx install qmk`
    - `qmk setup`
    - Move `~/qmk_firmware` to `~/local/qmk`
- Clone this repo inside the qmk layouts directory
    - `git clone <repo> ~/local/qmk/layouts/wjdp`
- Set keyboard and keymap defaults
    - `qmk config user.keyboard=<keyboard>`
    - `qmk config user.keymap=<layout>`
- Build and flash
    - `qmk compile`
    - `qmk flash`
