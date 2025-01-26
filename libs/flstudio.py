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



if __name__ == '__main__':
    
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
        """)

else:
    
    from . import stuff
    from . import wine
    from os import system as syscall
    from os import chdir, getenv

    chdir(getenv('HOME'))

    print(f'{stuff.YEL}')

    syscall('wget "https://archive.org/download/flstudio_202103/flstudio.exe"')

    print(f'{stuff.NRM}')

    syscall('wine flstudio.exe')