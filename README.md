# dwm - dynamic window manager
A fork of [dwm][1], a extremely fast, small, and dynamic window manager for X.

![dwm](./dwm.png)

## Requirements
In order to build dwm the Xlib header files are required.

## Installation
Edit config.mk to match your local setup (dwm is installed into the /usr/local namespace by default).

Afterwards enter the following command to build and install dwm (if necessary as root):
```sh
make clean install
```

## Running dwm
Add the following line to your **.xinitrc** to start dwm using startx:

```sh
exec dwm
```

In order to connect dwm to a specific display, make sure that the DISPLAY environment variable is set correctly, e.g.:

```
DISPLAY=foo.bar:1 exec dwm
```
(This will start dwm on display :1 of the host foo.bar.)

In order to display status info in the bar, you can do something like this in your .xinitrc:

```sh
while xsetroot -name "`date` `uptime | sed 's/.*,//'`"
do
    sleep 1
done &
exec dwm
```

## Configuration
The configuration of dwm is done by creating/editing the **config.h** and (re)compiling the source code.

[1]: https://dwm.suckless.org/
