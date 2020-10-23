gcc main.c -o pck3r
sudo apt install libgtk-3-dev
sudo apt install libvte-2.91-0 
gcc pck3r-terminal-emu.c  `pkg-config --cflags --libs vte-2.91` -o pck3r-terminal-emu 
clear
