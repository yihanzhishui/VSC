@echo off
rem git push
git add .
time_=%date:~0,4%-%date:~5,2%-%date:~8,2%_%time:~0,2%_%time:~3,2%_%time:~6,2%_
str=from LEGION
name_=$time str
git commit -m  time
git push