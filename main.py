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
import os, sys
import argparse
from libs import stuff, wine, nodejs, ohmyzsh, help

def after_empty(command, help_contents=None):
    if help_contents == None:
        help_contents = ''
    print(f'{stuff.sysERR()}{stuff.RED}After "{command}" is empty!\n{stuff.YEL}{help_contents}{stuff.NRM}')

def sys_command(sys_migration=None):
    if not sys_migration:
        after_empty('sys', '''$ pck3r sys {update/upgrade/updgr}
updgr : update and full-upgrade, Include snap\'s packages.'''
                    )
    elif sys_migration == 'update':
        os.system('sudo apt update')
    elif sys_migration == 'upgrade':
        os.system('sudo apt upgrade')
    elif sys_migration == 'updgr':
        os.system('sudo apt update && sudo apt -y full-upgrade && snap refresh')
    else:
        print(f'{stuff.sysERR()}{stuff.RED}Invalid sys command: {sys_migration}{stuff.NRM}')

def clear_command():
    os.system('clear')
    print(f'{stuff.sysOk()}This is a funny clear command :D')

def update_command():
    os.chdir('/opt/pck3r')
    os.system('sudo git pull && sudo git restore .')

def install_command(package_name=None):
    if not package_name:
        after_empty('install', '$ pck3r install {package name}')
        return
    if package_name == 'nodejs':
        nodejs.install()
    elif package_name == 'ohmyzsh':
        ohmyzsh.install()
    elif package_name == 'wine':
        wine.wine_install()
    else:
        handle_generic_install(package_name)

def handle_generic_install(package_name):
    print(f'{stuff.sysOk()}\nCommand is valid!\n{stuff.YEL}')
    if os.system(f'sudo apt install -y {package_name}') != 0:
        print(f'{stuff.sysERR()}{stuff.RED}Package(s) or Command(s) not found: {package_name}{stuff.NRM}')

def main():
    ''' main function '''
    # Description and help message
    parser = argparse.ArgumentParser(description='''
Pck3r is a modern package manager for Ubuntu. It acts as a simple tool that helps users manage software with APT, or Advanced Package Tool. Pck3r makes installing, updating, and managing software easier with a clear interface and straightforward commands.
''', add_help=False)
    
    parser.add_argument('-h', '--help', action='store_true', help='show this special help message and exit')
    parser.add_argument('command', nargs='?', default=None, help='The command to execute')
    parser.add_argument('args', nargs='*', help='Additional arguments for the command')

    args = parser.parse_args()

    # Help handler
    if args.help:
        print(help.msg())
        sys.exit(0)

    if args.command is None:
        # If no command is provided
        print(f'{stuff.sysERR()}{stuff.RED}No command provided. Use "--help" for a list of available commands.{stuff.NRM}')
        sys.exit(1)

    # Valid commands
    valid_commands = ['clear', 'update', 'install', 'uninstall', 'rm', 'sys', 'version']

    if args.command not in valid_commands:
        print(f'{stuff.sysERR()}{stuff.RED}Command not found: {args.command}{stuff.NRM}')
        sys.exit(1)
    
    # Command mapping
    command_mapping = {
        'clear': clear_command,
        'update': update_command,
        'install': install_command,
        'sys': sys_command,
        'version': lambda: print(f'\b{stuff.sysOk()}\bversion : 1.0')
    }

    if args.command in command_mapping:
        command_mapping[args.command](*args.args)
    else:
        print(f'{stuff.sysERR()}{stuff.RED}Command not found: {args.command}{stuff.NRM}')
        sys.exit(1)

if __name__ == '__main__':
    main()
