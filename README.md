# Pacman

Simple pacman game made as a studies project.

## Table of contents
* [Introduction](#introduction)
* [Project details](#project-details)
* [Technologies](#technologies)
* [Setup](#setup)
* [Screenshots](#screenshots)

## Introduction

Pacman is a project that allows players to play in two modes: single player and multiplayer. The logic of ghost's movement was implemented on the basis of algorithms from a real pacman game. In multiplayer mode, both players work together to eat all yellow points

## Project details

The project was created based on the MVC pattern. The game can be started in two modes: single player and multiplayer. The player controls the pacman - the yellow square. You win when you eat all small yellow points. Avoid being eaten by ghosts - colored squares. Eating a green square allows you to eat a ghost once.

## Technologies

Technologies used:
* C++
* Qt Framework
* Winsock API
* Doxygen

## Setup

In order to play single player, you need to compile the project using Qt and then click the single player button. In order to play multiplayer, you need to compile the project using Qt and then also compile server. Then start the server and two pacman applications. You should start player one and player two in two separate windows. The game will connect to the server itself.

Command to compile the server using g++ compiler:
```sh
g++ -o server server.cpp -lwsock32
```

If you do not have access to g++, the compiled server.exe file is located in "Server" folder.

## Screenshots

| ![](https://github.com/k4lin97/images/blob/master/pacman_0.png) |
|:--:|
| <b>Main menu</b>|

| ![](https://github.com/k4lin97/images/blob/master/pacman_1.png) |
|:--:|
| <b>Single player</b>|

| ![](https://github.com/k4lin97/images/blob/master/pacman_2.png) |
|:--:|
| <b>Multiplayer</b>|
