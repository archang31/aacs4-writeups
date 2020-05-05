# We're Related

## Cryptography -- 250 points

### Description

Recently, the Beacon Messenger App added support for one-time-read, 'disappearing' messages. We need you to find a flaw in their implementation, then decrypt an intercepted message provided to you upon connection. {{server}}:{{port}} [messenger.py](./messenger.py)

### Hints

* The server does not use any padding scheme and so ciphertexts are deterministic!
* RSA ciphertexts are 'just numbers'; they are malleable
* Can you create a ciphertext that is 'related to' the flag ciphertext? Maybe the server will respond with a 'related' plaintext!


### Write-up

No write-up or walk-through has been published for this challenge yet.

