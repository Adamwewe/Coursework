REM Verify database name 
ls

REM Pull the entire Spotify_Popularity table and print in log
sql2csv --db "sqlite:///SpotifyDatabase.db" \
        --query "SELECT * FROM Spotify_Popularity" 

REM Verify database name 
ls

REM Query first 5 rows of Spotify_Popularity and print in log
sql2csv --db "sqlite:///SpotifyDatabase.db" \
        --query "SELECT * FROM Spotify_Popularity LIMIT 5" \
        | csvlook 
# Verify database name 
ls

REM Save query to new file Spotify_Popularity_5Rows.csv
sql2csv --db "sqlite:///SpotifyDatabase.db" \
        --query "SELECT * FROM Spotify_Popularity LIMIT 5" \
        > Spotify_Popularity_5Rows.csv

REM Verify newly created file
ls

REM Print preview of newly created file
csvlook Spotify_Popularity_5Rows.csv


:: SQL on a local CSV file

REM Preview CSV file
ls

REM Apply SQL query to Spotify_MusicAttributes.csv
csvsql --query "SELECT * FROM Spotify_MusicAttributes ORDER BY duration_ms LIMIT 1" Spotify_MusicAttributes.csv | csvlook

:: Even more tidy, you can make a bash variable and call into it when making queries

REM Preview CSV file
ls

REM Store SQL query as shell variable
sqlquery="SELECT * FROM Spotify_MusicAttributes ORDER BY duration_ms LIMIT 1"

REM Apply SQL query to Spotify_MusicAttributes.csv
csvsql --query "$sqlquery" Spotify_MusicAttributes.csv


:: More tidy queries

REM Store SQL query as shell variable
sql_query="SELECT ma.*, p.popularity FROM Spotify_MusicAttributes ma INNER JOIN Spotify_Popularity p ON ma.track_id = p.track_id"

REM Join 2 local csvs into a new csv using the saved SQL
csvsql --query "$sql_query" Spotify_MusicAttributes.csv Spotify_Popularity.csv > Spotify_FullData.csv

REM Preview newly created file
csvstat Spotify_FullData.csv


:: Inserting back into the database

# Preview file
ls

REM Upload Spotify_MusicAttributes.csv to database
csvsql --db "sqlite:///SpotifyDatabase.db" --insert Spotify_MusicAttributes.csv

REM Store SQL query as shell variable
sqlquery="SELECT * FROM Spotify_MusicAttributes"

REM Apply SQL query to re-pull new table in database
sql2csv --db "sqlite:///SpotifyDatabase.db" --query "$sqlquery" 

:: Now everything we learned:

REM Store SQL for querying from SQLite database 
sqlquery_pull="SELECT * FROM SpotifyMostRecentData"

REM Apply SQL to save table as local file 
sql2csv --db "sqlite:///SpotifyDatabase.db" --query "$sqlquery_pull" > SpotifyMostRecentData.csv

REM Store SQL for UNION of the two local CSV files
sqlquery_union="SELECT * FROM SpotifyMostRecentData UNION ALL SELECT * FROM Spotify201812"

REM Apply SQL to union the two local CSV files and save as local file
csvsql 	--query "$sqlquery_union" SpotifyMostRecentData.csv Spotify201812.csv > UnionedSpotifyData.csv

REM Push UnionedSpotifyData.csv to database as a new table
csvsql --db "sqlite:///SpotifyDatabase.db" --insert UnionedSpotifyData.csv
