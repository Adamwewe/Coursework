# Reminders
cat soccer_scores.csv | grep 1959

# Reminder no. 2

cat two_cities.txt | egrep 'Sydney Carton|Charles Darnay' | wc -l

# Working on csv files

cat soccer_scores.csv | cut -d "," -f 2 | tail -n +2 | sort | uniq -c

# More piping
cat soccer_scores.csv | sed 's/Cherno/Cherno City/g' | sed 's/Arda/Arda United/g' > soccer_scores_edited.csv

# More STDIN-STDOUT work:

# Echo the first and second ARGV arguments
echo $1 
echo $2

# Echo out the entire ARGV array
echo $*

# Echo out the size of ARGV
echo $#

# Echo the first ARGV argument
echo $1 

# Cat all the files
# Then pipe to grep using the first ARGV argument
# Then write out to a named csv using the first ARGV argument
cat hire_data/* | grep "$1" > "$1".csv


