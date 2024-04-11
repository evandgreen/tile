# tiling window interface for X

a lightweight tiling window manager for Xorg, with an emphasis on minimalism and functionality

## installation

### using xinit
as superuser, run ```make install```, then append ```exec twix``` to your ```.xinitrc``` file.

###using a display manager
as superuser, create a ```/usr/share/xsessions/twix.desktop```, like\\
```
[Desktop Entry]
Encoding=UTF-8
Name=twix
Comment=tiling window interface for X
Exec=twix
Icon=twix
Type=XSession
```  
then, ```chown root:root !$``` and ```chmod 644 !$```  

## sources

tronche HTML Xlib Programming Manual https://tronche.com/gui/x/xlib/  
tronche Inter-Client Communications Conventions Manual https://tronche.com/gui/x/icccm/  
Extended Window Manager Hints https://specifications.freedesktop.org/wm-spec/wm-spec-1.3.html
dynamic window manager https://suckless.org/dwm  
Xlib - C Language X Interface https://www.x.org/releases/current/doc/libX11/libX11/libX11.html  
