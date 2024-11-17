# Linux Memory Dumper

This is a Linux memory dumper that extracts and searches the memory regions of any given process by its PID.
It reads the `/proc/<PID>/maps` file to get information about memory mappings of the process and can optionally filter the results using specified criteria provided by the user.

## Features
- Extraction of the memory regions for any given process based on the PID.
- Optionally, can filter memory regions by given search string.
- Optionally, can limit output to changed areas only (still incomplete).

## Dependencies
- Linux system with mounted `/proc` filesystem.
- C++11 or greater.

## Help
- **-p <pid>** : Define the pid
- **-f <string>** : Search for a string
