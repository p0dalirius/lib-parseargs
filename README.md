# lib-parseargs

<p align="center">
  A simple library to parse command line arguments in C++.
  <br>
  <img alt="GitHub release (latest by date)" src="https://img.shields.io/github/v/release/p0dalirius/lib-parseargs">
  <a href="https://twitter.com/intent/follow?screen_name=podalirius_" title="Follow"><img src="https://img.shields.io/twitter/follow/podalirius_?label=Podalirius&style=social"></a>
  <a href="https://www.youtube.com/c/Podalirius_?sub_confirmation=1" title="Subscribe"><img alt="YouTube Channel Subscribers" src="https://img.shields.io/youtube/channel/subscribers/UCF_x5O7CSfr82AfNVTKOv_A?style=social"></a>
  <br>
</p>

## Features

 - [x] Optional or required arguments, with default values.
 - [x] Positional arguments.
 - [x] Parsing of arguments and printing of help message if missing mandatory arguments.

![image](https://user-images.githubusercontent.com/79218792/209481333-ff7c23f1-684e-425a-90e5-b5a255d38c20.png)

## Example code

```cpp
#include <iostream>
#include "ArgumentsParser/ArgumentsParser.h"


ArgumentsParser parseArgs(int argc, char* argv[]) {
	ArgumentsParser parser = ArgumentsParser();

	parser.add_positional_string_argument("mode", "Operation mode");
	parser.add_positional_string_argument("another", "Another positional");
	
	parser.add_string_argument("target", "-t", "--target", "", true, "IP or adress of the target machine");
	parser.add_int_argument("port", "-p", "--port", "", true, "Port of the target machine");

	parser.add_boolean_switch_argument("verbose", "-v", "--verbose", false, false, "Verbose mode.");

	parser.parse_args(argc, argv);
	return parser;
}

int main(int argc, char* argv[])
{
	ArgumentsParser parser = parseArgs(argc, argv);

	if (std::get<bool>(parser.get_value("verbose")) == true) {
		std::cout << "[verbose] Mode verbose started.\n";
	}

	std::cout << std::get<int>(parser.get_value("port")) << "\n";

	parser.debug();
}

```

Output:

```
C:\Users\dev\> .\PocArgs.exe
Usage: PocArgs.exe <mode> <another> [-p port] [-t target] [-v verbose]

Positional arguments:
   <mode>   Operation mode
   <another>   Another positional

Required arguments:
   -t, --target IP or adress of the target machine
   -p, --port Port of the target machine

Optional arguments:
   -v, --verbose Verbose mode. (default: false)

```
