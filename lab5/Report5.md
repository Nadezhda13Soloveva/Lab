# Отчет по лабораторной работе № 5
## по курсу "Фундаментальная информатика"

Студент группы М8О-108Б-23 Соловьева Надежда Сергеевна

Работа выполнена 

Преподаватель: каф. 806 Севастьянов Виктор Сергеевич

1. **Тема**: Программирование машин Тьюринга
2. **Цель работы**: Составить программу машины Тьюринга в четвёрках, выполняющую заданное действие над словами, записанными на 
ленте. Отладку и тестирование проводить в среде интерактивного действующего макета jstu4. Алфавит МТ определяется 
заданием. Использование дополнительных (несобственных) букв (кроме λ) нежелательно. Необоснованное использование 
несобственных букв считается недочётом и является достаточным основанием для снижения оценки. 
В начальном состоянии головка МТ находится на пустой ячейке непосредственно справа от записанных на ленте 
аргументов – слов входного сообщения. В конечном состоянии головка МТ должна находиться на пустой ячейке 
непосредственно справа от результата (последнего преобразованного или вновь сгенерированного слова результирующего 
сообщения). Вычисления в программе, как правило, должны быть нормированными (аргументы после работы программы 
сохраняются на ленте в неизменном виде и не остаётся промежуточных результатов); ненормированные вычисления, 
особенно в простых случаях, считаются недочётом и являются достаточным основанием для снижения оценки. 
Перед составлением алгоритма для машины Тьюринга необходимо подготовить тесты для него – представительный 
набор различных входных сообщений, для которых известен правильный ответ, включая значения на границах области 
определения вычислимой функции и за её пределами. 

3. **Задание (вариант №)**: Вариант №32: Уменьшение на единицу целого неотрицательного числа в восьмеричной системе счисления.  
4. **Идея, метод, алгоритм решения задачи**:  
Идея: Посимвольно копируем вводное слово справа рядом через пробел. Далее изменяем записанное скопированное слово в зависимости от задания (меняем символы в соответствии с правилом вычитания единицы из числа в восьмеричной системе счичления).
<image src="/lab5/тьюрингсхема.png" alt="Схема работы программы">

**Команды и их функции**:  
    **00** - двигаем головку влево от стартовой позиции (пробел после вводного слова)  
    **leftf** - двигаем головку влево до начала вводного слова (пробела)  
    **checknull** - про
    **nul** - 
    **otr** - 
    **first** - считываем первую после пробела цифру n и в зависимости от её значения выстраиваем следующий алгоритм:    
       - **probeln** - заменяем цифру n на пробел  
       - **rightn** - двигаем головку вправо до конца вводного слова (пробела)  
       - **rightendn** - двигаем головку вправо до конца создаваемого слова (пробела), в конце этого слова записыываем цифру n  
       - **leftstep** - считываем последнюю цифру создаваемого слова n и в зависимости от её значения продолжаем алгоритм  
       - **leftstepn** - двигаем головку влево до начала создаваемого слова/конца вводного слова (пробела)  
       - **cpn** - двигаем головку влево до пробела, которым мы командой probeln заменили цифру n, и меняем его на изначально стоящую здесь цифру n  
       - **right** - двигаем головку вправо и начинаем процесс копирования следующей цифры командой first  
     **rightfin** - если скопированы все цифры водного слова (команда first оказалась в конце вводного слова (пробеле)), двиагем головку вправо до конца созданного слова (пробела)  
     **edit** - меняем цифру n на цифру n-1, если не поисходит переход на следующий разряд    
     **razryd** - двигаем головку влево и меняем следующий раз  
     **finish** - двигаем головку вправо до конца измененного скопированного слова (пробела) --> конец  
     
5. **Сценарий выполнения работы**:

| Входные данные | Выходные данные       | Описание тестируемого случая                                     |
|----------------|-----------------------|------------------------------------------------------------------|
| 767            | 767 766               | Вычитание единицы без перехода на следующий разряд               |  
| 770            | 770 767               | Вычитание единицы с переходом на следующий разряд                |
| 700            | 700 677               | Вычитание единицы с переходом на несколько следующих разрядов    |
| 100            | 100 077               | Вычитание единицы с изменением разрядности числа                 |   
| 0              | 0 7777777777777777777 | Вычитание единицы с выводом -1 через большое положительное число |   
| 00000001       | 00000001 0            | Вычитание единицы с устранением предстоящих нулей                |   

