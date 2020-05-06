# National Dex #65

## Reverse Engineering -- 100 points

### Description

We found the encryptor ([encrypt](./encrypt)) but it won't decrypt [encrypted](./encrypted)?

### Hints

* I think they're using a cipher designed by Bruce Schneier.
* When reversing, it's useful to look for magic constants or use a tool like [findcrypt](http://www.hexblog.com/?p=27) ([idapython version](https://github.com/you0708/ida/tree/master/idapython_tools/findcrypt) or [Ghidra version](https://github.com/d3v1l401/FindCrypt-Ghidra)).
* Make sure you're using CBC mode.


### Write-up

- [Write-up by welchbj](https://github.com/welchbj/ctf/tree/master/writeups/2020/CyberStakes/national-dex-65)
