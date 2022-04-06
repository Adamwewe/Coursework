<look into all contents/properties of a file with cat>
cat file.txt

<now we can look into less information with less>

less seasonal/spring.csv seasonal/summer.csv

<press spacebar to page dwn, :n to go to the second file, and :q to quit.>


<manipulate csv files from command line>

head seasonal/summer.csv


<autocomplete --> sea and press tab, it will fill in the directory name seasonal/ (with a trailing slash). If you>
<then type a and tab, it will complete the path as seasonal/autumn.csv>

<what if we want a shorter head? Then use head-n>

head -n 5 seasonal.csv

<recursion --> list folders inside folders>

<ls has another flag -F that prints a / after the name of every directory and a * after the name of every runnable program.> 
<Run ls with the two flags, -R and -F, ls has another flag -F that prints a / after the name of every directory and a * >
<after the name of every runnable program. Run ls with the two flags, -R and -F, and the absolute path to your home directory to see everything it contains>
<and the absolute path to your home directory to see everything it contains>

ls -R -F /home/repl


<need help? Then use the man command, for instance I want help with tail:>

man tail


<selecting just columns from a file>

cut -f 2-5,8 -d , values.csv

<the above means:>
"select columns 2 through 5 and columns 8, using comma as the separator". cut uses -f (meaning "fields") 
"to specify columns and -d (meaning "delimiter") to specify the separator."

"example to cut one column"

cut -f 1, -d,. seasonal/spring.csv

REM <re-run commands: with a "!" and you can also check the list of commands with history>
REM <wanna rerun a command that was specified with a number? rerun with ! + nb specified in history>

!head
history

REM < grep selects lines according to the values contained>
REM <recap: head and tail select rows, cut selects columns>

    REM -c: print a count of matching lines rather than the lines themselves
    REM -h: do not print the names of files when searching multiple files
    REM -i: ignore case (e.g., treat "Regression" and "regression" as matches)
    REM -l: print the names of files that contain matches, not the matches
    REM -n: print line numbers for matching lines
    REM -v: invert the match, i.e., only show lines that don't match


REM Print the contents of all of the lines containing the word molar in seasonal/autumn.csv 
REM by running a single command while 
REM in your home directory. Don't use any flags.

grep molar seasonal/autumn.csv

REM Invert the match to find all of the lines that don't contain the word molar in 
REM seasonal/spring.csv, and show their line numbers. Remember, it's considered good style 
REM to put all of the flags before 
REM other values like filenames or the search term "molar".

grep -v -n molar seasonal/spring.csv

REM Count how many lines contain the word incisor in autumn.csv and winter.csv combined. 
REM (Again, run a single command from your home directory.)

grep -c incisor seasonal/autumn.csv seasonal/winter.csv


REM The SEE ALSO section of the manual page for cut refers to a command called paste that can
REM be used to combine data files 
REM instead of cutting them up.


cut -d, -f 2 seasonal/summer.csv | grep -v Tooth 

:: We can chain any n commands together for example:

cut -d , -f 1 seasonal/spring.csv | grep -v Date | head -n 10

cut -d , -f 2 seasonal/summer.csv | grep -v Tooth | head -n 1

:: print records in a file with "wc" (word count)
:: You can make it print only one of these using -c, -w, or -l respectively



