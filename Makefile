.PHONY: all install uninstall

all: install

install:
	@echo "Unlinking pck3r (if installed)..."
	-sudo unlink /bin/pck3r
	@echo "Removing /opt/pck3r directory (if exists)..."
	-sudo rm -rf /opt/pck3r
	@echo "Creating /opt/pck3r directory..."
	sudo mkdir -p /opt/pck3r
	@echo "Copying files to /opt/pck3r..."
	sudo cp -rf . /opt/pck3r
	@echo "Creating symbolic link /bin/pck3r -> /opt/pck3r/main.py..."
	sudo ln -s /opt/pck3r/main.py /bin/pck3r
	@echo "Installation complete."

uninstall:
	@echo "Unlinking /bin/pck3r..."
	-sudo unlink /bin/pck3r
	@echo "Removing /opt/pck3r directory..."
	-sudo rm -rf /opt/pck3r
	@echo "Uninstallation complete."
