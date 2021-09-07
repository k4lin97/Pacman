# Pacman

Pacman game made with C ++ and Qt framework. Documentation created using doxygen can be found in the _Documentation folder. In there search for the index.html file.

## Game modes

- Single player
- Multiplayer

## Single player

In order to play single player, you need to compile the project using Qt and then click the single player button.

## Multiplayer

In order to play multiplayer, you need to compile the project using Qt and then also compile server. Then start the server and two pacman applications. You should start player one and player two in two separate windows. The game will connect to the server itself.
Command to compile the server using g++ compiler:

```sh
g++ -o server server.cpp -lwsock32
```

If you do not have access to g++, the compiled server.exe file is located in "Server" folder.
