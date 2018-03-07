This file contains basic information of sys_xdedup.c and the xhw1.c, which are given to us.
By doing a simple make clean, we can clean the console, while using the make command we can compile the given data. 

1. For -n 
Command : i) make
		  ii) ./xhw1 -n f1.txt f2.txt o.txt

Inputs: i) f1.txt = "abcd1234"
		ii) f2.txt = "abcd1234"

Output: Returns 8, which is the size of the 2 same files



2. For -p 
Command : i) make
		  ii) ./xhw1 -p f1.txt f2.txt o.txt

Inputs: i) f1.txt = "abcd1234"
		ii) f2.txt = "abcd12ef"
Output:  In o.txt we get "abcd12"

3. For -d 
Command : i) make
		  ii) ./xhw1 -d f1.txt f2.txt o.txt

Output: Debugging mode enabled. Print 10 msg


4. For -np
Command : i) make
		  ii) ./xhw1 -p f1.txt f2.txt o.txt

Inputs: i) f1.txt = "abcd1234"
		ii) f2.txt = "abcd12ef"

Output: np flag is active and common thing is : abcd12

Drawback: This code cannot take in the absolute and relative path, and doens't reply back the absolute path. I just assumed that all the files are lying in the same givne directorty folder. Also not all errors have been covered. 
