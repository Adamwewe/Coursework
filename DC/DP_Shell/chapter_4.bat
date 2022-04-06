:: Using python inside shell
REM in one step, create a new file and pass the print function into the file
echo "print('This is my first Python script')" > my_first_python_script.py

REM check file location 
ls

REM check file content 
cat my_first_python_script.py

REM execute Python script file directly from command line  
python my_first_python_script.py

:: Install packages more efficiently:

REM Add scikit-learn to the requirements.txt file
echo "scikit-learn" > requirements.txt

REM Preview file content
cat requirements.txt

REM Install the required dependencies
pip install -r requirements.txt

REM Check installed libs
pip list

:: Last important step! Data Job Automation with cron
	:: check https://crontab.guru/ for more info
	:: A simple example of a crontab that runs every minute
	
REM Verify that there are no CRON jobs currently scheduled
crontab -l 

REM Create Python file hello_world.py
echo "print('hello world')" > hello_world.py

REM Preview Python file 
cat hello_world.py

REM Add as job that runs every minute on the minute to crontab
echo "* * * * * python hello_world.py" | crontab

REM Verify that the CRON job has been added
crontab -l

:: Another example: 

REM Preview both Python script and requirements text file

cat create_model.py
cat requirements.txt

REM Pip install Python dependencies in requirements file
pip install -r requirements.txt

REM Run Python script on command line
python create_model.py

REM Add CRON job that runs create_model.py every minute
echo "* * * * * python create_model.py" | crontab

Verify that the CRON job has been scheduled via CRONTAB
crontab -l

