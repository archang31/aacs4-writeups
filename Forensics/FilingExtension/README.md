# Filing Extension

## Forensics -- 10 points

### Description

We went to apply for a tax-filing extension with the IRS, and they replied with this image saying it contained the code we needed. Unfortunately, our computer refuses to display it and just says that it isn't a PNG... [flag.png](./flag.png)

### Hints

* Is the extension the only way to tell a file's type?
* Wouldn't it be awesome if there was a [list](https://en.wikipedia.org/wiki/List_of_file_signatures) of way to identify files.


### Write-up

- [Write-up by starkindustries](https://github.com/starkindustries/CyberStakes2020#filing-extension---points-10)

Use `file` to determine the type of file and then interact with it as appropriate.

```
$ file flag.png
flag.png: Zip archive data, at least v2.0 to extract
$ mv flag.png flag.zip
$ unzip flag.zip
Archive:  flag.zip
  inflating: flag.txt
$ ls
flag.txt  flag.zip
$ cat flag.txt
ACI{Something_witty_ec22b3a9}%
```
