
user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ history
    1  cd
    2  ls
    3  mkid my_repository
    4  mkdir my_repository
    5  git init
    6  git remote add origin https://github.com/Nadezhda13Soloveva/LW.git
    7  git status
    8  history

user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ pwd
/c/Users/user/repository


user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ whoami
user

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ls
Lab/  Lab1Listing.md  README.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ mkdir lab2

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ history
    1  cd
    2  ls
    3  mkid my_repository
    4  mkdir my_repository
    5  git init
    6  git remote add origin https://github.com/Nadezhda13Soloveva/LW.git
    7  git status
    8  history
    9  cd reposutory
   10  cd repository
   11  pwd
   12  who
   13  whiami
   14  whoami
   15  ls
   16  mkdir lab2
   17  history

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ cd lab2

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ touch test2lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ echo "this is my text"
this is my text

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ echo -e "this \nis \nmy \ntext"
this
is
my
text

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ echo "I \nam \nreally \ntired \nof \nlife. \nOMG \nwhy \ndon't \nI \nunderstand \nmath \nanalysis?" > test2lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ cat test2lab.txt
I \nam \nreally \ntired \nof \nlife. \nOMG \nwhy \ndon't \nI \nunderstand \nmath \nanalysis?

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ echo -e "I'm \nreally \ntired \nof \nlife. \nOMG \nwhy \ndon't \nI \nunderstand \nmath \nanalysis?" > test2lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ cat test2lab.txt
I'm
really
tired
of
life.
OMG
why
don't
I
understand
math
analysis?

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ head -5 test2lab.txt
I'm
really
tired
of
life.

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ tail -7 test2lab.txt
OMG
why
don't
I
understand
math
analysis?

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ grep math test2lab.txt
math

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ grep I test2lab.txt
I'm
I

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ cp test2lab.txt test22lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ls
test22lab.txt  test2lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ cd

user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ mkdir lab22

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ls
Lab/  Lab1Listing.md  README.md  lab2/  lab22/

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ cd lab22

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab22 (master)
$ cd

user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ rmdir lab22

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ls
Lab/  Lab1Listing.md  README.md  lab2/

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ cd lab2

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ mv test2lab.txt lab2test.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ls
lab2test.txt  test22lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ rm test22lab.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ls
lab2test.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ssh-keygen -t rsa -b 4096 -C "nadezhda13soloveva@mail.ru"
Generating public/private rsa key pair.
Enter file in which to save the key (/c/Users/user/.ssh/id_rsa):
/c/Users/user/.ssh/id_rsa already exists.
Overwrite (y/n)? y
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /c/Users/user/.ssh/id_rsa
Your public key has been saved in /c/Users/user/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:czQUqxhkX4z+GYolYgz7mEWDGNomtvBhtyB5hhVSv3g nadezhda13soloveva@mail.ru
The key's randomart image is:
+---[RSA 4096]----+
|o++o  o  o+.     |
|o*o.oo ..o..     |
|B.O=o.... +      |
|oOo==o.ooo..     |
| .o*E..+So.o     |
|  o.. . .oo      |
|                 |
|                 |
|                 |
+----[SHA256]-----+

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ eval $(ssh-agent -s)
Agent pid 1386

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ssh-add ~/.shh/id_rsa
/c/Users/user/.shh/id_rsa: No such file or directory

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ ssh-add ~/.ssh/id_rsa
Enter passphrase for /c/Users/user/.ssh/id_rsa:
Identity added: /c/Users/user/.ssh/id_rsa (nadezhda13soloveva@mail.ru)

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ clip < ~/.ssh/id_rsa.pub

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ scp -r /c/Users/user/repository/lab2/* /c/Users/user/repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository/lab2 (master)
$ cd

user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git remote -v
LW      https://github.com/Nadezhda13Soloveva/Lab.git (fetch)
LW      https://github.com/Nadezhda13Soloveva/Lab.git (push)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git branch
* master

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ touch Lab2Listing.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$
