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
from os import  getenv
from os import system 
import time
###############################################################################
# Preinstall requirements                                                     #
system('pip install -r requirements.txt --bre')
###############################################################################
# Copy icon to the PATH
system('mkdir -p ~/.pck3r/icon ; cp -rf ./icon/pck3r-logo.png ~/.pck3r/icon')

# creating tkinter window


make_link = 'sudo ln -s %s/.pck3r/main.py /bin/pck3r' % getenv('HOME')

# Progress bar widget

# Function responsible for the updation
# of the progress bar value
def install():

    time.sleep(1)
    print('Unlinking pck3r (if was installed) ')
    system('sudo unlink /bin/pck3r ')
    system('sudo rm -rf /bin/pck3r*')
   
    system('rm -rf ~/.pck3r && sudo rm -rf /root/.pck3r') if (system('echo %s ; ls ~/.pck3r' % stuff.CYN)) ==0 else print('%sCopy all pck3r directory %s' %(stuff.CYN, stuff.NRM))
    system('mkdir ~/.pck3r')
    system('cp -rf . ~/.pck3r')
    system('sudo cp -rf . /root/.pck3r')
    system(make_link)
    time.sleep(1)
    print('%sCheck link ' % stuff.YEL)
    print('Link created ') if (system('ls -l  /bin/pck3r')) == 0  else print('%s%sNo link (/bin/pck3r)%s ' % (stuff.sysOk(), stuff.RED, stuff.NRM))
    time.sleep(1)
    print('%s%sPck3r installed successfuly %s' % (stuff.sysOk(), stuff.GRN, stuff.NRM))
    


install()