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
#reading from README

try:
    with open('/opt/pck3r/README.md', 'r') as readme:
        readme = ''.join(readme.readlines()[24:])

except:
    with open('README.md', 'r') as readme:
        readme = ''.join(readme.readlines()[24:])

def msg():

    return '%s%s%s' % (stuff.YEL, readme, stuff.NRM)
