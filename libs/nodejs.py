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
[AMZYEI]
"""

from . import stuff
import os 

def install():
    if os.system(f'''
    echo {stuff.YEL} ; 
    curl -fsSL https://deb.nodesource.com/setup_22.x | sudo -E bash - ;
    echo {stuff.CYN} ; sudo apt install -y nodejs ;
    sudo apt-get update && echo {stuff.MAG} ;''') == 0:
        print(f'{stuff.sysOk()}Node.js installed successfully!')
        
    else:
        print(f'{stuff.sysERR()}{stuff.RED}\nPlease retry...\n$pck3r install nodejs{stuff.NRM}')
