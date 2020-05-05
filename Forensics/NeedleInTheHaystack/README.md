# Needle in the Haystack

## Forensics -- 300 points

### Description

My PC crashed while I was running some program I found on the internet. I forgot what I typed into it, can you look through the [ram.img.tar.gz](./ram.img.tar.gz) to find it?

### Hints

* https://github.com/iAbadia/Volatility-Plugin-Tutorial
* volatility -f ram.img --profile=Win10x86\_15063 pslist | grep FlagApp
* .text:00311560 ; int \_\_cdecl main(int argc, co........


### Write-up

No write-up or walk-through has been published for this challenge yet.

