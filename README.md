# apricot

Simple **Socket.io** demo written in `C++`. Its aim is to provide a simple
working example of how to use the **Socket.io** library in a `C++` project,
using git `submodules` to manage dependencies and `CMake` as the build system.

```
apricot :: echo server
type 'exit' to quit
-----------------------------------
hello world!
<< hello world!
whoami
<< aiW_1pW3z1nVphxDAAAD
cowsay
<< 
 ______
< Moo! >
 ------
        \   ^__^
         \  (oo)\_______
            (__)\       )\/\
                ||----w |
                ||     ||
exit
-----------------------------------
```

## getting started

To get started with the demo, follow these steps:

1. Clone the repository with submodules recursively:

```bash
git clone --recurse-submodules https://github.com/Jabolol/apricot.git .
```

2. Create a build directory and navigate into it:

```bash
mkdir build
cd build
```

3. Generate the build files using CMake:

```bash
cmake ..
```

4. Initialize the server by running the following command in one terminal:

```bash
deno run -A www/main.ts
```

5. In another terminal, run the compiled Apricot executable:

```bash
./apricot
```

6. Type `help` to see a list of available commands.

## contributing

Contributions are welcome! If you find any issues or have suggestions for
improvements, please open an issue or submit a pull request.

## license

This project is licensed under the [MIT License](LICENSE).
