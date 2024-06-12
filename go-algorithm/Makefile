.PHONY: all
all: download verify test

.PHONY: fmt
fmt:
	go fmt ./...

.PHONY: clean
clean:
	go clean

.PHONY: download
download:
	go mod download -x

.PHONY: verify
verify:
	go mod verify

.PHONY: build
build:
	go build ./...

.PHONY: test
test:
	go test -v ./...
