#!/usr/bin/python3

from . import stuff
import os 

def installFirefox():
    print(f'{stuff.sysOk()}\n[WAIT FOR PROCESSING]\n{stuff.YEL}')
    os.system('''\
sudo apt purge -y firefox \
sudo install -d -m 0755 /etc/apt/keyrings && \
wget -q https://packages.mozilla.org/apt/repo-signing-key.gpg -O- | sudo tee /etc/apt/keyrings/packages.mozilla.org.asc > /dev/null && \
gpg -n -q --import --import-options import-show /etc/apt/keyrings/packages.mozilla.org.asc | awk '/pub/{getline; gsub(/^ +| +$/,""); if($0 == "35BAA0B33E9EB396F59CA838C0BA5CE6DC6315A3") print "\\nThe key fingerprint matches ("$0").\\n"; else print "\\nVerification failed: the fingerprint ("$0") does not match the expected one.\\n"}' && \
echo "deb [signed-by=/etc/apt/keyrings/packages.mozilla.org.asc] https://packages.mozilla.org/apt mozilla main" | sudo tee -a /etc/apt/sources.list.d/mozilla.list > /dev/null && \
echo 'Package: *\nPin: origin packages.mozilla.org\nPin-Priority: 1000' | sudo tee /etc/apt/preferences.d/mozilla && \
sudo apt-get update && sudo apt-get install -y firefox
''')

