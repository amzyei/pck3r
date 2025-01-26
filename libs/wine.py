#!/usr/bin/python3

""" 

Short description of this Python module.
Longer description of this module.
This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.
This program is distributed in the hope that it will be useful, but WITHOUT
ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program. If not, see <http://www.gnu.org/licenses/>.

"""
__authors__ = ['M.Amin Azimi .K (amzy-0)', 'mehrzero', 'https://github.com/amzy-0/pck3r/graphs/contributors']

def wine_installer():
    from os import system as syscall 
    from os import getenv, chdir
    from . import stuff

    syscall("sudo apt update && sudo apt full-upgrade")
    home = getenv("HOME")
    chdir(home)
    

    if (syscall("""
    sudo dpkg --add-architecture i386; 
    wget -nc https://dl.winehq.org/wine-builds/winehq.key;
    sudo apt-key add winehq.key;
    sudo add-apt-repository 'deb https://dl.winehq.org/wine-builds/ubuntu/ focal main' ;
    sudo apt install --install-recommends winehq-stable;
    """))!=0:

        print(f"{stuff.sysERR()}{stuff.NRM}")

    else:
        syscall("clear")
        print(stuff.sysOk())
        print(f"{stuff.GRN}wine version :")
        syscall(f"wine --version && echo {stuff.NRM}")


if __name__ == "__main__":

    print("""
This is a module not an executeable program
Alternative command :
$ python3 core_pck3r.py
OR
$ python3 installer.py
OR
$ chmod 755 core_pck3r.py ; ./core_pck3r.py
And for installing :
$ chmod 755 installer.py ; ./installer.py
    """ )


