[![Build Status](https://travis-ci.org/hibax/toto.svg?branch=master)](https://travis-ci.org/hibax/toto)



# Files mergers

## Usage
merger.py path_to_sources

## Output
path_to_sources/../generated_src/codingame.cpp
just directly copy file content in game

## Limitations
The script parse only the dir provided and not recursively.

Excluded files: 
* Algo.h and .cpp (redefinition...)
* Evaluation.h and .cpp (redefinition...)
* main.cpp (only use locally)

inGameMain.txt is needed as it is the working main in game
