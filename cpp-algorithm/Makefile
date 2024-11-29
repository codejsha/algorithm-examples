BUILD_TYPE:=debug

UNAME_S:=$(shell uname -s)
ifeq ($(UNAME_S),Linux)
	PRESET_NAME:=linux-$(BUILD_TYPE)
else ifeq ($(UNAME_S),Darwin)
	PRESET_NAME:=macos-$(BUILD_TYPE)
else ifeq ($(UNAME_S),Windows_NT)
	PRESET_NAME:=windows-$(BUILD_TYPE)
else
	$(error Unsupported platform: $(UNAME_S))
endif

BUILD_DIR:=$(PWD)/out/build/$(PRESET_NAME)

.PHONY: default
default:
	@echo "Please specify the target"

.PHONY: clean
clean:
	rm -rf $(BUILD_DIR)

.PHONY: configure
configure:
	cmake --preset $(PRESET_NAME)

.PHONY: build
build:
	cmake --build $(BUILD_DIR) --target all --parallel 6

.PHONY: test
test:
	ctest --test-dir $(BUILD_DIR)
