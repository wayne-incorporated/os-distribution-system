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