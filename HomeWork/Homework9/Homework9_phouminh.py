# CS1300 Spring 2018
# Author:
# Recitation Tuesday 930am Akriti Kupar
# Cloud9 Workspace Editor Link: https://ide.c9.io/…
# Homework 9

import os.path
def update_dictionary(filename, dictionary):
    dictionary_size = 0
    new_list = {}
    if os.path.exists(filename):
        print(filename,"loaded successfully.")
        infile = open(filename, 'r')
        newSize = 0
        for aline in infile:
            newSize = newSize + 1 # this should be counting the amount of values in the dictionary
            words = aline.split(',') # parsing the line
            second_word = words[1].strip("\n") # getting rid of the endline character
            new_list.update({words[0]:second_word})
        dictionary.update(new_list)
        dictionary_size = len(dictionary)
        print("The dictionary has",dictionary_size,"entries.")
        infile.close()
        return dictionary
    else:
        print(filename,"does not exist.")
        print("The dictionary has",dictionary_size,"entries.")
        return dictionary

def deslang(string, d): 
    myArray = string.strip().split()
    sequence = ""
    for word in myArray:
        if word in d:
            sequence+=d[word]
        else:
            sequence+=word
        sequence+=" "
    return sequence[0:-1]
def main():
    quit = 0
    dictionary = {}
    #update_dictionary(filename, dictionary)
    while quit == 0:
        choice = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
        while choice == "" or choice not in "aAdDqQ":
            choice = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
        else:
            if choice in 'aA':
                fileInput = input("Enter a filename: ")
                while fileInput == "":
                    fileInput = input("Enter a filename: ")
                else:
                    update_dictionary(fileInput,dictionary)
                    
            elif choice in 'dD':
                EnteredSentence = input("Enter a sentence: ")
                while EnteredSentence == "":
                    EnteredSentence = input("Enter a sentence: ")
                else:
                    print(deslang(EnteredSentence, dictionary))
                
                    
            elif choice in 'qQ':
               quit = 1
    
    
  
main()










'''def update_dictionary(filename,dictionary):
    infile = open(filename,'r')
    if infile is not open:
        print("File failed to open")
    dictionary_size = 0     
    slang_spelling_size = 0         # keep track of the size of each 
    slang_meaning_size = 0
    slang_spelling = []             # just practicing working with arrays in python
    slang_meaning = []
    for aline in infile:
        words = aline.split(',')
        slang_spelling.append(words[0])
        slang_spelling_size+=1
        secondWord = words[1].strip("\n")   # the text file had a \n at the end
        slang_meaning.append(secondWord)
        slang_meaning_size+=1
        dictionary.append([words[0],secondWord])
        dictionary_size+=1
    infile.close()
    return dictionary_size

def deSlangWords(string, dictionary):
    arrayForString = []
    word_count = 0
    for i in range(len(string)):
        if string[i] == " ":
            word_count = word_count + 1
    word_count = word_count + 1     # accounting for the last word 
    arrayForString = string.split(" ")
    result = []
    result = string.split(" ")
    for i in range(word_count):
        for j in range(dictionary_size):
            if arrayForString[i] == dictionary[j][0]:
               result[i] = dictionary[j][1]
               
    sequence = ""
    for k in range(word_count):
        sequence = sequence + result[k] + " "
    return sequence

def addWords(dictionary):
    valid_input = False
    while valid_input == False:
        filename = input("Enter file name: ")
        if filename != "":
            valid_input = True
            break
    value = update_dictionary(filename, dictionary)
    return value
   
def Quit():
    print("Goodbye!")
    return 0     
            
def main():
    global dictionary_size
    dictionary_size = 0
    dictionary = []
    filename = "textToEnglish.txt"     #passing this file name
    dictionary_size = dictionary_size + update_dictionary(filename,dictionary)   #filling the array for the dictionary and returning its size 
    
    print("The dictionary has", dictionary_size, "entries")
    choice = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
    valid_input = False
    while valid_input == False:
        if choice not in "adqADQ":
            valid_input = False
            choice = input("Would you like to (a)dd words to the dictionary, (d)e-slang a sentence, or (q)uit?: ")
        elif choice in 'aA':
            valid_input = True
            addWords(dictionary)
            main()
        elif choice in 'dD':
            validInput = False
            while validInput == False:
                given_string = input("Sentence: ")
                if given_string != "":
                    validInput = True
                    break
                else:
                    validInput = False
            result = deSlangWords(given_string, dictionary)
            print(result)
            main()
        elif choice in 'qQ':
            Quit()
            break
    
            

main()'''

