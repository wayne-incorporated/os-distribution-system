## Bug Report
- The corruption of the downloaded OS file from the server
	- Reporter: LEE Jeun
	- Submit Date: 2019-08-20
	- Summary: The downloded OS file is not the same with the original OS file
	- Environment: Windows 10 pro 64bit
	- Bug tracking
		- The server couldn't transfer OS file to the client perpectly. there were some defects while transferring data between the server and the client. some line of original source code was wrong in reading data from the buffer. it missed 1 byte in every cycle.
	<br/>
- realCapacity value is not updated
	- Reporter: LEE Jeun
	- Submit Date: 2019-10-31
	- Summary: realCapacity value is not updated on the database
	- Environment: Windows 7 Ultimate K 64bit
	- Bug tracking
		- there is no query for updating realCapacity column. 
	<br/>
- broken error message
	- Reporter: LEE Jeun
	- Submit Date: 2019-11-11
	- Summary: when showing the error pop-up window on the client, character is broken
	- Environment: Windows 7, Windows 8, Windows 10
	- Bug tracking
		- error message is depending on system language and there is no feature for dealing with unicode.
	<br/> 
- the client is not shut down right away
	- Reporter: LEE Jeun
	- Submit Date: 2019-11-13
	- Summary: the client is not shut down right away after error or clicking close button while installing
	- Environment: Windows 7, Windows 8, Windows 10
	- Bug tracking
		- there is no feature for shutting down for those situation.
	<br/>
- the client is suddenly shut down
	- Reporter: LEE Jeun
	- Submit Date: 2019-11-22
	- Summary: the client is suddenly shut down when going to step to download OS file
	- Environment: Windows 7, Windows 8, Windows 10
	- Bug tracking
		- before download step, the client gathers HW specification by using CreateProcess function. the reason is memory access violation in the second argument of CreateProcess function.
	<br/>
- the sub client cannot launches the main client
	- Reporter: LEE Jeun
	- Submit Date: 2019-11-22
	- Summary: the sub client is shut down with no result
	- Environment: Windows 7, Windows 8, Windows 10
	- Bug tracking
		- there is no right to handle other process in CreateProcess function. so using SHELLEXECUTEINFO structure and ShellExecuteEx function is alternative for that.
	<br/>
- OS update bug
	- Reporter: LEE Jeun
	- Submit Date: 2020-02-05
	- Summary: if USB has OS installed, the client cannot access USB
	- Environment: Windows 7, Windows 8, Windows 10
	- Bug tracking
		- when USB has OS installed, it has multiple partitions. and the client has no function to deal with these things.
	<br/>
- USB-STORAGE is invisible on Windows 7
	- Reporter: LEE Jeun
	- Submit Date: 2020-02-13
	- Summary: when installation is done on Windows 7, USB-STORAGE is invisible in file explorer
	- Bug tracking
		- for some reason, It seems that the client can't update disk properties after installation on Windows 7
	<br/>