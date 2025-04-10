#!/usr/bin/python3

import os
import argparse
from libs import stuff, wine, help,ohmyzsh


def clear_command():
    '''clear command'''
    os.system('clear')
    print(f'{stuff.sysOk()}This is a funny clear command :D')


def update_command():
    '''Pck3r's update'''
    os.chdir(f'{os.getenv("HOME")}/.pck3r')
    os.system('git restore . && git pull && python3 installer.py')


def install_command(package_name):
    if not package_name:
        print(f'{stuff.sysERR()}{stuff.RED}After "install" is empty!{stuff.NRM}')
        return
    elif package_name == 'nodejs':
        handle_installation(package_name)
        #nodejs.installer()
    elif package_name == 'ohmyzsh':
        handle_installation(package_name)
        ohmyzsh.install()

    elif package_name == 'wine':
        handle_installation(package_name)
        wine.wine_installer()
    else:
        handle_generic_install(package_name)


def handle_installation(package_name):
    print(f'Try to installing : {package_name}...'.capitalize())





def handle_generic_install(package_name):
    print(f'{stuff.sysOk()}\nCommand is valid!\n{stuff.YEL}')
    if os.system(f'sudo apt install {package_name}') != 0:
        print(f'''{stuff.sysERR()}{stuff.RED}
              Package(s) or Command(s) not found:
              {package_name}{stuff.NRM}''')


def main():
    parser = argparse.ArgumentParser(description='A command line utility.')
    parser.add_argument('command', choices=['clear', 'update', 'install', 'uninstall', 
                                             'rm', 'sys', 'help', 'version'],
                        help='Command to run')
    parser.add_argument('args', nargs='*', help='Arguments for the command')

    args = parser.parse_args()

    command_mapping = {
        'clear': clear_command,
        'update': update_command,
        'install': install_command,
        
    }

    command_mapping[args.command](*args.args)


if __name__ == '__main__':
    main()