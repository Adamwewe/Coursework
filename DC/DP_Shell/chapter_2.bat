:: scv kit and csvlook

:: Upgrade csvkit using pip  
pip install --upgrade csvkit

:: Print manual for in2csv
in2csv -h

:: Print manual for csvlook

in2csv -h

:: Use ls to find the name of the zipped file
ls

:: Use Linux's built in unzip tool to unpack the zipped file 
unzip SpotifyData.zip

:: Check to confirm name and location of unzipped file
ls

:: Convert SpotifyData.xlsx to csv
in2csv SpotifyData.xlsx

:: Print a preview in console using a csvkit suite command 
csvlook SpotifyData.csv 


REM More stats and worksheet conversion

REM Check to confirm name and location of the Excel data file
ls

REM Convert sheet "Worksheet1_Popularity" to CSV
in2csv SpotifyData.xlsx --sheet "Worksheet1_Popularity" > Spotify_Popularity.csv

REM Convert sheet "Worksheet2_MusicAttributes" to CSV
in2csv SpotifyData.xlsx --sheet "Worksheet2_MusicAttributes" > Spotify_MusicAttributes.csv

:: Print preview

csvlook Spotify_MusicAttributes.csv

:: Now we do some filtering


REM Check to confirm name and location of data file
ls

REM  Print a list of column headers in data file 
csvcut -n Spotify_MusicAttributes.csv

REM Print the first column, by position
csvcut -c 1 Spotify_MusicAttributes.csv

REM Print the first, third and fifth column, by position
csvcut -c 1,3,5 potify_MusicAttributes.csv
REM remember no spaces!! between the numbers!

REM Print the first column, by name
csvcut -c "track_id" Spotify_MusicAttributes.csv

REM Print the track id, song duration, and loudness, by name 
csvcut -c "track_id","duration_ms","loudness" Spotify_MusicAttributes.csv

:: Now some filtering 

REM Filter for row(s) where track_id = 118GQ70Sp6pMqn6w1oKuki
csvgrep -c "track_id" -m 118GQ70Sp6pMqn6w1oKuki Spotify_MusicAttributes.csv

REM Filter for row(s) where danceability = 0.812
csvgrep -c "danceability" -m 0.82 Spotify_MusicAttributes.csv

:: Now lets stack some csvfiles together

REM Stack the two files and save results as a new file
csvstack SpotifyData_PopularityRank6.csv SpotifyData_PopularityRank7.csv > SpotifyPopularity.csv

REM Preview the newly created file 
csvlook SpotifyPopularity.csv

:: Run multiple commands

REM If csvlook succeeds, then run csvstat 
csvlook Spotify_Popularity.csv && csvstat Spotify_Popularity.csv

:: Also we can stack the output of a command into another as follows:

REM Take top 15 rows from sorted output and save to new file
csvsort -c 2 Spotify_Popularity.csv | head -n 15 > Spotify_Popularity_Top15.csv

REM Preview the new file 
csvlook Spotify_Popularity_Top15.csv

:: More conversion/ stacking 


REM Convert the Spotify201809 tab into its own csv file 
in2csv Spotify_201809_201810.xlsx --sheet "Spotify201809" > Spotify201809.csv

REM Check to confirm name and location of data file
ls

REM Preview file preview using a csvkit function
csvlook Spotify201809.csv

REM Create a new csv with 2 columns: track_id and popularity
csvcut -c "track_id","popularity" Spotify201809.csv > Spotify201809_subset.csv

REM While stacking the 2 files, create a data source column
csvstack -g "Sep2018","Oct2018" Spotify201809_subset.csv Spotify201810_subset.csv > Spotify_all_rankings.csv