## SCOPE

The Priority of contribution (1 is the first priority)

1. Documentation
2. Redesign UI/UX
3. Bug fix
4. Add new feature
5. Update version/dependencies/test-case
6. Improve error/help message
7. Refactoring code

## RULES

- Format of the branch name

  [type]/[name]

  ​	ex) docs/README.md

- Format of the commit message

  [type] ([optional]) : [subject]

  [body]

  [footer]

  ​	ex) docs/README.md: Fix wrong spelled words in README.md

  ​		  uiux(client) : Add some button on the client

  ​		  hotfix(client): Fix some bugs on the client

  ​		  feature/f(client) : Add f feature on the client		  

- Format of the title of the merge request

    - same with the commit message
  
- Allowed [type] values
  - feature (new feature for the user, not a new feature for build script)
  - uiux (redesign UI/UX of the client or the server)
  - hotfix (bug fix for the user, not a fix to a build script)
  - docs (changes to the documentation)
  - refactor (refactoring production code, eg. renaming a variable)
  - test (adding missing tests, refactoring tests; no production code change)
  - chore (updating grunt tasks etc; no production code change)

## HOW TO CONTRIBUTE

1. Register your own account on Gitlab.

2. Download git bash and learn how to use it on https://git-scm.com/

3. Create SSH keys for your account and register public SSH key on Gitlab. then, you can push the commit from your local to your remote repository.

4. Fork the project. you can find the fork button in the right side of the title of this project. by clicking the fork button, you can have same project on your own remote repository in your account.  

5. Read README and CONTRIBUTING for understanding what the project is and how to contribute to this project well. you need to follow the rules describing in CONTRIBUTING.

6.  Here is the way.
    1. Documentation
        - you can edit or add the document on the remote repository in your account. create a new branch named like doc/[name] from your master branch. name can be the file name you want to edit or you created. edit or write the document on the new branch. 
    2. Redesign UI/UX
        - You may not be able to redesign UI/UX on the remote repository. so clone the project on your local repository. you can download the source code by clicking the button next to Web IDE button. you can also download it by using the command on git bash.  [git clone https://gitlab.com/(UserName)/os-distribution-system]  UserName is your username.     
        At first, you need to arrange IDE for this project. read README.md in advance of setting IDE. after setting up IDE is done, you can redesign UI/UX of this project. create a new branch named like uiux/client or uiux/server from your master branch.   
        In case of the client, you can redesign UI/UX by using Qt Designer or writing source code. for this, you need to learn about Qt framework. there is the well-defined documentation on https://doc.qt.io/   
        In case of the server, you can redesign UI/UX by replacing image, modifying source code in jsp, css, JavaScript, etc. redesign UI/UX on the new branch.  
    3. Bug fix
        - If you find some bugs on this project, notify the maintainer or owner of this project at first. If you want to fix bugs, clone the project on your local repository and arrange IDE for this project. and then, create a new branch named like hotfix(client) or hotfix(server) from your master branch. you can fix bugs by modifying source code. fix bugs on the new branch.  
    4. Add new feature
        - If you want to add new feature, discuss with the maintainer or owner of this project at first. If the maintainer or owner accept your opinion, you can work on it.  
        clone the project on your local repository and arrange IDE for this project. and then, create a new branch named like feature/[name] from your master branch. you can write source code for new feature on this project on the new branch.
   
   5. Update version/dependencies/test-case
   
   6. Improve error/help message
   
   7. Refactoring code
   
7. Before pushing it, Test your work whether it is working well. you have to push the commit for your work when it is the stable version.

8. If you want to implement what you did on the official, Create a merge request. when you send a merge request, leave a well-defined comment that describes what you did and difference between before and after.

   1. Documentation
      - send a merge request to Documentation branch on https://gitlab.com/wayne-inc/os-distribution-system
   2. Redesign UI/UX
      - send a merge request to uiux/client or uiux/server branch https://gitlab.com/wayne-inc/os-distribution-system
   3. Bug fix
      - send a merge request to master branch on https://gitlab.com/wayne-inc/os-distribution-system
   4. Add new feature
      - send a merge request to feature/[name] branch on https://gitlab.com/wayne-inc/os-distribution-system
   5. Update version/dependencies/test-case
   6. Improve error/help message
   7. Refactoring code

9. Review and discuss about your work with the maintainer or owner of this project.

10. If maintainer or owner want to accept your work on this project, they will merge your work on the official version.

## QUESTION

 If you want to ask for anything about this project, please contact with below address.

e-mail: jeun@wayne-inc.com