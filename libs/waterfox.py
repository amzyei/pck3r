import os 
from . import stuff

def install():

    os.system('''
sudo tee /usr/bin/waterfox > /dev/null <<EOF
#!/bin/bash
/opt/waterfox/waterfox
EOF
; 
wget https://cdn1.waterfox.net/waterfox/releases/6.5.6/Linux_x86_64/waterfox-6.5.6.tar.bz2
;
tar xvf waterfox-6.5.6.tar.bz2 && sudo rm -rf /opt/waterfox && sudo cp -rf waterfox /opt/ && sudo chmod +x /usr/bin/waterfox
''')