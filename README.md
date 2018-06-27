# 16/17 C语言大作业

###Write a program that will help elementaryschool pupils practice math.###

a)      The program willfirst ask the user for his/her ID number (including two letters & 4digits), e.g.

*Please input yourfour digit ID no:* *AB1234*

The program should have input validation.

Then the program prompts three choices:

(1)   Start a test

(2)   Check scores

(3)   Exit

 

Test: the programwill give 10 [math problems](), e.g.:

*12 \*  3=* *36*

*48 + 32 =* *80*

*…*

*56 / 28 =* *2*

 

Note:

i) Pupils willanswer each problem before the next one is given.

ii) The problemsshould include addition,subtraction, multiplication and division. They are randomly generated.

iii) Randomlygenerates numbers for problems. However, must ensure that both the problem and the result areno larger than two digits. The problem and the result should be greater than or equal to zero.The divisor cannot be zero.

iv) After tenproblems are finished, recordthe time used by the student to do the ten problems.

v) Gives a scoreto each student. Saves thisstudent’s ID, his/herscore and the time used into a file named ‘record.txt’.

vi) Print the following informationon the screen:

[Prob](). | Correct Answ.  |  Ur Answ

 

c)      [Check scores](): Searches thefile ‘[record]().txt’ and lists all the [historical]()scores for this student, e.g.:

 

[*Your previousrecords are:*]()

*AB1234  80  150 seconds*

*AB1234  50  182seconds*

*AB1234  90  98seconds*

 

You will be marked based on your program’s:

(1)	Correctiveness

(2)	Readability

(3)	Robustness

(4)	Conciseness