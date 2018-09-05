# BowlingScoreBoard

# How to build?

# How to use?
Build via qmake (pro file) or cmake (CMakeLists.txt; tested under Linux, CMake 3.2, GCC 4.9 and Qt 5.10).
Run the binary. It will bind automatically via UDP to localhost:6543.
Send messages via UDP (hint: use Packet Sender oder sendip) to the BowlingScoreBoard. This simulates the external character of the pin-counting-machine.

This is version 0.1.
Builds and runs with: Linux, Gcc, Qt 5.10 and QtCreator 4.7-rc1
Builds and runs with: Windows 7, Qt 5.5 and QtCreator 4.6

# Assumptions

Accepts messages for controlling the BowlingScoreBoard via UDP: hard-coded to localhost:6543 (see BSB_UdpListener.h)

- new game can be started via "game:reset"
- player-name can be set via "name:Klaus"
- name-handling; player-name has to be purely alphanumeric and will be truncated at ten characters.
- data for the current throw can be sent via "throw:8" (or whatever value from the range [0..10]

If the end of the possible throws is reached, nothing special will happen.
Messages are accepted, but not processed in a way that the state of the game-board changes.
Player has to actively reset the game (see above).


# Open tasks

use cmake: works
C++, Qt, ObjectOriented : by definition

display the current state
add the logic and the main-field
add QTest to the logic

expand the readme-file
remove all warnings!
run clzay/clang-tidy
check for leaks


bonus: some menu-option?
