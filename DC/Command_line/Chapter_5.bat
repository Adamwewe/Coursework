:: UNIX file editing

    REM Ctrl + K: delete a line.
    REM Ctrl + U: un-delete a line.
    REM Ctrl + O: save the file ('O' stands for 'output'). You will also need to press Enter to confirm the filename!
    REM Ctrl + X: exit the editor.


:: Recording and tracking steps of analysis referesher

    REM Run history.
    REM Pipe its output to tail -n 10 (or however many recent steps you want to save).
    REM Redirect that to a file called something like figure-5.history.


cp seasonal/s* ~

grep -h -v Tooth s*.csv > temp.csv

history | tail -n 3 > steps.txt 

:: the above makes new txt file with all steps 

:: How to save commands to rerun later --> you run nanop.sh 

nano dates.sh

:: inside it enter the following command then ctrl + o enter and ctrl +x

cut -d , - f 1 seasonal/*.csv

:: use bash to run it 
bash dates.sh 

:: Also no need to save as .sh necessrily, it can always be redirected:

bash dates.sh > teeth.out 

:: generalizability with bash:
	:: you can replace specific file names to generalize to all with "$@"
	
REM example here in this nano file

nano count-records.sh 
	tail -q-n +2 $@ | wc -l 

:: now we run 

bash count-records.sh seasonal/*.csv > num-records.out

:: The above logic can also be applied to specific command line parameters such as:

nano foo.sh
	cut -d , -f $2 $1 

bash column.sh seasonal/autumn.csv 1


:: Now into making more fleshed out bash scripts


nano foo.sh
	wc -l $@ | grep -v total | sort -n | head -n 1
	wc -l $@ | grep -v total | sort -n -r | head -n 1

bash foo.sh seasonal/*.csv > range.out

:: following this logic, loops can also ofc be written in shell using the standard multi-line format

for filename in $@
do 
	cut -d, -f 1 $filename | grep -v Date | sort | head -n 1
	cut -d, -f 1 $filename | grep -v Date | sort | tail -n 1
done

:: now you can run it also with other built in UNIX methods

bash date-range.sh seasonal/*.csv | sort

