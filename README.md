# Rail Cipher Transposition Encryption & Decryption Tool

This command-line tool implements an inspired rail cipher algorithm for encrypting and decrypting text messages using transposition. It allows users to specify a custom encryption key via command-line arguments and supports interactive commands for encryption, decryption, and application termination.

## Features

- **Encryption & Decryption:** Securely encrypt and decrypt messages using the rail cipher technique.
- **Custom Encryption Key:** Define a custom key for the encryption and decryption process.
- **Interactive Commands:** Use simple commands to perform encryption, decryption, or exit the application.

## Getting Started

### Prerequisites

- GCC compiler or any C compiler installed on your system.

### Installation

1. Clone this repository or download the source code.
2. Navigate to the project directory.
3. Compile the application using the provided `Makefile` by running:

```bash
make
```

This will generate an executable named `railcipher`.

### Usage

Run the application with the following command:

```bash
./railcipher <length of key> <key numbers...>
```

- `<length of key>`: The length of the encryption/decryption key.
- `<key numbers...>`: The sequence of numbers representing the key, separated by spaces.

#### Commands

After starting the application, use the following commands in the interactive prompt:

- `encrypt`: Encrypt a message. After entering this command, type the message you wish to encrypt and press Enter.
- `decrypt`: Decrypt a message. Similar to encryption, type the encrypted message after the command.
- `quit`: Exit the application.

## Example

```bash
./railcipher 7 4 3 1 2 5 6 7
encrypt Attack postponed until two A.M.
decrypt TTNAAPTMTSUOAODWCOIXKNLYPETZ
quit
```

## License

```text
Copyright 2024 Angatia Benson

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
```
