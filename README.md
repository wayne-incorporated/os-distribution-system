# IDE

- ## Client

  - Windows 10 pro

  - Visual Studio 2017

  - Qt Framework

  - Qt VS Tools

  - vcpkg

  ##### Language/External

  - C++
  - Qt 5.11.1 msvc 2015 32bit
  - zlib 1.2.11
  - minizip 1.2.11
  - ImageWriter
  - The OpenSSL ToolKit

- ## Server

  - Windows 10 pro
  - Spring Tool Suite 3.9.9
  - Java SDK 12.0.2 64bit
  - MySQL 8.0
  - Pivotal tc server Developer Edition v4.0 based on Tomcat 9.0.13
  - Maven 3.6.1

  ##### Language/External

  - Java
  - JavaScript
  - jsp
  - xml
  - html
  - css
  - Spring Framework
  - MyBatis
  - MySQL
  - smarteditor2 2.10.0

# How to set up the project

- ## Client

  1. Download the project.
     [git clone https://gitlab.com/wayne-inc/os-distribution-system]
  2. Download Qt online installer https://www.qt.io/download
  3. Install Qt 5.11.1 msvc 2015 32bit by using online installer.
  4. Add Qt VS Tool on Visual Studio 2017.
  5. Configure environment variables, MSVC path.
  6. Download QtWebKit module and copy each file into right path 
     https://drive.google.com/open?id=11gOMQCYOvfPkDN3WfsY-Jd2H3043Mvfa
  7. Test by creating initial Qt project. If building is success, Qt setting is done.
  8. For downloding and installing external libraries, recommend using vcpkg. You can download in https://github.com/microsoft/vcpkg. And follow the description on this site. You can easily download/install and build zlib, minizip by vcpkg.
  9. After all of the above are done, setting up is completed. You can build the client project by Visual Studio 2017.

- ## Server

  1. Download and install Java SDK in Oracle homepage.
  2. Configure environment variables for Java development.
  3. Download MySQL installer in http://www.mysql.com and install MySQL.
  4. Configure the database in MySQL.
  5. Download Spring Tool Suite 3.9.9 https://spring.io/tools3/sts/legacy
  6. Make Spring, MySQL and MyBatis work together.
  7. After all of the above are done, you can build and run the server on your local pc.

## How the OS distribution system works

When users run the installer(client) to install Wayne OS on their disk...

1. The client requests introduction(main) and license information to the server.
2. The server reads introduction(main) and license information from html files and sends those to the client. 
3. The client shows those in the first page(main) and the second page(license).
4. The client requests disk(device) volume list to the server.
5. The server sends disk(device) volume list in JSON format to the client.
6. The client recognizes the disk which users plugs on their pc and gathers all data such as vendor, model name, serial number, disk capacity.
7. The client also gathers the data which users selected in options on the client such as Wayne OS version(free or paid), disk drive, disk type, disk volume and the data which is collected for better service such as IP address, Ram, CPU, GPU, Local OS information users are using on their pc.
8. The client sends all data gathered from users in JSON format to the server.
9. The server compares the data from the client with the data stored in the server.
   - The free version: The server sends the information of the os file which is matched for the disk volume users selected to the client.
   - The paid version: For the paid version, the disk information is registered for one paid version os file on the server in advance. If the data from the client is not matched for the data stored in the server, the server sends an error to the client and the client shows an error message. And then, the client is exited. On the other hand, the server sends the information of the os file which is matched for the registration to the client.
10. The client requests 30MB of the os file to the server and the server sends 30MB of the os file to the client in each cycle until the whole file is processed.
11. After that, the client decompresses the file downloaded from the server.
12. After decompression is completed, the client starts to install Wayne OS on users disk.
13. After Installation is completed, the client shows the complete page to notify users that it is done.

## SYNOPSIS

A server-client system that distribute OS image file to user.

1. Server admin upload OS image files to server
2. User connect Removable Device (ex: USB flash drive) to own PC
3. User execute client program
4. Client program send user side information to server
5. Server recognize user side information (ex: Device ID, IP Address, etc) and record it to DB
6. Server send OS image file to client program
7. Client program install the OS image to the Removable Device

## FOR WHOM?

Organization that distribute OS image file which can be installed in Removable Device

## LICENSE

- Open-Source Library License
  - Qt Framework
    - full development framework with tools designed to streamline the creation of applications and user interfaces for desktop, embedded, and mobile platforms. [https://www.qt.io/](https://www.qt.io/)
      Copyright 2019 The Qt Company
      the GNU Lesser General Public License version 3 (LGPLv3)
  - zlib
    - Compression library, [http://www.zlib.net/](http://www.zlib.net/)
      Copyright 1995-2013 Jean-loup Gailly and Mark Adler.
      zlib License
  - minizip
    - For zip and unzip additional library, [http://www.winimage.com/zLibDll/minizip.html](http://www.winimage.com/zLibDll/minizip.html)
      Copyright 1998-2010 Gilles Vollant (minizip) 
      (http://www.winimage.com/zLibDll/minizip.html)
      zlib License
  - ImageWriter
    - The utility to read and write raw image files to SD and USB memory devices
      Original version developed by Justin Davis 
      <[tuxdavis@gmail.com](mailto:tuxdavis@gmail.com)>
      Maintained by the ImageWriter developers
      (http://sourceforge.net/projects/win32diskimager)
      the General Public License v2 (GPL-2)
  - SmartEditor2
    - The WYSIWYG editor based on the web written by JavaScript
      Copyright (C) NAVER corp. https://github.com/naver/smarteditor2the 
      GNU Lesser General Public License version 2.1 (LGPL v2.1)
  - OpenSSL shared Library (we use only The OpenSSL ToolKit dll files)
    - an open-source implementation of the SSL/TLS protocols written in C and distributed as two shared libraries. [https://www.openssl.org/](https://www.openssl.org/)
      Copyright (c) 1998-2018 The OpenSSL Project.
      OpenSSL License, SSLeay License
- https://gitlab.com/wayne-inc/os-distribution-system/blob/master/LICENSE

## CONTRIBUTING

https://gitlab.com/wayne-inc/os-distribution-system/blob/master/CONTRIBUTING