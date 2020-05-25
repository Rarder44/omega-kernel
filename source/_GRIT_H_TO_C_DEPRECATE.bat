
echo NOT FUNCTIONAL
pause
exit /B

@echo off
if "%1"=="" (
	echo.
	echo usage:
	echo _GRIT_H_TO_C.bat FOLDER_WITH_H_TO_CONVERT
	echo.
) else ( 
	set currentPath="%cd%"

	cd %1
	for /f %%f in ('dir /b *.h') do (
		call :elaborate_file %%f
	)
	
	del temp.txt
	
	cd %currentPath% 
)

pause
EXIT /B





:elaborate_file
echo %1
copy %1 *.c 1>NUL
copy %1 temp.txt 1>NUL
echo|set /p="extern "  > %1

rem riga per riga importo solo la "prima" ( quella con la dichiarazione ) 
rem Prendo una riga
for /f "tokens=*" %%a in (temp.txt) do (

	set "MDSStr=%%a"
	echo  %mdsstr%
	rem set "MDSStr=const unsigned char ASC_DATA[] = {"
	FOR /f "tokens=*delims==" %%b IN ("x%mdsstr%x") DO IF not "%%b"=="" (
		rem se trovo l'=
		rem aggiungo la riga al file .h
		echo trovato
		echo %mdsstr%  >> %1
		EXIT /B
	)	
)


rem type temp.txt >> %%f

EXIT /B
