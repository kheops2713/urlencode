all: urlencode urldecode

urlencode:
	gcc -lcurl -o urlencode urlencode.c

urldecode:
	ln -s urlencode urldecode

clean:
	rm -f urlencode urldecode

install:
	install -s -m 755 urlencode /usr/local/bin
	install -s -m 755 urldecode /usr/local/bin

.PHONY: all install clean
