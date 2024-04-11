# tiling window manager for X

a lightweight tiling window manager for Xorg, with an emphasis on minimalism and functionality

## installation

### using xinit
as superuser, run ```make install```, then append ```exec tile``` to your ```.xinitrc``` file.

### using a display manager
as superuser, create ```/usr/share/xsessions/tile.desktop```:
```
[Desktop Entry]
Encoding=UTF-8
Name=tile
Comment=tiling window manager
Exec=tile
Icon=tile
Type=XSession
```  
then, ```chown root:root !$``` and ```chmod 644 !$```  

## sources

dynamic window manager https://suckless.org/dwm  
tinywm https://github.com/mackstann/tinywm  
tronche HTML Xlib Programming Manual https://tronche.com/gui/x/xlib/  
tronche Inter-Client Communications Conventions Manual https://tronche.com/gui/x/icccm/  
Extended Window Manager Hints https://specifications.freedesktop.org/wm-spec/wm-spec-1.3.html  
Xlib - C Language X Interface https://www.x.org/releases/current/doc/libX11/libX11/libX11.html  
