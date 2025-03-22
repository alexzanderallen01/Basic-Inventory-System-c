# Overview

This program was created to understand how I could go about creating a inventory system for video games like what you can find in something like RPG Maker. It is designed to read from a quote on quote save file that would hold a character's data like their inventory. I want to be able to use this project with something like a test base adventure game as then I could save both someones progress & their inventory in one place and only have to use one file. This program is able to create a save file by reading from the master file and creating a new file with that data. Then that data is pulled from the chosen file and split into two vectors, one for item name and one for the amount of a item. Once a inventory has been edited to one's liking, the file can be saved and the program ends.

[Software Demo Video](https://youtu.be/msD5f9f3BnA)

# Development Environment

The 3 tools I used for this project was VS Code, Developer Command Prompt for VS, and GCC compiler. VS Code was the IDE I used to program my project in, while the Developer Command Prompt is what I used to create and format my project at the start. The GCC compiler was a tool I downloaded so that I could compile and run my code.

The programming language I used was c++. I have never used it before, but it has many simlar things to c#. Over all c++ was harder to get a hang of then c# as many small things like spliting a string is not already given to you in an easy format. Although c++ was a LOT easier to get into window form programs using their easy to use libraries like raylib. The libraries I used where iostream, fstream, sstream, vector, string, algorithm, and limits. Most of those libraries were used in order to do something I am used to being able to do in python or c#.

# Useful Websites

- [w3schools](https://www.w3schools.com/cpp/default.asp) Most of what I learned about c++ that did not come from my friend who knows c++ unlike myself came from here.
- [stackoverflow](https://stackoverflow.com/questions/68396962/how-to-split-strings-in-c-like-in-python) I learned how to split strings here and based one of my functions off of Marko Borković solution.
- [visualstudio](https://code.visualstudio.com/docs/languages/cpp) This website taught me how to set up my work space & create a project. It also helped me get a compiler for c++

# Future Work

- Windowed based inventory editing with images for each item (Started doing this in a new project in the same repository)
- Fix program breaking old save files after adding new items to master list
- Add a way to delete old save files