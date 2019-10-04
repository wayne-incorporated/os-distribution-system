## SCOPE

- Bug fix
- Documentation
- Redesign UI/UX
- Add new feature
- Update version/dependencies/test-case
- Improve error/help message
- Refactoring code

## RULES

- Format of the branch name

  [type]/[name]

  ​	ex) feature/test

- Format of the commit message

  [type] ([scope]) : [subject]

  [body]

  [footer]

  ​	ex) Fix(client): Fix ~ 

- Allowed [type] values
  - Feature (new feature for the user, not a new feature for build script)
  - Fix (bug fix for the user, not a fix to a build script)
  - Docs (changes to the documentation)
  - Refactor (refactoring production code, eg. renaming a variable)
  - Test (adding missing tests, refactoring tests; no production code change)
  - Chore (updating grunt tasks etc; no production code change)

## HOW TO CONTRIBUTE

1. Fork the project. you can find the fork button in the right side of the title of this project. by clicking the fork button, you can have same project on your own remote repository in your account.
2. You may not be able to work on the project on the remote repository. so, Clone the project on your local repository for your work. you can clone this project by clicking clone button which is next to the fork button. you can also clone it by using the command.   
   [git clone https://gitlab.com/<User_name>/os-distribution-system]  
   (ex. If user name is "test", git clone https://gitlab.com/test/os-distribution-system)  
3. Read README file and CONTRIBUTING for understanding what the project is and how to contribute to this project well. you need to follow the rules describing in CONTRIBUTING.
4. Create a new branch for what you try to work on.  
   - Bug fix
     - If you find some bugs, create a new branch named like hotfix-[version] from master branch. version is the number of the version which has bugs. find the factor of bugs and fix bugs on the new branch.    
   - Documentation
     - If you find some wrong spelled words in the document or want to add something for better understanding, create a new branch named like docs/[name] from master branch. name can be the file name what you want to modify or what you want to add. fix wrong spelled words by using editor or write a new document and add it on the new branch.  
   - Redesign UI/UX
     - If you want to redesign UI/UX of the client or the server, create a new branch named like UiUx/client or UiUx/server from master branch. In case of the client, you can modify UI/UX by using Qt designer or writing source code. It depends on you. In case of the server, There are many ways for modifying UI/UX such as replacing image files, changing source code in css, jsp, JavaScript, etc. It also depends on you. All modification are going on the new branch.   
   - Add new feature
     - If you want to add new feature, create a new branch named like feature/[name] from master branch. for example, If you want to add the function for reading IP address, branch name can be like feature/IPAddr. for adding new feature, you need to find the section where you want to add. then, writing source code for new function in this section. after writing source code, you must test whether It is working well and causing errors/bugs. All modification are going on the new branch.
   - Update version/dependencies/test-case 
   - Improve error/help message
     - If you want to improve error/help message, create a new branch named like fix/error-msg or fix/help-msg. the error message is important for developers because developers can easy to find the reason of the error by the error message. and the help message is important for users. so if you feel the current message is not enough to understand, make the message more well-defined. All modification are going on the new branch.  
   - Refactoring code
     - If you want to do code refactoring, create a new branch named like refactor/[file name] from master branch. If you want to refactor source code in test.cpp, branch name can be refactor/test.cpp. you can make source code more better understanding and easier to revise it. you must focus on the structure, not adding the feature. All modification are going on the new branch.
5. Before pushing it, Test your work whether it is working well. you have to push the commit for your work when it is the stable version.
6. If you want to implement what you did on this project, Create merge request. when you send a merge request, leave a well-defined comment that describes what you did and difference between before and after.
7. Review your work with the maintainer or owner of this project.
8. If maintainer or owner want to accept your work on this project, they will merge your work on the official version.

## QUESTION

 If you want to ask for anything about this project, please contact with below address.

chatting: wayne-inc-cr.slack.com

e-mail: jeun@wayne-inc.com

www.wayne-inc.com