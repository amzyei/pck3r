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

# system error (red logo print)

from os import system as syscall

def install_dotnet():

    from . import stuff

    if (syscall('wget https://packages.microsoft.com/config/ubuntu/20.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo dpkg -i packages-microsoft-prod.deb')) !=0 :
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)




    elif (syscall('sudo apt update')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt  install -y apt-transport-https')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt  update')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall(' sudo apt  install -y dotnet-sdk-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt  install -y aspnetcore-runtime-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt  install -y dotnet-runtime-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt install -y mono-complete')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 )  '% stuff.RED)



    elif (syscall('sudo apt  update')) != 0:
        stuff.sysERR()
        print('%sCan\'t install .NET (only for *UBUNTU 20.04 )  '% stuff.RED)


    else:
        stuff.sysOk()
        print('%s.NET(microsoft dotnet and MCS compiler (LINUX platform) ) installed  '% stuff.GRN )

def uninstall_dotnet():

    from . import stuff

    if (syscall('sudo apt update')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt purge  -y apt-transport-https')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt  update')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall(' sudo apt purge  -y dotnet-sdk-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt purge  -y aspnetcore-runtime-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt purge  -y dotnet-runtime-3.1')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 ) \n '% stuff.RED)



    elif (syscall('sudo apt purge  -y mono-complete')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 )  '% stuff.RED)



    elif (syscall('sudo apt  update && sudo apt full-upgrade ; sudo apt autoremove -y')) != 0:
        stuff.sysERR()
        print('%sCan\'t remove .NET (only for *UBUNTU 20.04 )  '% stuff.RED)


    else:
        stuff.sysOk()
        print('%s.NET(microsoft dotnet and MCS compiler (LINUX platform) ) reomved  '% stuff.GRN )




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
    """)