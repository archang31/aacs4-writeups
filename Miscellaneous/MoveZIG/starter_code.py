#!/usr/bin/python3
import argparse
import socket

# 'argparse' is a very useful library for building python tools that are easy
# to use from the command line.  It greatly simplifies the input validation
# and "usage" prompts which really help when trying to debug your own code.
parser = argparse.ArgumentParser(description="Solver for 'All Your Base' challenge")
parser.add_argument("ip", help="IP (or hostname) of remote instance")
parser.add_argument("port", type=int, help="port for remote instance")
args = parser.parse_args();

# This tells the computer that we want a new TCP "socket"
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# This says we want to connect to the given IP and port
sock.connect((args.ip, args.port))

# This gives us a file-like view for receiving data from the connection which
# makes handling messages from the server easier since it handles the
# buffering of lines for you.  Note that this only helps us on receiving data
# from the server and we still need to send data over the underlying socket
# (i.e. `sock.send(...)` at the end of the loop below).
f = sock.makefile()

while True:
    line = f.readline().strip()
    # This iterates over data from the server a line at a time.  This can
    # cause some unexpected behavior like not seeing "prompts" until after
    # you've sent a reply for it (for example, you won't see "answer:" for
    # this problem). However, you can still "sock.send" below to transmit data
    # and the server will handle it correctly.

    # Handle the information from the server to extact the problem and build
    # the answer string.
    pass # Fill this in with your logic
    # A good starting point for approaching the problem:
    #   1) Identify and capture the text of each question (the "----" lines
    #          should be useful for this).
    #   2) Extract the three primary parts of each question:
    #      a) The source encoding
    #      b) The destination encoding
    #      c) The source data
    #   3) Convert the source data to some "standard" encoding (like 'raw')
    #   4) Convert the "standardized" data to the destination encoding

    # Send a response back to the server
    answer = "Clearly not the answer..."
    sock.send((answer + "\n").encode()) # The "\n" is important for the server's
                                        # interpretation of your answer, so make
                                        # sure there is only one sent for each
                                        # answer.
