| Bug ID | | |                 | Bug overview                                                 |             |                 | Environment                | Bug details                                                  |                                                              |                                                              |                                                              | Bug tracking(For developers only) |             |          |
| --------- | ------------------------------------------------------------ | -------- | ----------- | ------------------------------------------------------------ | ----------- | --------------- | -------------------------- | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | --------------------------------- | ----------- | -------- |
| ID Number | Name                                                         | Reporter | Submit Date | Summary                                                      | URL | Screenshot link |                            | Steps to reproduce                                           | Expected result                                              | Actual result                                                | Description                                                  | Severity                          | Assigned to | Priority |
| 1         | Booting problem with new OS file                             | LEE Jeun | 19/08/20    | new OS file installed on usb by using a client isn't booting | N/A         | N/A             | Windows 10 pro             | install new OS file on usb from the server                   | booting and other features are successful                    | booting failed                                               | screen showed "32-bit relocation out of kernel -- system halted!" | high                              | LEE Jeun    | high     |
| 2         | downloaded file corruption                                   | LEE Jeun | 19/09/11    | original file and downloaded file from the server are not same | N/A         | N/A             | Windows 10 pro             | download OS file from the server by using the client         | original file and downloaded file from the server are same   | there are some difference in between                         | diff -d on ubuntu and fc /b on windows command prompt - result shows that they are not same. | high                              | LEE Jeun    | high     |
| 3         | not storing CPU information on the database, not updating realCapacity value on the database | LEE Jeun | 19/10/31    | CPU information is somtimes not stored in the database, realCapcity value is not updated on the database | N/A         | N/A             | Windows 7 Ultimate K 64bit | download and install Wayne OS on USB by using the client     | CPU information is always stored in the database, realCapacity value is updated on the database | CPU information is sometimes not stored on the database, realCapacity is not updated on the database | the columes related with this issue has no data or remains old data | low                               | LEE Jeun    | high     |
| 4         | broken error message for installation with usb OS installed, not closed after error in installation with usb OS installed | LEE Jeun | 19/11/11    | when showing error message in installation with usb OS installed, message string is broken, and not closed automatically after that | N/A         | N/A             | Windows 10 pro             | trying to install wayne OS with usb OS installed             | show right error message when error occurs in installation with usb OS installed, and closed after that | when showing error message in installation with usb OS installed, message string is broken, and not closed automatically after that | need to change encoding and there is no feature for shutting down after error occurs. | low                               | LEE Jeun    | high     |
| 5         | not shutting down after any kind of errors in installation and clicking exit button while decomressing or installing | LEE Jeun | 19/11/13    | the client is not shut down after any kind of errors in installation and clicking exit button while decompressing or installing | N/A         | N/A             | Windows 10 pro             | errors occur while installing or clicking exit button while decompressing or installing | the client is shut down automatically                        | the client is not shut down automatically                    | there is no feature for shutting down while this situation   | low                               | LEE Jeun    | high     |
| 6         | when going to step to download the OS file, the client is suddenly shut down | LEE Jeun | 19/11/19    | the client is suddenly shut down when going to step to download the OS file | N/A         | N/A             | Windows 10 home            | after selecting all options and going to the step to download the OS file, the client is suddenly shut down | the client enter to the step to download the OS file         | the client is suddenly shut down                             | problem in the function for reading HW specification | high                              | LEE Jeun    | high     |
| 7         | the main client is not running on Windows 7                  | LEE Jeun | 19/11/22    | when trying to go to the download step, app crash occurs on Win7 | N/A         | N/A             | Windows 7 Ultimate K 64bit | try to enter the download step on the client                 | the client downloads the OS file from the server             | app crash occurs with error code                             | Memory access violation in CreateProcess function            | high                              | LEE Jeun    | high     |
| 8         | the sub client is not running on Windows 7                   | LEE Jeun | 19/11/22    | when running the sub client, the sub client is shut down with no result | N/A         | N/A             | Windows 7 Ultimate K 64bit | try to run the sub client                                    | the sub client recognizes whether vcredist package is installed or not, installs vcredist package if not installed, run the main client | the sub client is shut down with no result                   | no right to handle other process in CreateProcess function   | high                              | LEE Jeun    | high     |
