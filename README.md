![]()
![]()
![]()
# pck3r :

=======
![release](https://img.shields.io/badge/release-1.0-blue) ![issues](https://img.shields.io/github/issues/amzyei/pck3r) ![license](https://img.shields.io/github/license/amzyei/pck3r)

# pck3r

>>>>>>> REPLACE
<<<<<<< SEARCH
# pck3r :

![Screenshot](screenshot/pck3r.png)

Pck3r is a modern package manager for Ubuntu. It acts as a simple tool that helps users manage software with APT, or Advanced Package Tool. Pck3r makes installing, updating, and managing software easier with a clear interface and straightforward commands.

# logo :

    尸⼕长㇌尺



# system wide installation :


*for system wide installation :*


$ ./setup.py




# pck3r commands

"install" command :

    $ pck3r install "somthing" :
    {
        nodejs,
        wine,
        ohmyzsh,      
        or ...
    }
    
"clear" command :

    $ pck3r clear:
    clear your terminali (only for fun :D)

"sys" command :

    $ pck3r sys update
    update your oprating system

    $ pck3r sys upgrade
    upgrade your oprating system

    $ pck3r sys updgr
    update and full-upgrade, Include snap's packages.

"pkg" command :

    $ pck3r pkg <package name>"
    (search for packages ...)"


"update" command :

    $ pck3r update
    update to last release from github.com/amzyei/pck3r



"version" command :

    $ pck3r version
    this command show pck3r version



=======
# pck3r :

![Screenshot](screenshot/pck3r.png)

Pck3r is a modern package manager for Ubuntu. It acts as a simple tool that helps users manage software with APT, or Advanced Package Tool. Pck3r makes installing, updating, and managing software easier with a clear interface and straightforward commands.

## Logo

```
尸⼕长㇌尺
```

## System-wide Installation

To install pck3r system-wide, use the provided Makefile:

```bash
make install
```

This will copy the necessary files to `/opt/pck3r` and create a symbolic link `/bin/pck3r` pointing to the main executable.

To uninstall pck3r, run:

```bash
make uninstall
```

## pck3r Commands

### install

Install packages such as nodejs, wine, ohmyzsh, or others:

```bash
pck3r install "package_name"
```

Example packages:

- nodejs
- wine
- ohmyzsh
- or others

### clear

Clear your terminal (just for fun :D):

```bash
pck3r clear
```

### sys

Manage your operating system updates:

```bash
pck3r sys update
pck3r sys upgrade
pck3r sys updgr
```

- `update`: update your operating system
- `upgrade`: upgrade your operating system
- `updgr`: update and full-upgrade, including snap packages

### pkg

Search for packages:

```bash
pck3r pkg <package_name>
```

### update

Update pck3r to the latest release from GitHub:

```bash
pck3r update
```

### version

Show the current version of pck3r:

```bash
pck3r version
```
