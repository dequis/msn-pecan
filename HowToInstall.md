#labels Featured
# Install #

Most likely you need Pidgin first :) Get it [here](http://www.pidgin.im/).

After you have installed it check HowToUse.

## Windows ##

Just execute the installer, which you can find [here](http://msn-pecan.googlecode.com/files/msn-pecan-0.1.4.exe).

## Ubuntu ##

Use the **Ubuntu Software Center** and search for **msn-pecan**, or type in a terminal:
```
sudo apt-get install msn-pecan
```

## Fedora ##

Go to **Administration->Add/Remove Software**, and search for **purple-msn-pecan**, or type in a terminal:
```
sudo yum install purple-msn-pecan
```

## Debian ##

Typing in a terminal:
```
sudo apt-get install msn-pecan
```

## Arch Linux ##

You need to compile it from [AUR](https://wiki.archlinux.org/index.php/AUR_User_Guidelines), [here](http://aur.archlinux.org/packages.php?ID=15327) is the package.

## Nokia N900 ##

Go to the [Maemo downloads page](http://maemo.org/downloads/product/Maemo5/telepathy-msn-pecan/).

## Gentoo ##

```
emerge msn-pecan
```

## Pidgin Portable ##

You'll be asked for a location, go where Pidgin Portable is installed, and then into **plugins** subdir.

## Adium (Mac OS X) ##

http://code.google.com/p/msn-pecan/wiki/AdiumBuilds

## FreeBSD ##

```
cd /usr/ports/net-im/pidgin-msn-pecan && make install clean
```

## Compile ##

Make sure you have the development files for libpurple (libpurple-devel in RPM based distros, libpurple-dev in Debian ones).

Then, simply download/extract the tarball and issue:

```
make
sudo make install
```

And for translations:
```
sudo make install_locales
```