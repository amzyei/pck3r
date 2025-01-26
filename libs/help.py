#!/usr/bin/python3
#!/usr/bin/ruby

""" 

Short description of this RUBY module.
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

from os import system as syscall
from os import getenv

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



