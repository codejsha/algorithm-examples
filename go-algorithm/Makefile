.PHONY: all
all: fmt clean build test

.PHONY: fmt
fmt:
	go fmt ./...

.PHONY: clean
clean:
	go clean

.PHONY: build
build:
	go build ./...

.PHONY: test
test:
	go test -v ./...
