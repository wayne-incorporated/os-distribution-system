## SCOPE

The Priority of contribution (1 is the first priority)

1. Documentation
2. Redesign UI/UX
3. Bug fix
4. Add new feature
5. Update version/dependencies/test-case
6. Improve error/help message
7. Refactoring code
<br/>


## RULES

- Format of the branch name  

    [type]/[name]
    
    ex)  
        ``
        docs/README.md
        ``
    <br/>
- Format of the commit message    
    
    [type] ([optional]) : [subject]

    [body]
    
    [footer]
    <br/>
    
    ex)  
    ``
    docs/README.md: Fix wrong spelled words in README.md
    ``<br/>
    ``
    uiux: Add some button on the client
    ``<br/>
    ``
    hotfix: Fix some bugs on the client
    ``<br/>
    ``
    feature/f: Add f feature on the client
    ``<br/>    
- Format of the title of the merge request

    - same with the commit message
    <br/>
  
- Allowed [type] values
  - feature (new feature for the user, not a new feature for build script)
  - uiux (redesign UI/UX of the client or the server)
  - hotfix (bug fix for the user, not a fix to a build script)
  - docs (changes to the documentation)
  - refactor (refactoring production code, eg. renaming a variable)
  - test (adding missing tests, refactoring tests; no production code change)
  - chore (updating grunt tasks etc; no production code change)
<br/>


## HOW TO CONTRIBUTE

1. Register your own account on Gitlab.

2. Download and install Git. you can download in [here](https://git-scm.com/). you can also learn all about Git on that site.

3. Create SSH keys for your account and register public SSH key on Gitlab. then, you can push the commit from your local to your remote repository.

4. Fork the project. you can find the fork button in the right side of the title of this project. by clicking the fork button, you can have same project on your own remote repository in your account.  

5. Read README and CONTRIBUTING for understanding what the project is and how to contribute to this project well. you need to follow the rules describing in CONTRIBUTING.

6.  Here is the way.
    
    - Documentation
    
        - you can edit or add the document on the remote repository in your account. you can also do it by using editor after cloning this project on your local repository. create a new branch from master branch following the rule. then, edit or create the document.
        <br/> 
    - Redesign UI/UX
    
        - You may not be able to redesign UI/UX on the remote repository. so clone the project on your local repository. you can download the source code by clicking the button next to Web IDE button. you can also download it by using the command on git bash.
            
            ``
            git clone https://gitlab.com/(UserName)/os-distribution-system
            ``<br/> UserName is your username on Gitlab.<br/>     
        At first, you need to arrange IDE for this project. read README.md in advance of setting IDE. after setting up IDE is done, you can redesign UI/UX of this project. create a new branch from master branch following the rule.<br/>   
        In case of the client, you can redesign UI/UX by using Qt Designer or writing source code. for this, you need to learn about Qt framework. there is the well-defined documentation on https://doc.qt.io/   
        In case of the server, you can redesign UI/UX by replacing image, modifying source code in jsp, css, JavaScript, etc.
        <br/>
    - Bug fix
    
        - If you find some bugs on this project, notify and discuss with other contributors or the maintainer of this project at first. by this way, other contributors and the maintainer of this project can help you. you can fix bugs easier than when you try to fix bugs alone.<br/> 
        clone the project on your local repository and arrange IDE for this project. and then, create a new branch from master branch following the rule. then, try to fix bugs discussing other contributors or the maintainer of this project.  
        <br/> 
    - Add new feature
    
        - If you want to add new feature, discuss with the maintainer or owner of this project at first. If the maintainer or owner accept your opinion, you can work on it.  
         clone the project on your local repository and arrange IDE for this project. and then, create a new branch from master branch following the rule. then, write source code for new feature on this project.
        <br/>
    - Update version/dependencies/test-case
    
        - If you think that updating version or external things such as libraries, etc. or dependencies or test-case is needed, please notify the maintainer or owner of this project what you found at first. If they agree with your opinion, try on it with the maintainer discussing that thing.
        <br/>
    - Improve error/help message
    
        - If you feel you need to add or improve error/help messages, please notify and discuss with the maintainer or owner of this project at first. then, create a new branch from master branch following the rule and try on it.
        <br/>
    - Refactoring code
    
        - If you want to do code refactoring, please discuss with the maintainer or owner of this project at first. if they agree with your opinion, create a new branch from master branch following the rule. then, try on it. 
        <br/>   

7. Before pushing it, you have to make sure that It has no problem. Test your work whether it is working well. you have to push the commit for your work when it is the stable version.

8. Create a merge request. when you send a merge request, leave a well-defined comment that describes what you did and difference between before and after.

   - Documentation
        - send a merge request to Documentation branch on wayne-inc/os-distribution-system
        <br/>
   - Redesign UI/UX
        - send a merge request to uiux branch wayne-inc/os-distribution-system
        <br/>
   - Bug fix
        - send a merge request to master branch on wayne-inc/os-distribution-system
        <br/>
   - Add new feature
        - send a merge request to develop branch on wayne-inc/os-distribution-system
        <br/>
   - Update version/dependencies/test-case
        - discuss with the maintainer or owner of this project.
        <br/>
   - Improve error/help message
        - send a merge request to develop branch on wayne-inc/os-distribution-system
        <br/>
   - Refactoring code
        - send a merge request to develop branch on wayne-inc/os-distribution-system
        <br/>
9. Review and discuss about your work with the maintainer or owner of this project.

10. If maintainer or owner want to accept your work on this project, they will merge your work on the official version.
<br/>


## QUESTION

 If you want to ask for anything about this project, please contact with below address.

e-mail: jeun@wayne-inc.com