6. **Протокол**:
 ```
00, ,<,leftf

leftf,1,<,leftf 
leftf,2,<,leftf
leftf,0,<,checknul
leftf,3,<,leftf
leftf,4,<,leftf
leftf,5,<,leftf
leftf,6,<,leftf
leftf,7,<,leftf
leftf, ,>,first

checknul, ,>,nul
checknul,1,<,leftf
checknul,2,<,leftf
checknul,3,<,leftf
checknul,4,<,leftf
checknul,5,<,leftf
checknul,6,<,leftf
checknul,7,<,leftf
checknul,0,<,leftf
nul,0,>,nul
nul, ,>,otr
nul,1,1,first
nul,2,2,first
nul,3,3,first
nul,4,4,first
nul,5,5,first
nul,6,6,first
nul,7,7,first

otr, ,7,otr1
otr1,7,>,otr2
otr2, ,7,otr2
otr2,7,>,otr3
otr3, ,7,otr3
otr3,7,>,otr4
otr4, ,7,otr4
otr4,7,>,otr5
otr5, ,7,otr5
otr5,7,>,otr6
otr6, ,7,otr6
otr6,7,>,otr7
otr7, ,7,otr7
otr7,7,>,otr8
otr8, ,7,otr8
otr8,7,>,otr9
otr9, ,7,otr9
otr9,7,>,otr10
otr10, ,7,otr10
otr10,7,>,otr11
otr11, ,7,otr11
otr11,7,>,otr12
otr12, ,7,otr12
otr12,7,>,otr13
otr13, ,7,otr13
otr13,7,>,otr14
otr14, ,7,otr14
otr14,7,>,otr15
otr15, ,7,otr15
otr15,7,>,otr16
otr16, ,7,otr16
otr16,7,>,otr17
otr17, ,7,otr17
otr17,7,>,otr18
otr18, ,7,otr18
otr18,7,>,otr19
otr19, ,7,finish


right1,0,>,right1 
right1,2,>,right1
right1,1,>,right1
right1,3,>,right1
right1,4,>,right1
right1,5,>,right1
right1,6,>,right1
right1,7,>,right1
right1, ,>,rightend1

right0,0,>,right0 
right0,2,>,right0
right0,1,>,right0
right0,3,>,right0
right0,4,>,right0
right0,5,>,right0
right0,6,>,right0
right0,7,>,right0
right0, ,>,rightend0

right2,0,>,right2 
right2,2,>,right2
right2,1,>,right2
right2,3,>,right2
right2,4,>,right2
right2,5,>,right2
right2,6,>,right2
right2,7,>,right2
right2, ,>,rightend2

right3,0,>,right3 
right3,2,>,right3
right3,1,>,right3
right3,3,>,right3
right3,4,>,right3
right3,5,>,right3
right3,6,>,right3
right3,7,>,right3
right3, ,>,rightend3

right4,0,>,right4 
right4,2,>,right4
right4,1,>,right4
right4,3,>,right4
right4,4,>,right4
right4,5,>,right4
right4,6,>,right4
right4,7,>,right4
right4, ,>,rightend4

right5,0,>,right5 
right5,2,>,right5
right5,1,>,right5
right5,3,>,right5
right5,4,>,right5
right5,5,>,right5
right5,6,>,right5
right5,7,>,right5
right5, ,>,rightend5

right6,0,>,right6 
right6,2,>,right6
right6,1,>,right6
right6,3,>,right6
right6,4,>,right6
right6,5,>,right6
right6,6,>,right6
right6,7,>,right6
right6, ,>,rightend6

right7,0,>,right7 
right7,2,>,right7 
right7,1,>,right7
right7,3,>,right7
right7,4,>,right7
right7,5,>,right7
right7,6,>,right7
right7,7,>,right7
right7, ,>,rightend7

rightend1,0,>,rightend1 
rightend1,2,>,rightend1
rightend1,1,>,rightend1
rightend1,3,>,rightend1
rightend1,4,>,rightend1
rightend1,5,>,rightend1
rightend1,6,>,rightend1
rightend1,7,>,rightend1
rightend1, ,1,leftstep

rightend0,0,>,rightend0 
rightend0,2,>,rightend0
rightend0,1,>,rightend0
rightend0,3,>,rightend0
rightend0,4,>,rightend0
rightend0,5,>,rightend0
rightend0,6,>,rightend0
rightend0,7,>,rightend0
rightend0, ,0,leftstep

rightend2,0,>,rightend2 
rightend2,2,>,rightend2
rightend2,1,>,rightend2
rightend2,3,>,rightend2
rightend2,4,>,rightend2
rightend2,5,>,rightend2
rightend2,6,>,rightend2
rightend2,7,>,rightend2
rightend2, ,2,leftstep

rightend3,0,>,rightend3 
rightend3,2,>,rightend3
rightend3,1,>,rightend3
rightend3,3,>,rightend3
rightend3,4,>,rightend3
rightend3,5,>,rightend3
rightend3,6,>,rightend3
rightend3,7,>,rightend3
rightend3, ,3,leftstep

rightend4,0,>,rightend4 
rightend4,2,>,rightend4
rightend4,1,>,rightend4
rightend4,3,>,rightend4
rightend4,4,>,rightend4
rightend4,5,>,rightend4
rightend4,6,>,rightend4
rightend4,7,>,rightend4
rightend4, ,4,leftstep

rightend5,0,>,rightend5 
rightend5,2,>,rightend5
rightend5,1,>,rightend5
rightend5,3,>,rightend5
rightend5,4,>,rightend5
rightend5,5,>,rightend5
rightend5,6,>,rightend5
rightend5,7,>,rightend5
rightend5, ,5,leftstep

rightend6,0,>,rightend6 
rightend6,2,>,rightend6
rightend6,1,>,rightend6
rightend6,3,>,rightend6
rightend6,4,>,rightend6
rightend6,5,>,rightend6
rightend6,6,>,rightend6
rightend6,7,>,rightend6
rightend6, ,6,leftstep

rightend7,0,>,rightend7 
rightend7,2,>,rightend7 
rightend7,1,>,rightend7
rightend7,3,>,rightend7
rightend7,4,>,rightend7
rightend7,5,>,rightend7
rightend7,6,>,rightend7
rightend7,7,>,rightend7
rightend7, ,7,leftstep

first,1, ,probel1
first,0, ,probel0
first,2, ,probel2
first,3, ,probel3
first,4, ,probel4
first,5, ,probel5
first,6, ,probel6
first,7, ,probel7
first, ,>,rightfin

probel1, ,>,right1
probel0, ,>,right0
probel2, ,>,right2
probel3, ,>,right3
probel4, ,>,right4
probel5, ,>,right5
probel6, ,>,right6
probel7, ,>,right7

leftstep,1,<,leftstep1
leftstep,2,<,leftstep2
leftstep,3,<,leftstep3
leftstep,4,<,leftstep4
leftstep,5,<,leftstep5
leftstep,6,<,leftstep6
leftstep,7,<,leftstep7
leftstep,0,<,leftstep0

leftstep1,1,<,leftstep1
leftstep1,2,<,leftstep1
leftstep1,3,<,leftstep1
leftstep1,4,<,leftstep1
leftstep1,5,<,leftstep1
leftstep1,6,<,leftstep1
leftstep1,7,<,leftstep1
leftstep1,0,<,leftstep1
leftstep1, ,<,cp1

leftstep2,1,<,leftstep2 
leftstep2,2,<,leftstep2
leftstep2,3,<,leftstep2
leftstep2,4,<,leftstep2
leftstep2,5,<,leftstep2
leftstep2,6,<,leftstep2
leftstep2,7,<,leftstep2
leftstep2,0,<,leftstep2
leftstep2, ,<,cp2

leftstep3,1,<,leftstep3
leftstep3,2,<,leftstep3
leftstep3,3,<,leftstep3
leftstep3,4,<,leftstep3
leftstep3,5,<,leftstep3
leftstep3,6,<,leftstep3
leftstep3,7,<,leftstep3
leftstep3,0,<,leftstep3
leftstep3, ,<,cp3

leftstep4,1,<,leftstep4
leftstep4,2,<,leftstep4
leftstep4,3,<,leftstep4
leftstep4,4,<,leftstep4
leftstep4,5,<,leftstep4
leftstep4,6,<,leftstep4
leftstep4,7,<,leftstep4
leftstep4,0,<,leftstep4
leftstep4, ,<,cp4

leftstep5,1,<,leftstep5 
leftstep5,2,<,leftstep5
leftstep5,3,<,leftstep5
leftstep5,4,<,leftstep5
leftstep5,5,<,leftstep5
leftstep5,6,<,leftstep5
leftstep5,7,<,leftstep5
leftstep5,0,<,leftstep5
leftstep5, ,<,cp5

leftstep6,1,<,leftstep6
leftstep6,2,<,leftstep6
leftstep6,3,<,leftstep6
leftstep6,4,<,leftstep6
leftstep6,5,<,leftstep6
leftstep6,6,<,leftstep6
leftstep6,7,<,leftstep6
leftstep6,0,<,leftstep6
leftstep6, ,<,cp6

leftstep7,1,<,leftstep7
leftstep7,2,<,leftstep7
leftstep7,3,<,leftstep7
leftstep7,4,<,leftstep7
leftstep7,5,<,leftstep7
leftstep7,6,<,leftstep7
leftstep7,7,<,leftstep7
leftstep7,0,<,leftstep7
leftstep7, ,<,cp7

leftstep0,1,<,leftstep0
leftstep0,2,<,leftstep0
leftstep0,3,<,leftstep0
leftstep0,4,<,leftstep0
leftstep0,5,<,leftstep0
leftstep0,6,<,leftstep0
leftstep0,7,<,leftstep0
leftstep0,0,<,leftstep0
leftstep0, ,<,cp0

cp1,1,<,cp1
cp1,2,<,cp1
cp1,3,<,cp1
cp1,4,<,cp1
cp1,5,<,cp1
cp1,6,<,cp1
cp1,7,<,cp1
cp1,0,<,cp1
cp1, ,1,right

cp2,1,<,cp2
cp2,2,<,cp2
cp2,3,<,cp2
cp2,4,<,cp2
cp2,5,<,cp2
cp2,6,<,cp2
cp2,7,<,cp2
cp2,0,<,cp2
cp2, ,2,right

cp3,1,<,cp3
cp3,2,<,cp3
cp3,3,<,cp3
cp3,4,<,cp3
cp3,5,<,cp3
cp3,6,<,cp3
cp3,7,<,cp3
cp3,0,<,cp3
cp3, ,3,right

cp4,1,<,cp4
cp4,2,<,cp4
cp4,3,<,cp4
cp4,4,<,cp4
cp4,5,<,cp4
cp4,6,<,cp4
cp4,7,<,cp4
cp4,0,<,cp4
cp4, ,4,right

cp5,1,<,cp5
cp5,2,<,cp5
cp5,3,<,cp5
cp5,4,<,cp5
cp5,5,<,cp5
cp5,6,<,cp5
cp5,7,<,cp5
cp5,0,<,cp5
cp5, ,5,right

cp6,1,<,cp6
cp6,2,<,cp6
cp6,3,<,cp6
cp6,4,<,cp6
cp6,5,<,cp6
cp6,6,<,cp6
cp6,7,<,cp6
cp6,0,<,cp6
cp6, ,6,right

cp7,1,<,cp7
cp7,2,<,cp7
cp7,3,<,cp7
cp7,4,<,cp7
cp7,5,<,cp7
cp7,6,<,cp7
cp7,7,<,cp7
cp7,0,<,cp7
cp7, ,7,right

cp0,1,<,cp0
cp0,2,<,cp0
cp0,3,<,cp0
cp0,4,<,cp0
cp0,5,<,cp0
cp0,6,<,cp0
cp0,7,<,cp0
cp0,0,<,cp0
cp0, ,0,right

right,1,>,first
right,2,>,first
right,3,>,first
right,4,>,first
right,5,>,first
right,6,>,first
right,7,>,first
right,0,>,first

rightfin,1,>,rightfin
rightfin,2,>,rightfin
rightfin,3,>,rightfin
rightfin,4,>,rightfin
rightfin,5,>,rightfin
rightfin,6,>,rightfin
rightfin,7,>,rightfin
rightfin,0,>,rightfin
rightfin, ,<,edit

edit,0,7,razryd 
edit,7,6,finish
edit,6,5,finish
edit,5,4,finish
edit,4,3,finish
edit,3,2,finish
edit,2,1,finish
edit,1,0,finish

finish,1,>,finish
finish,2,>,finish
finish,3,>,finish
finish,4,>,finish
finish,5,>,finish
finish,6,>,finish
finish,7,>,finish
finish,0,>,finish
finish, , ,finish


razryd,7,<,edit
```

7. **Выводы**: В процессе работы узнали о Машине Тьюринга и принципе её работы, научились писать программы в четвёрках. В принципе работа понравилась, если не брать в расчёт количество потраченного на неё времени. Из-за того, что приходиться расписывать каждый шаг, легко пропустить тот или иной этап и потеряться в собственном коде, на зато по итогу выполнения чувствуешь себя мудрецом не от мира сего. Итог 8/10.
