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
    print(f'Installing Oh My Zsh...')
    os.system('sudo apt install -y git')

    if os.system('curl --version') != 0:
        print(f'{stuff.sysERR()}{stuff.RED}"curl" is required for using "oh-my-zsh" ; installing curl...{stuff.NRM}')
    if os.system('curl --version') != 0:
        print(f'{stuff.sysERR()}{stuff.RED}"curl" is required for using "oh-my-zsh" ; installing curl...{stuff.NRM}')
        if os.system('sudo apt install curl -y') != 0:
            print(f'{stuff.sysERR()}{stuff.RED}Failed to install curl. Please install it manually.{stuff.NRM}')
            return
    installation_command = 'sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"'
    if os.system(installation_command) == 0:
        print(f'{stuff.sysOk()}Oh My Zsh installed successfully!{stuff.NRM}')
    else:
        print(f'{stuff.sysERR()}{stuff.RED}Oh My Zsh installation failed.{stuff.NRM}')
