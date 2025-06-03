SUDO = sudo
LINK = /bin/pck3r
TARGET_DIR = /opt/pck3r
SRC_DIR = .

.PHONY: all install uninstall check

all: install check

uninstall:
	@echo "Unlinking $(LINK) (if installed)"
	-$(SUDO) unlink $(LINK) || true
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
	$(SUDO) cp -rf $(SRC_DIR)/* $(TARGET_DIR)
	@echo "Creating symbolic link $(LINK) -> $(TARGET_DIR)/main.py"
	$(SUDO) ln -sf $(TARGET_DIR)/main.py $(LINK)

check:
	@echo "Checking link $(LINK)"
	@if [ -L "$(LINK)" ]; then \
		ls -l $(LINK); \
		echo "Link created successfully"; \
	else \
		echo "No link found at $(LINK)"; \
	fi
