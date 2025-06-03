#!/usr/bin/python3
""" 
Short description of this python3 module.
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

from libs import stuff
from os import system 
import time

# creating link
make_link = 'sudo ln -s /opt/pck3r/main.py /bin/pck3r'


def setup():

    print('Unlinking pck3r (if was installed) ')
    system('sudo unlink /bin/pck3r')
    system('sudo rm -rf /opt/pck3r') if (system(f'echo {stuff.CYN};ls /opt/pck3r/')) ==0 else print(f'Copy all pck3r directory{stuff.NRM}')
    system('sudo mkdir -p /opt/pck3r')
    system('sudo cp -rf . /opt/pck3r')
    system(make_link)
    time.sleep(1)
    print(f'{stuff.YEL}Check link ')
    print('Link created') if (system('ls -l  /bin/pck3r')) == 0  else print('{stuff.sysOk()}{stuff.RED}No link (/bin/pck3r){stuff.NRM}')
    time.sleep(1)
    print(f'{stuff.sysOk()}{stuff.GRN}Pck3r installed successfuly{stuff.NRM}')


setup()
