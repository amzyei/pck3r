#!/usr/bin/ruby
 # mehrzero@gmail.com :]
require './requirements/library'
home=Dir.home
Dir.chdir(home+"/.pck3r")
def tlauncher()
  if (system"wget https://tlauncher.org/jar;unzip jar;rm README-* .txt jar;mv TLauncher* TLauncher.jar ")!=true
    sys_status"error"
    return 1
  else
    sys_status"not_error"
    return 0
  end
end
print "\nPrerequisites for installing software minecraft are:\n\t1.Update the entire system \n\t2.install openjfx\n\t3.install openjdk-8-jre\n".bold
sys_status("start_install")
system "sudo apt update && sudo apt full-upgrade -y" #update and upgrade (full upgrade)
# (install openjfx) * (install openjdk-8-jre)
system "sudo apt install openjfx -y && sudo apt install openjdk-8-jre -y"
if tlauncher()!=0
  print "The operation was a failure\nTlauncher not found !\n".red
  sys_status"error"
else
  print "/TLauncher.jar\nPlease try : \n".green,"$ pck3r minecraft\n".bold.brown
end
