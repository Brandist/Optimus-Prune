# Usefull and forgetable git commands:

## clone:

> git clone https://github.com/Brandist/Optimus-Prune.git

## add

### add everything in current dir and sub dirs

> git add .

### add specifics

> git add somefir/somefile.cpp

### Undo an add

> git reset

> git reset somefile.cpp

## remove a file of folder

> git rm -r somefile.cpp

## push after adding

> git commit -m "some elaborate but short message"

> git push

## pull

> git pull

## branches

### branch status && current branch

> git branch

> git branch -a

> git branch --show-current

### switch branch

> git checkout SOME_BRANCH_NAME

> git checkout main

### create new branch

> git branch -b SOME_BRANCH_NAME

### delete a branch

> git branch -d SOME_BRANCH_NAME

## merging 

Tip: Always pull the main branch before merging and pushing to avoid conflicts.

No one should be working on your branch, so this shouldnt be the case often.

### current branch with main

> git merge --squash YOUR_CURRENT_BRANCH

> git push

**notes:** --squash: results in compacted commit history. Meaning that if you have 10 commits on your branch, and you merge with main. The main commit history shows the 10 commits as 1 commit. Makes the commit history more readable and shows each merge as 1 commit. 

### main with current branch

> git merge main

**notes:** Almost no need to use this, since your branch should only contain the work of your API, not the other branches. So this command should not be used unless you want the other API's in your branch as well.

## inspection and status

> git status

**notes:** output basic status, uncommitted changes, changed files needed to be add first, changes waiting to be pushed, etc.

> git diff

OR

> git log

**notes:** shows the changes made between the local files and the last commit on github. This can be handy when a file is changed and needed for a commit, but your not sure what has changed. A GUI or vs code extension might be better for checking the changes.

# Other things

If you keep needing to login before pulling or pushing use this command:

> git config credential.helper store

before pulling or pushing, after putting in your information one time, it stores it.
