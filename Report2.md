# Отчет по лабораторной работе № 2
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Bash, LINUX terminal
2. **Цель работы**: неучиться работать с терминалом Linux
3. **Задание**:
 - Опробовать следующие команды:
    - who
    - pwd
    - ls
    - cd
    - cp
    - mv
    - rm
    - cat
    - ps
    - tail
    - head
    - grep
    - history
    - mkdir
    - rmdir
    - sudo
    - echo
    - ssh
    - scp
    - ssh-keygen
    - ssh-copy-id
- Использовать основные команды
- Сохранить листинг в файл
- Заархивировать
- Отправить на удаленную машину, там разархивировать
- Скачать разархивированный файл к себе на машину
- Составить отчет с листингом в формате markdown
- Выложить на github через merge веток
4. **Листинг**
  
  См. NewLab2Listing.md (листинг с использованием перечисленных команд)

  ***Листинг архивирования и дальнейших действий***
```

user@DESKTOP-IL3KD9K MINGW64 ~ (main)
$ cd repository

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ls
Lab/  Lab2Listing.md  lab2/  lab2test.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ git remote -v
LW      https://github.com/Nadezhda13Soloveva/Lab.git (fetch)
LW      https://github.com/Nadezhda13Soloveva/Lab.git (push)

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ tar cvf archive.tar Lab2Listing.md
Lab2Listing.md

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ls
Lab/  Lab2Listing.md  archive.tar  lab2/  lab2test.txt

user@DESKTOP-IL3KD9K MINGW64 ~/repository (master)
$ ssh n_soliviova@185.5.249.140
The authenticity of host '185.5.249.140 (185.5.249.140)' can't be established.
ED25519 key fingerprint is SHA256:gMWpghci4jH+8KckY83J+zLNE4DrwfrDZorZZU2IRGI.
This key is not known by any other names.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '185.5.249.140' (ED25519) to the list of known hosts.
n_soliviova@185.5.249.140's password:
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


The programs included with the Ubuntu system are free software;
the exact distribution terms for each program are described in the
individual files in /usr/share/doc/*/copyright.

Ubuntu comes with ABSOLUTELY NO WARRANTY, to the extent permitted by
applicable law.

n_soliviova@vds2476450:~$ ssh-keygen -t rsa -b 4096 -C "nadezhda13soloveva@mail.ru"
Generating public/private rsa key pair.
Enter file in which to save the key (/home/n_soliviova/.ssh/id_rsa):
Created directory '/home/n_soliviova/.ssh'.
Enter passphrase (empty for no passphrase):
Enter same passphrase again:
Your identification has been saved in /home/n_soliviova/.ssh/id_rsa
Your public key has been saved in /home/n_soliviova/.ssh/id_rsa.pub
The key fingerprint is:
SHA256:X9VcPXS4kZMNinn3krnWf+o2Aius6lrRvCeu3irBwac nadezhda13soloveva@mail.ru
The key's randomart image is:
+---[RSA 4096]----+
|              oB+|
|           o .*+=|
| .        o o o++|
|  o .o     . o.+ |
| . +. o S   . + .|
|  E  . . ...   + |
|   .. o.. .o  o .|
|  .. o oo . ..o o|
|  .=*++. .   +ooo|
+----[SHA256]-----+
n_soliviova@vds2476450:~$ eval $(ssh-agent -s)
Agent pid 140850
n_soliviova@vds2476450:~$ ssh-add ~/.shh/id_rsa
/home/n_soliviova/.shh/id_rsa: No such file or directory
n_soliviova@vds2476450:~$ ssh-add ~/.ssh/id_rsa
Enter passphrase for /home/n_soliviova/.ssh/id_rsa:
Identity added: /home/n_soliviova/.ssh/id_rsa (nadezhda13soloveva@mail.ru)

n_soliviova@vds2476450:~$ ssh-copy-id n_soliviova@185.5.249.140
The authenticity of host '185.5.249.140 (185.5.249.140)' can't be established.
ECDSA key fingerprint is SHA256:HaVGMUF4Ylk978WKR4oBPYEWkv+fd86Gg9Yqcwnu3Z4.
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
/usr/bin/ssh-copy-id: INFO: attempting to log in with the new key(s), to filter out any that are already installed
/usr/bin/ssh-copy-id: INFO: 1 key(s) remain to be installed -- if you are prompted now it is to install the new keys
n_soliviova@185.5.249.140's password:

Number of key(s) added: 1

Now try logging into the machine, with:   "ssh 'n_soliviova@185.5.249.140'"
and check to make sure that only the key(s) you wanted were added.

n_soliviova@vds2476450:~$ ssh n_soliviova@185.5.249.140
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.


n_soliviova@vds2476450:~/soloveva_dir$ scp C:\Users\user\repository\archive.tar n_soliviova@185.5.249.140:/soloveva_dir
ssh: Could not resolve hostname c: Temporary failure in name resolution
```

  ***Листинг из PowerShell***
```
n_soliviova@vds2476450:~$ scp C:\Users\user\repository\archive.tar n_soliviova@185.5.249.140
ssh: Could not resolve hostname c: Temporary failure in name resolution
n_soliviova@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

n_soliviova@vds2476450:~$ scp C:\Users\user\repository\archive.tar n_soliviova@185.5.249.140
ssh: Could not resolve hostname c: Temporary failure in name resolution
n_soliviova@vds2476450:~$ exit
logout
Connection to 185.5.249.140 closed.

PS C:\Users\user\repository> ssh n_soliviova@185.5.249.140
n_soliviova@185.5.249.140's password:
Welcome to Ubuntu 20.04.6 LTS (GNU/Linux 5.4.0-162-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage
New release '22.04.3 LTS' available.
Run 'do-release-upgrade' to upgrade to it.

Last login: Mon Sep 25 09:58:05 2023 from 85.143.224.14
n_soliviova@vds2476450:~$ ls
archive.tar
n_soliviova@vds2476450:~$ tar xvf archive.tar
Lab2Listing.md
n_soliviova@vds2476450:~$ mv Lab2Listing.md NewLab2Listing.md
n_soliviova@vds2476450:~$ ls
archive.tar  NewLab2Listing.md

PS C:\Users\user\repository> scp n_soliviova@185.5.249.140:~/NewLab2Listing.md C:\Users\user\repository
n_soliviova@185.5.249.140's password:
NewLab2Listing.md                                100% 5823   709.6KB/s   00:00
```

5. **Вывод:** В процессе работы научились: использовать вышеперчисленные команды, подключаться к удаленному серверу и работать на нём, работать с SSH ключами,
   архивировать и разархивировать файлы, обмениваться файлами между локальной машиной и удаленным сервером.
   

