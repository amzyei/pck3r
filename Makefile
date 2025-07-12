SUDO = sudo
LINK = /usr/bin/pck3r
TARGET_DIR = /opt/pck3r
SRC_DIR = .

.PHONY: all install uninstall check

all: install check

uninstall:
	@echo "Removing $(LINK) (if installed)"
	$(SUDO) rm -r $(LINK) || true
	@if [ -d "$(TARGET_DIR)" ]; then \
		echo "Removing $(TARGET_DIR) directory"; \
		$(SUDO) rm -rf $(TARGET_DIR); \
	else \
		echo "$(TARGET_DIR) does not exist, skipping removal"; \
	fi

install: uninstall
	@echo "Creating $(TARGET_DIR) directory"
	$(SUDO) mkdir -p $(TARGET_DIR)
	@echo "Copying files to $(TARGET_DIR)"
	$(SUDO) rsync -a $(SRC_DIR)/ $(TARGET_DIR)/
	@echo "Making main.py executable"
	$(SUDO) chmod +x $(TARGET_DIR)/main.py
	@echo "Creating wrapper script $(LINK)"
	@echo '#!/bin/sh' | $(SUDO) tee $(LINK) > /dev/null
	@echo '/usr/bin/python3 $(TARGET_DIR)/main.py "$$@"' | $(SUDO) tee -a $(LINK) > /dev/null
	$(SUDO) chmod +x $(LINK)

check:
	@echo "Checking $(LINK)"
	@if [ -e "$(LINK)" ] && [ -x "$(LINK)" ]; then \
		ls -l $(LINK); \
		echo "Executable found successfully"; \
	else \
		echo "No executable found at $(LINK)"; \
	fi
