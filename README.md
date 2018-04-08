# Fretter

A C++ tool to convert guitar tabs to sheet music.

![It still works!](https://raw.githubusercontent.com/andzandz/Fretter/master/screenshot.png)

**Beware: this code was written when I was 16/17, so it's not the best I've ever written(!). The concerns are separatedish though. Feel free to read the code for critique/amusement. Make some GitHub issues if you want :-D**

## Running

### On Linux

On Ubuntu and derivatives, this command _should_ install the necessary SDL libraries, for both running and compiling (it will pull in the runtime packages as dependencies):

```
$ sudo apt install libsdl-image1.2-dev libsdl-ttf2.0-dev
```

If this fails or you're on a different distro, look through your package manager for `libSDL*-dev` packages for `SDL_image` and `SDL_ttf`. Don't install any `libsdl2-*` libraries.

Once this is done you _should_ be able to run the `fretter` binary. I have recompiled it for you for 64-bit computers. Download or clone the repo, and then cd into the directory it is in:

```
$ chmod +x fretter
$ ./fretter
```

### On Windows

You _should_ be able to run `fretter.exe` without installing anything. I haven't tried it since 9 years ago.

### On Mac

I haven't included a MacOS binary. I didn't have a Mac. You will have to try compiling it. Maybe you could try wine, but I didn't have much success with that on Linux. Also, the .exe is most likely 32 bit.

## Compilation

If the `.exe` or Linux executable file `fretter` doesn't run as-is:

### On Linux/BSD/etc: 

After installing the package listed above, you can try the compile script:

```
$ sh compile.sh
```

If successful, this will create the `fretter` executable, so then:

```
$ ./fretter
```

### On Windows/Mac/Linux/etc:

You could try the Code::Blocks project (the Fretter.cbp file)

Notes:

This project is written for SDL 1.2. I originally learned C++ and SDL over at LazyFoo tutorials. They are updated for SDL 2 now with the originals gone, but you can still read their instructions for installing SDL 1.2 on this [2013 snapshot over at the Wayback Machine](http://web.archive.org/web/20130812013144/http://lazyfoo.net/SDL_tutorials/lesson01/index.php). Be careful, you will also need to install the `SDL_image` and `SDL_ttf` libraries, these are not included by default with SDL 1.2.

## Usage

Once you've got it running, click the dashes at the bottom to put a tab value there. Scroll the mouse to adjust the value. 

You can also adjust the _guitar tuning_ with your scrollwheel on the notes to the left of the tab.

You can click/scroll on the buttons at the top to turn the note guide on/off(click), transpose by octave(scroll) and swap between displaying sharps and flats(scroll). 

There is no save/open facility. Take a screenshot, that's, like, good enough, right?

If you do use it, be sure to convert some tabs of some teenage music, like Green Day or Fall Out Boy.

## Licence

**WTFPL** i.e. public domain. Use any of this code as you wish. If you do make use of this code for some reason, including a link to this repo would be nice.
