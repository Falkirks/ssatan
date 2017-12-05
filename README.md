ssatan
======

This is a quick command line tool for generating a secret satan (secret santa but you get things people hate) gift exchange.

## How it works
Put a file for each person in the `./people` directory. ssatan will copy them to the clipboard in a random order and tell you which person to send them to. The file names should be the names of the people and the contents of the files will be the message to send to the person who is getting a gift for that person.


## Requirments

* pbcopy
* dirent.h

## Distribution
This tool will copy the file contents to the clipboard, it is up to you to figure out how to distribute the information without seeing who people got. I do this over Facebook Messenger, by change the font size and color and deleting messages after. 