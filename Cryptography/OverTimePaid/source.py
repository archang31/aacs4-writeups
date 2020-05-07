#!/usr/bin/python3
import os
import binascii
import random

words = [
    "ALPHA",
    "BRAVO",
    "CHARLIE",
    "DELTA",
    "ECHO",
    "FOXTROT",
    "GOLF",
    "HOTEL",
    "INDIA",
    "SIERRA",
    "TANGO",
    "ZETA",
]

INTRO = "The following encoded individuals are to be given a $27.3k bonus:".ljust(63) + "\n"
OUTRO = "Furthermore, the FLAG is:".ljust(63) + "\n"

def divide_chunks(l, n):
    # looping till length l
    for i in range(0, len(l), n):
        yield l[i:i + n]

def encrypt_otp(data):
    d = data.encode('utf-8')
    otp = bytes(os.urandom(64))
    out = []
    for i in range(0, len(d)):
        out.append(d[i] ^ otp[i % len(otp)])
    return bytes(out)

def generate_line(length):
    out = ''
    while len(out) < length:
        out += random.choice(words) + " "

    out = out[0:length-1]
    out = ' '.join(out.split(" ")[0:-1])
    return out.ljust(length-1) + '\n'


def generate_doc(flag):
    out = INTRO

    for i in range(0,10):
        out += generate_line(64)

    out += " " * 63 + "\n"
    out += OUTRO + "\n"
    out += flag.ljust(63) + "\n"
    return out

flag = "redacted"
doc = generate_doc(flag)
enc = encrypt_otp(doc)
enc = list(divide_chunks(enc, 64))

out = b''
for line in enc:
    out += binascii.hexlify(line) + b"\n"

f = open("./document.encrypted", "wb")
f.write(out)
f.close()


