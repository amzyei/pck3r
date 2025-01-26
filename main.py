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

from os import system, chdir, getenv
from sys import argv
from libs import stuff, dotnet, wine 

argc = len(argv)

for i in range(argc):

        # if user just type $ pck3r
        if argc <= 1:
                print('%s%sCommand not found !%s\nPlease try:\n$ pck3r help %s' 
                    %  (stuff.sysERR(), stuff.RED, stuff.CYN, stuff.NRM))

        else:

            # if argument 1 equal to "clear"
            # clear terminal
            # do :
            if argv[1] == 'clear' and argc == 2:
                system('clear')
                print('%sThis is funny clear command :D ' 
                % stuff.sysOk())
            
            # pck3r updator
            elif argv[1] == 'update' and argc == 2:
                chdir('%s/.pck3r' 
                % getenv('HOME'))
                print('%s/.pck3r/./updator'  
                % getenv('HOME'))
                system('./updator')

            # if argument 1 equal to "help"
            # like -> $ pck3r help
            # do :
            elif argv[1] == 'help' and argc == 2:
                from libs import help

            # if argument 1 equal to "install"
            # and argument 2 is not empty
            # do :
            elif argv[1] == 'install' and argc >= 2:

                # if after install is empty
                if argv[1]== 'install' and argc <= 2:
                    print('%s%sAfter "install" is empty !%s ' 
                    % (stuff.sysERR() , stuff.RED, stuff.NRM))
                
                elif argv[2] == 'flstudio' and argc == 3:
                    from libs import flstudio

                # if argument 2 is nodejs
                elif argv[2]=='nodejs' and argc==3:

                    if (system(
                        '''echo %s ; 
                        curl -sL https://deb.nodesource.com/setup_12.x | sudo -E bash - ;
                         echo %s ; sudo apt install nodejs; sudo apt-get update && echo %s;
                         sudo apt install yarnpkg -y'''
                        % (stuff.YEL, stuff.CYN, stuff.MAG)))==0:

                        print('%s' % stuff.sysOk())

                        system('echo %s"Nodejs LTS Version :" ;  node --version %s' 
                        %(stuff.GRN, stuff.NRM))
                        system('echo "Npm Version :" %s; npm --version %s' 
                        %(stuff.GRN, stuff.NRM))

                        # Exception
                    else:
                        print('%s%s\nplease retry...\n$ pck3r install nodejs%s ' 
                        % (stuff.sysERR() , stuff.RED, stuff.NRM))

                elif argv[2] == 'dotnet' and argc==3:
                    dotnet.install_dotnet()

                elif argv[2] == 'ohmyzsh' and argc==3:
                    system('sudo apt install zsh curl')
                    if (system('curl --version')) == 0 :
                        system('sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"') 
                    else:
                        system('echo "curl" is required for using "ohMyZsh" ; sudo apt install curl')
                        system('sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"') 

                elif argv[2] == 'minecraft' and argc==3:
                    chdir('%s/.pck3r' % getenv('HOME'))
                    system('g++ minecraft-pck3r.cpp -o  minecraft')
                    system('./minecraft')
                
                # wine installer blocks
                # command : $ pck3r install  wine 
                elif argv[2] == 'wine' and argc==3:
                    wine.wine_installer()

                # argument 2 is not empty

                elif argv[2:] != [] and argc >= 2:
                    print('%s%s\nCommand is valid!\n%s' 
                    % (stuff.sysOk(), stuff.GRN, stuff.YEL))
                    if (system('sudo apt install %s' 
                    % ' '.join(argv[2:])))==0:
                        pass
                    # Exception
                    else:
                        print('%s%sPackage(s) or Command(s) not found : \'%s"' 
                        % (stuff.sysERR(), stuff.RED, ' '.join(argv[2:])))

            # if argument 1 equal to "uninstall"
            elif argv[1] == 'uninstall' and argc >= 2:

                # if after "uninstall" is empty
                if argv[1] == 'uninstall' and argc <= 2:

                    print('%s %sAfter "uninstall" is empty !%s ' 
                    % (stuff.sysERR() , stuff.RED, stuff.NRM))
                
                # if user want uninstall dotnet 
                # do :
                elif argv[2]=='dotnet' and argc==3:
                    dotnet.uninstall_dotnet()

                # argument 2 is not empty
                # do :
                elif argv[2:] != [] and argc >= 2:
                    print('%s%s\nCommand is valid!\n%s' % (stuff.sysOk(), stuff.GRN, stuff.YEL))
                    system('sudo apt purge %s' % ' '.join(argv[2:]))

            # if argument 1 equal to "rm" (sudo apt remove)
            elif argv[1] == 'rm' and argc >= 2:

                # if after install is empty
                if argv[1]== 'rm' and argc<=2:
                    print('%s %sAfter "rm" is empty !%s ' % (stuff.sysERR() , stuff.RED, stuff.NRM))

                #  argument 2 is not empty
                # do :
                if argv[2:] != [] and argc>=2:
                    print('%s%s\nCommand is valid!\n%s' % (stuff.sysOk(), stuff.GRN, stuff.YEL))
                    system('sudo apt remove %s' % ' '.join(argv[2:]))

                # Exception
                else:
                    print('%sCommand or package(s) not found : %s' % (stuff.sysERR(), ' '.join(argv[2:])))


            # Too many arguments error for $ pck3r term
            # Only use :
            # $ pck3r tilix <somthing> <somthing> <somthing> <somthing>, ...
            elif argv[1] =='tilix' and argc==2:
                system('sudo apt install tilix  ; clear ; tilix ')


            # Too many arguments error for $ pck3r tilix
            # Only use :
            # $ pck3r tilix <somthing> <somthing> <somthing> <somthing>, ...
            elif argv[1] =='tilix' and argc>2:
                    print('%s%sToo many arguments !\nOnly use :\n$ pck3r term %s' % (stuff.sysERR(), stuff.RED, stuff.NRM))


            # if after "sys" command is empty
            elif argv[1] == 'sys' and argc == 2:
                print('''
                %s%sAfter "sys" is empty !
                Please try:
                $ pck3r sys <update/upgrade/updgr(update and upgrade)>%s
                '''
                 % (stuff.sysERR() , stuff.RED, stuff.NRM))

            # if after pck3r equal to "sys"
            elif argv[1] == 'sys' and argc > 2:
                if argv[2]=='update' and argc==3:
                    system('sudo apt update')
                    print('%s%s\nYour OS updated%s' % (stuff.sysOk(), stuff.GRN, stuff.NRM))

                # if user command, equal to $ pck3r sys upgrade
                #do :
                elif argv[2] == 'upgrade' and argc==3:
                    
                    if (system('sudo apt full-upgrade')) == 0:
                        
                        # print with green logo  
                        print('%s%syour OS  upgraded' % (stuff.sysOk(), stuff.GRN))
                        # echo green color and 
                        # and say:
                        system('echo %s' % stuff.GRN)
                    
                        # All information about OS 
                        system('echo your OS information :')
                        system('uname -a ')

                        # the machine architecture 
                        system('echo your machine architecture : ')
                        system('uname -p')
                        # end of the all information and 
                        #back to the true color of this terminal 
                        system('echo %s' % stuff.NRM)
                    
                    # Exception
                    else:
                        
                        print(f'{stuff.sysERR()}{stuff.RED}Please try:\n$ pck3r sys <update/upgrade/updgr(update and upgrade)>{stuff.NRM}')


                # if user command, equal to $ pck3r sys updgr
                #do :
                elif argv[2] == 'updgr' and argc==3:
                    
                    if (system('sudo apt update && sudo apt full-upgrade')) ==0:
                            
                        print('%s%syour OS updated and upgraded' % (stuff.sysOk(), stuff.GRN))
                        system('echo %s' % stuff.GRN)
                        system('echo your OS information :')
                        system('uname -a ')
                        system('echo your machine architecture : ')
                        system('uname -p')
                        system('echo %s' % stuff.NRM)
                                    
                # if command is not a valid one !
                # will send an error to the user.
                # do :
                else:
                    print(f'{stuff.sysERR()}{stuff.RED}Please try:\n$ pck3r sys <update/upgrade/updgr(update and upgrade)>{stuff.NRM}')
                    
                    
            # if after "pkg" is empty
            elif argv[1]== 'pkg' and argc <= 2:
                print('%s%sAfter "pkg" is empty !%s ' % (stuff.sysERR() , stuff.RED, stuff.NRM))
            
            # if after "pkg" is not empty
            elif argv[1] == 'pkg' and argc >= 2:

                # if after "pkg" isn't empty
                if argv[2:] != [] and argc >= 2:
                    system('sudo apt search %s' % ' '.join(argv[2:]))
            
            elif argv[1] == 'minecraft' and argc ==2:

                    if (system('ls ~/.TLauncher-2.75.jar'))==0:
                            print('%s%sRunning minecraft...%s' %(stuff.sysOk() , stuff.GRN, stuff.NRM))
                            system('sudo java -jar ~/.TLauncher-2.75.jar')
                    
                    else:

                        print('''%s%s
                        Can't running minecraft  !
                        check this path : %s/.TLauncher-2.75.jar
                        install minecraft :
                        $ pck3r install minecraft%s
                        '''
                        %(stuff.sysERR(), stuff.RED, getenv('HOME'), stuff.NRM))
            

            # if user want to see the pck3r version
            elif argv[1] == 'version' and argc ==2:
                print(f'{stuff.CYN}version is :{stuff.YEL} 0.2{stuff.NRM}')
          

            # if command not valid 
            # print :
            # and breaking any operation  
            else:
                print('%s%sCommand not found !%s\nPlease try:\n$ pck3r help %s'
                 % (stuff.sysERR(), stuff.RED, stuff.CYN, stuff.NRM))

        # end of (for) loop
        break
