:: print with echo
echo hello World!

:: to print var value use "$"

echo $USER

echo $OSTYPE

:: creating shell vars:
training=seasonal/summer.csv
:: NO SPACES!! Then you can refer to it as any file in the dir
head -n 1 $training

:: Loops are also useful here, they share the same format as list comprehension

for filetype in gif jpg png; do echo $filetype; done

:: lets try it with filenames now

for filename in people/*; do echo $filename; done

:: run commands in a loop:

for file in seasonal/*.csv; do grep 2017-07 $file | tail -n 1; done