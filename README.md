![release](https://img.shields.io/badge/release-1.0-blue) ![issues](https://img.shields.io/github/issues/amzyei/pck3r) ![license](https://img.shields.io/github/license/amzyei/pck3r)

# pck3r

![Screenshot](screenshot/pck3r.png)

Pck3r is a modern package manager for Ubuntu. It is a simple tool that helps users manage software using APT, the Advanced Package Tool. Pck3r makes installing, updating, and managing software easier with a clear interface and simple commands.

# Logo

    尸⼕长㇌尺

# System-wide Installation

*To install system-wide:*

```bash
$ make all / make install 
```

# pck3r Commands

**install** command:

```bash
$ pck3r install "something"
```

Examples of packages you can install:

- nodejs
- wine
- ohmyzsh
- or others

**clear** command:

```bash
$ pck3r clear
```

This command clears your terminal (just for fun :D).

**sys** command:

```bash
$ pck3r sys update
```

Updates your operating system.

```bash
$ pck3r sys upgrade
```

Upgrades your operating system.

```bash
$ pck3r sys updgr
```

Updates and fully upgrades your system, including snap packages.

**pkg** command:

```bash
$ pck3r pkg <package name>
```

Searches for packages.

**update** command:

```bash
$ pck3r update
```

Updates pck3r to the latest release from github.com/amzyei/pck3r.

**version** command:

```bash
$ pck3r version
```

Shows the current version of pck3r.
