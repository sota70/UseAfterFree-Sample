# Use-After-Free Exploitation Sample Code

This repository contains sample code demonstrating a use-after-free vulnerability and a secure version with the vulnerability fixed. The code is written in C programming language.

## Table of Contents

- [Introduction](#introduction)
- [Vulnerable Code](#vulnerable-code)
- [Secure Code](#secure-code)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Use-after-free is a type of software vulnerability that occurs when a program accesses memory that has been freed. This vulnerability can lead to various security issues, including crashes, information disclosure, or even remote code execution.

The purpose of this sample code is to demonstrate the use-after-free vulnerability and provide a secure version that mitigates the vulnerability.

## Vulnerable Code

The `vuln.c` file contains the vulnerable code that demonstrates the use-after-free vulnerability. It includes a `login` function that performs a login based on the user's permission stored in a `User` structure. The `main` function demonstrates the use-after-free vulnerability by freeing a `User` structure and then accessing it again.

## Secure Code

The `secure.c` file contains the secure version of the code that fixes the use-after-free vulnerability. It introduces a `safeFree` function that securely frees the memory and sets the pointer to `NULL`. The `main` function in the secure version demonstrates the correct usage of `safeFree` to prevent unauthorized access to freed memory.

## Usage

To compile and run the code, follow these steps:

1. Make sure you have a C compiler installed on your system (e.g., GCC).
2. Open a terminal and navigate to the directory containing the source code files (`vuln.c` and `secure.c`).
3. Compile the vulnerable code by running the following command:
4. Compile the secure code by running the following command:
5. Run the vulnerable code by executing the following command:
6. Run the secure code by executing the following command:

**Note:** Running the vulnerable code may result in undefined behavior or crashes due to the use-after-free vulnerability. The secure code, on the other hand, demonstrates the correct usage to prevent the vulnerability.

## Contributing

Contributions to this sample code are welcome. If you find any issues or have suggestions for improvement, please feel free to open an issue or submit a pull request.

## License

This sample code doesn't have license.

---

Please note that the provided code contains a vulnerability that can be exploited for malicious purposes. It is important to use this code responsibly and only for educational or authorized testing purposes. Do not use it for any illegal activities or to harm others. Always prioritize security and ensure that your code is free from vulnerabilities.
