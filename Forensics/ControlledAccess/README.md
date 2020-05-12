# Controlled Access

## Forensics -- 50 points

### Description

We've been asked to help a certificate authority figure out what a [device](https://shop.hak5.org/products/shark-jack) they found plugged into their network was doing. They were able to dump the [firmware.bin](./firmware.bin) and would like to know if it allowed the attacker to connect to any devices that their firewall (which blocks inbound SSH) would have stopped. Their internal domain uses 'digisigner.local' for DNS host names. The flag is the hostname of the *internal* host that the hacker targeted (i.e. ACI{[local hostname targeted]}).

### Hints

* A tool like [binwalk](https://github.com/ReFirmLabs/binwalk) might be useful for inspecting the firmware.
* The [documentation](https://docs.hak5.org/hc/en-us/categories/360002117973-Shark-Jack) mentions that the 'attack' payload for this device lives in a very particular spot on the filesystem...


### Write-up

- [Write-up by starkindustries](https://github.com/starkindustries/CyberStakes2020#controlled-access---points-50)
- [Write-up by starkindustries Pt2](https://github.com/starkindustries/CyberStakes2020/tree/master/ControlledAccess)
- [Write-up by eesantiago](https://github.com/eesantiago/Writeups/tree/master/CyberStakes_2020/controlled_access)
