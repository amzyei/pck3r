#!/usr/bin/env python3

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

#color zone
NRM = "\x1B[0m"
RED = "\x1B[31m"
GRN = "\x1B[32m"
YEL = "\x1B[33m"
BLU = "\x1B[34m"
MAG = "\x1B[35m"
CYN = "\x1B[36m"
WHT = "\x1B[37m"
#end of color zone

# Modules error

def stop():
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
    """ )

if __name__ == "__main__":
    stop()
else:
    # system error (red logo print)
    def sysERR():
        return("\n%s尸⼕长㇌尺 : ERROR !\n%s"% (RED, NRM))

    #system call done (green logo print)
    def sysOk():
        return("\n%s尸⼕长㇌尺 :\n %s" % (GRN, NRM))
