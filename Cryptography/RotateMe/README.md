# Rotate Me

## Cryptography -- 5 points

### Description

Our security manager, Julius, is confident nobody can break his encryption and so left the flag for everyone to see. [ciphered\_flag.txt](./ciphered\_flag.txt)

### Hints

* Does knowing the flag format give you any information about how the flag was encrypted?
* When in [Rome](https://en.wikipedia.org/wiki/Caesar_cipher)?
* Julius is notorious for playing games with the problem names...


### Write-up

This is a [rotational/shift cipher](https://en.wikipedia.org/wiki/Caesar_cipher) so just test for the rotation. See the [solve](./solve.py)

```
$ python3 solve.py
ACI{CrYpTo_FuN_fOr_AlL_vHYZgabJ}
```
