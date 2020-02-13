v 1.4.2

- Server

	- no change
	<br/>

- Client

	- Add the notice pop-up window for forcing users plug out USB from PC and plug in USB again after installation. this window may show only on Window 7.
	- If the client can't find the volume name to mount on USB, make the client keep find the volume name until users plug out USB from PC and plug in USB again after installation. by this way, the client can find the volume name by updating disk properties. this process may be run only on Windows 7.
	<br/>

v 1.3.2

- Server
  
    - no change
    <br/>

- Client
  
    - Add the new feature to clean USB before OS installation, to deal with the volume of USB in OS installation.
    - Implement new installation algorithm.  
    the former installation process is "download->extract->install".  
    new process is "download->extract and install", merging the feature to extract .zip file into installation feature.
    - Fix the feature to get the real capacity of USB.
    - Delete SSD option in disk selection step.
    - Change OS version name to Wayne OS free version, Wayne OS paid version in version selection step.
    - Change icon and company-logo image to new one.
    - Change the client name to Wayne OS Installer.
    <br/>

v 1.2.2

- Server

	- no change
	<br/>

- Client

	- Make the client shut down right away after closing pop-up window for any kind of errors.
	- Add message box for querying to close the client in any situation.
	- Fix the function for GPU information to read multiple GPUs on the PC.
	- Fix the function for Local OS information to read language information used in Local OS also.
	- Fix the bug in redistConsole which installs Microsoft VC++ Redistributable Package on Windows 7
	- Fix the bug about reading HW specifiation in the main client on Windows 7
	<br/>

v 1.2.1

- Server

	- no change
	<br/>

- Client

	- Fix broken error message string while in installation.
	- Make the client shut down right away after closing pop-up window for error in installation.
	<br/>

v 1.2.0

- Server

	- Update the realCapacity record on the database and the web when the new record is coming.
	<br/>

- Client

	- Rewrite the function for reading CPU information.
	- After decompressing the OS file downloaded from the server, file extension is not fixed as .bin, the same as the original file. 
	<br/>

v 1.1.0

- Server

    - Add more hardware specification(RAM information, CPU information, GPU information, Local OS information) columns on the database and the web.
    - Add initial installation date column on the database and the web for managing warranty.
    - Add real capacity of the USB column on the database and the web.
    - Add columns for private IP, public IP on the database and the web.
    <br/>
- Client

    - Add functions for reading more hardware specification.(RAM information, CPU information, GPU information, Local OS information)
    - Add the function for reading real capacity of the USB.
    - Add the function for reading public IP address.
    - Add the function for decompressing the zipped OS file downloaded from the server.
    - Modify the way to write the OS file downloaded from the server.
    <br/>

v 1.0.0

- Server

    - productID, customerInfo0, customerInfo1 columns can store longer string on the web.
    - When imgName is changed, It is updated on the database.
    - Fix file corruption problem when downloading the OS file from the server.
    - Fix encoding problem in making mainInfo.html and licenseInfo.html by using editor on the web.
    - Translate UI of the server in English.
    - Replace the old version smarteditor2 with the latest English version smarteditor2.
    <br/>
- Client

    - The default version type option(free or paid) is free version.
    - When the dummy.img file is for paid version, the client can skip the installation.
    <br/>

v 0.0.1

- Initial version

    - Server
    - Client