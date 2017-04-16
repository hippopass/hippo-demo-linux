CFLAGS=-Wall -g
LDLIBS=-lhippo-linux-x86_64
LDFLAGS=-L. -Wl,-R.

build: demo

clean:
	rm -rf demo || true

.PHONY: build clean
