Simple demonstration of an SDL2 program set up as a Mac .app bundle.

Dependencies: `brew install dylibbundler pkg-config sdl2`

Run `build.sh` to build the program and set up the app.

  * macOS is finicky about caching the `info.plist` contents, so if you edit it,
    you may need to move the `.app` to a different location or rename to make
    changes take effect.

  * Note that `Info.plist` sets `NSHighResolutionCapable` to true, but the app
    does not initialize the window with `SDL_WINDOW_ALLOW_HIGHDPI`. This is an
    option for getting the high-resolution (non-blurry) window control, but
    keeping the SDL rendering itself at 1x resolution.
