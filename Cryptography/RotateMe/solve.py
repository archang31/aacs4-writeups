def rotate(sentence, shift):
    """
    Using an implementation of the rotational cipher, given a sentence
    return a new sentence(code) shifted by (shift) amount
    """
    code = []

    for letter in sentence:
        if letter.isupper():
            new_letter = (ord(letter) + shift) % (ord('Z') + 1)
            if new_letter < ord('A'):
                new_letter = chr(new_letter + ord('A'))
            else:
                new_letter = chr(new_letter)
            code.append(new_letter)
        elif letter.islower():
            new_letter = (ord(letter) + shift) % (ord('z') + 1)
            if new_letter < ord('a'):
                new_letter = chr(new_letter + ord('a'))
            else:
                new_letter = chr(new_letter)
            code.append(new_letter)
        else:
          code.append(letter)

    return ''.join(code)

with open("ciphered_flag.txt", 'rt') as f:
    cipher = f.read()
for i in range(1, 26):
    plaintext = rotate(cipher, i)
    if 'ACI' in plaintext:
        print(plaintext)
        break
