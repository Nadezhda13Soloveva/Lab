# Отчет по лабораторной работе № 1
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Знакомство с Git, Github, Gitlab etc
2. **Цель работы**: Научиться работать с Git
3. **Задание**: 
	- завести репозиторий 
	- отчет с листингом в Markdown (листинг - ctrl+c -> ctrl+v из терминала с форматированием в markdown)
	- создать отдельную ветку в репозитории под задание
	- создать коммит с листингом и отчетом
	- смержить ветку в мейн
4. **Идея, метод, алгоритм решения задачи**:  
5. **Сценарий выполнения работы**:

6. **Листинг**: 
```
user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (main)
$ git init
Initialized empty Git repository in C:/Users/user/repository/.git/

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git status
On branch master

No commits yet

nothing to commit (create/copy files and use "git add" to track)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ touch README.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)
        README.md

nothing added to commit but untracked files present (use "git add" to track)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git add README.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)
        new file:   README.md


user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git commit -m "[create repository]"
[master (root-commit) e87ba2e] [create repository]
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 README.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git log
commit e87ba2e33fee81a32f48705ec29c5ec01681d79c (HEAD -> master)
Author: Nadezhda Soloveva <nadezhda13soloveva@mail.ru>
Date:   Mon Sep 18 11:34:49 2023 +0300

    [create repository]

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git log --oneline
e87ba2e (HEAD -> master) [create repository]

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git remote add LW https://github.com/Nadezhda13Soloveva/Lab.git

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git ls-remote
From https://github.com/Nadezhda13Soloveva/Lab.git
f7fa8665b30d77527a570c5c55767a520ece1e90        HEAD
f7fa8665b30d77527a570c5c55767a520ece1e90        refs/heads/main

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git commit -m "[remote repository from GitHub]"
On branch master
nothing to commit, working tree clean

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git remote -v
LW      https://github.com/Nadezhda13Soloveva/Lab.git (fetch)
LW      https://github.com/Nadezhda13Soloveva/Lab.git (push)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git push origin master
fatal: 'origin' does not appear to be a git repository
fatal: Could not read from remote repository.

Please make sure you have the correct access rights
and the repository exists.

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git push LW master
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Writing objects: 100% (3/3), 227 bytes | 227.00 KiB/s, done.
Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'master' on GitHub by visiting:
remote:      https://github.com/Nadezhda13Soloveva/Lab/pull/new/master
remote:
To https://github.com/Nadezhda13Soloveva/Lab.git
 * [new branch]      master -> master

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git remote show LW
* remote LW
  Fetch URL: https://github.com/Nadezhda13Soloveva/Lab.git
  Push  URL: https://github.com/Nadezhda13Soloveva/Lab.git
  HEAD branch: main
  Remote branches:
    main   new (next fetch will store in remotes/LW)
    master tracked
  Local ref configured for 'git push':
    master pushes to master (up to date)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git branch
* master

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git checkout -b "lab1"
Switched to a new branch 'lab1'

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git branch
* lab1
  master

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ ^C

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git touch Lab1Listing.md
git: 'touch' is not a git command. See 'git --help'.

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ touch Lab1Listing.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git status
On branch lab1
Untracked files:
  (use "git add <file>..." to include in what will be committed)
        Lab1Listing.md

nothing added to commit but untracked files present (use "git add" to track)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git add Lab1Listing.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git commit -m "[create Lab1Listing.md]"
[lab1 0f7ad41] [create Lab1Listing.md]
 1 file changed, 0 insertions(+), 0 deletions(-)
 create mode 100644 Lab1Listing.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$ git push LW --all
Enumerating objects: 3, done.
Counting objects: 100% (3/3), done.
Delta compression using up to 4 threads
Compressing objects: 100% (2/2), done.
Writing objects: 100% (2/2), 269 bytes | 269.00 KiB/s, done.
Total 2 (delta 0), reused 0 (delta 0), pack-reused 0
remote:
remote: Create a pull request for 'lab1' on GitHub by visiting:
remote:      https://github.com/Nadezhda13Soloveva/Lab/pull/new/lab1
remote:
To https://github.com/Nadezhda13Soloveva/Lab.git
 * [new branch]      lab1 -> lab1

user@DESKTOP-IL3KD9K MINGW64 ~/repository (lab1)
$


```

5.  **Вывод:** В процессе выполнения лабораторной работы мы научились создавать репозиторий в GitHub, создавать коммиты и ветви, подключаться к удаленному репозиторию, отправлять коммиты с локального репозитория в удаленный, делать листинг работы, мержить ветви.
