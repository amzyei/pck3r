#!/usr/bin/python3

from os import system as syscall
from os import chdir, getcwd, getenv

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

else:
    from . import stuff

    message ="""%s
    -----------------------------------------
    |                                       |
    | pck3r : It is a versatile program and |
    |                                       |
    | you avoid using useless commands and  |
    |                                       |
    | it is written for Ubuntu...           |
    |                                       |
    -----------------------------------------


\"install\" command :

    $ pck3r install \"somthing\" :
    {
        nodejs,
        wine,
        ohmyzsh,
        flstudio,
        minecraft,
        or ...
    }

\"clear\" command :

    $ pck3r clear:
    {clear your terminal }


\"sys\" command :

    $ pck3r sys update
    (update your oprating system)

    $ pck3r sys upgrade
    (upgrade your oprating system)

    $ pck3r sys updgr
    (both, update and upgrade (full upgrade))


\"tilix\" command :

    $ pck3r tilix
    (tilix terminal ...)

\"dotnet\" command :

    $ pck3r install dotnet
    (installing .NET (dot net ) C0RE, ASP, MCS compiler , ...)

\"pkg\" command :

    $ pck3r pkg <package name>
    (search for packages ...)

\"update\" command :

    $ pck3r update
    (update to last release from github.com/amzy-0/pck3r)
    
\"minecraft\" command :

    $ pck3r minecraft
    (minecraft runner)

"version" command :

    $ pck3r version
    (this command show pck3r version)


            %s
    """ % (stuff.YEL, stuff.NRM)




    # pck3r heart runner
    
    if (syscall(' %s/.pck3r/scripts/./pck3r-heart.rb' %getenv('HOME')))==0:
        print(message)
        syscall('~/.pck3r/scripts/./pck3r-heart.rb')

    # if ruby not installed 
    else:
        print('%sdependency detected : ruby-full%s' % (stuff.YEL, stuff.NRM))
        
        syscall('sudo apt install ruby-full')
        syscall('clear')
        print(message)
        syscall('~/.pck3r/scripts/./pck3r-heart.rb')
