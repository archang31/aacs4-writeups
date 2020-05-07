# Needle in the Haystack

## Forensics -- 300 points

### Description

My PC crashed while I was running some program I found on the internet. I forgot what I typed into it, can you look through the [ram.img.tar.gz](https://challenge.acictf.com/static/fd6851d0187f64596550b2f8b2b517e2/ram.img.tar.gz) to find it?

**Note:** I did not download this locally due to size.

### Hints

* https://github.com/iAbadia/Volatility-Plugin-Tutorial
* volatility -f ram.img --profile=Win10x86\_15063 pslist | grep FlagApp
* .text:00311560 ; int \_\_cdecl main(int argc, co........


### Write-up

No write-up or walk-through has been published for this challenge yet.
