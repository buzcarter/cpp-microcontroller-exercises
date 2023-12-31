# New C++ Project Stub

## Installing On Windows

Here's what i remember:

* install gcc
* install MinGW (make)
* Edit System Environment Variables (add above bin directories to your system's PATH)
    * %NVM_HOME%
    * %NVM_SYMLINK%
    * C:\Program Files\Git\cmd
    * F:\Program Files\Arduino CLI\
    * F:\Program Files\C-Compilers\bin
    * F:\Program Files\mingw64\bin

Check versions:

```sh
g++ --version 
git --version
mingw32-make.exe --version
node -v
npm -v
nvm --version
```

## Create Stubs

```sh
code includes/sandbox.cpp
code critter.cpp
code .vscode/tasks.json
code .gitignore
code .editorconfig
code README.md
git init
```

## Contents

### sandbox.cpp

```cpp
bool isSwingSetAvailable()
{
  return true;
}
```

### critter.cpp

```cpp
#include <iostream>
#include "includes/sandbox.cpp"

using std::cout;
using std::endl;

int main()
{
  cout << (isSwingSetAvailable() ? "Go to the park now" : "You'd better wait") << endl;

  return 0;
}
```

### tasks.json

```json
{
  "version": "2.0.0",
  "tasks": [{
    "label": "build and run",
    "type": "shell",
    "command": "g++ critter.cpp -o critter && ./critter",
    "group": {
      "kind": "build",
      "isDefault": true
    }
  }]
}
```

### .gitignore

### .editorconfig

```shell
# editorconfig.org
root = true

[*]
indent_style = space
indent_size = 2
end_of_line = lf
charset = utf-8
trim_trailing_whitespace = true
insert_final_newline = true

[*.md]
trim_trailing_whitespace = false
indent_size = 4
```

### README.md

This!
