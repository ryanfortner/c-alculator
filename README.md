# c-alculator
a simple calculator written in c

This is my first complete c program, although it's simple, it's a great learning experience for me!

### Installing:
```
git clone https://github.com/ryanfortner/c-alculator.git
mkdir build && cd build
cmake ..
make
# sudo make install
```

### Uninstalling:
```
sudo rm /usr/local/bin/c-alculator
```

### EXPERIMENTAL: Building a deb: 
First follow the compile steps (don't run `sudo make install` though), this will generate a .deb package in the current directory
```
make package
```
