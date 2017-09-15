==================================================
Nitro_Test solution for Nitro C++ Proficiency Test
Author: Ozgur Emrah Kocak
	ozguremrah@gmail.com
==================================================

Description:
------------
This program reads and parses a JSON file containing rectangle definitions
and finds intersections of defined rectangles as specified at "C Proficiency Test.pdf".


Usage:
------
The program takes a single command line	argument,the name of the JSON file.
On start-up, the JSON file is loaded and validated. Then two lists are outputted:
the list of all rectangles in the file; and the list of all intersections.
Since this project is made on Windows, Windows executables are found in 'bin' folder. 
It is developed platform independent but I couldn't test it on Linux or IOS.
Normal usage: Nitro_Test JSONFileName	
Unit Test usage: Nitro_Test --log_level=all
There are also bat files (run.bat,runtest.bat).		

	
Sources used:
-------------
1) JSON for Modern C++ Version 2.1.1 by nlohmann 
	Source: https://github.com/nlohmann/json/releases
2) Boost 1.65.1 Unit Test Framework
	Source: http://www.boost.org/


Compile Notes:
--------------
This project is developed and compiled using standart C++ 14. There are two 3rd party
sources; JSON parser and Boost framework. Both of them are platform independent and
single-header usage variant (no library compilation is needed for Boost). JSON file header
json.hpp is already included in "includes" directory. For Boost you need to download it
from http://www.boost.org/ and include root directory (/I"C:\local\boost_1_65_1").

For unit testing purposes you need to define _UNIT_TEST (/D "_UNIT_TEST") and
--log_level=all as command argument. This will open unit testing codes and sets log level
to report all log messages including the passed test notification.

Unit Tests:
-----------
So far I included unit tests to verify JSON file and rectangle intersections. 
There are two configuration files for unit testing;
1) test_config_fileIntegrity.txt; includes filenames for file verification and
				  expected error codes.
2) test_config_intersection.txt; includes filenames for rectangle definition files,
				 expected number of rectangles and expected
				 number of intersections for each file.
This way you do not need to change the code to test new files; just add file names and
expected values to configuration files. I do not add an automated test to check intersection
coordinates, only verified them looking to the output. Could be added given more time.
Trivial automated tests are also skipped for time conservation (class member initialization,
mutator and accessor verifications). 
