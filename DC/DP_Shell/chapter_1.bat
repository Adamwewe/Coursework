REM How to use curl to download the file frm predicted URL

REM Use curl to download the file from the redirected URL
curl -L https://assets.datacamp.com/production/repositories/4180/datasets/eb1d6a36fa3039e4e00064797e1a1600d267b135/201812SpotifyData.zip

REM Download and rename the file in the same step
curl -o Spotify201812.zip -L https://assets.datacamp.com/production/repositories/4180/datasets/eb1d6a36fa3039e4e00064797e1a1600d267b135/201812SpotifyData.zip

REM Download all 100 data files
curl -O https://s3.amazonaws.com/assets.datacamp.com/production/repositories/4180/datasets/files/datafile[001-100].txt

REM Print all downloaded files to directory
ls datafile*.txt

REM Now using Wgnet which is more multipurpose
	REM allows for recursion
	
REM # Fill in the two option flags 
wget -bc https://assets.datacamp.com/production/repositories/4180/datasets/eb1d6a36fa3039e4e00064797e1a1600d267b135/201812SpotifyData.zip

REM # Verify that the Spotify file has been downloaded
ls 

REM # Preview the log file 
cat wget-log


:: Waiting:

REM # View url_list.txt to verify content
cat url_list.txt

REM # Create a mandatory 1 second pause between downloading all files in url_list.txt
wget --wait=1 -i url_list.txt

REM # Take a look at all files downloaded
ls


:: Use curl, download and rename a single file from URL
curl -o Spotify201812.zip -L https://assets.datacamp.com/production/repositories/4180/datasets/eb1d6a36fa3039e4e00064797e1a1600d267b135/201812SpotifyData.zip

:: Unzip, delete, then re-name to Spotify201812.csv
unzip Spotify201812.zip && rm Spotify201812.zip
mv 201812SpotifyData.csv Spotify201812.csv

:: View url_list.txt to verify content
cat url_list.txt

:: Use Wget, limit the download rate to 2500 KB/s, download all files in url_list.txt
wget --limit-rate=2500k -i url_list.txt

:: Take a look at all files downloaded
ls