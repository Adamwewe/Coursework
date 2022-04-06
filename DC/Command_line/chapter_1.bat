pwd <print working directory>

ls <list all files, equivalient to dir>

ls/home/repl/course.txt <full line in action>

<difference between relative and absoltue path:>
<relative:>
winter.csv
<abosulte path:>
/home/repl/seasonal/winter.csv

<ls is always used with a space between path and command>

<just like windows u can use cd to change directories>

cd


<Copying works with cp, here is an example below:>

cp seasonal/summer.csv /home/repl/backup/summer.bck

<Copying multiple files works like this:

cp seasonal/spring.csv seasonal/summer.csv backup

<now moving from one directory to another, u do the same as above but with the keyword mv for move>

<to rename you stay in the same directory and just use mv with a new name later>

<to remove use rm>

cd seasonal
rm autumn.csv 
cd ..
rm seasonal/summer.csv

<to remove directories use rmdir>

rmdir people

<to create directories remotely use mkdir>

mkdir yearly/2017 2017

<move to home dir>

mv ~/people/agarwal.txt scratch

