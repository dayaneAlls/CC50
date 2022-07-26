import cs50
import re

text = cs50.get_string("Text: ")
chars, words, sentences, grade, L, S = 0, 1, 0, 0, 0, 0

#counts all the letters in the text
chars = len([i for i in text if i.isalpha()])
#counts all the words in the text
words = len(re.findall(r' ', text))
#counts all the sentences in the text
sentences = len(re.findall(r'[.!?]', text))

#calculates the school level according to the Coleman-Liau formula
L = (chars/words)*100
S = (sentences/words)*100
grade = (0.0588 * L) - (0.296 * S) - 15.8

#print grade
if grade >=16:
    print("Grade 16+.")
elif grade < 1:
    print("Before grade 1.")
else:
    print("Grade: ", int(grade))
