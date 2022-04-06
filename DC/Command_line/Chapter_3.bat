:: How to save a command's output:

head -n 5 seasonal/summer.csv > top.csv

:: redirect output with ">" 

tail -n 5 seasonal/winter.csv > last.csv

:: Using a command's output as an input is always done by intermediary:


tail -n  seasonal/winter.csv > last.csv

head -n 1 last.csv

:: but as you can see its not very efficient with many intermediaries, 
:: we need to figure a way to do this better, enter pipes:

head -n 5 seasonal/summer.csv | tail -n 3

REM The pipe symbol tells the shell to use the output of 
REM the command on the left as the input to the command on the right.


:: wildcards --> Use "*" to make your life easier

head -n 3 seasonal/s*

REM the shell has other wildcards as well, though they are less commonly used:

    REM ? matches a single character, so 201?.txt will match 2017.txt or 2018.txt, but not 2017-01.txt.
    REM [...] matches any one of the characters inside the square brackets, so 201[78].txt matches 2017.txt or 2018.txt, 
	REM but not 2016.txt.
    REM {...} matches any of the comma-separated patterns inside the curly brackets, 
	REM so {*.txt, *.csv} matches any file whose name ends with .txt or .csv, but not files whose names end with .pdf.


:: Sorting with sort:
	
	REM -n numerically
	REM -r to reverse order
	REM -b ignore blanks
	REM -f fold case

cut -d , -f 2 seasonal/summer.csv | grep -v Tooth | sort -r

:: To return non-duplciates use the uniq keyword, here is an example with all the previous
:: work in action:

cut -d, -f 2 seasonal/winter.csv | grep -v Tooth | sort | uniq -c

:: Now we save pipe outputs

cut -d , -f 2 seasonal/*.csv | grep -v Tooth > teeth-only.txt

:: To kill use ctrl+c 


:: recap of all the pipes:

wc -l seasonal/* | grep -v total | sort -n | head -n 1





