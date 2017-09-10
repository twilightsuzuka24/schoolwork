# coding: utf-8

'''
TODO: 
	1. Create a variable called 'name' that holds a name.
	2. Print "Hello <name>" using the name variable.
	   For example, if the name is "Ron" it should print:
	   Hello Ron!

There are a few ways to use variables in strings:
	- Adding strings together using '+'.
	- Using a comma between the string and the variable. 
	  The comma combines the strings and adds a space between them.
	- Using the string's format() function.

You can make notes in a script by using comments.
	- The hash sign, #, is used for a one-line comment. 
	  Python ignores all text after the #.
	- A three-quote comment (single or double quotes) lets you put 
	  any number of lines of text between the opening and closing 
	  three quotes.
'''


name = 'Ron'
print "Hello {}".format(name)