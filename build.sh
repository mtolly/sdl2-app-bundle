#!/bin/bash
set -e
set -u

gcc $(pkg-config --cflags --libs sdl2) main.c -o SDLApp.app/Contents/MacOS/sdl-app
dylibbundler -cd -of -b -x SDLApp.app/Contents/MacOS/sdl-app -d SDLApp.app/Contents/libs/
# -cd makes the libs dir if necessary
# -of overwrites lib files
# -b bundles (copies) the libs into the folder
# -x <prog> is the executable to read libs from and rewrite the lib paths in
# -d <dir> is the lib dir
# The default relative path written to the libraries is '@executable_path/../libs/'
# which matches the folder structure here.
# Use "otool -L SDLApp.app/Contents/MacOS/sdl-app" to view the paths
