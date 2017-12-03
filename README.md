# Snake - Nokia 3310
This is an implementation of the Snake game as in the classic Nokia 3310.

![Snake](img/snake.PNG?raw=true "Snake")

# Author
Marcel Tella-Amo

# Compiling it
Tested in Ubuntu 16.04
```
git clone git@github.com:MarcelTella/Snake.git
cd Snake/
mkdir Snake-build
cd Snake-build/
cmake ..
make -j
```
# Dependences
OpenCV (To create a very naive User Interface using images)
```
sudo apt-get install libopencv-dev
```

NCurses (Keystroke detection)
```
sudo apt-get install libncurses5-dev libncursesw5-dev
```
# Running it
Just run
```
./src/bin/Main
```
and you will be able to play. Enjoy! :)
# Running tests
```
./test/bin/Tests
```
