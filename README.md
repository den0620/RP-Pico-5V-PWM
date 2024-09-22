# RP-Pico-5V-PWM
Simple C program to manipulate 5V fans with raspberry pi pico (or replica)

Tested with "ASUS FCN FNQG" fan

May or may not work with yours

# Building & running
Inspect file for changes and run in project's root directory:

`chmod +x ./build.sh && ./build.sh`

and your uf2 executable should be in ./build/src/5vpwm.uf2

![Preview](https://github.com/den0620/RP-Pico-5V-PWM/blob/main/preview.jpg)

~~dont ask why it looks like this~~

# Notice
Tach (yellow) (reporting) wire is not utilized

Graduation doesn't seem to work

Closely inspect your fan's wires to connect everything right
