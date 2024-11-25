# Build Your Own Web Server (c++)
This challenge is to build your own basic web server.

At its core a web server is actually quite simple. It’s a server that listens for connections from clients and responds to them. The clients make those requests using a protocol known as HTTP (and expect responses in the same protocol, obviously).

HTTP like many early Unix and Internet protocols is text based, so human readable. The original HTTP specification from 1991, is short and sweet. It originally didn’t even have a version number! But was later renamed HTTP/0.9, to differentiate it from HTTP/1.0. The HTTP/1.0 specification seems to be lost in the mists of time.

The first full formal HTTP specification is HTTP/1.1 - also known as - RFC2616 from 1999. You can dig through all the HTTP standards on the W3C website.

[Instructions](https://codingchallenges.fyi/challenges/challenge-webserver)

# Build

Linux only : ```./build.sh```

Change **BUILD_MODE** (in build.sh)
- None: 149K
- Debug: 723K
    - enables SO_REUSEADDR option on the socket, address can be reused before the operating system releases the port.
    - prints info to stdout.
- RelWithDebInfo: 919K
- MinSizeRel: 55K

# Usage

```
./ccwebserver
./ccwebserver -h
./ccwebserver -p 80
```

# Test
```
build.sh -t
```

# Multiple requests
run script ```doRequests.sh```
- results: 
    - 1000 requests done in 1971 - 2632 milliseconds
    - 5000 requests while doing requests in browser without lag
